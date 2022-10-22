/*
-----------------------------------------------------------------------------------
Nom du fichier  : main.cpp
Auteur(s)       : Chloé Salamin, Guilherme Pinto
Date creation   : 18.10.2022

Description     : <à compléter>

Remarque(s)     : À exécuter sur la console Windows. (Problème avec le clear)

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#include <cstdlib>
#include <iostream>
#include <vector>
#include <limits>
#include "affichagePuissance4.h"
#include "Puissance4.h"

using namespace std;

int main() {

   cout << "******************" << endl
        << "* " << "Regles du Jeu:" << " *" << endl
        << "******************" << endl
        << "Le but du jeu est d'aligner une suite de 4 pions de meme couleur sur "
        << "une grille comptant 6 rangees et 7 colonnes. Chaque joueur dispose de "
        << "21 pions d'une couleur (par convention, en general jaune ou rouge). "
        << "Tour a tour, les deux joueurs placent un pion dans la colonne de leur "
        << "choix, le pion coulisse alors jusqu'a la position la plus basse possible"
        << " dans la dite colonne a la suite de quoi c'est a l'adversaire de jouer."
        << " Le vainqueur est le joueur qui realise le premier un alignement "
        << "(horizontal, vertical ou diagonal) consecutif d'au moins quatre "
        << "pions de sa couleur. Si, alors que toutes les cases de la grille de"
        << " jeu sont remplies, aucun des deux joueurs n'a realise un tel "
        << "alignement, la partie est declaree nulle." << endl
        << endl << endl
        << "******************" << endl
        << "* " << "Comment jouer:" << " *" << endl
        << "******************" << endl
        << "Ce programme va demander a tour de role au joueur 1 et au joueur 2 de"
        << " jouer. Le joueur doit entrer le numero de la colonne dans laquelle il"
        << " souhaite deposer un pion. Le pion joue est represente par un 1 pour "
        << "le joueur 1 et un 2 pour le joueur 2. Les colonnes jouables sont 7 "
        << " de 1 a 7." << endl << endl;

   const int TAILLE_LIGNE = 6, TAILLE_COLONNE = 7;
   int ligne, colonne, nombreCoup, joueur = 1;
   bool erreur = false, saisieOK, gagnant = false;

   vector<vector<int>> tableau(TAILLE_LIGNE, vector<int>(TAILLE_COLONNE, 0));

   for (nombreCoup = 0; nombreCoup < TAILLE_LIGNE * TAILLE_COLONNE; ++nombreCoup) {

      do {

         cout << "Joueur " << joueur << endl
              << "Veuillez entrer le numero de la colonne dans laquelle "
              << "vous souhaitez jouer (1 - " << TAILLE_COLONNE << ") : ";
         if (!(saisieOK = cin >> colonne &&
                          colonne <= TAILLE_COLONNE && colonne > 0)) {
            cin.clear();
            cout << "Erreur avec la valeur que vous avez introduite. Veuillez bien "
                 << "entrer un numero de colonnes entre 1 et " << TAILLE_COLONNE
                 << "." << endl;
         }
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } while (!saisieOK);
      cout << endl;
      colonne--;
      jouer(tableau, joueur, ligne, colonne, TAILLE_LIGNE, erreur);
      afficherTableau(tableau);
      gagnant = joueurAGagne(tableau, joueur, ligne, colonne, nombreCoup, erreur);
      if (gagnant) {
         //gagnant = true;
         break;
      }
   }

   if (gagnant) {
      cout << "Bravo! Joueur " << joueur << " a gagne!" << endl;
   } else {
      cout << "Match nul!" << endl;
   }

   system("pause");
   return EXIT_SUCCESS;
}
