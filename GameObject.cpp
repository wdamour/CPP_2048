#include "GameObject.h"

GameObject::GameObject(int o_x, int o_y, int o_size_x, int o_size_y, int o_name) {
	x = o_x;
	y = o_y;
	width = o_size_x;
	height = o_size_y;
	switch (o_name)
	{
	case -2:
		name = "Image_2048/Endgame.bmp";
		break;
	case -1:
		name = "Grille";
		break;
	case 0:
		name = "EmptyCell";
		break;
	case 2:
		name = "Image_2048/2.bmp";
		break;
	case 4:
		name = "Image_2048/4.bmp";
		break;
	case 8:
		name = "Image_2048/8.bmp";
		break;
	case 16:
		name = "Image_2048/16.bmp";
		break;
	case 32:
		name = "Image_2048/32.bmp";
		break;
	case 64:
		name = "Image_2048/64.bmp";
		break;
	case 128:
		name = "Image_2048/128.bmp";
		break;
	case 256:
		name = "Image_2048/256.bmp";
		break;
	case 512:
		name = "Image_2048/512.bmp";
		break;
	case 1024:
		name = "Image_2048/1024.bmp";
		break;
	case 2048:
		name = "Image_2048/2048.bmp";
		break;
	default:
		break;
	}
}

GameObject::~GameObject()
{
}

void GameObject::drawRectangle(SDL_Renderer* renderer)
{
	SDL_Rect rect = { x, y, width, height };
	if (name == "Grille")
	{
		SDL_SetRenderDrawColor(renderer, 187, 173, 160, 255);
	}
	else
	{
		SDL_SetRenderDrawColor(renderer, 204, 192, 179, 255);
	}
	SDL_RenderFillRect(renderer, &rect);
}

SDL_Texture* GameObject::chargeImage(SDL_Renderer* renderer)
{
	SDL_Surface* surface = SDL_LoadBMP(name.data());
	if (surface == NULL)
	{
		std::cout << "Error SDL_LoadBMP : " << SDL_GetError();
	}

	//Texture
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL)
	{
		std::cout << "Error SDL_CreateTextureFromSurface : " << SDL_GetError();
	}

	SDL_FreeSurface(surface);
	return texture;
}

void GameObject::drawImage(SDL_Texture* texture, SDL_Renderer* renderer) {
	//Draw
	SDL_Rect position;
	position.x = x;
	position.y = y;
	position.w = width;
	position.h = height;

	SDL_RenderCopy(renderer, texture, NULL, &position);
}

void GameObject::deleteChargeImage(SDL_Texture* texture) {
	//Détruit texture
	SDL_DestroyTexture(texture);
}