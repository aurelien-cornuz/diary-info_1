/**
 * Affiche un carré
 */
#include <stdio.h>
int main() {
    int size = 0;
    if(scanf("%d", &size) != 1) return 1;

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            putchar('*');
        }
        puts("");
    }
}