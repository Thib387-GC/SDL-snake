#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <SDL2/SDL.h>
#include "Vector2.h"

class Snake;
class ShapeRenderer;

class Food
{
	Vector2 position = Vector2(0,0);
	std::mt19937 gen;
	ShapeRenderer& sr;

public:
	Food(const Snake& _snake, ShapeRenderer& _sr);
	void GeneratePosition(const Snake& _snake);
	const Vector2& GetPosition();
	void Draw();
};

