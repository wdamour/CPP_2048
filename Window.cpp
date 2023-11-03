#include "window.h"
#include <iostream>
#include <SDL.h>

Window::Window(int width, int height) {
	//Initialisation SDL
	error = SDL_Init(SDL_INIT_VIDEO);
	if (error != 0)
	{
		std::cout << "Error SDL_Init : " << SDL_GetError();
	}

	// Création Window
	window = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout << "Erreur SDL_CreateWindow : " << SDL_GetError();
		error = 1;
	}

	//Création renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		std::cout << "Erreur SDL_CreateRenderer : " << SDL_GetError;
	}
}

Window::~Window() {
	//Détruit rendere
	SDL_DestroyRenderer(renderer);

	//Détruit window
	SDL_DestroyWindow(window);

	//Fermeture SDL
	SDL_Quit();
}

void Window::Update()
{
	SDL_RenderPresent(renderer);
}

int Window::getError()
{
	return error;
}

void Window::Clean()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

SDL_Renderer* Window::getRenderer()
{
	return renderer;
}