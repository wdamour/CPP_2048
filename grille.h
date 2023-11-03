#pragma once
#ifndef GRILLE_H
#define GRILLE_H

#include<vector>
#include <SDL.h>
#include "GameObject.h"
#include "window.h"

class Grille2048 {
public:
    Grille2048();

    void afficherGrille();

    void ajouterNombreAleatoire();

    int getElement(int row, int col);

    void setElement(int row, int col, int value);

    bool isGameEnd();

    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight();

    void afficherGrilleWindow(Window* window, SDL_Texture* texture[11]);

private:
    std::vector<std::vector<int>> grille;
};

#endif