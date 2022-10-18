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

vector<vector<int>> jouer(vector<vector<int>> &tableau, const int JOUEUR,
                          int colonne, const int TAILLE_LIGNE, const int
                          TAILLE_COLONNE) {
   int ligne;
   for (ligne = TAILLE_LIGNE; ligne > 0;) {
      if(tableau.at(ligne).at(colonne) == 0){
         tableau.at(ligne).at(colonne) = JOUEUR;
      } else{
         ligne--;
      }
   }
   //tableau.at(ligne).at(colonne) = JOUEUR;
   return tableau;
}



int main() {


   //cin >>
   const int JOUEUR1 = 1, JOUEUR2 = 2, TAILLE_LIGNE = 6, TAILLE_COLONNE = 7;
   int ligne = 2, colonne = 5;
   //vector<vector<int>> tableau(6, vector<int>(7, 0));

   vector<vector<int>> tableau(TAILLE_LIGNE, vector<int>(TAILLE_COLONNE, 0));
   jouer(tableau, JOUEUR1, ligne, colonne);
   afficherTableau(tableau);

   return EXIT_SUCCESS;
}
