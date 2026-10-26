# Semaine 06/16

- [ ] Structures de contrôle
  - [ ] if / else
  - [ ] if / else if / else
  - [ ] switch / case
  - [ ] while
  - [ ] for
  - [ ] do / while
  - [ ] break / continue
  - [ ] goto

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
