#include <iostream>
#include <vector>
#include <ctime>
#include <conio.h>
#include <SDL.h>
#include "GameObject.h"
#include "window.h"
#include "grille.h"
#include "main_console.h"
#include "main_window.h"
#include "test_affichage_window.h"
#include "test.h"


int main(int argc, char** args) {
	//Décommenter une ligne pour executer le code

	//Jeu en mode console
	//int i = main_console();
	
	// Jeu en mode fenêtre
	int j = main_window();
	
	// test affichage fenêtre avec un rectangle et des images
	//int k = test_affichage_window();

	//___________________test conole____________________
	// affiche grille vide
	//afficheGrilleVide();

	//test merge et move side
	//testMoveAndMergeSide();

	//test merge et move Top Bottom
	//testMoveAndMergeTopBottom();

	//Test si fin de partie quand 2048
	//testEndgame2048();

	//Test side merge possible
	//testFullGridPossibleSideMerge();

	//Test TopBottom merge possible
	//testFullGridPossibleTopBottomMerge();

	//Test No Possible Merge
	//testFullGridNoPOssibleMerge();
	return 0;
}