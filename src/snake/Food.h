#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <SDL2/SDL.h>

class Snake;
class ShapeRenderer;

class Food
{
	sf::Vector2f position;
	std::mt19937 gen;
	ShapeRenderer& sr;

public:
	Food(const Snake& _snake, ShapeRenderer& _sr);
	void GeneratePosition(const Snake& _snake);
	const sf::Vector2f& GetPosition();
	void Draw();
};

