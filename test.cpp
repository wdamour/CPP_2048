#include <iostream>
#include <vector>
#include <ctime>
#include <conio.h>
#include "grille.h"
#include "test.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void afficheGrilleVide() {

    Grille2048 grille;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            grille.setElement(i, j, 0);
        }
    }
    grille.afficherGrille();
}

void testMoveAndMergeSide() {

    Grille2048 grille;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            grille.setElement(i, j, 0);
        }
    }
    grille.setElement(0, 1, 2);
    grille.setElement(0, 2, 2);
    grille.setElement(1, 1, 4);
    grille.setElement(1, 2, 8);
    grille.afficherGrille();
    bool badKey = true;
    while (badKey)
    {
        // badKey = false;
        int c = 0;
        switch ((c = _getch()))
        {
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
}

void testMoveAndMergeTopBottom() {

    Grille2048 grille;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            grille.setElement(i, j, 0);
        }
    }
    grille.setElement(1, 0, 2);
    grille.setElement(1, 1, 4);
    grille.setElement(2, 0, 2);
    grille.setElement(2, 1, 8);
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
}

void testEndgame2048() {
    Grille2048 grille;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            grille.setElement(i, j, 0);
        }
    }
    grille.setElement(0, 0, 2048);
    grille.afficherGrille();
    if (grille.isGameEnd()) {
        std::cout << "Partie Terminée";
    }
}

void testFullGridPossibleSideMerge() {

    Grille2048 grille;

    grille.setElement(0, 0, 2);
    grille.setElement(0, 1, 2);
    grille.setElement(0, 2, 4);
    grille.setElement(0, 3, 8);
    grille.setElement(1, 0, 4);
    grille.setElement(1, 1, 8);
    grille.setElement(1, 2, 16);
    grille.setElement(1, 3, 4);
    grille.setElement(2, 0, 2);
    grille.setElement(2, 1, 4);
    grille.setElement(2, 2, 8);
    grille.setElement(2, 3, 2);
    grille.setElement(3, 0, 4);
    grille.setElement(3, 1, 8);
    grille.setElement(3, 2, 4);
    grille.setElement(3, 3, 16);

    grille.afficherGrille();
    bool badKey = true;
    while (badKey)
    {
        if (grille.isGameEnd()) {
            std::cout << "Partie Terminée";
            bool badKey = false;
            break;
        }
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
        
    }
}

void testFullGridPossibleTopBottomMerge() {

    Grille2048 grille;

    grille.setElement(0, 0, 4);
    grille.setElement(0, 1, 2);
    grille.setElement(0, 2, 4);
    grille.setElement(0, 3, 8);
    grille.setElement(1, 0, 4);
    grille.setElement(1, 1, 8);
    grille.setElement(1, 2, 16);
    grille.setElement(1, 3, 4);
    grille.setElement(2, 0, 2);
    grille.setElement(2, 1, 4);
    grille.setElement(2, 2, 8);
    grille.setElement(2, 3, 2);
    grille.setElement(3, 0, 4);
    grille.setElement(3, 1, 8);
    grille.setElement(3, 2, 4);
    grille.setElement(3, 3, 16);

    grille.afficherGrille();
    bool badKey = true;
    while (badKey)
    {
        if (grille.isGameEnd()) {
            std::cout << "Partie Terminée";
            bool badKey = false;
            break;
        }
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

    }
}

void testFullGridNoPOssibleMerge() {

    Grille2048 grille;

    grille.setElement(0, 0, 16);
    grille.setElement(0, 1, 2);
    grille.setElement(0, 2, 4);
    grille.setElement(0, 3, 8);
    grille.setElement(1, 0, 4);
    grille.setElement(1, 1, 8);
    grille.setElement(1, 2, 16);
    grille.setElement(1, 3, 4);
    grille.setElement(2, 0, 2);
    grille.setElement(2, 1, 4);
    grille.setElement(2, 2, 8);
    grille.setElement(2, 3, 2);
    grille.setElement(3, 0, 4);
    grille.setElement(3, 1, 8);
    grille.setElement(3, 2, 4);
    grille.setElement(3, 3, 16);

    grille.afficherGrille();
    bool badKey = true;
    while (badKey)
    {
        if (grille.isGameEnd()) {
            std::cout << "Partie Terminée";
            bool badKey = false;
            break;
        }
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

    }
}