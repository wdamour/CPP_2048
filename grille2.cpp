#include <iostream>
#include <vector>
#include <ctime>

const int SIZE = 4;

class Grille2048 {
public:
    Grille2048() : grille(SIZE, std::vector<int>(SIZE, 0)) {
        // Initialisation de la graine du générateur de nombres aléatoires
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        // Ajout de deux nombres aléatoires (2 ou 4) lors de la création de la grille
        ajouterNombreAleatoire();
        ajouterNombreAleatoire();
    }

    // Fonction pour afficher la grille du jeu
    void afficherGrille() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (grille[i][j] == 0) {
                    std::cout << "    -";
                }
                else {
                    std::cout << " " << grille[i][j] << " ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    // Fonction pour ajouter un nombre aléatoire (2 ou 4) à un emplacement vide
    void ajouterNombreAleatoire() {
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

private:
    std::vector<std::vector<int>> grille;
};

int main() {
    Grille2048 grille;
    grille.afficherGrille();

    return 0;
}