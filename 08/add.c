#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main(void) {
    printf("%d\n", add(add(3,4),add(5,6)));
    return 0;
}
