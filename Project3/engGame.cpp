#include "grille.h"
#include "endGame.h"

bool isGameEnd(Grille2048 grille) {
    // check for 2048
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (grille.getElement(i, j) == 2048)
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
            if (grille.getElement(i, j) == 0)
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
                int element = grille.getElement(i, j);
                if (element != 0)
                {
                    if ((i == 0 || i == 1 || i == 2) && grille.getElement(i + 1, j) == element)
                    {
                        return false;
                    }
                    else if ((i == 1 || i == 2 || i == 3) && grille.getElement(i - 1, j) == element)
                    {
                        return false;
                    }
                    else if ((j == 0 || j == 1 || j == 2) && grille.getElement(i, j + 1) == element)
                    {
                        return false;
                    }
                    else if ((j == 1 || j == 2 || j == 3) && grille.getElement(i, j - 1) == element)
                    {
                        return false;
                    }
                    else
                    {
                        return true;
                    }
                }
            }
        }
    }
}
