/* Demo for the function crypt used  */

#if 0

This snippet can be used to decrypt hashes used in olds versions 
of linux where the password hash is in plain text in the /etc/passwd
The salt are the first two letters of the hash.
For example this prints:
ueqwOCnSGdsuM < The password for nebula 06

#endif

#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
int main()
{
  printf("%s\n", crypt("hello", "ue"));
  return 0;
}
