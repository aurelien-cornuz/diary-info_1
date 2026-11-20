/**
 * $ ./factor 360 97 1001 1
 * 360 = 2^3 * 3^2 * 5
 * 97 = 97
 * 1001 = 7 * 11 * 13
 * 1 = 1
 * 
 * $ ./factor 360
 * 360 = 
 */

#include <stdio.h>

int main(int argc, char * argv[]) {
    for (int arg = 1; arg < argc; arg++) {
        int n;
        if (sscanf(argv[arg], "%d", &n) != 1) return 2;
        printf("%d = ", n);
        int number = n;
        char *s = "";
        for (int base = 2; base * base <= n; base++) {
            int exp = 0;
            while(number % base == 0) { number /= base; exp++; }
            if (exp > 0) {
                printf("%s%d^%d", s, base, exp);
                s = " * ";
            }
        }
        if (number > 1 || n == 1) printf("%s%d", s, number);
        printf("\n");
    }
}