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
#include <limits>

using namespace std;

void afficherTableau(const vector<vector<int>> &tableau) {
    for (const vector<int> &tableau1D: tableau) {
        for (int val: tableau1D) {
            cout << val << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> jouer(vector<vector<int>> &tableau,int joueur, int &ligne,
                          int colonne, const int TAILLE_LIGNE, bool erreur) {

    for (ligne = TAILLE_LIGNE - 1; ligne >= 0;) {
        if (tableau.at(ligne).at(colonne) == 0) {
            tableau.at(ligne).at(colonne) = joueur;
            return tableau;
        } else {
            ligne--;
        }
    }
    erreur = true;
    cout << endl << "Erreur cette colonne est deja complete. Rejouer dans une autre"
                    " colonne svp.";
}


bool verficationHorizental(){

}

bool verficationVertical(){

}


bool verficationDiagonale(){

}

bool joueurAGagne(const vector<vector<int>> &tableau, int ligne, int colonne, int nombreCoup , bool erreur,int joueur){
    if (erreur){
        return false;
    } else {
        if (nombreCoup  >= 7){
            if (verficationHorizental() == true|| verficationVertical() == true || verficationDiagonale() == true){
                return true;
            }
        } else {
            joueur = joueur % 2 + 1;
        }
    }
}



int main() {


    //cin >>
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
        colonne--;
        jouer(tableau, joueur,ligne, colonne, TAILLE_LIGNE, erreur);

        afficherTableau(tableau);
        if (joueurAGagne(tableau, ligne, colonne, nombreCoup, erreur, joueur)){
            gagnant = true;
            break;
        }
    }

    if (gagnant){
        cout << "Bravo! Joueur " << joueur << " a gagne!" << endl;
    } else {
        cout << "Match nul!" << endl;
    }


    return EXIT_SUCCESS;
}
