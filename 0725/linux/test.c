#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    
    char s[256];
    int n;
    float f;
    char c;
    scanf("Hello,%d,%g,%c,%[^\n]", &n, &f, &c, s);
    printf("%s\n", s);
    return 0;
}
