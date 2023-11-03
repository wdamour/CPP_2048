#include <iostream>
#include <vector>
#include <ctime>
#include <conio.h>
#include <SDL.h>
#include "GameObject.h"
#include "window.h"
#include "grille.h"
#include "main_window.h"

int main_window() {
	//Création de la fenêtre
	Window* window = new Window(600, 600);

	GameObject cell2(0, 0, 100, 100, 2);
	SDL_Texture* texture2 = cell2.chargeImage(window->getRenderer());

	GameObject cell4(0, 0, 100, 100, 4);
	SDL_Texture* texture4 = cell4.chargeImage(window->getRenderer());

	GameObject cell8(0, 0, 100, 100, 8);
	SDL_Texture* texture8 = cell8.chargeImage(window->getRenderer());

	GameObject cell16(0, 0, 100, 100, 16);
	SDL_Texture* texture16 = cell16.chargeImage(window->getRenderer());

	GameObject cell32(0, 0, 100, 100, 32);
	SDL_Texture* texture32 = cell32.chargeImage(window->getRenderer());

	GameObject cell64(0, 0, 100, 100, 64);
	SDL_Texture* texture64 = cell64.chargeImage(window->getRenderer());

	GameObject cell128(0, 0, 100, 100, 128);
	SDL_Texture* texture128 = cell128.chargeImage(window->getRenderer());

	GameObject cell256(0, 0, 100, 100, 256);
	SDL_Texture* texture256 = cell256.chargeImage(window->getRenderer());

	GameObject cell512(0, 0, 100, 100, 512);
	SDL_Texture* texture512 = cell512.chargeImage(window->getRenderer());

	GameObject cell1024(0, 0, 100, 100, 1024);
	SDL_Texture* texture1024 = cell1024.chargeImage(window->getRenderer());

	GameObject cell2048(0, 0, 100, 100, 2048);
	SDL_Texture* texture2048 = cell2048.chargeImage(window->getRenderer());

	SDL_Texture* texture[11] = { texture2,texture4,texture8, texture16, texture32, texture64, texture128, texture256, texture512, texture1024, texture2048 };
	GameObject cell[11] = { cell2,cell4,cell8, cell16, cell32, cell64, cell128, cell256, cell512, cell1024, cell2048 };

	Grille2048 grille;
	grille.afficherGrilleWindow(window, texture);
	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			const Uint8* state = SDL_GetKeyboardState(NULL);
			if (state[SDL_SCANCODE_UP])
			{
				Grille2048 grille2 = grille;
				grille.moveUp();
				bool isSame = true;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++) {
						if (grille.getElement(i, j) != grille2.getElement(i, j))
						{
							isSame = false;
						}
					}
				}if (!isSame)
				{
					grille.ajouterNombreAleatoire();
				}
				grille.afficherGrilleWindow(window, texture);
			}
			else if (state[SDL_SCANCODE_DOWN])
			{
				Grille2048 grille2 = grille;
				grille.moveDown();
				bool isSame = true;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++) {
						if (grille.getElement(i, j) != grille2.getElement(i, j))
						{
							isSame = false;
						}
					}
				}if (!isSame)
				{
					grille.ajouterNombreAleatoire();
				}
				grille.afficherGrilleWindow(window, texture);
			}
			else if (state[SDL_SCANCODE_RIGHT])
			{
				Grille2048 grille2 = grille;
				grille.moveRight();
				bool isSame = true;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++) {
						if (grille.getElement(i, j) != grille2.getElement(i, j))
						{
							isSame = false;
						}
					}
				}if (!isSame)
				{
					grille.ajouterNombreAleatoire();
				}
				grille.afficherGrilleWindow(window, texture);
			}
			else if (state[SDL_SCANCODE_LEFT])
			{
				Grille2048 grille2 = grille;
				grille.moveLeft();
				bool isSame = true;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++) {
						if (grille.getElement(i, j) != grille2.getElement(i, j))
						{
							isSame = false;
						}
					}
				}if (!isSame)
				{
					grille.ajouterNombreAleatoire();
				}
				grille.afficherGrilleWindow(window, texture);
			}
			if (grille.isGameEnd()) {
				Window* windowEndgame = new Window(600, 200);
				GameObject endgame(0, 0, 600, 200, -2);
				SDL_Texture* textureEndgame=endgame.chargeImage(windowEndgame->getRenderer());
				endgame.drawImage(textureEndgame, windowEndgame->getRenderer());
				windowEndgame->Update();
				system("pause");
				endgame.deleteChargeImage(textureEndgame);
				delete windowEndgame;
				break;
			}
		}
	}

	for (int i = 0; i < 11; i++)
	{
		cell[i].deleteChargeImage(texture[i]);
	}


	// Wait
	//system("pause");
	delete window;
	return 0;
}