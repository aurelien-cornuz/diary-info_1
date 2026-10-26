#include <stdio.h>

int main() {
    for (int i = 0; /* pas de condition de maintien */ ;i++) {
        printf("oops %d\n", i);
    }
}

// i = i + 1;
// i += 1;
// i = 5;
// printf("%d", i++); // 5
// i = 5;
// printf("%d", ++i); // 6