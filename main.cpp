#include <iostream>
#include <fstream> // Important !
#include <string>
#include <vector>
#include "images.h"
#include "filtres.h"
using namespace std;

//prototype des fonctions
string saisirNomFichier();
void afficherMenu();
int saisirChoixUtilisateur();

int main()
{




/*pour le maintest.cpp il compile pas les tests par contre si on met les tests automatique
 dans le main.cpp ca marche par ce que le compilateur considere
main.cpp comme source principale */

//***********************************************menu principal*******************************************

    vector<vector<int>> red;
    vector<vector<int>> green;
    vector<vector<int>> blue;
    vector <int > rep1;
    vector <vector3d> vc;
    string fich;
    Image creerimg;

    string nomFichier = saisirNomFichier();
    // Charger l'image depuis le fichier
    Image monImage(nomFichier);
    monImage.afficherImage();

    int choixUtilisateur;
    // qst 4 et 5 de la partie 2
  do
    {
        afficherMenu();
        choixUtilisateur = saisirChoixUtilisateur();



        switch (choixUtilisateur)
        {

        case 1:
          (monImage.composanteRouge2()).afficherImage();
          break;
        case 2:
           if( monImage.detection(13,255,1))
           {
               cout<<"presente ";
           }else{cout<<"non presente"<<endl;}
            break;
        case 3:
           (monImage.niveauGris()).afficherImage();
            break;
        case 4:

            (monImage.noirBlanc(5)).afficherImage();
            break;
        case 5:

            rep1=monImage.histogrammeGris();
            for(int i=0;i<rep1.size();i++)
            {
                cout<<rep1[i];
            }
            cout<<endl;
            break;
        case 6:

            vc=monImage.histogrammeCouleur();
            break;

        case 7:


            (monImage.luminosityUp(5)).afficherImage();
            break;
        case 8:

            (monImage.luminosityDown(5)).afficherImage();
            break;
        case 9:

           ( monImage.contrasteUp(4)).afficherImage();
            break;
        case 10:

            (monImage.contrasteDown(4)).afficherImage();
            break;
        case 11:
           ( monImage.reglageAuto()).afficherImage();
            break;

        case 12:

            fich =saisirNomFichier();

            creerimg = Image(fich);
            break;
        case 13:

            monImage.creationImagePpm(fich);
            break;
             case 14:
               char co;
           cout<<"Vous voulez la rogner de quel cote choisir entre g ou d ou h ou b ?"<<endl;
           cin>>co;
           switch (co)
           {
               case 'g':
                   cout<<"image apres rogner a gauche"<<endl;
                   (monImage.rogneG()).afficherImage();
                   break;
               case 'd':
                   cout<<"image apres rogner a droite"<<endl;
                   (monImage.rogneD()).afficherImage();
                   break;
               case 'h':
                   cout<<"image apres rogner  en haut"<<endl;
                   (monImage.rogneH()).afficherImage();
                   break;
               case 'b':
                   cout<<"image apres rogner en bas"<<endl;
                   (monImage.rogneB()).afficherImage();
                   break;
           }

            break;
               case 15:
                   char co1;
                   cout<<"Vous voulez la roter de quel cote choisir entre D et G ?"<<endl;
                   cin>>co1;
                   switch(co1)
                   {
                   case 'D':
                       cout<<"Image apres rotation a droite "<<endl;
                    (monImage.rotationD()).afficherImage();
                    break;
                   case 'G':
                        cout<<"Image apres rotation a gauche "<<endl;
                       (monImage.rotationG()).afficherImage();
                       break;

                   }
                   case 16:
                       char co2;
                   cout<<"Vous voulez la retourner de quel cote choisir entre H et V ?"<<endl;
                   cin>>co2;
                   switch(co2)
                   {
                   case 'H':
                       cout<<"Image apres son retournement  horizentalement "<<endl;
                    (monImage.returnmentH()).afficherImage();
                    break;
                   case 'V':
                        cout<<"Image apres son retournement verticalement "<<endl;
                       (monImage.returnmentV()).afficherImage();
                       break;

                   }
                   case 17 :
                       int f;
                       cout<<"donner un facteur pour agrandir l'image"<<endl;
                       cin>>f;

                    cout<<"Image apres son agrandissement :"<<endl;
                    (monImage.agrandissement(f)).afficherImage();
                    break;




        default:
            cout << "Choix invalide. " << endl;
            break;
        }

    }while (choixUtilisateur != 18);

    //qst 2 de la partie 4

 /*vector<vector<float>> vec = {{1.0/16.0,1.0/8.0,1.0/16.0},{1.0/8.0,1.0/4.0,1.0/8.0},{1.0/16.0,1.0/8.0,1.0/16.0}};
  Filtre flouG3(vec,1);*/


   return 0;
}



// QST 1 de la partie 2
string saisirNomFichier()
{
    string nomFichier;
    cout << "Veuillez saisir le nom du fichier image au format ppm : ";
    cin >> nomFichier;
    return nomFichier;
}
void afficherMenu()
{
    cout << "===== Menu =====" << endl;
    cout << "1. Composante Rouge" << endl;
    cout << "2. Detection" << endl;
    cout << "3.Niveau gris" << endl;
    cout << "4.NoirBlanc" << endl;
    cout << "5.histogrammeGris" << endl;
    cout << "6.histogrammeCouleur" << endl;
    cout << "7.luminosityUp pour diminuer la luminosite" << endl;
    cout << "8.luminosityDown pour diminuer la luminosite" << endl;
    cout << "9.contrasteUp" << endl;
    cout << "10.contrasteDown" << endl;
    cout << "11.reglageAuto" << endl;
    cout << "12.creer une image a partir du fichier" << endl;
    cout << "13.enregistrer un nouveau fichier image a partir d'une image" << endl;
    cout << "14.Rogner l'image a gauche , a droite , en haut ou en bas" << endl;
    cout << "15.rotation de l'image a gauche ou a droite" << endl;
    cout << "16.retournement de l'image horizentalent ou verticalement" << endl;
    cout << "17.agrandissement de l'image " << endl;
    cout <<"18.Quitter le programme !!"<<endl;

}
int saisirChoixUtilisateur()
{
    int choix;
    cout << "Veuillez choisir une option du menu : ";
    cin >> choix;
    return choix;
}
