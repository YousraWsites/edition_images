#ifndef FILTRES_H_INCLUDED
#define FILTRES_H_INCLUDED

#include <iostream>
#include <vector>



class filtre{
    private:
        vector<vector<float> > _action;
        int _rayon;
    public:
        filtre();
        filtre(const vector<vector<float>> & filtre, int r){
              _action = filtre;
             _rayon = r;
        }
        Image application( Image& image);
};
#endif // FILTRES_H_INCLUDED
