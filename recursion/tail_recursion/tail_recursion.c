#include <stdio.h>
static int atoi(const char *str, int n)
{
    if (str == 0 || *str == 0)
        return n;
    return atoi(str+1, n*10 + *str-'0');
}
int main(int argc, char **argv)
{
    for (int i = 1; i != argc; ++i)
        printf("%s -> %d\n", argv[i], atoi(argv[i], 0));
    return 0;
}
