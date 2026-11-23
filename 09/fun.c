#include <stdio.h>
#include <ctype.h>

void inc_digits(char *s) {
    while(*s != '\0') {
        if (isdigit(*s)) { (*s)++; }
        s++;
    }
}

int main() {
    char s[] = "Maman, j'ai 5 ans";  
    inc_digits(s);
    puts(s);
}