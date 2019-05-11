#include <stdio.h>
// boot strap quine
int main(int argc, char const *argv[])
{
  int i;
  printf("char s[] = {\n");
  for(i = 0; s[i]; ++i) printf("\t%d,\n", s[i]);
  printf("%s", s);
  return 0;
}
