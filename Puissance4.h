/*
-----------------------------------------------------------------------------------
Nom du fichier  : Puissance4.h
Auteur(s)       : Chloé Salamin, Guilherme Pinto
Date creation   : 22.10.2022

Description     : <à compléter>

Remarque(s)     : <à compléter>

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#ifndef MANDELBROT_PUISSANCE4_H
#define MANDELBROT_PUISSANCE4_H

bool joueurAGagne(const std::vector<std::vector<int>> &tableau, int &joueur,
                  int ligne, int colonne, int nombreCoup, bool erreur);

std::vector<std::vector<int>> jouer(std::vector<std::vector<int>> &tableau,
                                    int joueur, int &ligne,
                                    int colonne, const int TAILLE_LIGNE,
                                    bool &erreur);

bool verfication(std::vector<std::vector<int>> tableau, int ligne, int colonne);
#endif //MANDELBROT_PUISSANCE4_H
