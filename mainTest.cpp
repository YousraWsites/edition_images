#include <iostream>
#include <fstream> // Important !
#include <string>
#include <vector>
#include "images.h"
#include "filtres.h"
using namespace std;


int maintest()
{
     //*****************************tests automatiques pour la partie 1 *****************************************
//test automatique  pour composante rouge

     // Création d'une image pour le test
    /*vector<vector<int>> rouge = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> vert = {{11, 12, 13}, {14, 15, 16}, {17, 18, 19}};
    vector<vector<int>> bleu = {{21, 22, 23}, {24, 25, 26}, {27, 28, 29}};

    Image testImage(rouge, vert, bleu, 3, 3);

    // Affichage de l'image avant l'appel de la
    cout<<"************************test automatique****************"<<endl;
    cout << "Image avant composanteRouge2 :" << endl;
    testImage.creationImagePpm("avant_composanteRouge.ppm");

    // Appel de la fonction
    testImage.composanteRouge2();

    // Affichage de l'image après l'appel de la fonction
    cout << "Image après composanteRouge2 :" << endl;
    testImage.creationImagePpm("apres_composanteRouge.ppm");*/


//test automatique  pour detection
    /*
    // Création d'une image pour le test
    vector<vector<int>> rouge = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> vert = {{11, 12, 13}, {14, 15, 16}, {17, 18, 19}};
    vector<vector<int>> bleu = {{21, 22, 23}, {24, 25, 26}, {27, 28, 29}};

    Image testImage(rouge, vert, bleu, 3, 3);
     cout<<"************************test automatique****************"<<endl;
    // Appel de la fonction de test
    bool resultat = testImage.detection(5, 15, 25);

    // Affichage du résultat
    if (resultat) {
        cout << "La couleur (5, 15, 25) a ete detectee dans l'image." << endl;
    } else {
        cout << "La couleur (5, 15, 25) n'a pas ete détectee dans l'image." << endl;
    }*/
//test automatique pour niveau gris
   /*cout<<"************************test automatique****************"<<endl;
   vector<vector<int>> rouge = { {100, 150, 200}, {50, 75, 100} };
vector<vector<int>> vert = { {50, 75, 100}, {25, 38, 50} };
vector<vector<int>> bleu = { {25, 38, 50}, {13, 19, 25} };

Image monImage(rouge, vert, bleu, 2, 3);

Image imageGris = monImage.niveauGris();

// Vérification des valeurs de l'image résultante (à remplacer avec vos valeurs attendues)
vector<vector<int>> rougeGrisAttendu = { {150, 125, 175}, {75, 62, 87} };
vector<vector<int>> vertGrisAttendu = { {150, 125, 175}, {75, 62, 87} };
vector<vector<int>> bleuGrisAttendu = { {150, 125, 175}, {75, 62, 87} };

// Comparaison des valeurs obtenues avec les valeurs attendues
if (imageGris.getRouge() == rougeGrisAttendu && imageGris.getVert() == vertGrisAttendu && imageGris.getBleu() == bleuGrisAttendu) {
    cout << "Le test a réussi ! La fonction niveauGris fonctionne correctement." << endl;
} else {
    cout << "Le test a échoué. La fonction niveauGris ne fonctionne pas comme prévu." << endl;
}*/
//test automatique pour noiretblanc

    /*
    cout<<"************************test automatique****************"<<endl;

    vector<vector<int>> rouge = {{50, 100, 150}, {75, 125, 175}, {100, 150, 200}};
    vector<vector<int>> vert = {{75, 125, 175}, {100, 150, 200}, {125, 175, 225}};
    vector<vector<int>> bleu = {{100, 150, 200}, {125, 175, 225}, {150, 200, 250}};

    // Créez une image avec ces valeurs
    Image monImage(rouge, vert, bleu, 3, 3);

    // Appliquez manuellement le calcul de l'image en noir et blanc avec un seuil de 150
    vector<vector<int>> noirBlancAttendu = {{0, 0, 0}, {0, 255, 255}, {255, 255, 255}};

    // Appelez la fonction noirBlanc
    Image imageNoirBlanc = monImage.noirBlanc(200);

    // Affichez les résultats pour vérification
    cout << "Rouge après noir et blanc : " << endl;
    for (auto i = 0; i < imageNoirBlanc.getRouge().size(); ++i) {
        for (auto j = 0; j < imageNoirBlanc.getRouge()[0].size(); ++j) {
            cout << imageNoirBlanc.getRouge()[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Vert après noir et blanc : " << endl;
    for (auto i = 0; i < imageNoirBlanc.getVert().size(); ++i) {
        for (auto j = 0; j < imageNoirBlanc.getVert()[0].size(); ++j) {
            cout << imageNoirBlanc.getVert()[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Bleu après noir et blanc : " << endl;
    for (auto i = 0; i < imageNoirBlanc.getBleu().size(); ++i) {
        for (auto j = 0; j < imageNoirBlanc.getBleu()[0].size(); ++j) {
            cout << imageNoirBlanc.getBleu()[i][j] << " ";
        }
        cout << endl;
    }*/
//test automatique pour histogrammegris
/*
   cout<<"************************test automatique****************"<<endl;
    vector<vector<int>> rouge = {{100, 150, 200}, {50, 120, 180}, {70, 130, 160}};
    vector<vector<int>> vert = {{120, 170, 220}, {80, 150, 200}, {100, 160, 190}};
    vector<vector<int>> bleu = {{80, 130, 180}, {40, 110, 160}, {60, 120, 150}};

    Image testImage(rouge, vert, bleu, 3, 3);

    // Appeler la fonction noirBlanc avec un seuil de 150
    Image resultImage = testImage.noirBlanc(150);

    // Vérifier si l'image résultante est conforme aux attentes
    // Ici, on s'attend à ce que les pixels avec une valeur supérieure à 150 deviennent blancs (255) et les autres noirs (0).
    if (resultImage.getRouge()[0][0] == 255 && resultImage.getRouge()[1][1] == 255 && resultImage.getRouge()[2][2] == 255) {
      cout << "Test reussi : l'image noir et blanc est conforme aux attentes." << std::endl;
    } else {
       cout << "echec du test : l'image noir et blanc ne correspond pas aux attentes." << std::endl;
    }*/


//tests automatique pour luminosityup et down
    // Créer une image de test

     /*cout<<"************************test automatique****************"<<endl;
    vector<vector<int>> rouge = {{100, 150, 200}, {50, 120, 180}, {70, 130, 160}};
    vector<vector<int>> vert = {{120, 170, 220}, {80, 150, 200}, {100, 160, 190}};
    vector<vector<int>> bleu = {{80, 130, 180}, {40, 110, 160}, {60, 120, 150}};

    Image testImage(rouge, vert, bleu, 3, 3);

    // Appliquer la fonction luminosityUp avec un facteur de 1.5
    Image resultImage = testImage.luminosityUp(1.5);

    // Afficher l'image originale
   cout << "Image originale :" << endl;
    testImage.afficherImage();

    // Afficher l'image résultante
    cout << "Image après luminosityUp :" <<endl;
    resultImage.afficherImage();*/


    // Créer une image de test
    /*
     cout<<"************************test automatique****************"<<endl;
     vector<vector<int>> rouge = {{100, 150, 200}, {50, 120, 180}, {70, 130, 160}};
    vector<vector<int>> vert = {{120, 170, 220}, {80, 150, 200}, {100, 160, 190}};
    vector<vector<int>> bleu = {{80, 130, 180}, {40, 110, 160}, {60, 120, 150}};

    Image testImage(rouge, vert, bleu, 3, 3);

    // Appliquer la fonction luminosityUp avec un facteur de 1.5
    Image resultImage = testImage.luminosityDown(0.8);

    // Afficher l'image originale
   cout << "Image originale :" << endl;
    testImage.afficherImage();

    // Afficher l'image résultante
    cout << "Image après luminosiDown :" <<endl;
    resultImage.afficherImage();*/

//test pour contrastUp et down

    // Créer une image de test avec des niveaux de gris variés
    /*cout<<"************************test automatique****************"<<endl;
    vector<vector<int>> rouge = {{50, 100, 150}, {120, 180, 220}, {30, 80, 200}};
    vector<vector<int>> vert = {{70, 120, 170}, {90, 140, 190}, {40, 100, 150}};
    vector<vector<int>> bleu = {{90, 140, 190}, {60, 110, 160}, {80, 130, 180}};

    Image testImage(rouge, vert, bleu, 3, 3);

    // Afficher l'image originale
    cout << "Image originale :" << endl;
    testImage.afficherImage();

    // Appliquer la fonction contrasteUp avec un facteur de 1.5
    Image contrasteUpImage = testImage.contrasteUp(1.5);
    cout << "Image après contrasteUp :" << endl;
    contrasteUpImage.afficherImage();

    // Appliquer la fonction contrasteDown avec un facteur de 1.5
    Image contrasteDownImage = testImage.contrasteDown(1.5);
    cout << "Image après contrasteDown :" << endl;
    contrasteDownImage.afficherImage();*/
//test pour reglageauto

    // Créer une image de test avec des niveaux de gris variés
   /* cout<<"************************test automatique****************"<<endl;
   vector<vector<int>> rouge = {{50, 100, 150}, {120, 180, 220}, {30, 80, 200}};
    vector<vector<int>> vert = {{70, 120, 170}, {90, 140, 190}, {40, 100, 150}};
    vector<vector<int>> bleu = {{90, 140, 190}, {60, 110, 160}, {80, 130, 180}};

    Image testImage(rouge, vert, bleu, 3, 3);

    // Afficher l'image originale
    cout << "Image originale :" << endl;
    testImage.afficherImage();

    // Appliquer la fonction reglageAuto
    Image reglageAutoImage = testImage.reglageAuto();
    cout << "Image après réglage automatique :" << endl;
    reglageAutoImage.afficherImage();*/
//*****************************tests automatiques pour la partie 2 **********************************************
// test pour la question 2 pour creer une image a partir d'un fichier ppm
     /*Image testImage("exCouleur.ppm");

    // Afficher l'image
    cout << "Image creee a partir du fichier :" << endl;
    testImage.afficherImage();*/

//test pour la question 3 pour cree un  fichier ppm a partie d'une image
     // Créer une image
    /*vector<vector<int>> rouge = {{200, 50, 100}, {100, 150, 200}, {150, 200, 50}};
    vector<vector<int>> vert = {{100, 150, 200}, {150, 200, 50}, {200, 50, 100}};
    vector<vector<int>> bleu = {{150, 200, 50}, {200, 50, 100}, {50, 100, 150}};

    Image testImage(rouge, vert, bleu, 3, 3);

    // Appeler la fonction creationImagePpm pour générer le fichier ppm
    testImage.creationImagePpm("testyousra.ppm");

    cout << "Fichier ppm créé avec succès." << endl;*/


//*****************************tests automatiques pour la partie 3 *****************************************

    // Créer une image de test
   /* vector<vector<int>> rouge = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> vert = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    vector<vector<int>> bleu = {{100, 200, 300}, {400, 500, 600}, {700, 800, 900}};

    Image monImage(rouge, vert, bleu, 3, 3);

    // Afficher l'image originale
    cout << "Image originale :" << endl;
    monImage.afficherImage();

    // Appliquer la fonction rogner à gauche
     cout << "Image apres rogner a gauche :" << endl;
   (monImage.rogneG()).afficherImage();*/






//test automatique de rotation question 2 et 3

  /*vector<vector<int>> rouge = {{100, 150, 200}, {50, 120, 180}, {70, 130, 160}};
    vector<vector<int>> vert = {{120, 170, 220}, {80, 150, 200}, {100, 160, 190}};
    vector<vector<int>> bleu = {{80, 130, 180}, {40, 110, 160}, {60, 120, 150}};

    Image testImage(rouge, vert, bleu, 3, 3);

    // Afficher l'image originale
    cout << "Image originale :" << endl;
    testImage.afficherImage();

    // Tester la rotation vers la droite (90° sens horaire)
    cout << "Image après rotation vers la droite :" << endl;
           (testImage.rotationD()).afficherImage();



    // Tester la rotation vers la gauche (90° sens trigonométrique)
    cout << "Image après rotation vers la gauche :" << endl;
            (testImage.rotationG()).afficherImage();*/


//test automatique de retournement

    // Créer une image de test
    /*vector<vector<int>> rouge = {{100, 150, 200}, {50, 120, 180}, {70, 130, 160}};
    vector<vector<int>> vert = {{120, 170, 220}, {80, 150, 200}, {100, 160, 190}};
    vector<vector<int>> bleu = {{80, 130, 180}, {40, 110, 160}, {60, 120, 150}};

    Image testImage(rouge, vert, bleu, 3, 3);

    // Afficher l'image originale
    cout << "Image originale :" << endl;
    testImage.afficherImage();

    // Tester le retournement horizontal
    cout << "Image après retournement horizontal :" << endl;
    (testImage.returnmentH()).afficherImage();


    // Tester le retournement vertical
    cout << "Image après retournement vertical :" << endl;
  (testImage.returnmentH()).afficherImage();*/

//test de agrandissement

    // Créer une image de test
    /*vector<vector<int>> rouge = {{100, 150, 200}, {50, 120, 180}, {70, 130, 160}};
    vector<vector<int>> vert = {{120, 170, 220}, {80, 150, 200}, {100, 160, 190}};
    vector<vector<int>> bleu = {{80, 130, 180}, {40, 110, 160}, {60, 120, 150}};

    Image testImage(rouge, vert, bleu, 3, 3);

    // Afficher l'image originale
    cout << "Image originale :" << endl;
    testImage.afficherImage();

    // Tester l'agrandissement avec un facteur k
    int k = 2;
    cout << "Image après agrandissement (facteur " << k << ") :" << endl;
      // Choisissez votre facteur d'agrandissement
      (testImage.agrandissement(k)).afficherImage();*/


//**********************************************************partie 4 des filtres***********************************

//test automatique de la question 1 de la partie 4
 // Créer une image exemple
    /*vector<vector<int>> exempleImage = {{50, 100, 150}, {75, 125, 175}, {100, 150, 200}};
    Image monImage(exempleImage, exempleImage, exempleImage, 3, 3);

    // Afficher l'image originale
    cout << "Image originale : " << endl;
    monImage.afficherImage();

    // Définir un filtre exemple (matrice 3x3)
    vector<vector<float>> exempleFiltre = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};
    filtre monFiltre(exempleFiltre, 1);

    // Appliquer le filtre à l'image
    Image imageFiltree = monFiltre.application(monImage);

    // Afficher l'image après l'application du filtre
    cout << "\nImage après application du filtre : " << endl;
    imageFiltree.afficherImage();*/

//qst 2 de la partie 4

 /*vector<vector<float>> vec = {{1.0/16.0,1.0/8.0,1.0/16.0},{1.0/8.0,1.0/4.0,1.0/8.0},{1.0/16.0,1.0/8.0,1.0/16.0}};
  Filtre flouG3(vec,1);*/
    return 0;
}
