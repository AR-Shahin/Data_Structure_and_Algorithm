#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    int top = 13;
    int i;
    for (i = 1; i <= n; i++)
    {

        i % 2 == 0 ? (sum -= ((top * i) / i)) : (sum += ((top * i) / i));
    }

    printf("\n%d", sum);
    return 0;
}
