#include <stdio.h>
#include <string.h>

union myUnion
{
    int i;
    float f;
    char c;
};

int main()
{
    union myUnion u;

    u.i = 10;
    printf("i: %d\n", u.i);

    u.f = 10.5;
    printf("f: %f\n", u.f);

    u.c = 'A';
    printf("c: %c\n", u.c);

    return 0;
}