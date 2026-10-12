#include <stdio.h>

int main(int argc, char * argv[]) {
    // Lecture sur les arguments
    int i = 0;
    if (argc > 1) {
        if (sscanf(argv[1], "%d", &i) != 1) {
            printf("Erreur!\n");
            return 1;
        }
    }

    // Lecture sur l'entrée standard
    int j = 0;
    if (scanf("%d", &j) != 1) {  // Lecture au clavier
        printf("Erreur!\n");
        return 2;
    }

    // Affichage des valeurs
    printf("Valeur de i: %d\n", i);
    printf("Valeur de j: %d\n", j);
}