#pragma once
#ifndef GRILLE_H
#define GRILLE_H

#include<vector>

class Grille2048 {
public:
    Grille2048();

    void afficherGrille();

    void ajouterNombreAleatoire();

    int getElement(int row, int col);

    void setElement(int row, int col, int value);

private:
    std::vector<std::vector<int>> grille;
};

#endif