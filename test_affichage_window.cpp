#include <iostream>
#include <SDL.h>
#include "GameObject.h"
#include "window.h"
#include "test_affichage_window.h"

int test_affichage_window() {
	//Création de la fenêtre
	Window* window = new Window(600, 600);

	//Chergement des textures
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

	//Draw Base Grid
	GameObject testRect(50, 50, 500, 500, -1);
	testRect.drawRectangle(window->getRenderer());
	int x = 2;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			GameObject testCell(i * 100 + i * 20 + 70, j * 100 + j * 20 + 70, 100, 100, x);
			switch (x)
			{
			case 2:
				testCell.drawImage(texture[0], window->getRenderer());
				break;
			case 4:
				testCell.drawImage(texture[1], window->getRenderer());
				break;
			case 8:
				testCell.drawImage(texture[2], window->getRenderer());
				break;
			case 16:
				testCell.drawImage(texture[3], window->getRenderer());
				break;
			case 32:
				testCell.drawImage(texture[4], window->getRenderer());
				break;
			case 64:
				testCell.drawImage(texture[5], window->getRenderer());
				break;
			case 128:
				testCell.drawImage(texture[6], window->getRenderer());
				break;
			case 256:
				testCell.drawImage(texture[7], window->getRenderer());
				break;
			case 512:
				testCell.drawImage(texture[8], window->getRenderer());
				break;
			case 1024:
				testCell.drawImage(texture[9], window->getRenderer());
				break;
			case 2048:
				testCell.drawImage(texture[10], window->getRenderer());
				break;
			default:
				break;
			}
			if (x < 2048)
			{
				x *= 2;
			}
		}
	}
	window->Update();

	// Wait
	std::system("pause");
	//delete les texture
	for (int i = 0; i < 11; i++)
	{
		cell[i].deleteChargeImage(texture[i]);
	}

	delete window;
		return 0;
}
