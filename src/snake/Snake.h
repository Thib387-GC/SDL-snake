#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SDL2/SDL.h>

class Food;
class ShapeRenderer;

class Snake
{
	std::vector<sf::Vector2f> body;
	sf::Vector2f direction;
	ShapeRenderer& sr;

public:
	Snake(ShapeRenderer& _sr);
	const std::vector<sf::Vector2f>& GetBody() const;
	void ProcessEvent(const SDL_Event& _event);
	const sf::Vector2f& GetNextPosition() const;
	void Grow();
	void Move();
	bool ProcessUpdate(Food& _food);
	bool IsPositionBody(const sf::Vector2f& _pos) const;
	void Draw();
};

