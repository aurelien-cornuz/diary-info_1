# Semaine 09/16

- [ ] Vendredi Labo Test (de rattrappage)
- [ ] Chaînes de caractères

## Chaînes de caractères

Une chaîne de caractère c'est une succession de caractères en mémoire. Chaque caractère
prend 8 bit et est encodé (généralement) avec la table ASCII.

Une chaîne de caractère s'adresse par son premier caractère avec un pointeur vers un 
caractère:

```c
char *s = "toto";
```

### Notation tableau

```c
a[b]    *(a + b)
```

```c
int main() {
    char *s = "salut";
    putchar(s[3]);    //  3[s]
}
```

```c
char s[] = "salut" // (a) La chaîne est modificable
char *s  = "salut" // (b) La chaîne n'est pas modifiable
```

### <string.h>

```c
long int strlen(const char *s) {
    long int count = 0;
    while(*s != '\0') { count++; s++; }
    return count;
}

long int strlen(const char *s); 
```

```c
bool isalpha(char u); // A-Z a-z
bool isdigit(char u); // 0-9 
bool ispunct(char u); // .,;.!?
bool isspace(char u); // ' \n\t\v\f'
```

### Pointer sur à partir de trois avec un *s

```c
char s[] = "abcdefghijklmnopqrstuvwxyz";
char *q = s[3];
puts(q); // defghi...
puts(&s[3]); // defghijk...
```