/*
-----------------------------------------------------------------------------------
Nom du fichier  : Puissance4.cpp
Auteur(s)       : Chloé Salamin, Guilherme Pinto
Date creation   : 22.10.2022

Description     : <à compléter>

Remarque(s)     : <à compléter>

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include "Puissance4.h"
using namespace std;


bool joueurAGagne(const vector<vector<int>> &tableau, int &joueur, int ligne,
                  int colonne, int nombreCoup, bool &erreur) {

   if (erreur) {
      erreur = false;
      cout << endl << "Erreur cette colonne est deja complete. Rejouer dans une "
           << "autre colonne svp." << endl;
      return false;
   } else {
      if (nombreCoup >= 7) {
         if (verfication(tableau, ligne, colonne)) {
            return true;
         }
      }
      joueur = joueur % 2 + 1;
   }
   return false;
}

vector<vector<int>> jouer(vector<vector<int>> &tableau, int joueur, int &ligne,
                          int colonne, bool& erreur) {

   const int TAILLE_LIGNE = (int) tableau.size();
   for (ligne = TAILLE_LIGNE - 1; ligne >= 0;) {
      if (tableau.at(ligne).at(colonne) == 0) {
         tableau.at(ligne).at(colonne) = joueur;
         return tableau;
      } else {
         ligne--;
      }
   }
   erreur = true;
   return tableau;
}


bool verfication(const vector<vector<int>> &tableau, int ligne, int colonne) {

   /*
   // Verification Horizontal
   const int TAILLE_COLONNE = (int) tableau.at(0).size();
   int compteurVictoire = 0;

   int decalageGauche = colonne > 3 ? 3 : colonne;
   int debutColonne = colonne - decalageGauche;

   int decalageDroite = TAILLE_COLONNE - colonne > 3 ? 3 :
                        TAILLE_COLONNE - 1 - colonne;
   int finColonne = colonne + decalageDroite;

   for (int col = debutColonne; col <= finColonne; ++col) {
      if (tableau.at(ligne).at(colonne) ==
          tableau.at(ligne).at(col)) {
         compteurVictoire++;
         if (compteurVictoire > 3) {
            return true;
         }
      } else {
         compteurVictoire = 0;
      }
   }
   compteurVictoire = 0;


   // Verification vertical
   const int TAILLE_LIGNE = (int) tableau.size();

   int decalageHaut = ligne > 3 ? 3 : ligne;
   int debutLigne = ligne - decalageHaut;

   int decalageBas = TAILLE_LIGNE - ligne > 3 ? 3 :
                     TAILLE_LIGNE - 1 - ligne;
   int finLigne = ligne + decalageBas;
   for (int l = debutLigne; l <= finLigne; ++l) {
      if (tableau.at(ligne).at(colonne) ==
          tableau.at(l).at(colonne)) {
         compteurVictoire++;
         if (compteurVictoire > 3) {
            return true;
         }
      } else {
         compteurVictoire = 0;
      }
   }
   compteurVictoire = 0;


   // Verification diagonale droite "/"
   if (decalageBas < decalageGauche) {
      decalageGauche = decalageBas;
   } else {
      decalageBas = decalageGauche;
   }
   if (decalageHaut < decalageDroite) {
      decalageDroite = decalageHaut;
   } else {
      decalageHaut = decalageDroite;

   }
   debutLigne = ligne - decalageHaut;
   finLigne = ligne + decalageBas;
   debutColonne = colonne - decalageGauche;
   finColonne = colonne + decalageDroite;
   for (int l = debutLigne; l <= finLigne; --finColonne,
      ++l) {
      for (int col = finColonne; col >= debutColonne && col > finColonne - 1;
           --col) {
         if (tableau.at(ligne).at(colonne) ==
             tableau.at(l).at(col)) {
            compteurVictoire++;
            if (compteurVictoire > 3) {
               return true;
            }
         } else {
            compteurVictoire = 0;
         }
      }
   }
   compteurVictoire = 0;


   // Verifier Diagonale gauche "\"
   if (decalageBas < decalageDroite) {
      decalageDroite = decalageBas;
   } else {
      decalageBas = decalageDroite;
   }
   if (decalageHaut < decalageGauche) {
      decalageGauche = decalageHaut;
   } else {
      decalageHaut = decalageGauche;
   }

   debutLigne = ligne - decalageHaut;
   finLigne = ligne + decalageBas;
   debutColonne = colonne - decalageGauche;
   finColonne = colonne + decalageDroite;

   for (int l = debutLigne; l <= finLigne; ++debutColonne, ++l) {
      for (int col = debutColonne; col <= finColonne && col < debutColonne + 1;
           ++col) {
         if (tableau.at(ligne).at(colonne) ==
             tableau.at(l).at(col)) {
            compteurVictoire++;
            if (compteurVictoire > 3) {
               return true;
            }
         } else {
            compteurVictoire = 0;
         }
      }
   }
   return false;
    */

   const int TAILLE_COLONNE = (int) tableau.at(0).size();
   const int TAILLE_LIGNE = (int) tableau.size();

   int decalageGauche = colonne > 3 ? 3 : colonne;
   int debutColonne = colonne - decalageGauche;

   int decalageDroite = TAILLE_COLONNE - colonne > 3 ? 3 :
                        TAILLE_COLONNE - 1 - colonne;
   int finColonne = colonne + decalageDroite;

   int decalageHaut = ligne > 3 ? 3 : ligne;
   int debutLigne = ligne - decalageHaut;

   int decalageBas = TAILLE_LIGNE - ligne > 3 ? 3 :
                     TAILLE_LIGNE - 1 - ligne;
   int finLigne = ligne + decalageBas;

   bool verif = verifHorizontal(debutColonne, finColonne, tableau, ligne, colonne);

   verif = verif || verifVertical(debutLigne, finLigne, tableau, ligne, colonne);

   verif = verif || verifDiagonaleDroite(decalageDroite, decalageGauche,
                                         decalageHaut, decalageBas,
                                         tableau, ligne, colonne);

   verif = verif || verifDiagonaleGauche(decalageDroite, decalageGauche,
                                         decalageHaut, decalageBas,
                                         tableau, ligne, colonne);
   return verif;
}

bool verifDiagonaleDroite(int decalageDroite, int decalageGauche,
                          int decalageHaut, int decalageBas,
                          const vector<vector<int>> &tableau, int ligne,
                          int colonne) {
   // Verification diagonale droite "/"
   int compteurVictoire = 0;
   if (decalageBas < decalageGauche) {
      decalageGauche = decalageBas;
   } else {
      decalageBas = decalageGauche;
   }
   if (decalageHaut < decalageDroite) {
      decalageDroite = decalageHaut;
   } else {
      decalageHaut = decalageDroite;

   }
   int debutLigne = ligne - decalageHaut;
   int finLigne = ligne + decalageBas;
   int debutColonne = colonne - decalageGauche;
   int finColonne = colonne + decalageDroite;
   for (int l = debutLigne; l <= finLigne; --finColonne,
      ++l) {
      for (int col = finColonne; col >= debutColonne && col > finColonne - 1;
           --col) {
         if (tableau.at(ligne).at(colonne) ==
             tableau.at(l).at(col)) {
            compteurVictoire++;
            if (compteurVictoire > 3) {
               return true;
            }
         } else {
            compteurVictoire = 0;
         }
      }
   }
   return false;
}

bool verifDiagonaleGauche(int decalageDroite, int decalageGauche,
                          int decalageHaut, int decalageBas,
                          const vector<vector<int>> &tableau, int ligne,
                          int colonne) {
   // Verifier Diagonale gauche "\"
   int compteurVictoire = 0;
   if (decalageBas < decalageDroite) {
      decalageDroite = decalageBas;
   } else {
      decalageBas = decalageDroite;
   }
   if (decalageHaut < decalageGauche) {
      decalageGauche = decalageHaut;
   } else {
      decalageHaut = decalageGauche;
   }

   int debutLigne = ligne - decalageHaut;
   int finLigne = ligne + decalageBas;
   int debutColonne = colonne - decalageGauche;
   int finColonne = colonne + decalageDroite;

   for (int l = debutLigne; l <= finLigne; ++debutColonne, ++l) {
      for (int col = debutColonne; col <= finColonne && col < debutColonne + 1;
           ++col) {
         if (tableau.at(ligne).at(colonne) ==
             tableau.at(l).at(col)) {
            compteurVictoire++;
            if (compteurVictoire > 3) {
               return true;
            }
         } else {
            compteurVictoire = 0;
         }
      }
   }
   return false;
}

bool verifHorizontal(int debutColonne, int finColonne,
                     const vector<vector<int>> &tableau,
                     int ligne, int colonne) {
   // Verification Horizontal
   int compteurVictoire = 0;

   for (int col = debutColonne; col <= finColonne; ++col) {
      if (tableau.at(ligne).at(colonne) ==
          tableau.at(ligne).at(col)) {
         compteurVictoire++;
         if (compteurVictoire > 3) {
            return true;
         }
      } else {
         compteurVictoire = 0;
      }
   }
   return false;
}

bool verifVertical(int debutLigne, int finLigne,
                   const vector<vector<int>> &tableau,
                   int ligne, int colonne) {
   // Verification vertical
   int compteurVictoire = 0;

   for (int l = debutLigne; l <= finLigne; ++l) {
      if (tableau.at(ligne).at(colonne) ==
          tableau.at(l).at(colonne)) {
         compteurVictoire++;
         if (compteurVictoire > 3) {
            return true;
         }
      } else {
         compteurVictoire = 0;
      }
   }
   return false;
}