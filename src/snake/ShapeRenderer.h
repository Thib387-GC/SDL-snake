#pragma once
#include <SFML/Graphics.hpp>
#include <SDL2/SDL.h>

class ShapeRenderer
{
	SDL_FRect shape;

	SDL_Renderer& renderer;

public:
	ShapeRenderer(SDL_Renderer& _renderer);
	void Update(const float _x, const float _y, const SDL_Color& _color);
	void Draw() const;
};

