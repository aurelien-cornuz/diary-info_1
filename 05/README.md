# Semaine 05/16

- [ ] Lecture des arguments et de l'entrée standard
- [ ] Variables 

## Variable 

C'est quoi une variable en informatique ? 

- Une valeur 
- Un symbol (identifiant p.ex: les_pommes, the_answer, i, toto)
- Un espace mémoire réservé
- Un type de stockage (int, float, double, chaîne de caractère...)
- Une durée de vie (visibilité)
  
## Type de donnée

### Entiers

#### Non signés

```c
unsigned char
unsigned short
unsigned int 
unsigned long int
unsigned long long int 

#include <stdint.h>
uint8_t
uint16_t
uint32_t
uint64_t
```

#### Signés

```c
signed char
signed short
signed int 
signed long int
signed long long int 

#include <stdint.h>
int8_t
int16_t
int32_t
int64_t
```

### Réels (virgule flottante)

```c
float
double
long double
```

## Exemple de lecture

```c
#include <stdio.h>

int main(int argc, char * argv[]) {
    // Lecture sur les arguments
    int i = 0;    
    if (argc > 1) {
        if (sscanf(argv[1], "%d", &i) != 1) {
            printf("Erreur!\n");
            return 1;
        }
    }

    int j = 0;
    // Lecture sur l'entrée standard
    if (scanf("%d", &j) != 1) {  // Lecture au clavier
        printf("Erreur!\n");
        return 2;
    }

    // Affichage des valeurs
    printf("Valeur de i: %d\n", i);
    printf("Valeur de j: %d\n", j);
}
```

## Help et version


```c
void help() {
    printf("Version 1.2.3\n"); 
    printf("Pour utiliser ce programme... il faut... bref, de l'aide\n");
}

int main(int argc, char* argv[]) {

    if (argc > 1 && argv[1][0] == '-' && argv[1][1] === 'v') {
        printf("Version 1.2.3\n"); 
        return 0;
    }

    if (argc > 1 && (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)) {
        help();
    }
}
