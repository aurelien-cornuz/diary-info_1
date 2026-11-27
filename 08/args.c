#include <stdio.h>

int read_argument(int n, char *k[]) {
    if (n < 2) return -1;
    return atoi(k[1]);
}

int main(int argc, char *argv[]) {
    int value = read_argument(argc, argv);
    printf("Valeur passée : %d\n", value);
}