#include <stdio.h>
#include <stdlib.h>

int main()
{
    double n1, n2, s;

    printf("n1: ");
    scanf("%lf", &n1);

    printf("n2: ");
    scanf("%lf", &n2);

    s = n1 + n2;

    printf("%f + %f = %f\n", n1, n2, s);

    return EXIT_SUCCESS;
}
