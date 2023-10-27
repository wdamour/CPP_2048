#include <iostream>
#include <vector>
#include <ctime>
#include "grille.h"

#define BLACK   "\033[30m"
#define RESET   "\033[0m"

const int SIZE = 4;


Grille2048::Grille2048() :grille(SIZE, std::vector<int>(SIZE, 0)) {
    // Initialisation de la graine du générateur de nombres aléatoires
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // Ajout de deux nombres aléatoires (2 ou 4) lors de la création de la grille
    ajouterNombreAleatoire();
    ajouterNombreAleatoire();
}


// Fonction pour afficher la grille du jeu
void Grille2048::afficherGrille() {
    for (int i = 0; i < 4; i++) {
        std::cout << "____________________" << std::endl;
        std::cout << "|    |    |    |    |" << std::endl;
        for (int j = 0; j < 4; j++) {
            if (grille[i][j] == 0) {
                std::cout <<"|" << BLACK << "   -" << RESET;
            }
            else if (grille[i][j] < 10) {
                std::cout << "|   " << grille[i][j];
            }
            else if (grille[i][j] < 100) {
                std::cout << "|  " << grille[i][j];
            }
            else if (grille[i][j] < 1000) {
                std::cout << "| " << grille[i][j];
            }
            else {
                std::cout << "|" << grille[i][j];
            }
        }
        std::cout << "|" << std::endl << "|    |    |    |    |" << std::endl;
    }
    std::cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
    std::cout << std::endl;
}

// Fonction pour ajouter un nombre aléatoire (2 ou 4) à un emplacement vide
void Grille2048::ajouterNombreAleatoire() {
    std::vector<std::pair<int, int>> casesVides;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grille[i][j] == 0) {
                casesVides.push_back(std::make_pair(i, j));
            }
        }
    }

    if (casesVides.size() > 0) {
        int index = std::rand() % casesVides.size();
        int newValue = (std::rand() % 2 + 1) * 2; // Génère un 2 ou un 4
        grille[casesVides[index].first][casesVides[index].second] = newValue;
    }
}

int Grille2048::getElement(int row, int col) {
    return grille[row][col];
}

void Grille2048::setElement(int row, int col, int value) {
    grille[row][col] = value;
}
