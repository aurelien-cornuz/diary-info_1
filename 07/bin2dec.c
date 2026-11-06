/**
 * Convertisseur binaire en décimal
 * 
 * Exemple: 
 * 
 * $./bin2dec 1001010110
 * 598
 * 
 * En cas d'erreur :
 * $ ./bin2dec salut
 * Erreur, l'entrée n'est pas un nombre binaire 
 */
#include <stdio.h>
#include <string.h>  // Pour strlen

int main(int argc, char*argv[]) {
    // Lecture de l'argument
    if (argc < 2) { 
        printf("Erreur: pas assez d'arguments\n");
        return 1;
    }
    char* binary_number = argv[1];
    const long int size = strlen(binary_number);

    // Détecte si le nombre est bien binaire
    for (int i = 0; i < size; i++) {
        char c = binary_number[i];
        if (c != '1' && c != '0') {
            printf("Erreur: ce n'est pas un nombre valide\n");
            return 2;
        }
    }

    // Convertir la valeur en décimal
    int number = 0;
    for (int i = 0; i < size; i++) {
        char bit = binary_number[i] - '0';
        printf("%hhd\n", bit);
    }

    // Afficher le nombre converti
    printf("%d\n", number);
}

