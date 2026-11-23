
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double delta(double a, double b, double c)
{
    double delta = ((b * b) - (4 * a * c));
    if (a == 0)
    {
        fprintf(stderr, "a < 0, division par 0\n");
        return EXIT_FAILURE;
    }
    if (delta < 0)
    {

        fprintf(stderr, "Delta = %g il donc est plus petit que 0. Donc aucune solutions dans R\n", delta);
        return EXIT_FAILURE;
    }
    return delta;
}

double viet(double x1, double x2, double a, double b)
{
    double c;
    x1 = (-1 * b) + sqrt(delta(a, b, c)) / 2 * a;
    x2 = (-1 * b) - sqrt(delta(a, b, c)) / 2 * a;
    printf("X1 = %lf\n", x1);
    printf("X2 = %lf\n", x2);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        fprintf(stderr, "Veuillez rentrer 3 valeurs\n");
        return EXIT_FAILURE;
    }

    for (int arg = 1; arg < argc; arg++)
    {
        char *c = argv[arg];
        double value = 0;
        if (sscanf(c, "%lg", &value) != 1)
        {
            fprintf(stderr, "Veuillez rentrer des valeurs valides\n");
            return EXIT_FAILURE;
        }
    }
    double x1;
    double x2;
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);
    printf("a = %g\n", a);
    printf("b = %g\n", b);
    printf("c = %g\n", c);

    delta(a, b, c);

    viet(x1, x2, a, b);
    return 0;
}