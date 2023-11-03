#pragma once
#include <SDL.h>
// mettre en place la window

class Window
{
public:
	Window(int width, int height);
	~Window();
	void Update();
	int getError();
	void Clean();
	SDL_Renderer* getRenderer();


private:
	// Pointers to our window and surface
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	int error;
};