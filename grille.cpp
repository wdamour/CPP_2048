#include <iostream>
#include <vector>

class Grille2048 {
public:
    Grille2048() : grille(4, std::vector<int>(4, 1000)) {}

    // Fonction pour afficher la grille du jeu
    void afficherGrille() {
        for (int i = 0; i < 4; i++) {
            std::cout <<"____________________" << std::endl;
            std::cout << "|    |    |    |    |" << std::endl;
            for (int j = 0; j < 4; j++) {
                if (grille[i][j] == 0) {
                    std::cout << "|   -";
                }
                else if(grille[i][j]<10) {
                    std::cout << "|   " << grille[i][j];
                }
                else if(grille[i][j]<100) {
                    std::cout << "|  " << grille[i][j];
                }
                else if(grille[i][j]<1000) {
                    std::cout << "| " << grille[i][j];
                }
                else {
                    std::cout << "|" << grille[i][j];
                }
            }
            std::cout << "|"<< std::endl  << "|    |    |    |    |" << std::endl;
        }
        std::cout <<"¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
        std::cout << std::endl;
    }

private:
    std::vector<std::vector<int>> grille;
};

int main() {
    Grille2048 grille;
    // std::cout << grille[0][0] << std::endl;
    grille.afficherGrille();
    return 0;
}