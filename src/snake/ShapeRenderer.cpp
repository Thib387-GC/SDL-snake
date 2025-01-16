#include "ShapeRenderer.h"

#include <SDL2/SDL.h>
ShapeRenderer::ShapeRenderer(SDL_Renderer& _renderer) :  renderer(_renderer)
{

	shape.h = 32;
	shape.w = 32;

}

void ShapeRenderer::Update(const float _x, const float _y, const SDL_Color& _color)
{
	shape.x = _x;
	shape.y = _y;
	SDL_SetRenderDrawColor(&renderer, _color.r,_color.g,_color.b,_color.a); // Set color to solid white

}

void ShapeRenderer::Draw() const
{
	SDL_RenderFillRectF(&renderer, &shape); // Draw a filled rectangle

}

