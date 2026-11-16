#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char decimal[10000];
    char binaire[40000];
    size_t longueur_binaire = 0;

    printf("Entrez un entier décimal positif : ");

    if (scanf("%9999s", decimal) != 1) {
        fprintf(stderr, "Erreur de lecture.\n");
        return 1;
    }

    /* Vérifier que l'entrée ne contient que des chiffres */
    for (size_t i = 0; decimal[i] != '\0'; i++) {
        if (!isdigit((unsigned char)decimal[i])) {
            fprintf(stderr, "Entrée invalide : utilisez des chiffres positifs.\n");
            return 1;
        }
    }

    /*
     * Conversion répétée : division de la chaîne décimale par 2.
     * Chaque reste donne un bit, du moins significatif au plus significatif.
     */
    while (!(decimal[0] == '0' && decimal[1] == '\0')) {
        int reste = 0;

        for (size_t i = 0; decimal[i] != '\0'; i++) {
            int valeur = reste * 10 + (decimal[i] - '0');
            decimal[i] = (char)('0' + valeur / 2);
            reste = valeur % 2;
        }

        /* Supprimer les zéros au début du quotient */
        size_t debut = 0;
        while (decimal[debut] == '0' && decimal[debut + 1] != '\0')
            debut++;

        if (debut > 0)
            memmove(decimal, decimal + debut, strlen(decimal + debut) + 1);

        binaire[longueur_binaire++] = (char)('0' + reste);
    }

    if (longueur_binaire == 0)
        binaire[longueur_binaire++] = '0';

    printf("Binaire : ");
    while (longueur_binaire > 0)
        putchar(binaire[--longueur_binaire]);
    putchar('\n');

    return 0;
}