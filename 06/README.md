# Semaine 06/16

- [x] Structures de contrôle
  - [x] if / else
  - [x] if / else if / else
  - [x] switch / case
  - [x] while
  - [x] for
  - [x] do / while
  - [x] break
  - [x] goto

## Structures de contrôle

En C il existe la notion de structures de contrôle qui permettent de modifier le flux d'exécution d'un programme, soit les choix, soit les boucles.

## Choix

Une décision se fait avec l'instruction `if` qui permet d'exécuter un bloc de code si une condition est vraie. On peut également ajouter un bloc `else` pour exécuter un autre bloc de code si la condition est fausse.

```c
if ( /* condition */ ) { /* code si vrai */ }
if ( /* condition */ ) { /* code si vrai */ } else { /* code si faux */ }
```

Imaginons deux conditions `a` et `b`, on peut les combiner avec les opérateurs logiques `&&` (et) et `||` (ou). Pour simplifier l'écriture et éviter les blocs imbriqués, on peut combiner les conditions dans un seul `if`.

```c
bool a = true;
bool b = false;

if ( a )
{
    if ( b )
    {
        printf("true");
    }
}

if ( a && b )
{
  printf("true");
}
```

Il existe dans d'autres langages des instructions `elif` ou `elseif` qui permettent de chaîner les conditions. En C elle n'existe pas, mais on peut utiliser dans un `else` un autre `if` pour obtenir le même résultat. On parle alors de `else if`.

```c
if ( /* condition */ ) {
    /* code si vrai */
} else {
    if ( /* condition */ ) {
        /* code si vrai */
    }
}
else {
    /* code si faux */
}
```

On constate que le premier bloc `else` ne contient qu'un seul `if`, on peut donc l'écrire plus simplement sans les accolades. Puis pour améiorer la lecture, mettre le `if` sur la même ligne que le `else`.

```c
if ( /* condition */ ) {
    /* code si vrai */
} else if ( /* condition */ ) {
    /* code si vrai */
} else {
    /* code si faux */
}
```

Le `else` final reste optionnel, on peut donc l'omettre si on n'a pas de code à exécuter dans ce cas.

## Boucles

Une boucle est une structure de contrôle qui permet d'exécuter un bloc de code plusieurs fois. Il existe plusieurs types de boucles en C, chacune ayant ses propres caractéristiques et utilisations.

### Goto

Originellement en programmation une boucle était effectuée avec l'instruction `goto`, qui permet de sauter à une autre partie du code. En C on peut labelliser une instruction avec un nom suivi de `:`. Par exemple on peut numéroter les lignes d'un programme:

```c
#include <stdio.h>

int main() {
    10: int i = 0;
    20: printf("%d\n", i);
    30: i++;
    40: if (i < 10) goto 20;
}
```

Cela fonctionne très bien, mais ce n'est pas la bonne approche, on pourrait simplifier en ne conservant qu'un label et le nommer:

```c
#include <stdio.h>

int main() {
    int i = 0;
    loop: printf("%d\n", i);
    i++;
    if (i < 10) goto loop;
}
```

En pratique on n'utilise jamais `goto`, le C est mieux fichu que ça et propose des structures de contrôle plus adaptées pour gérer les boucles. Il existe trois types de boucles en C: `for`, `while` et `do while`. Chacune a ses propres caractéristiques et utilisations.

### Boucle for

On utilise cette boucle si on connaît a priori le nombre d'exécution. Elle est composée de trois parties: l'initialisation, la condition et l'incrémentation. La syntaxe est la suivante:

```c
for (initialisation; condition; incrémentation) {
    /* code à exécuter */
}
```

Par exemple si on veut afficher les nombres de 0 à 9, on peut écrire:

```c
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}
```

On peut également compter dans l'autre sens:

```c
for (int i = 10; i > 0; i--) {
    printf("%d\n", i);
}
```

On peut aussi omettre l'initialisation, la condition ou l'incrémentation, mais il faut alors les gérer à l'intérieur de la boucle. Par exemple:

```c
int i = 0;
for (; i < 10; ) {
    printf("%d\n", i);
    i++;
}
```

Ou même créer une boucle infinie:

```c
for (;;) {
    /* code à exécuter */
}
```

### Boucle while

La boucle *while* ou en français "tant que" est utilisée lorsque l'on ne connaît pas le nombre d'exécutions à l'avance. Elle s'exécute tant qu'une condition est vraie. La syntaxe est la suivante:

```c
int i = 0;
while (i < 10) { /*code*/; i++; }
```

### Boucle do-while

La boucle *do-while* est similaire à la boucle *while*, mais elle garantit que le bloc de code sera exécuté au moins une fois, même si la condition est fausse dès le départ. La syntaxe est la suivante:

```c
int i = 0;
do { /*code*/; i++; } while ( i < 10 )
```

## Exercice : deviner un nombre

Réaliser un programme qui se comporte comme suit:

```bash
$ ./guess 100
J'ai choisi un nombre entre 1 et 100 quel est-il ?
> 50
C'est plus grand !
> 75
C'est plus petit !
> 63
C'est plus grand !
> 69
Bravo ! Vous avez trouvé le nombre 69 en 4 essais.
```

> Pour générer une valeur aléatoire entre 1 et N utilisez la fonction `rand()` de la bibliothèque standard C. N'oubliez pas d'initialiser le générateur de nombres aléatoires avec `srand(time(NULL))` pour obtenir des résultats différents à chaque exécution.
>
> ```c
> #include <stdlib.h>
> #include <time.h>
>
> int main() {
>     srand(time(NULL));
>     int random_number = rand() % N + 1;
>     ...
> }
> ```

## Exercice : Triangle

### Première partie : triangle simple

Écrire un programme qui dessine un triangle rectangle de hauteur et de largeur N où N est donné en argument.

```bash
./triangle 5
*
**
***
****
*****
```

### Deuxième partie : mirroir horizontal

Si la valeur transmise est négative, on aligne le triangle à droite:

```bash
./triangle -5
    *
   **
  ***
 ****
*****
```

La solution est disponible [ici](triangle.c)
