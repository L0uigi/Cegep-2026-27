# Projet de session — Solitaire

## 1. Présentation

Vous devez programmer une version **console** du jeu de solitaire à billes.

Ce projet vise à réinvestir les notions suivantes :

- `struct`
- fonctions
- passage de paramètres par **valeur**, **référence** et **pointeur**
- tableaux à 2 dimensions
- allocation dynamique
- organisation d’un projet en **plusieurs fichiers**

Le projet doit être réalisé **sans classe**. L’utilisation de `struct` est attendue.

## 2. Description du jeu

Le jeu solitaire est un jeu de patience très simple dans lequel des billes placées sur un plateau doivent être retirées. L’objectif est qu’il ne reste qu’une seule bille à la fin du jeu.

#### Règles

- Il n’est possible de se déplacer qu’à l’horizontal et à la verticale. Aucune diagonale n’est permise dans les règles de base.
- Une bille ne peut se déplacer que si elle passe par-dessus une seule bille et qu’elle arrive dans un trou, c’est-à-dire sur une case où il n’y a pas de bille.
- Lorsqu’on passe par-dessus une bille, la bille par-dessus laquelle on est passé est retirée du jeu.
- On ne peut bouger qu’une seule bille à la fois.

#### Exemple de déplacement

La bille à gauche est celle qui est déplacée. On remarque que la bille qui était au centre disparaît après le déplacement.

Avant : `● ● ○`  
Après : `○ ○ ●`

Légende :

- `●` = bille
- `○` = trou

#### Formulation d’un coup valide

Un coup est valide seulement si toutes les conditions suivantes sont respectées :

1. La case de départ contient une bille.
2. La bille se déplace **horizontalement ou verticalement seulement**.
3. Le déplacement est de **deux cases exactement**.
4. La case située entre le départ et l’arrivée contient **une bille**.
5. La case d’arrivée est **vide**.
6. Après le déplacement :
   - la case de départ devient `VIDE`
   - la bille sautée est retirée du jeu
   - la case d’arrivée devient `BILLE`

#### Déplacements interdits

Les actions suivantes sont interdites :

- se déplacer en diagonale
- sauter par-dessus zéro bille
- sauter par-dessus plus d’une bille
- arriver sur une case occupée
- arriver sur une case non jouable

## 3. Fin de la partie et victoire

La partie se termine lorsqu’il n’est plus possible d’effectuer de coup valide.

### Résultats possibles

- **Victoire de base** : terminer avec exactement **une seule bille**
- **Victoire parfaite** : terminer avec exactement **une seule bille au centre**
- **Défaite** : aucun coup n’est possible et il reste plus d’une bille

Pour démarrer une partie standard, il faut remplir le plateau avec les billes puis retirer celle du centre.

## 4. Variations du plateau

Le plateau logique est toujours un tableau de taille **7 x 7**.

Certaines cases du tableau représentent des positions inexistantes ou inutilisables dans le jeu. Ces cases doivent être identifiées par la valeur :

- `BILLE`
- `VIDE`
- `NON_DISPO`

Important : il est **interdit** de déplacer la main sur une case `NON_DISPO`.

### Style anglais

Le style anglais est en croix avec **33 trous**.

|   |   |   |   |   |   |   |
| - | - | - | - | - | - | - |
|   |   | ● | ● | ● |   |   |
|   |   | ● | ● | ● |   |   |
| ● | ● | ● | ● | ● | ● | ● |
| ● | ● | ● | ○ | ● | ● | ● |
| ● | ● | ● | ● | ● | ● | ● |
|   |   | ● | ● | ● |   |   |
|   |   | ● | ● | ● |   |   |

### Style européen / français

Le style français ajoute 4 trous supplémentaires, pour un total de **37 trous**. Il est considéré plus complexe.

|   |   |   |   |   |   |   |
| - | - | - | - | - | - | - |
|   |   | ● | ● | ● |   |   |
|   | ● | ● | ● | ● | ● |   |
| ● | ● | ● | ● | ● | ● | ● |
| ● | ● | ● | ○ | ● | ● | ● |
| ● | ● | ● | ● | ● | ● | ● |
|   | ● | ● | ● | ● | ● |   |
|   |   | ● | ● | ● |   |   |

### Mode pratique

Un mode d’entraînement avec les billes placées en croix dans un plateau anglais.

|   |   |   |   |   |   |   |
| - | - | - | - | - | - | - |
|   |   | ○ | ● | ○ |   |   |
|   |   | ○ | ● | ○ |   |   |
| ○ | ○ | ○ | ● | ○ | ○ | ○ |
| ● | ● | ● | ○ | ● | ● | ● |
| ○ | ○ | ○ | ● | ○ | ○ | ○ |
|   |   | ○ | ● | ○ |   |   |
|   |   | ○ | ● | ○ |   |   |

Le programme pourra éventuellement permettre plusieurs variantes de départ :

- **Le trou central (classique)** : on laisse le centre vide.
- **Le trou à un endroit choisi** : le joueur choisi l'emplacement du trou de départ.

## 5. Interface du jeu

Le joueur contrôle un **curseur** qui se déplace sur le plateau.

### Déplacement

Le curseur se déplace avec les touches :

- `a` : gauche
- `w` : haut
- `d` : droite
- `s` : bas

### Action

La touche **barre d’espace** permet :

- de **prendre** une bille si le curseur n’en tient pas déjà une
- de **déposer** la bille si le curseur en tient une

### Comportement du curseur

- Le curseur doit toujours se trouver sur une case jouable.
- La curseur **ne peut pas aller sur une case `NON_DISPO`**.
- La curseur peut se trouver sur une case contenant une bille ou sur une case vide.
- Lorsque le joueur tente une action invalide, le programme ne doit pas modifier le plateau.

### Représentation visuelle

- `X` vert : le curseur **ne tient pas** de bille
- `x` rouge : le curseur **tient** une bille

Un guide des touches doit être affiché sous le plateau.

Exemple:

`Gauche: a | Haut: w | Droite: d | Bas: s | Action: espace`

Le guide doit être mis à jour lorsque de nouvelles options deviennent disponibles (`annuler`, `refaire`, `redémarrer`, `quitter`, etc.).

## 6. Contraintes de programmation

1. Vous ne devez utiliser **aucune classe**.
2. Vous devez utiliser les `struct` et les types fournis dans le code de départ, ou des versions très proches.
3. Le plateau doit être représenté par un **tableau 2D statique** de type :  
   `Cases plateau;`
4. Le plateau doit avoir une taille de **7 x 7**.
5. Les cases doivent être représentées par un `enum`.
6. Aucune variable globale supplémentaire ne doit être ajoutée.
7. Vous pouvez ajouter des fonctions utilitaires.
8. Vous pouvez ajouter des `struct`,  `enum` ou `using` si cela est pertinent, tant que cela respecte les contraintes du projet.
9. Le programme doit être séparé en plusieurs fichiers selon le niveau atteint.

---

## 7. Code de départ

Vous devez partir de la base suivante. Vous pouvez la modifier au besoin, mais vous ne devez pas ajouter de variables globales supplémentaires.

```cpp
const char carte[3]{ 'O', ' ', '\xdb' };

const size_t LARGEUR = 7;
const size_t HAUTEUR = 7;
const size_t LIGNE_CONTROLES = HAUTEUR + 2;
const size_t LIGNE_ANNULER = LIGNE_CONTROLES + 1;
const size_t LIGNE_MESSAGE = LIGNE_ANNULER + 1;

enum Case { BILLE, VIDE, NON_DISPO };

enum class Configuration { ANGLAIS, EUROPEEN, PRATIQUE };

enum class Action
{
	INCONNUE,
	HAUT = 119,
	GAUCHE = 97,
	DROITE = 100,
	BAS = 115,
	MANIPULER = 32,
	QUITTER = 27,
	REINITIALISER = 114,
	ANNULER = 117,
	REFAIRE = 121
};

using Cases = Case[HAUTEUR][LARGEUR];

struct Position
{
	int8_t	ligne;
	int8_t	colonne;
};

struct Curseur
{
	bool		enMain;
	Position	depart, arrivee;
	Position	prise;
};

struct Data
{
	Position depart;
	Position retiree;
	Position arrivee;
};

struct Noeud
{
	Data data;
	Noeud* noeudSous = nullptr;
};

struct Pile
{
	size_t taille = 0;
	Noeud* dessusPile = nullptr;
};
```

## 8. Fonctions suggérées

Les fonctions suivantes sont données à titre indicatif. Vous pouvez les utiliser, les renommer, en fusionner certaines ou en créer d’autres.

```cpp
initialiserPlateau
afficherPlateau
reafficherCase
placerCurseurDepart
afficherCurseur
positionValide
manipulerBille
prendreBille
deposerBille
saisirAction
miseAJour
afficherMenu
demarrer
```

# Répartition de la note finale

La note finale du projet est divisée en deux parties :

* **50 % : fonctionnalités**
* **50 % : qualité du code**

## Évaluation des fonctionnalités — 50 %

Les fonctionnalités sont évaluées indépendamment les unes des autres.

Une fonctionnalité manquante n'empêche pas l'obtention des points associés à une autre fonctionnalité. Une fonctionnalité partiellement réalisée peut recevoir une partie des points prévus.

## Plateau et interface de base — 8 points

- Plateau anglais correctement représenté : **2 pts**
- Déplacement du curseur avec `a`, `w`, `s`, `d` : **2 pts**
- Impossibilité d'aller sur une case `NON_DISPO` : **1 pt**
- Prendre une bille avec la barre d'espace : **1 pt**
- État visuel du curseur selon qu'une bille est tenue ou non : **1 pt**
- Guide des touches affiché et à jour : **1 pt**

## Validation et exécution d'un coup — 14 points

- La case de départ contient une bille : **1 pt**
- Déplacement horizontal ou vertical seulement : **1 pt**
- Déplacement de deux cases exactement : **1 pt**
- Présence d'une bille sur la case intermédiaire : **2 pts**
- Case d'arrivée vide et jouable : **1 pt**
- Un coup invalide ne modifie pas le plateau : **2 pts**
- La case de départ devient vide : **1 pt**
- La bille sautée est retirée : **1 pt**
- La bille déplacée apparaît à l'arrivée : **1 pt**
- La manipulation prendre/déplacer/déposer demeure cohérente : **3 pts**

## Configurations supplémentaires — 4 points

- Configuration européenne fonctionnelle : **2 pts**
- Mode pratique fonctionnel : **2 pts**

## Gestion d'une partie — 8 points

- Recommencer après la fin d'une partie : **1 pt**
- Redémarrer pendant une partie : **1 pt**
- Confirmation avant de redémarrer ou quitter : **1 pt**
- Détection de la fin de la partie : **5 pts**

## Sauvegarde — 2 points

- Conservation des coups effectués : **1 pt**
- Création du fichier demandé à la fin : **1 pt**

## Annuler et refaire — 11 points

- Annuler un coup correctement : **3 pts**
- Refaire un coup annulé : **3 pts**
- Intégrité du jeu conservée : **2 pts**
- Enchaîner correctement `Annuler` et `Refaire` : **2 pts**
- Afficher le nombre d'annulations disponibles : **1 pt**

## Choix du trou de départ — 3 points

- Choix entre le centre et une position personnalisée : **1 pt**
- Sélection de la position avec le curseur : **1 pt**
- Refus d'une position invalide ou `NON_DISPO` : **1 pt**

**Total : 50 points**

## Qualité du code — 50 %

## Respect des contraintes et structures imposées — 10 points

- Aucune variable globale supplémentaire : **1 pt**
- Utilisation adéquate des `struct` et `enum` : **1 pts**
- Plateau représenté par un tableau 2D statique `7 x 7` de `Case` : **1 pts**
- Initialisation du plateau anglais avec une approche algorithmique utilisant des boucles : **4 pts**
- Configurations supplémentaires initialisées sans duplication excessive : **2 pt**
- Respect général de l'architecture imposée : **1 pt**

## Découpage en fonctions — 10 points

- `main()` simple et lisible : **2 pts**
- Responsabilités principales séparées en fonctions : **3 pts**
- Fonctions ayant une responsabilité claire : **2 pts**
- Peu ou pas de duplication de code : **2 pts**
- Fonctions utilitaires pertinentes : **1 pt**

## Paramètres, types et structures — 8 points

- Passage par valeur, référence et pointeur utilisé adéquatement : **3 pts**
- Absence de copies inutiles : **2 pt**
- Distinction claire entre données consultées et modifiées : **2 pt**
- Types de retour appropriés : **1 pt**

## Lisibilité et style — 8 points

- Indentation et présentation uniformes : **2 pts**
- Noms significatifs : **2 pts**
- Code aéré et facile à suivre : **1 pt**
- Commentaires utiles : **1 pt**
- Absence de code mort : **1 pt**
- Utilisation adéquate de constantes : **1 pt**

## Organisation multifichier — 6 points

- Séparation minimale entre `main.cpp`, `solitaire.h` et `solitaire.cpp` : **2 pts**
- Déclarations dans les `.h` appropriés : **1 pt**
- Définitions dans les `.cpp` appropriés : **1 pt**
- Inclusions cohérentes : **1 pt**
- Composants supplémentaires séparés logiquement lorsque pertinent : **1 pt**

## Robustesse et qualité technique — 8 points

- Actions invalides gérées proprement : **2 pts**
- Aucun plantage évident en utilisation normale : **2 pt**
- État du curseur, du plateau et de la partie cohérent : **1 pt**
- Historique cohérent lorsque présent : **1 pt**
- Historique dynamique utilisant des neouds chaînés lorsque `Annuler`/`Refaire` est implanté : **1 pt**
- Mémoire dynamique correctement libérée : **1 pt**

**Total : 50 points**
