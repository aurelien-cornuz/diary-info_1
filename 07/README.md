
```c
./bin2dec 1001010110
598

./bin2dec 101
5

./bin2dec salut
Erreur, l'entrée n'est pas un nombre binaire 
```

1. Écrire le corps du programme `main`
2. Vérifier que le nombre d'arguments correct
3. Vérifier que la chaîne de caractère ne comporte que des '0', et '1'
4. Construire le nombre à partir de la chaîne

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
