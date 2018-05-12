/* Demo for the function crypt used  */

#if 0

This snippet can be used to decrypt hashes used in olds versions 
of linux where the password hash is in plain text in the /etc/passwd
The salt are the first two letters of the hash.
For example this prints:
ueqwOCnSGdsuM < The password for nebula 06

#endif

/* TODO: Make this a threaded program */

#include <iostream>
#include <fstream>
#include <crypt.h>
#include <thread>
#include <string>
int main()
{
  std::ifstream passwd("UserPassCombo-Jay.txt");
  std::string pass;
  std::string hash("ueqwOCnSGdsuM");
  while(passwd >> pass)
  {
    if( hash.compare(crypt(pass.c_str(), "ue")) == 0) break;
  }
  std::cout << pass << std::endl;
  return 0;
}
