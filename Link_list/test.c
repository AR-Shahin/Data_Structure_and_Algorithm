#include <stdio.h>
int main()
{
    int a, b, r;
    printf("enter a b : ");
    scanf("%d %d", &a, &b);
    r = (a * a) + (8 * a * b) + (2 * b) - (4 * a * b);

    printf("\n%d", r);
}
