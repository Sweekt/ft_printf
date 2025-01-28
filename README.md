# ft\_printf

**ft\_printf** est un projet du cursus de l'école 42. L'objectif est de recréer une version simplifiée de la fonction standard `printf` en C. Ce projet permet de se familiariser avec la gestion des arguments variadiques, le formatage de texte et l'écriture modulaire.

---

## Table des matières

1. [Description](#description)
2. [Fonctionnalités](#fonctionnalités)
3. [Installation](#installation)
4. [Utilisation](#utilisation)
5. [Structure du projet](#structure-du-projet)
6. [Tests](#tests)
7. [Ressources](#ressources)
8. [Auteur](#auteur)

---

## Description

Le projet ft\_printf consiste à implémenter une fonction capable de produire une sortie formatée similaire à `printf`. Elle doit gérer plusieurs spécificateurs de format et être capable de traiter des arguments variadiques.

Ce projet vous permet d’améliorer vos compétences en :

- Manipulation d’arguments variadiques avec `va_list`.
- Gestion de formats complexes.
- Écriture d’un code modulaire et optimisé.

---

## Fonctionnalités

La fonction ft\_printf doit gérer les spécificateurs suivants :

- **%c** : Affiche un caractère.
- **%s** : Affiche une chaîne de caractères.
- **%p** : Affiche un pointeur en notation hexadécimale.
- **%d** ou **%i** : Affiche un entier signé en base 10.
- **%u** : Affiche un entier non signé en base 10.
- **%x** ou **%X** : Affiche un entier non signé en base 16 (minuscule ou majuscule).
- **%%** : Affiche un symbole `%`.

Prototype de la fonction :

```c
int ft_printf(const char *format, ...);
```

---

## Installation

1. Clonez ce dépôt :

   ```bash
   git clone https://github.com/votre-utilisateur/ft_printf.git
   cd ft_printf
   ```

2. Compilez la bibliothèque :

   ```bash
   make
   ```

3. Une fois compilée, la bibliothèque `libftprintf.a` sera générée.

---

## Utilisation

Pour utiliser ft\_printf dans vos projets :

1. Ajoutez `libftprintf.a` à votre commande de compilation :

   ```bash
   gcc -Wall -Wextra -Werror main.c -L. -lftprintf -o programme
   ```

2. Incluez le fichier d'en-tête dans vos fichiers sources :

   ```c
   #include "ft_printf.h"
   ```

Exemple d'utilisation :

```c
#include "ft_printf.h"

int main(void) {
    ft_printf("Bonjour, %s !\n", "monde");
    ft_printf("Hexadécimal : %x\n", 255);
    return 0;
}
```

---

## Structure du projet

```
ft_printf/
|-- ft_printf.c         # Fonction principale
|-- ft_printf_utils.c   # Fonctions utilitaires
|-- ft_printf.h         # Header principal
|-- Makefile            # Automatisation de la compilation
|-- README.md           # Documentation
```

---

## Tests

1. Testez la fonction avec des cas simples et complexes :

   ```bash
   ./programme
   ```

2. Utilisez des frameworks de test comme :

   - [Printf Tester](https://github.com/Tripouille/printfTester)
   - [42TESTERS-PRINTF](https://github.com/Mazoise/42TESTERS-PRINTF)

---

## Ressources

- [Documentation du projet ft\_printf (42)](https://projects.intra.42.fr/projects/ft_printf)
- [Manpages des fonctions variadiques](https://man7.org/linux/man-pages/)
- [Printf Tester](https://github.com/Tripouille/printfTester)

---

## Auteur

- **Benjamin "Sweekt" Roy** ([beroy@student.42lyon.fr](mailto:beroy@student.42lyon.fr))

- **Votre Nom** ([votre-login@42.fr](mailto\:votre-login@42.fr))

---

