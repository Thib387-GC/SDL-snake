#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SDL2/SDL.h>
#include"Vector2.h"
class Food;
class ShapeRenderer;

class Snake
{
	std::vector<Vector2> body;
	Vector2 direction;
	ShapeRenderer& sr;

public:
	Snake(ShapeRenderer& _sr);
	const std::vector<Vector2>& GetBody() const;
	void ProcessEvent(const SDL_Event& _event);
	const Vector2& GetNextPosition() const;
	void Grow();
	void Move();
	bool ProcessUpdate(Food& _food);
	bool IsPositionBody(const Vector2& _pos) const;
	void Draw();
};

