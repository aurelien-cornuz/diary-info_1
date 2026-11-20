#include <stdio.h>

void add_one(int *i) {
    *i += 1;
    printf("%d\n", 4 * (*i));
}

int main() {
    int k = 2;
    add_one(&k);
    printf("%d\n", k);
}