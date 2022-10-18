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

void afficherTableau(const vector<vector<int>>tableau2D){
    for(const vector<int>& tableau1D : tableau2D) {
        for (int val : tableau1D){
            cout << val << " ";
        }
        cout << endl;
    }

}


int main() {

    vector<vector<int>>tableau(6, vector<int>(7, 0));
    afficherTableau(tableau);


    return EXIT_SUCCESS;
}
