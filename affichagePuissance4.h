/*
-----------------------------------------------------------------------------------
Nom du fichier  : affichagePuissance4.h
Auteur(s)       : Chloé Salamin, Guilherme Pinto
Date creation   : 22.10.2022

Description     : Contient la méthode qui affiche le plateau de jeu
                  et la méthode pour effacer la console à chaque tour.

Remarque(s)     : La méthode pour effacer la console fonctionne
                  sur console windows (console extern) et non sur le terminal.

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#ifndef MANDELBROT_AFFICHAGEPUISSANCE4_H
#define MANDELBROT_AFFICHAGEPUISSANCE4_H

void afficherTableau(const std::vector<std::vector<int>> &tableau);

void effacerConsole();

#endif //MANDELBROT_AFFICHAGEPUISSANCE4_H
