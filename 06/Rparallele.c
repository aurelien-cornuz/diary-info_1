#include <stdio.h>

int main(int argc, char *argv[])
{
    double result = 0.0;
    for (int i = 1; i < argc; i++)
    {
        char *n = argv[i];
        int c;
        if (sscanf(n, "%d", &c) != 1)
        {
            printf("Error, arguments invalides\n");

            return 1;
        }
        if (c < 0)
        {
            printf("Error, arguments inféreiru à 0\n");

            return 1;
        }
        result += (1.0 / c);
    }
    printf("%f\n", (1.0 / result));

    return 0;
}