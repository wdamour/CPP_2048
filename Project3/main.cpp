#include <iostream>
#include <vector>
#include <ctime>
#include <conio.h>
#include "grille.h"
#include "move.h"
#include "endGame.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int main() {
    Grille2048 grille;
    grille.afficherGrille();
    bool badKey = true;
    while (badKey)
    {
        // badKey = false;
        int c = 0;
        switch ((c = _getch()))
        {
        case KEY_UP:
            moveUp(&grille);
            grille.ajouterNombreAleatoire();
            system("cls");
            grille.afficherGrille();
            if (isGameEnd(grille))
            {
                std::cout << "Partie Terminéé";
                bool badKey = false;
            }
            break;
        case KEY_DOWN:
            moveDown(&grille);
            grille.ajouterNombreAleatoire();
            system("cls");
            grille.afficherGrille();
            if (isGameEnd(grille))
            {
                std::cout << "Partie Terminéé";
                bool badKey = false;
            }
            break;
        case KEY_RIGHT:
            moveRight(&grille);
            grille.ajouterNombreAleatoire();
            system("cls");
            grille.afficherGrille();
            if (isGameEnd(grille))
            {
                std::cout << "Partie Terminéé";
                bool badKey = false;
            }
            break;
        case KEY_LEFT:
            moveLeft(&grille);
            grille.ajouterNombreAleatoire();
            system("cls");
            grille.afficherGrille();
            if (isGameEnd(grille))
            {
                std::cout << "Partie Terminéé";
                bool badKey = false;
            }
            break;
        default:
            badKey = true;
            break;
        }
        if (isGameEnd(grille)) {
            break;
        }
    }

    return 0;
}