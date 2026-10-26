#include <stdio.h>

void help () {
    printf("help\n");
}

int main() {
    printf("Menu: \n");
    printf("1) Pâtes carbonara\n");
    printf("2) Kebab\n");
    printf("3) McDonald\n");
    printf("4) Help\n");
    printf("5) Quitter\n");
    printf("\n>");
    int choice = 4;
    if (scanf("%d", &choice) != 1) return -1;

    switch (choice) {
        case 1: 
            printf("carbo\n");
            break;
        case 2:
            printf("kebab\n");
            break;
        case 3: 
            printf("McDonald\n");
            break;
        case 4:
            help();
            break;
        case 5: 
            return 0;
        default: 
            return -2;
    }
    
}