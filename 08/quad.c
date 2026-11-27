/* quadratique.c : résout a·x² + b·x + c = 0.
 * Compilation : gcc -Wall -o quadratique quadratique.c -lm */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void help(void)
{
    puts("Usage : quadratique a b c\n"
         "Résout l'équation a·x² + b·x + c = 0 (racines réelles ou complexes).\n"
         "Exemple : quadratique 1 -3 2   donne x1 = 1, x2 = 2");
}

double delta(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

void display(double a, double b, double c)
{
    printf("Équation : %g·x² %+g·x %+g = 0\n", a, b, c);
    if (a == 0) {                                   /* cas dégénéré : b·x + c = 0 */
        if (b != 0) printf("Équation linéaire, x = %g\n", -c / b);
        else        puts(c == 0 ? "Tout x est solution." : "Aucune solution.");
        return;
    }
    double d = delta(a, b, c);
    printf("Delta = %g\n", d);
    if (d > 0)
        printf("Deux racines réelles : x1 = %g, x2 = %g\n",
               (-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a));
    else if (d == 0)
        printf("Racine double : x = %g\n", -b / (2 * a) + 0.0);
    else
        printf("Deux racines complexes : x = %g ± %gi\n",
               -b / (2 * a) + 0.0, sqrt(-d) / fabs(2 * a));
}

int main(int argc, char *argv[])
{
    if (argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))) {
        help();
        return 0;
    }
    double v[3];
    char *end;
    for (int i = 0; i < 3 && argc == 4; i++) {
        v[i] = strtod(argv[i + 1], &end);
        if (end == argv[i + 1] || *end) argc = 0;   /* argument non numérique */
    }
    if (argc != 4) {
        help();
        return 1;
    }
    display(v[0], v[1], v[2]);
    return 0;
}