#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
void test(char *s){
    s = malloc(1000);
} */

void test(char **s){
    *s = malloc(1000);
}

char *test2(char *s){
    s = malloc(1000);
    return s;
}

int main(int argc, const char *argv[])
{
    char *s = NULL;
    test(&s);

    s = test(s);
    return 0;
}
