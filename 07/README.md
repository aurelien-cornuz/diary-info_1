# Semaine 07/16

- [x] Exercice : conversion binaire vers décimal
- [x] Exercice : carré
- [x] L'opérateur ternaire
- [x] Priorité et associativité des opérateurs

## Opérateur ternaire

Le ternaire est un `if / else` qui produit une valeur. C'est le seul opérateur du C à trois opérandes :

```c
condition ? valeur_si_vrai : valeur_si_faux
```

Il se lit ainsi : si la condition est vraie, l'expression vaut `valeur_si_vrai`, sinon elle vaut `valeur_si_faux`. Les deux écritures suivantes sont équivalentes :

```c
// Avec if / else
int b;
if (a == 2) {
    b = 100;
} else {
    b = 200;
}

// Avec le ternaire
int b = (a == 2) ? 100 : 200;
```

Comme le ternaire est une expression, on peut l'employer partout où une valeur est attendue, par exemple dans un argument de `printf` :

```c
printf("Vous avez %d message%s\n", n, (n > 1) ? "s" : "");
```

Il convient à un choix entre deux valeurs simples, pour initialiser une variable ou fournir un argument. Dès qu'il s'agit d'exécuter des instructions différentes selon le cas, un `if / else` reste le bon outil, et imbriquer plusieurs ternaires rend vite le code illisible.

### Le test inutile

Une condition est déjà un booléen. Écrire « si c'est vrai, retourne vrai, sinon retourne faux » est donc redondant :

```c
// Maladroit
if (error == true) {
    return true;
} else {
    return false;
}

// Tout aussi maladroit
return error == true ? true : false;

// Suffisant
return error;
```

## Priorité des opérateurs

À l'école, on apprend que la multiplication passe avant l'addition, ce qui donne :

```c
2 + 3 * 5 + 8 / 2   // = 2 + 15 + 4 = 21
```

Le C compte bien plus de quatre opérateurs (`=`, `?:`, `^`, `%`, `&&`, `<<`, etc.) et personne ne les retient tous. La fiche de référence jaune donne pour chacun deux informations. La première est sa priorité : plus le nombre est petit, plus l'opérateur est évalué tôt. La seconde est son associativité, qui indique dans quel sens regrouper deux opérateurs de même priorité. De gauche à droite, `a - b - c` se lit `(a - b) - c`. De droite à gauche, `a = b = c` se lit `a = (b = c)`.

Dans le doute, mieux vaut ajouter des parenthèses : elles ne coûtent rien et épargnent au lecteur, vous compris dans six mois, d'avoir à consulter la table.

### Extrait de la table

| Priorité | Opérateurs | Associativité |
|:--------:|------------|:-------------:|
| 3 | `*`  `/`  `%` | gauche → droite |
| 4 | `+`  `-` | gauche → droite |
| 9 | `^` (XOR bit à bit) | gauche → droite |
| 13 | `?:` (ternaire) | droite → gauche |
| 14 | `=` | droite → gauche |

Le numéro exact dépend de la fiche utilisée, seul l'ordre relatif compte.

### Exemple pas à pas

Prenons l'expression suivante :

```c
a = b + c * d ^ e % f ? g : h ? i : j;
```

La méthode consiste à ajouter des parenthèses en partant de l'opérateur le plus prioritaire, jusqu'à ce que tout soit parenthésé. Les opérateurs `*` et `%` (priorité 3) passent en premier :

```c
a = b + (c * d) ^ (e % f) ? g : h ? i : j;
```

Vient ensuite `+` (priorité 4), puis `^` (priorité 9) :

```c
a = (b + (c * d)) ^ (e % f) ? g : h ? i : j;
a = ((b + (c * d)) ^ (e % f)) ? g : h ? i : j;
```

Le ternaire (priorité 13) s'associe de droite à gauche : c'est donc le dernier `? :` qui se regroupe en premier, puis celui qui l'englobe.

```c
a = ((b + (c * d)) ^ (e % f)) ? g : (h ? i : j);
a = (((b + (c * d)) ^ (e % f)) ? g : (h ? i : j));
```

L'affectation `=` (priorité 14) passe en dernier : on range simplement le résultat dans `a`.

### À vous de jouer

Parenthésez les expressions suivantes, puis vérifiez votre réponse avec un `printf` :

```c
int x = 2 + 3 * 5 + 8 / 2;
int y = 10 - 4 - 3;          // associatif de gauche à droite
int z = 1 + 2 << 3;          // `<<` est moins prioritaire que `+`
```

## Exercice : conversion binaire vers décimal

Il s'agit d'écrire un programme qui convertit un nombre binaire en décimal. Il reçoit en argument une chaîne de caractères représentant le nombre binaire et affiche sa valeur décimale.

```bash
./bin2dec 1001010110
598

./bin2dec 101
5

./bin2dec salut
Erreur, l'entrée n'est pas un nombre binaire
```

### Rappel sur la numération binaire

Chaque chiffre (ou bit) a pour poids une puissance de 2, en partant de la droite :

| bit | 1 | 0 | 1 |
|-----|---|---|---|
| poids | 2² = 4 | 2¹ = 2 | 2⁰ = 1 |

Ainsi `101` vaut 1×4 + 0×2 + 1×1, soit 5.

### Deux astuces

Un caractère n'est pas un nombre. Le caractère `'1'` a pour code ASCII 49, et non 1. Pour obtenir la valeur du chiffre, on soustrait le code de `'0'` :

```c
int bit = c - '0';   // '0' → 0, '1' → 1
```

Il n'est par ailleurs pas nécessaire de calculer des puissances de 2. En lisant la chaîne de gauche à droite, on double le résultat courant à chaque nouveau bit, puis on lui ajoute ce bit. Voici le déroulement pour `101` :

| bit lu | calcul | `number` |
|:------:|--------|:--------:|
| (départ) | | 0 |
| 1 | 0 × 2 + 1 | 1 |
| 0 | 1 × 2 + 0 | 2 |
| 1 | 2 × 2 + 1 | 5 |

En C, cela s'écrit `number = number * 2 + bit;`.

### Marche à suivre

On commence par écrire le corps de `main` et par vérifier que le nombre d'arguments (`argc`) est correct. On contrôle ensuite que la chaîne ne contient que des `'0'` et des `'1'`, puis on construit le nombre en appliquant la seconde astuce, et on l'affiche. Voici un code de départ :

```c
#include <stdio.h>
#include <string.h>  // pour strlen

int main(int argc, char *argv[]) {
    char *number = argv[1];

    const long int size = strlen(number);

    for (int i = 0; i < size; i++) {
        char c = number[i];
        printf("%c ", c);
    }
}
```

La solution se trouve dans [bin2dec.c](bin2dec.c).

## Exercice : affichage d'un carré

L'idée est d'imbriquer deux boucles pour afficher un carré de côté N.

```bash
echo 5 | ./square
*****
*****
*****
*****
*****
```

N est lu sur l'entrée standard avec `scanf`. Le `echo 5 |` évite simplement d'avoir à taper la valeur au clavier.

### Principe

La boucle extérieure (`row`) s'exécute N fois et chaque itération produit une ligne. La boucle intérieure (`col`) s'exécute elle aussi N fois et chaque itération affiche une étoile. À la fin de chaque ligne, on passe à la suivante.

```text
row = 0 :  col = 0..4  →  * * * * *  ↵
row = 1 :  col = 0..4  →  * * * * *  ↵
...
```

La solution se trouve dans [square.c](square.c).

### Pour aller plus loin

Modifiez le programme pour afficher d'abord un rectangle, dont la largeur et la hauteur diffèrent, puis un triangle rectangle, en faisant dépendre la boucle intérieure de `row`. Essayez enfin un carré vide, dont seul le contour est dessiné.
