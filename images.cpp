#include <iostream>
#include"images.h"
#include <vector>
#include<stdexcept>
#include <fstream> // Important !
#include <cmath>
using namespace std;

Image::Image() {
    cout << "appel constructeur vide" << endl;
}



//partie2
//qst2
Image::Image(const string &picture)
{
    // Declaration des variables

    string line; // pour recuperer les lignes du fichier image au format .ppm, qui est code en ASCII.
    string format; //pour recuperer le format de l'image : celui-ci doit être de la forme P3
    string name; // au cas où l'utilisateur se trompe dans le nom de l'image a charger, on redemande le nom.
    int taille;
    vector <int> mypixels; // pour recuperer les donnees du fichier de maniere lineaire. On repartira ensuite ces donnees dans les tableaux correspondants
    ifstream entree; // Declaration d'un "flux" qui permettra ensuite de lire les donnees de l'image.
    int hauteur; // pour bien verifier que l'image est carree, et de taille respectant les conditions fixees par l'enonce
    // Initialisation des variables
    name = picture;
    // Permet d'ouvrir le fichier portant le nom picture
    // ouverture du fichier portant le nom picture
    entree.open(name);
    // On verifie que le fichier a bien ete ouvert. Si cela n'est pas le cas, on redemande un nom de fichier valide
    while (!entree)
    {
        //cin.rdbuf(oldbuf);
        cerr << "Erreur! Impossible de lire de fichier " << name << " ! " << endl;
        cerr << "Redonnez le nom du fichier a ouvrir SVP. Attention ce fichier doit avoir un nom du type nom.ppm." << endl;
        cin >> name;
        entree.open(name); // relance
    }
    // Lecture du nombre definissant le format (ici P3)
    entree >> format;
    // on finit de lire la ligne (caractere d'espacement)
    getline(entree, line);
    // Lecture du commentaire
    getline(entree, line);
    //lecture des dimensions
    entree >> taille >> hauteur;
    getline(entree, line); // on finit de lire la ligne (caractere d'espacement)
    // On verifie que l'image a une taille qui verifie bien les conditions requises par l'enonce.
    // Si cela n'est pas le cas, on redemande un fichier valide, et ce, tant que necessaire.
    while (format != "P3")
    {
        if (format != "P3")
        {
            cerr << "Erreur! L'image que vous nous avez donnee a un format ne verifiant pas les conditions requises." << endl;
            cerr << "L'image que vous nous avez donnee doit etre codee en ASCII et non en brut." << endl;
        }
        entree.close();
        // On va redemander un nom de fichier valide.
        do
        {
            cerr << "Veuillez redonner un nom de fichier qui respecte les conditions de format et de taille. Attention, ce nom doit etre de la forme nom.ppm." << endl;
            cin >> name;
            entree.open(name); // relance
        }
        while(!entree);
        // Lecture du nombre definissant le format (ici P3)
        entree >> format;
        getline(entree, line); // on finit de lire la ligne (caractere d'espacement)
        // Lecture du commentaire
        getline(entree, line);
        //lecture des dimensions
        entree >> taille >> hauteur; // relance
        getline(entree, line); // on finit de lire la ligne (caractere d'espacement)
    }
    //Lecture de la valeur max
    getline(entree, line);
    //Lecture des donnees et ecriture dans les tableaux :
    // Pour plus de simplicite, on stocke d'abord toutes les donnees dans mypixels
    // dans l'ordre de lecture puis ensuite on les repartira dans les differents tableaux.
    //Les donnees stockees dans mypixels sont de la forme RGB RGB RGB ....
    // Il faudra donc repartir les valeurs R correspondant a la composante rouge de l'image
    // dans le tableau red, de même pour G et B.
    int pix;
    mypixels.resize(3*taille*hauteur); // taille fixe : on alloue une fois pour toutes
    for (int i = 0; i < 3*taille*hauteur; i++)
    {
        entree >> pix;
        mypixels[i]=pix;
    }
    // Remplissage des 3 tableaux : on repartit maintenant les valeurs dans les bonnes composantes
    // Comme dans mypixels, les donnees sont stockees de la maniere suivante : RGB RGB RGB, il faut mettre
    // les valeurs correspondant a la composante rouge dans red, ...
    // Ainsi, les valeurs de la composante rouge correspondent aux valeurs stockes aux indices
    // congrus a 0 mod 3 dans mypixels, que les valeurs de la composante verte correspond aux valeurs
    // stockes aux indices sont congrus a 1 mod 3, ...
    // les valeurs d'une ligne
    int val;
    _rouge.resize(hauteur);
    _vert.resize(hauteur);
    _bleu.resize(hauteur);
    for (int i = 0; i < hauteur; i++)
    {
        vector <int> ligneR(taille);
        vector <int> ligneB(taille);  // les lignes ont toutes la même taille
        vector <int> ligneG(taille);
        for (int j = 0; j < taille; j++)
        {
            val =  mypixels[3*j + 3*taille*i];
            ligneR[j]=val;
            val = mypixels[3*j + 1 + 3*taille*i];
            ligneG[j]=val;
            val = mypixels[3*j + 2 + 3*taille*i];
            ligneB[j]=val;
        }
        _rouge[i]=ligneR;
        _vert[i]=ligneG;
        _bleu[i]=ligneB;
    }
    _longueur = _rouge.size();
    _largeur = _rouge[0].size();
    // Informations a l'utilisateur pour dire que tout s'est bien passe
    cout << " L'image " << name << " a bien ete chargee dans les tableaux ." << endl;
    entree.close();
}

//partie 2
//qst 3

//prend une image et la transfrome en fichiers


void Image::creationImagePpm(const string & picture)
{
    string name; // au cas où l'utilisateur se trompe dans le nom de l'image a charger, on redemande le nom.
    ofstream sortie; // Declaration d'un "flux" qui permettra ensuite de lire les donnees de l'image.
    name = picture;
    // Permet d'ouvrir le fichier portant le nom picture
    // ouverture du fichier portant le nom picture
    sortie.open(name);
    // On verifie que le fichier a bien ete ouvert. Si cela n'est pas le cas, on redemande un nom de fichier valide
    while (!sortie)
    {
        //cin.rdbuf(oldbuf);
        cerr << "Erreur! Impossible de lire de fichier " << name << " ! " << endl;
        cerr << "Redonnez le nom du fichier a ouvrir SVP. Attention ce fichier doit avoir un nom du type nom.ppm." << endl;
        cin >> name;
        sortie.open(name); // relance
    }
    sortie << "P3" <<endl;
    cout << _longueur << _largeur << endl;
    sortie << _longueur <<" "<< _largeur << endl << 255 << endl;
    for(int i = 0; i < _rouge.size(); i++)
    {
        for (int j = 0; j < _rouge[i].size(); j++)
        {
            sortie << _rouge[i][j] <<endl;
            sortie << _vert[i][j] <<endl;
            sortie << _bleu[i][j] <<endl;
        }
    }

    cout << " L'image " << name << " a bien ete chargee dans les tableaux ." << endl;
    sortie.close();

}
bool comparevector(vector < vector <int> >& tab1,vector < vector <int> >& tab2)
{
    if(tab1.size()!=tab2.size())//nombre de lignes est different
    {
       return false;
    }
    for(int i=0;i<tab1.size();i++)
    {
        if(tab1[i].size()!=tab2[i].size())
        {
            return false;
        }
    }
    return true;
}
bool Image::vectorverifier(vector < vector <int> > r,vector < vector <int> > v,vector < vector <int> > b)
{
    if(!comparevector(r,v))//si c'est pas egaux
    {
        return false;
    }else if(!comparevector(v,b))//si c'est pas egaux
    {
        return false;
    }else{return true;}//si les 3 sont egaux}
}
Image::Image(vector <vector <int>> r,vector <vector <int>> v,vector < vector <int> >b,int lo,int la)
{
    if(!vectorverifier(r,v,b))
    {
        throw invalid_argument("les vecteurs n'ont pas la meme dimension");
    }
    _longueur=lo;
    _largeur=la;
   _rouge=r;
   _vert=v;
   _bleu=b;
}
Image Image::composanteRouge2() const {
    // Obtenir les dimensions de l'image
    int hauteur = _rouge.size();
    int largeur = _rouge[0].size();

    // Créer une nouvelle image résultante avec les mêmes dimensions que l'originale
    Image nouvelleImage(_rouge, vector<vector<int>>(hauteur, vector<int>(largeur, 0)),
                        vector<vector<int>>(hauteur, vector<int>(largeur, 0)),
                        _longueur, _largeur);

    return nouvelleImage;
}


bool Image::detection(int x,int y,int z){
    bool flat = false;
    for(int i = 0;i < _rouge.size();i++){
        for(int j = 0;j < _rouge[i].size();j++){
                if(_rouge[i][j] == x){
                    flat = _vert[i][j] == y && _bleu[i][j] == z;
                    if(flat){
                        return flat;
                    }
                }
        }
    }
    return flat;
}
Image Image::niveauGris() {
    // Créer un vecteur pour stocker les niveaux de gris résultants
    vector<vector<int>> tab1(_rouge.size(), vector<int>(_rouge[0].size(), 0));

    for (int i = 0; i < _rouge.size(); ++i) {
        for (int j = 0; j < _rouge[i].size(); ++j) {
            // Calculer le niveau de gris pour chaque pixel
            tab1[i][j] = (_rouge[i][j] + _vert[i][j] + _bleu[i][j]) / 3;
        }
    }

    // Créer une nouvelle instance de la classe Image avec les niveaux de gris calculés
    Image imageGris(tab1, tab1, tab1, _longueur, _largeur);

    return imageGris;
}

vector<vector<int>> Image::getRouge() const {
    return _rouge;
}

vector<vector<int>> Image::getVert() const {
    return _vert;
}

vector<vector<int>> Image::getBleu() const {
    return _bleu;
}
//methode pour afficher une image
void Image::afficherImage() {
    for (int i = 0; i < _longueur; ++i) {
        for (int j = 0; j <_largeur; ++j) {
            cout << "(" << getRouge()[i][j] << "," << getVert()[i][j] << "," << getBleu()[i][j] << ") ";
        }
        cout << endl;
    }
    cout << endl;
}
Image Image::noirBlanc(int seuil)
{
    vector < vector <int> > rouge;
    vector < vector <int> > vert;
    vector < vector <int> > bleu;
    rouge=_rouge;
    vert=_vert;
    bleu=_bleu;
    for(int i=0;i<_rouge.size();i++)
    {
        for(int j=0; j<_rouge[i].size();j++)
        {
            if((_rouge[i][j]+_vert[i][j]+_bleu[i][j]/3)>seuil)
            {
                rouge[i][j]=255;
                vert[i][j]=255;
                bleu[i][j]=255;

            }else{
                rouge[i][j]=0;
                vert[i][j]=0;
                bleu[i][j]=0;
                }
       }

     }
     //je donne quoi comme longueur et largeur
     Image result (rouge,vert,bleu,_longueur,_largeur);
     return result ;
}
//si histogramme[10] est égal à 5, cela signifie qu'il y a 5 pixels dans l'image qui ont un niveau de gris égal à 10.
vector<int> Image::histogrammeGris() {
    vector<int> histogramme(256, 0); // Initialiser le vecteur histogramme avec 256 cases à 0

    // Parcourir les pixels de l'image et incrémenter les valeurs correspondantes dans l'histogramme
    for (int i = 0; i < _rouge.size(); ++i) {
        for (int j = 0; j < _rouge[i].size(); ++j) {
            // Calculer la valeur en niveau de gris (moyenne des composantes rouge, vert et bleu)
            int niveauGris = (_rouge[i][j] + _vert[i][j] + _bleu[i][j]) / 3;

            // Incrémenter le compteur correspondant dans l'histogramme
            histogramme[niveauGris]++;
        }
    }

    return histogramme;
}
vector<vector3d> Image::histogrammeCouleur(){
    int nb = _rouge.size() * _rouge[0].size();
    vector<vector3d> i(nb);
    for(int j = 0;j < nb;j++){
        i.push_back(vector3d(_rouge[(j / _rouge[0].size())][j % _rouge[0].size()]
                             ,_vert[(j / _rouge[0].size())][j % _rouge[0].size()]
                             ,_bleu[(j / _rouge[0].size())][j % _rouge[0].size()]));
    }

}
/*vector<vector3d> histogrammeCouleur() const {
        // Initialiser un vecteur 3D pour stocker l'histogramme
       vector<Vecteur3D> histogramme;

        // Parcourir les pixels de l'image
        for (int i = 0; i < _rouge.size(); ++i) {
            for (int j = 0; j < _rouge[i].size(); ++j) {
                // Ajouter un nouvel élément à la fin du vecteur avec push_back
                histogramme.push_back(Vecteur3D(_rouge[i][j], _vert[i][j], _bleu[i][j]));
            }
        }

        // Retourner l'histogramme résultant
        return histogramme;
    }
*/
Image Image::luminosityUp(float fac1) {
    vector<vector<int>> newRouge = _rouge;
    vector<vector<int>> newVert = _vert;
    vector<vector<int>> newBleu = _bleu;

    // Applique le facteur à chaque composante en veillant à rester dans la plage [0, 255]
    for (int i = 0; i < _rouge.size(); ++i) {
        for (int j = 0; j < _rouge[i].size(); ++j) {
            newRouge[i][j] = _rouge[i][j] * fac1;
            if (newRouge[i][j] > 255) {
                newRouge[i][j] = 255;
            } else if (newRouge[i][j] < 0) {
                newRouge[i][j] = 0;
            }

            newVert[i][j] = _vert[i][j] * fac1;
            if (newVert[i][j] > 255) {
                newVert[i][j] = 255;
            } else if (newVert[i][j] < 0) {
                newVert[i][j] = 0;
            }

            newBleu[i][j] = _bleu[i][j] * fac1;
            if (newBleu[i][j] > 255) {
                newBleu[i][j] = 255;
            } else if (newBleu[i][j] < 0) {
                newBleu[i][j] = 0;
            }
        }
    }

    // Crée et retourne une nouvelle image avec la luminosité augmentée
    return Image(newRouge, newVert, newBleu, _longueur, _largeur);
}
// Méthode pour diminuer la luminosité
Image Image::luminosityDown(float fac2) {
    vector<vector<int>> newRouge = _rouge;
    vector<vector<int>> newVert = _vert;
    vector<vector<int>> newBleu = _bleu;

    // Applique le facteur à chaque composante en veillant à rester dans la plage [0, 255]
    for (int i = 0; i < _rouge.size(); ++i) {
        for (int j = 0; j < _rouge[i].size(); ++j) {
            newRouge[i][j] = _rouge[i][j] * fac2;
            if (newRouge[i][j] < 0) {
                newRouge[i][j] = 0;
            } else if (newRouge[i][j] > 255) {
                newRouge[i][j] = 255;
            }

            newVert[i][j] = _vert[i][j] * fac2;
            if (newVert[i][j] < 0) {
                newVert[i][j] = 0;
            } else if (newVert[i][j] > 255) {
                newVert[i][j] = 255;
            }

            newBleu[i][j] = _bleu[i][j] * fac2;
            if (newBleu[i][j] < 0) {
                newBleu[i][j] = 0;
            } else if (newBleu[i][j] > 255) {
                newBleu[i][j] = 255;
            }
        }
    }

    // Crée et retourne une nouvelle image avec la luminosité diminuée
    return Image(newRouge, newVert, newBleu, _longueur, _largeur);
}
//qst 11
Image Image::contrasteUp(float facteur)
    {
        vector<vector<int>> rougeCopy = _rouge;
        vector<vector<int>> vertCopy = _vert;
       vector<vector<int>> bleuCopy = _bleu;

        for (int i = 0; i < _longueur; ++i)
        {
            for (int j = 0; j < _largeur; ++j)
            {
                int newRouge = (_rouge[i][j] - 128) * facteur + 128;
                int newVert = (_vert[i][j] - 128) * facteur + 128;
                int newBleu = (_bleu[i][j] - 128) * facteur + 128;

                // Vérification des limites
                if (newRouge < 0)
                    newRouge = 0;
                else if (newRouge > 255)
                    newRouge = 255;

                if (newVert < 0)
                    newVert = 0;
                else if (newVert > 255)
                    newVert = 255;

                if (newBleu < 0)
                    newBleu = 0;
                else if (newBleu > 255)
                    newBleu = 255;

                rougeCopy[i][j] = newRouge;
                vertCopy[i][j] = newVert;
                bleuCopy[i][j] = newBleu;
            }
        }

        return Image(rougeCopy, vertCopy, bleuCopy, _longueur, _largeur);
    }

    // Méthode pour diminuer le contraste
Image Image::contrasteDown(float facteur)
    {
       vector<vector<int>> rougeCopy = _rouge;
        vector<vector<int>> vertCopy = _vert;
        vector<vector<int>> bleuCopy = _bleu;

        for (int i = 0; i < _longueur; ++i)
        {
            for (int j = 0; j < _largeur; ++j)
            {
                int newRouge = (_rouge[i][j] - 128) / facteur + 128;
                int newVert = (_vert[i][j] - 128) / facteur + 128;
                int newBleu = (_bleu[i][j] - 128) / facteur + 128;

                // Vérification des limites
                if (newRouge < 0)
                    newRouge = 0;
                else if (newRouge > 255)
                    newRouge = 255;

                if (newVert < 0)
                    newVert = 0;
                else if (newVert > 255)
                    newVert = 255;

                if (newBleu < 0)
                    newBleu = 0;
                else if (newBleu > 255)
                    newBleu = 255;

                rougeCopy[i][j] = newRouge;
                vertCopy[i][j] = newVert;
                bleuCopy[i][j] = newBleu;
            }
        }

        return Image(rougeCopy, vertCopy, bleuCopy, _longueur, _largeur);
    }
//qst 12
Image Image::reglageAuto() {
    // Calcule la luminosité moyenne de l'image actuelle
    int totalPixels = _longueur * _largeur;
    int sommeLuminosite = 0;

    for (int i = 0; i < _rouge.size(); ++i) {
        for (int j = 0; j < _rouge[i].size(); ++j) {
            sommeLuminosite += (_rouge[i][j] + _vert[i][j] + _bleu[i][j]) / 3;
        }
    }

    int luminositeMoyenne = sommeLuminosite / totalPixels;

    // Calcule le facteur de luminosité pour atteindre une luminosité moyenne de 128
    float facteurLuminosite = 128.0 / luminositeMoyenne;

    // Applique le facteur de luminosité
    Image imageLuminosite = luminosityUp(facteurLuminosite);

    // Calcule le facteur de contraste pour augmenter le contraste tout en évitant les débordements
    float facteurContraste = 255.0 / sqrt(255.0 - 2 * luminositeMoyenne);

    // Applique le facteur de contraste
    Image imageContraste = imageLuminosite.luminosityUp(facteurContraste);

    // Retourne l'image avec réglage automatique
    return imageContraste;
}
//partie 3
//qst 1
void supprimePremier(vector<vector<int>>& tab1, char c) {
    switch (c) {
    case 'g':
        for (int i = 0; i < tab1.size(); i++) {
            tab1[i].erase(tab1[i].begin());//les premiers elements colones  a gauche du haut vers le bas
        }
        break;
    case 'd':
        for (int i = 0; i < tab1.size(); i++) {
            tab1[i].pop_back();
        }
        break;
    case 'h':
        tab1.erase(tab1.begin());
        break;
    case 'b':
        tab1.pop_back();
        break;
    default:
        // Gestion d'un caractère invalide
        break;
    }
}

Image Image::rogneG() {
    supprimePremier(_rouge, 'g');
    supprimePremier(_vert, 'g');
    supprimePremier(_bleu, 'g');
    // Vous devez retourner une nouvelle instance de l'image ici, par exemple :
    return Image(_rouge, _vert, _bleu, _longueur, _largeur);
}

Image Image::rogneD() {
    supprimePremier(_rouge, 'd');
    supprimePremier(_vert, 'd');
    supprimePremier(_bleu, 'd');
    return Image(_rouge, _vert, _bleu, _longueur, _largeur);
}

Image Image::rogneH() {
    supprimePremier(_rouge, 'h');
    supprimePremier(_vert, 'h');
    supprimePremier(_bleu, 'h');
    return Image(_rouge, _vert, _bleu, _longueur, _largeur);
}

Image Image::rogneB() {
    supprimePremier(_rouge, 'b');
    supprimePremier(_vert, 'b');
    supprimePremier(_bleu, 'b');
    return Image(_rouge, _vert, _bleu, _longueur, _largeur);
}

//qst 2 et 3
vector<vector<int>> rotationshun(vector<vector<int>>& tab1) {
    vector<vector<int>> nv(tab1[0].size(), vector<int>(tab1.size(), 0));

    for (int i = 0; i < tab1.size(); i++) {
        for (int j = tab1[i].size() - 1, k = 0; j >= 0; j--, k++) {
            nv[k][i] = tab1[i][j];
        }
    }

    return nv;
}

vector<vector<int>> rotationni(vector<vector<int>>& tab1) {
    vector<vector<int>> nv(tab1[0].size(), vector<int>(tab1.size(), 0));

    for (int i = tab1[0].size() - 1, k = 0; i >= 0; i--, k++) {
        for (int j = 0; j < tab1.size(); j++) {
            nv[i][j] = tab1[j][i];  // Correction ici : inversion des indices
        }
    }

    return nv;
}

Image Image::rotationD() {
    return Image(rotationshun(_rouge), rotationshun(_vert), rotationshun(_bleu), _longueur, _largeur);
}

Image Image::rotationG() {
    return Image(rotationni(_rouge), rotationni(_vert), rotationni(_bleu),_longueur, _largeur);
}




//qst 4
vector<vector<int>> transitionH(vector<vector<int>>& tab1) {
    vector<vector<int>> nv(tab1.size(), vector<int>(tab1[0].size(), 0));

    for (int i = tab1.size() - 1; i >= 0; i--) {
        for (int j = 0; j < tab1[i].size(); j++) {
            nv[tab1.size() - i - 1][j] = tab1[i][j];
        }
    }

    return nv;
}

vector<vector<int>> transitionV(vector<vector<int>>& tab1) {
    vector<vector<int>> nv(tab1.size(), vector<int>(tab1[0].size(), 0));

    for (int i = 0; i < tab1.size(); i++) {
        for (int j = tab1[i].size() - 1; j >= 0; j--) {
            nv[i][tab1[i].size() - j - 1] = tab1[i][j];
        }
    }

    return nv;
}

Image Image::returnmentH() {
    return Image(transitionH(_rouge), transitionH(_vert), transitionH(_bleu), _longueur, _largeur);
}

Image Image::returnmentV() {
    return Image(transitionV(_rouge), transitionV(_vert), transitionV(_bleu), _longueur, _largeur);
}

//qst 5
vector<vector<int>> agrandir(vector<vector<int>>& tab1, int k) {
    vector<vector<int>> nv(tab1.size() * k, vector<int>(tab1[0].size() * k, 0));

    for (int i = 0; i < tab1.size(); i++) {
        for (int j = 0; j < tab1[i].size(); j++) {
            for (int x = 0; x < k; x++) {
                for (int y = 0; y < k; y++) {
                    nv[i * k + x][j * k + y] = tab1[i][j];
                }
            }
        }
    }

    return nv;
}

Image Image::agrandissement(int k) {
    return Image(agrandir(_rouge, k), agrandir(_vert, k), agrandir(_bleu, k), _longueur * k, _largeur * k);
}

