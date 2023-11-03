#include <iostream>
#include <vector>
#include <ctime>
#include <conio.h>
#include "grille.h"
#include "main_console.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int main_console() {

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
            grille.moveUp();
            grille.ajouterNombreAleatoire();
            system("cls");
            grille.afficherGrille();
            break;
        case KEY_DOWN:
            grille.moveDown();
            grille.ajouterNombreAleatoire();
            system("cls");
            grille.afficherGrille();
            break;
        case KEY_RIGHT:
            grille.moveRight();
            grille.ajouterNombreAleatoire();
            system("cls");
            grille.afficherGrille();
            break;
        case KEY_LEFT:
            grille.moveLeft();
            grille.ajouterNombreAleatoire();
            system("cls");
            grille.afficherGrille();
            break;
        default:
            badKey = true;
            break;
        }
        if (grille.isGameEnd()) {
            std::cout << "Partie Terminée";
            bool badKey = false;
            break;
        }
    }

    return 0;
}