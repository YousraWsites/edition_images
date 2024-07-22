Notre travail contient image.cpp et image.h et filtre.cpp et filtre.h et main.cpp(source principal) et maintest.cpp qui contient les tests automatique 
qui sont chacun en commentaire.

//pour le maintest.cpp il compile pas les tests par contre si on met les tests automatique dans le main.cpp ca marche par ce que le compilateur considere 
main.cpp comme source principale 
***********************************************************************main.cpp**************************************************************************

le main.cpp contient le menu principal du programme qui resume toutes les actions qu'on peut faire sur une image etc.

***********************************************************************maintest.cpp***********************************************************************

---->>le maintest.cpp contient tout les tests automatiques des fonctions.

//pour le maintest.cpp il compile pas les tests par contre si on met les tests automatique dans le main.cpp ca marche par ce que le compilateur considere 
main.cpp comme source principale 

**********************************************************************image.cpp***************************************************************************





1. Constructeurs:
   - Image::Image(): Constructeur vide.
   - Image::Image(const string &picture): Constructeur qui charge une image à partir dun fichier PPM.

2. Fonctions de Manipulation de lImage:
   - void Image::creationImagePpm(const string &picture): Crée un fichier PPM à partir des données actuelles de limage.
   - Image Image::composanteRouge1(): Retourne une nouvelle image avec seulement la composante rouge.
   - void Image::composanteRouge2(): Modifie limage actuelle en conservant uniquement la composante rouge.
   - bool Image::detection(int x, int y, int z): Vérifie si une couleur spécifique est présente dans limage.
   - Image Image::niveauGris(): Convertit limage en niveaux de gris.
   - vector<int> Image::histogrammeGris(): Calcule lhistogramme des niveaux de gris de limage.
   - vector<vector3d> Image::histogrammeCouleur(): Calcule lhistogramme des couleurs de limage.
   - Image Image::luminosityUp(float fac1): Augmente la luminosité de limage.
   - Image Image::luminosityDown(float fac2): Diminue la luminosité de limage.
   - Image Image::contrasteUp(float facteur): Augmente le contraste de limage.
   - Image Image::contrasteDown(float facteur): Diminue le contraste de limage.
   - Image Image::reglageAuto(): Effectue un réglage automatique de la luminosité et du contraste.

3. Opérations sur la Taille de lImage:
   - void supprimepremier(vector<vector<int> > & tab1, char c): Supprime une partie de limage (gauche, droite, haut, bas).
   - Image Image::rogneG(): Rogne limage à gauche.
   - Image Image::rogneD(): Rogne limage à droite.
   - Image Image::rogneH(): Rogne limage en haut.
   - Image Image::rogneB(): Rogne limage en bas.
   - Image Image::rotationD(): Effectue une rotation de limage vers la droite.
   - Image Image::rotationG(): Effectue une rotation de limage vers la gauche.
   - Image Image::returnmentH(): Effectue un renversement horizontal de limage.
   - Image Image::returnmentV(): Effectue un renversement vertical de limage.
   - Image Image::agrandissement(int k): Effectue un agrandissement de limage.






***********************************************************************image.h*****************************************************************************







1. Directives de préprocesseur (`#ifndef`, `#define`, `#endif`):
   - Ces directives sont utilisées pour éviter les inclusions multiples du fichier d'en-tête (`images.h`) lors de la compilation. Elles garantissent que le contenu du fichier n'est inclus qu'une seule fois.

2. Inclusions de bibliothèques (`#include`):
   - Le fichier inclut les bibliothèques iostream et vector, nécessaires pour utiliser des fonctionnalités de gestion des flux et des vecteurs en C++.

3. Déclaration des fonctions:
   - Plusieurs fonctions sont déclarées sans être définies. Ces fonctions incluent `supprimepremier`, `rotationshun`, `rotationni`, `transitionH`, `transitionV`, et `agrandir`. Elles semblent être liées à des opérations de manipulation d'images telles que la rotation, la transition et l'agrandissement.

4. Déclaration de la classe `vector3d`:
   - Cette classe représente un vecteur tridimensionnel avec des composantes `px`, `py`, et `pz`. Elle a des méthodes pour obtenir et définir les valeurs des composantes, ainsi qu'une méthode `augmenter`.

5. Déclaration de la classe `Image`:
   - La classe `Image` représente une image et possède plusieurs membres privés :
     - Trois vecteurs 2D pour les composantes rouge, vert et bleu de l'image (`_rouge`, `_vert`, `_bleu`).
     - Les dimensions de l'image (`_longueur`, `_largeur`).
   - Le constructeur par défaut `Image()` et le constructeur avec arguments `Image(vector<vector<int>>, vector<vector<int>>, vector<vector<int>>, int, int)` sont déclarés.
   - D'autres méthodes sont déclarées, telles que celles pour afficher une image, vérifier l'égalité de deux images, extraire la composante rouge, effectuer la détection d'une couleur spécifique, convertir en niveaux de gris, obtenir des histogrammes, ajuster la luminosité, le contraste, et effectuer diverses transformations géométriques (rognage, rotation, retournement, agrandissement).





******************************************************************filtre.h******************************************************************************


La classe filtre a un membre privé _action, qui est une matrice de valeurs flottantes représentant le filtre.
La classe a aussi un membre privé _rayon qui représente le rayon du filtre.
Le constructeur par défaut de la classe filtre est défini.
Un constructeur avec initialisation du filtre et du rayon est également défini.
Une méthode application est déclarée pour appliquer le filtre à une image.

*****************************************************************filtre.cpp******************************************************************************


--->>>>qst 1

La méthode application prend une référence à un objet de type Image en paramètre.
Elle obtient les dimensions de l'image d'entrée.
Elle crée une nouvelle image résultante avec la même taille que l'originale.
Elle copie l'image originale pour éviter la modification en temps réel.
Elle applique le filtre à chaque pixel de l'image en utilisant la convolution.
Elle crée et retourne une nouvelle image résultante après l'application du filtre.


----->>>qst 2
creation d'un filtre 