#include "grille.h"
#include "move.h"

void moveUp(Grille2048* grille) {
    for (int i = 1; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int element = (*grille).getElement(i, j);
            if (element != 0)
            {
                int i2 = i - 1;
                while (i2 >= 0 && (*grille).getElement(i2, j) == 0)
                {
                    i2 -= 1;
                }
                i2 += 1;
                if (i2 - 1 >= 0 && (*grille).getElement(i2 - 1, j) == element)//merge 
                {
                    (*grille).setElement(i2 - 1, j, element * 2);
                    (*grille).setElement(i, j, 0);
                }
                else if (i2 != i)
                {
                    (*grille).setElement(i2, j, element);
                    (*grille).setElement(i, j, 0);
                }
            }
        }
    }
}

void moveDown(Grille2048* grille) {
    for (int i = 2; i >= 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            int element = (*grille).getElement(i, j);
            if (element != 0)
            {
                int i2 = i + 1;
                while (i2 <= 3 && (*grille).getElement(i2, j) == 0)
                {
                    i2 += 1;
                }
                i2 -= 1;
                if (i2 + 1 <= 3 && (*grille).getElement(i2 + 1, j) == element)//merge
                {
                    (*grille).setElement(i2 + 1, j, element * 2);
                    (*grille).setElement(i, j, 0);
                }
                else if (i2 != i)
                {
                    (*grille).setElement(i2, j, element);
                    (*grille).setElement(i, j, 0);
                }
            }
        }
    }
}

void moveLeft(Grille2048* grille) {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            int element = (*grille).getElement(i, j);
            if (element != 0)
            {
                int j2 = j - 1;
                while (j2 >= 0 && (*grille).getElement(i, j2) == 0)
                {
                    j2 -= 1;
                }
                j2 += 1;
                if (j2 - 1 >= 0 && (*grille).getElement(i, j2 - 1) == element)//merge
                {
                    (*grille).setElement(i, j2 - 1, element * 2);
                    (*grille).setElement(i, j, 0);
                }
                else if (j2 != j)
                {
                    (*grille).setElement(i, j2, element);
                    (*grille).setElement(i, j, 0);
                }
            }
        }
    }
}

void moveRight(Grille2048* grille) {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 2; j >= 0; j--)
        {
            int element = (*grille).getElement(i, j);
            if (element != 0)
            {
                int j2 = j + 1;
                while (j2 <= 3 && (*grille).getElement(i, j2) == 0)
                {
                    j2 += 1;
                }
                j2 -= 1;
                if (j2 + 1 <= 3 && (*grille).getElement(i, j2 + 1) == element)//merge
                {
                    (*grille).setElement(i, j2 + 1, element * 2);
                    (*grille).setElement(i, j, 0);
                }
                else if (j2 != j)
                {
                    (*grille).setElement(i, j2, element);
                    (*grille).setElement(i, j, 0);
                }
            }
        }
    }
}