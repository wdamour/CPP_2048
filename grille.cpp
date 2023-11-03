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
                std::cout << "|" << BLACK << "   -" << RESET;
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

bool Grille2048::isGameEnd() {
    // check for 2048
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (getElement(i, j) == 2048)
            {
                return true;
            }
        }
    }
    // check for empty spot
    bool isEmpty = false;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (getElement(i, j) == 0)
            {
                isEmpty = true;
                return false;
            }
        }
    }
    // check if possible move
    if (!isEmpty)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int element = getElement(i, j);
                if (element != 0)
                {
                    if ((i == 0 || i == 1 || i == 2) && getElement(i + 1, j) == element)
                    {
                        return false;
                    }
                    else if ((i == 1 || i == 2 || i == 3) && getElement(i - 1, j) == element)
                    {
                        return false;
                    }
                    else if ((j == 0 || j == 1 || j == 2) && getElement(i, j + 1) == element)
                    {
                        return false;
                    }
                    else if ((j == 1 || j == 2 || j == 3) && getElement(i, j - 1) == element)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}

void Grille2048::moveUp() {
    for (int i = 1; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int element = getElement(i, j);
            if (element != 0)
            {
                int i2 = i - 1;
                while (i2 >= 0 && getElement(i2, j) == 0)
                {
                    i2 -= 1;
                }
                i2 += 1;
                if (i2 - 1 >= 0 && getElement(i2 - 1, j) == element)//merge 
                {
                    setElement(i2 - 1, j, element * 2);
                    setElement(i, j, 0);
                }
                else if (i2 != i)
                {
                    setElement(i2, j, element);
                    setElement(i, j, 0);
                }
            }
        }
    }
}

void Grille2048::moveDown() {
    for (int i = 2; i >= 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            int element = getElement(i, j);
            if (element != 0)
            {
                int i2 = i + 1;
                while (i2 <= 3 && getElement(i2, j) == 0)
                {
                    i2 += 1;
                }
                i2 -= 1;
                if (i2 + 1 <= 3 && getElement(i2 + 1, j) == element)//merge
                {
                    setElement(i2 + 1, j, element * 2);
                    setElement(i, j, 0);
                }
                else if (i2 != i)
                {
                    setElement(i2, j, element);
                    setElement(i, j, 0);
                }
            }
        }
    }
}

void Grille2048::moveLeft() {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            int element = getElement(i, j);
            if (element != 0)
            {
                int j2 = j - 1;
                while (j2 >= 0 && getElement(i, j2) == 0)
                {
                    j2 -= 1;
                }
                j2 += 1;
                if (j2 - 1 >= 0 && getElement(i, j2 - 1) == element)//merge
                {
                    setElement(i, j2 - 1, element * 2);
                    setElement(i, j, 0);
                }
                else if (j2 != j)
                {
                    setElement(i, j2, element);
                    setElement(i, j, 0);
                }
            }
        }
    }
}

void Grille2048::moveRight() {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 2; j >= 0; j--)
        {
            int element = getElement(i, j);
            if (element != 0)
            {
                int j2 = j + 1;
                while (j2 <= 3 && getElement(i, j2) == 0)
                {
                    j2 += 1;
                }
                j2 -= 1;
                if (j2 + 1 <= 3 && getElement(i, j2 + 1) == element)//merge
                {
                    setElement(i, j2 + 1, element * 2);
                    setElement(i, j, 0);
                }
                else if (j2 != j)
                {
                    setElement(i, j2, element);
                    setElement(i, j, 0);
                }
            }
        }
    }
}

void Grille2048::afficherGrilleWindow(Window* window, SDL_Texture* texture[11])
{
    GameObject grilleBackground(50, 50, 500, 500, -1);
    grilleBackground.drawRectangle(window->getRenderer());
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            GameObject cell(j * 100 + j * 20 + 70, i * 100 + i * 20 + 70, 100, 100, grille[i][j]);
            if (grille[i][j] == 0) {
                cell.drawRectangle(window->getRenderer());
            }
            else {
                int number = grille[i][j];
                switch (number)
                {
                case 2:
                    cell.drawImage(texture[0], window->getRenderer());
                    break;
                case 4:
                    cell.drawImage(texture[1], window->getRenderer());
                    break;
                case 8:
                    cell.drawImage(texture[2], window->getRenderer());
                    break;
                case 16:
                    cell.drawImage(texture[3], window->getRenderer());
                    break;
                case 32:
                    cell.drawImage(texture[4], window->getRenderer());
                    break;
                case 64:
                    cell.drawImage(texture[5], window->getRenderer());
                    break;
                case 128:
                    cell.drawImage(texture[6], window->getRenderer());
                    break;
                case 256:
                    cell.drawImage(texture[7], window->getRenderer());
                    break;
                case 512:
                    cell.drawImage(texture[8], window->getRenderer());
                    break;
                case 1024:
                    cell.drawImage(texture[9], window->getRenderer());
                    break;
                case 2048:
                    cell.drawImage(texture[10], window->getRenderer());
                    break;
                default:
                    break;
                }

            }
        }
    }
    window->Update();
}