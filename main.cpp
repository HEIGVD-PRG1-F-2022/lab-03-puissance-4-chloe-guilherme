/*
-----------------------------------------------------------------------------------
Nom du fichier  : main.cpp
Auteur(s)       : Chloé Salamin,Guilherme Pinto
Date creation   : 18.10.2022

Description     : <à compléter>

Remarque(s)     : <à compléter>

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void afficherTableau(const vector<vector<int>>&tableau){
    for(const vector<int>& tableau1D : tableau) {
        for (int val : tableau1D){
            cout << val << " ";
        }
        cout << endl;
    }
}

vector<vector<int>>jouer(vector<vector<int>>tableau, const int JOUEUR, int ligne, int colonne){
    tableau.at(ligne).at(colonne) = JOUEUR;
    return tableau;
}



int main() {

    vector<vector<int>>tableau(6, vector<int>(7, 0));
    afficherTableau(tableau);



    return EXIT_SUCCESS;
}
