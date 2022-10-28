/*
-----------------------------------------------------------------------------------
Nom du fichier  : Puissance4.h
Auteur(s)       : Chloé Salamin, Guilherme Pinto
Date creation   : 22.10.2022

Description     : Contient les méthodes pour le déroulement du jeu.
                  La méthode pour déterminer le gagnant et
                  les méthodes de vérification si un joueur à gagné pour chaque cas.

Remarque(s)     :

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#ifndef MANDELBROT_PUISSANCE4_H
#define MANDELBROT_PUISSANCE4_H

std::vector<std::vector<int>> jouer(std::vector<std::vector<int>> &tableau,
                                    int joueur, int &ligne,
                                    int colonne, bool &erreur);

bool joueurAGagne(const std::vector<std::vector<int>> &tableau, int &joueur,
                  int ligne, int colonne, int nombreCoup, bool &erreur);


bool verifDiagonaleDroite(int decalageDroite, int decalageGauche,
                          int decalageHaut, int decalageBas,
                          const std::vector<std::vector<int>> &tableau, int ligne,
                          int colonne);

bool verifDiagonaleGauche(int decalageDroite, int decalageGauche,
                          int decalageHaut, int decalageBas,
                          const std::vector<std::vector<int>> &tableau, int ligne,
                          int colonne);

bool verifHorizontal(int debutColonne, int finColonne,
                     const std::vector<std::vector<int>> &tableau,
                     int ligne, int colonne);

bool verifVertical(int debutLigne, int finLigne,
                   const std::vector<std::vector<int>> &tableau,
                   int ligne, int colonne);

#endif //MANDELBROT_PUISSANCE4_H
