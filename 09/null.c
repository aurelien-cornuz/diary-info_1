#include <stdio.h>


/**
 * '0'  = 0x30
 * '\0' = 0x00
 * 0    = 0x00
 * NULL = 0x00
 * 
 * char *s = "ab";  // 97 98 00
 *            ^
 * (*s)++; //"bb"   // 98 98 00
 *            ^
 * s++     //"bb"
 *             ^
 */
void puts_(char *s) {
    while(*s != '\0') putchar(*(s++));
    putchar('\n');
}

int main() {
    puts_("Je vais te révéler un secret\0La terre est ronde");
}