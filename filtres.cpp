#include <iostream>
#include"images.h"
#include <vector>
#include<stdexcept>
#include <fstream> // Important !
#include <cmath>
#include "filtres.h"
using namespace std;


Image filtre::application( Image& image) {

        int hauteur = (image.getRouge()).size();
        int largeur = (image.getRouge())[0].size();
        vector<vector<int>>  nouvelleImage(hauteur, vector<int>(largeur, 0.0));
        vector<vector<int>>  imageCopie = image.getRouge();
        for (int i = _rayon; i < hauteur - _rayon; i++) {
            for (int j = _rayon; j < largeur - _rayon; j++) {
                float somme = 0.0;
                for (int x = -_rayon; x <= _rayon; x++) {
                    for (int y = -_rayon; y <= _rayon; y++) {
                        somme += _action[x + _rayon][y + _rayon] * imageCopie[i + x][j + y];
                    }
                }
                nouvelleImage[i][j] = somme;
            }
        }
        Image i (nouvelleImage,nouvelleImage,nouvelleImage,hauteur,largeur);
        return i;
    }
