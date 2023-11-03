#pragma once
#include <iostream>
#include <SDL.h>



class GameObject
{
public:
	GameObject(int o_x, int o_y, int o_size_x, int o_size_y, int o_name);
	~GameObject();
	void drawRectangle(SDL_Renderer* renderer);
	SDL_Texture* chargeImage(SDL_Renderer* renderer);
	void drawImage(SDL_Texture* texture, SDL_Renderer* renderer);
	void deleteChargeImage(SDL_Texture* texture);

private:
	int x;
	int y;
	int width;
	int height;
	std::string name;
};