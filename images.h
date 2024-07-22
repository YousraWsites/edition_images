#ifndef IMAGES_H_INCLUDED
#define IMAGES_H_INCLUDED
#include <iostream>
#include <vector>

using namespace std;

void supprimepremier(vector<vector<int> > & tab1 );
vector<vector<int> > rotationshun(vector<vector<int> > & tab1);
vector<vector<int> > rotationni(vector<vector<int> > & tab1);
vector<vector<int> > transitionH(vector<vector<int> > & tab1);
vector<vector<int> > transitionV(vector<vector<int> > & tab1);
vector<vector<int> > agrandir(vector<vector<int> > & tab1,int k);
class vector3d{
    private:
        int px;
        int py;
        int pz;
    public:
        vector3d(int x= 0,int y= 0,int z= 0){
            px = x;
            py = y;
            pz = z;
        }
         int getRouge() const { return px; }
         int getVert() const { return py; }
         int getBleu() const { return pz; }

         void setRouge(int r) { px = r; }
         void setVert(int v) { py = v; }
         void setBleu(int b) { pz = b; }
         void augementer();//question 11

};
class Image
{
private:
    vector < vector <int> > _rouge;
    vector < vector <int> > _vert;
    vector < vector <int> > _bleu;
    int _longueur;
    int _largeur;

public:

    Image();
    //constructeur avec argument
    Image(vector < vector <int> >,vector < vector <int> >,vector < vector <int> >,int,int);
    //constructeur de la partie 2
    Image(const string &picture);
    //methode pour afficher une image
    void afficherImage();
    //qst 2
    bool vectorverifier(vector < vector <int> >,vector < vector <int> >,vector < vector <int> >);
    //qst 3

   Image composanteRouge2() const;
    //qst 4
    bool detection(int,int,int);
    //qst 5
    Image niveauGris();
    vector<vector<int>>getRouge() const ;
    vector<vector<int>>getVert() const ;
    vector<vector<int>>getBleu() const ;

    //qst 7
     Image noirBlanc(int );
    //qst 8
     vector<int> histogrammeGris();
     //qst 9
     vector<vector3d> histogrammeCouleur();
     // histo 2
     vector<vector3d> histogrammeCouleur() const;
     //qst 10
     Image luminosityUp(float fac1);
    Image luminosityDown(float fact2);
    //qst 11
     Image contrasteUp(float facteur);
     Image contrasteDown(float facteur);
    //qst 12
    Image reglageAuto();

//partie2
   //qst 3
   void creationImagePpm(const string & picture);
//partie 3
      //qst 1
        Image rogneD();
        Image rogneG();
        Image rogneH();
        Image rogneB();
      //qst 2 et 3
        Image rotationD();
        Image rotationG();
      //qst 4
        Image returnmentH();
        Image returnmentV();
      //qst 5
        Image agrandissement(int k);

};








#endif // IMAGES_H_INCLUDED
