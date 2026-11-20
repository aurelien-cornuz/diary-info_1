# Semaine 08/16

- [x] Discussion sur le labo test
- [x] Fonctions
- [x] Passage par adresse

## Fonctions

### C'est quoi une fonction ?

Une fonction est un morceau de programme auquel on donne un nom. On lui fournit des valeurs en entrée (les **arguments**), elle effectue un travail et elle renvoie éventuellement un résultat (la **valeur de retour**).

On peut la voir comme une machine : on met quelque chose dedans, on récupère quelque chose à la sortie, sans avoir besoin de savoir comment elle fonctionne à l'intérieur. Vous en utilisez déjà depuis le début du cours : `printf`, `scanf`, `sqrt` sont des fonctions écrites par d'autres. Et `main` elle-même est une fonction, celle que le système appelle au lancement du programme.

Écrire ses propres fonctions permet :

- de **ne pas se répéter** : un calcul écrit une seule fois peut être utilisé partout ;
- de **découper** un problème compliqué en petits problèmes simples, chacun avec un nom explicite ;
- de **tester** et de corriger chaque morceau séparément.

### La syntaxe

```c
int add(int a, int b) {
    return a + b;
}
```

Une fonction se compose de quatre éléments :

| Élément | Dans l'exemple | Rôle |
|---------|----------------|------|
| Type de retour | `int` | Le type de la valeur renvoyée. `void` si la fonction ne renvoie rien. |
| Nom | `add` | Comment on l'appelle. Un verbe qui décrit ce qu'elle fait est un bon choix. |
| Paramètres | `(int a, int b)` | Les variables qui recevront les arguments, chacune avec son type. `(void)` si aucun. |
| Corps | `{ return a + b; }` | Les instructions exécutées. |

Le mot-clé `return` termine immédiatement la fonction et renvoie la valeur au code qui l'a appelée. Une fonction `void` peut utiliser `return;` sans valeur pour sortir plus tôt.

Pour **appeler** la fonction, on écrit son nom suivi des arguments entre parenthèses :

```c
int r = add(3, 4);   // r vaut 7
```

Attention au vocabulaire : les **paramètres** sont les variables déclarées dans la définition (`a` et `b`), les **arguments** sont les valeurs qu'on donne à l'appel (`3` et `4`).

En C, une fonction doit être connue avant d'être utilisée. C'est pourquoi on l'écrit **au-dessus** de `main`. Sinon, il faut annoncer son existence en haut du fichier par un **prototype**, c'est-à-dire sa première ligne suivie d'un point-virgule :

```c
int add(int a, int b);   // prototype : "cette fonction existe, elle est définie plus bas"
```

C'est exactement ce que contiennent les fichiers `.h` comme `stdio.h` : les prototypes de `printf`, `scanf`, etc.

### Ce qui se passe lors d'un appel : la pile

Pour comprendre comment les valeurs circulent entre l'appelant et la fonction, il faut connaître la **pile** (*stack*). C'est une zone de la mémoire qui fonctionne comme une pile d'assiettes : on dépose en haut, on retire par le haut.

Voici le mécanisme, simplifié, pour `r = add(3, 4);` :

1. **L'appelant dépose les arguments sur la pile** : `3` et `4`.
2. **La fonction s'exécute.** Elle trouve ses paramètres `a` et `b` sur la pile, ce sont des **copies** des valeurs données.
3. **Elle fait son travail** et dépose le résultat `7` sur la pile.
4. **L'appelant récupère le résultat** et le range dans `r`. Tout ce que la fonction avait déposé disparaît.

```text
   1. appel          2-3. exécution        4. retour

                     ┌─────────┐
                     │ résultat│ = 7
   ┌─────────┐       ├─────────┤
   │  b = 4  │       │  b = 4  │
   ├─────────┤       ├─────────┤
   │  a = 3  │       │  a = 3  │           ┌─────────┐
   ├─────────┤       ├─────────┤           │  r = 7  │
   │  main   │       │  main   │           │  main   │
   └─────────┘       └─────────┘           └─────────┘
```

Deux conséquences importantes :

- Les variables d'une fonction (paramètres et variables déclarées dedans) sont **locales** : elles n'existent que pendant l'exécution de la fonction et disparaissent ensuite.
- La fonction travaille sur des **copies**. Si elle modifie `a`, la variable de l'appelant n'est pas touchée. On appelle cela le **passage par valeur**.

### Exemples vus en classe

#### Appels imbriqués : [add.c](add.c)

```c
printf("%d\n", add(add(3, 4), add(5, 6)));
```

Un appel de fonction est une expression : il a une valeur, on peut donc l'utiliser comme argument d'une autre fonction. Avant d'appeler le `add` extérieur, il faut connaître ses arguments. Le programme évalue donc d'abord `add(3, 4)` qui vaut `7` et `add(5, 6)` qui vaut `11`, puis `add(7, 11)` qui vaut `18`, et enfin `printf` affiche `18`.

#### `main` est une fonction comme les autres : [args.c](args.c)

```c
int main(int argc, char *argv[])
```

`main` reçoit elle aussi des paramètres : ce sont les arguments écrits dans le terminal au lancement du programme.

- `argc` (*argument count*) est le nombre d'arguments, nom du programme compris.
- `argv` (*argument vector*) est un tableau de chaînes de caractères : `argv[0]` est le nom du programme, `argv[1]` le premier argument, etc.

```console
$ ./args 42
Valeur passée : 42
```

Ici `argc` vaut `2`, `argv[0]` vaut `"./args"` et `argv[1]` vaut `"42"`. Attention, `"42"` est du **texte** : la fonction `atoi` (déclarée dans `stdlib.h`) le convertit en nombre entier.

L'exemple montre aussi qu'on peut transmettre `argc` et `argv` à une autre fonction, `read_argument`, qui se charge de vérifier qu'un argument est bien présent et de le convertir. Le `main` reste court et lisible.

La valeur renvoyée par `main` est transmise au système : `0` signifie que tout s'est bien passé, une autre valeur signale une erreur.

#### Une fonction qui s'appelle elle-même : [fib.c](fib.c)

La suite de Fibonacci se définit ainsi : les deux premiers termes valent 1, et chaque terme suivant est la somme des deux précédents (1, 1, 2, 3, 5, 8, 13, ...). Cette définition se traduit presque mot pour mot en C :

```c
int fib(int n) {
    if (n == 1 || n == 2) return 1;      // cas de base
    return fib(n - 1) + fib(n - 2);      // appel récursif
}
```

Une fonction qui s'appelle elle-même est dite **récursive**. Cela fonctionne grâce à la pile : chaque appel dépose ses propres arguments, donc chaque `fib` a son propre `n`, indépendant des autres.

```text
fib(4)
├── fib(3)
│   ├── fib(2) → 1
│   └── fib(1) → 1
│   = 2
└── fib(2) → 1
= 3
```

Une fonction récursive a toujours besoin d'un **cas de base** qui s'arrête sans se rappeler. Sans lui, les appels s'empilent indéfiniment jusqu'à ce que la pile soit pleine et que le programme plante (*stack overflow*).

## Passage par adresse

### Le problème

Puisqu'une fonction reçoit des copies, elle ne peut pas modifier les variables de l'appelant :

```c
void add_one(int i) {
    i += 1;            // modifie la copie seulement
}

int main(void) {
    int k = 2;
    add_one(k);
    printf("%d\n", k);   // affiche 2, k n'a pas changé
}
```

Et une fonction ne peut renvoyer qu'une seule valeur avec `return`. Comment faire, alors, pour qu'une fonction modifie une variable, ou fournisse plusieurs résultats ?

### La solution : donner l'adresse

Chaque variable est rangée quelque part en mémoire, à une **adresse**. Au lieu de donner à la fonction une copie de la valeur, on lui donne l'adresse de la variable. La fonction sait alors *où* se trouve la variable d'origine et peut aller la modifier directement.

C'est l'exemple [address.c](address.c) :

```c
void add_one(int *i) {
    *i += 1;
    printf("%d\n", 4 * (*i));
}

int main() {
    int k = 2;
    add_one(&k);
    printf("%d\n", k);
}
```

Trois notations à retenir :

| Notation | Où | Signification |
|----------|----|---------------|
| `&k` | à l'appel | « l'adresse de `k` » |
| `int *i` | dans les paramètres | `i` est un **pointeur** : une variable qui contient l'adresse d'un `int` |
| `*i` | dans la fonction | « la valeur qui se trouve à l'adresse `i` », c'est-à-dire `k` lui-même |

Déroulement :

1. `main` dépose sur la pile **l'adresse** de `k`, et non sa valeur.
2. `add_one` reçoit cette adresse dans `i`. `*i += 1` va à cette adresse et ajoute 1 : `k` vaut maintenant `3`.
3. La fonction affiche `4 * 3`, soit `12`.
4. De retour dans `main`, `k` vaut bien `3`.

```console
$ ./address
12
3
```

Une image : passer par valeur, c'est donner une **photocopie** d'un document, on peut griffonner dessus sans toucher l'original. Passer par adresse, c'est donner **l'adresse du bureau** où se trouve l'original : on peut aller le modifier.

### Vous l'utilisiez déjà sans le savoir

C'est pour cette raison qu'on écrit `&` devant les variables dans `scanf` :

```c
int n;
scanf("%d", &n);
```

`scanf` doit écrire la valeur lue *dans* `n`. Si on lui donnait `n` (une copie de sa valeur), elle ne pourrait pas la modifier. On lui donne donc l'adresse `&n`. Oublier le `&` est une erreur classique : le programme compile (avec un avertissement) puis plante ou affiche n'importe quoi.

### En résumé

| | Passage par valeur | Passage par adresse |
|---|---|---|
| À l'appel | `f(k)` | `f(&k)` |
| Paramètre | `int x` | `int *x` |
| La fonction reçoit | une copie de la valeur | l'adresse de la variable |
| Peut modifier `k` ? | non | oui, via `*x` |
| Usage | cas général | modifier une variable, renvoyer plusieurs résultats |

## Feedback des étudiants sur le labo test

### Difficulté et durée

- Le test a été jugé très difficile, nettement plus que le labo 6, et infaisable en 1h30.
- Personne ne s'attendait à ce niveau de difficulté.
- Le stress du test s'ajoute : on perd ses moyens.

### Décalage avec le cours et les labos

- Plusieurs notions étaient nouvelles ou trop peu exercées : plusieurs arguments dans `sscanf`, nombre d'arguments quelconque, `EOF`, nombres premiers.
- Certaines notions ont été montrées en classe, mais sans que l'accent soit mis dessus (utilisation de la boucle, par exemple).
- Le test ressemblait peu aux labos faits en classe : ceux qui ont révisé à partir des labos ont été pris de court.
- Les rappels théoriques en fin de donnée n'aident pas : on n'est pas là pour apprendre pendant le test.
- Il aurait fallu connaître la feuille jaune par cœur.
- Le lien entre la théorie et les labos manque (en Python, chaque labo va avec sa théorie) : on ne sait pas sur quoi se concentrer.
- Certains ont l'impression d'apprendre à la maison avec l'IA plutôt qu'en cours.

### Compréhension de la donnée

- C'est le problème principal pour plusieurs étudiants : donnée relue plusieurs fois sans comprendre ce qui était attendu.
- Comprendre la démarche a pris beaucoup de temps, surtout pour ceux qui partent de zéro en programmation.
- La difficulté est plus grande pour les étudiants dont le français n'est pas la langue maternelle.

### Usage de l'IA

- Plusieurs étudiants s'appuient sur l'IA pour faire leurs labos (gain de temps, théorie pas maîtrisée) et n'arrivent pas à travailler seuls : sans IA, le test est dur.
- Le reproche d'avoir utilisé un LLM sans travailler a été mal reçu : certains font tout à la main et ne confient au LLM que la dernière passe, pour obtenir la note maximale.
- La comparaison avec la volée 2019 n'a pas été appréciée.

### Environnement technique (SEB)

- La compilation avec `gcc` ne fonctionnait pas.
- Le bug du copier-coller a pénalisé les étudiants.
- Les raccourcis clavier habituels n'étaient pas disponibles.
- Impossible d'allumer le rétroéclairage du clavier sous SEB.
- Le format `clang-format` imposé est déroutant quand on a l'habitude d'un autre.

### Méthode d'évaluation

- Un code qui ne fonctionne pas ne vaut rien : avec peu de tests qui passent, la démarche n'est pas récompensée, même quand on s'approche de la solution.
- Suggestion : fournir la formule mathématique à traduire en code, pour obtenir au moins une fonction qui affiche quelque chose sans maîtriser les nombres premiers.
- Il y a beaucoup de critères.
- Sur le labo PCB, tous les tests passent et la note reste mauvaise (regarder le labo de M. Bouzas : tous les tests passent, pas la moyenne).
- Commentaires en anglais : ils rapportent plus de points, mais un anglais approximatif est pénalisé.
- Recevoir une note indicative, puis une autre, est frustrant : une seule note serait préférable.

### Demandes

- Un labo test à blanc pour se mettre dans le bain.
- Être plus guidés : ce format de test est nouveau.
- Recevoir des indications sur les points à travailler avant les labos.

## Décisions

- On fera 3 labos tests on prendra les deux meilleures des trois.
- Test en classe de SEB + Copier coller etc... Pour valider la config de tous
- Donner des indications sur le contenu du labo avant le labo
- Définir une date
- Vérifier que alt-s fonctionne sur SEB
- Pas de format dans le labo test !

