/*
-----------------------------------------------------------------------------------
Nom du fichier  : affichagePuissance4.cpp
Auteur(s)       : Chloé Salamin, Guilherme Pinto
Date creation   : 22.10.2022

Description     : <à compléter>

Remarque(s)     : <à compléter>

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include "affichagePuissance4.h"

using namespace std;

void afficherTableau(const vector<vector<int>> &tableau) {
   for (const vector<int> &tableau1D: tableau) {
      cout << "|";
      for (int val: tableau1D) {
         cout << setw(2) << val << setw(2) << "|";
      }
      cout << endl;
   }
   cout << endl;
}