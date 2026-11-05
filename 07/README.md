# Semaine 07/16

- [ ] Conversion binaire vers décimal

## Exercice : Conversion binaire vers décimal

On souhaite écrire un programme qui convertit un nombre binaire en décimal. Le programme prendra en argument une chaîne de caractères représentant un nombre binaire et affichera le nombre décimal correspondant.

```bash
./bin2dec 1001010110
598

./bin2dec 101
5

./bin2dec salut
Erreur, l'entrée n'est pas un nombre binaire
```

### Étapes de réalisation

1. Écrire le corps du programme `main`
2. Vérifier que le nombre d'arguments correct
3. Vérifier que la chaîne de caractère ne comporte que des '0', et '1'
4. Construire le nombre à partir de la chaîne

Voici un code de départ pour vous aider à démarrer:

```c
int main(int argc, char*argv[]) {
    char* number = argv[1];

    const long int size = strlen(number);

    for (int i = 0; i < size; i++) {
        char c = number[i];
        printf("%c ", c);
    }
}
```

Vous trouverez la solution dans [bin2dec.c](bin2dec.c)

## Exercice : affichage d'un carré

L'idée est d'ici d'imbriquer des boucles pour afficher un carré de taille N, où N est donné en argument.

```bash
./square 5
*****
*****
*****
*****
*****
```

On utilise une boucle dans une boucle pour afficher les lignes et les colonnes du carré. Vous trouverez la solution dans [square.c](square.c)
