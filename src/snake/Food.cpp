#include "Food.h"
#include "Snake.h"
#include "ShapeRenderer.h"

Food::Food(const Snake& _snake, ShapeRenderer& _sr) : sr(_sr)
{
	gen.seed(std::time(nullptr));
	GeneratePosition(_snake);
}

void Food::GeneratePosition(const Snake& _snake)
{
	const std::vector<sf::Vector2f> body = _snake.GetBody();
	bool found;
	do {
		found = false;
		sf::Vector2f tmpPosition((int)(gen() % 23) - 11, (int)(gen() % 17) - 8);
		if (_snake.IsPositionBody(tmpPosition) || tmpPosition == _snake.GetNextPosition()) {
			found = true;
		}
		position = tmpPosition;
	} while (found);
}

const sf::Vector2f& Food::GetPosition()
{
	return position;
}

void Food::Draw()
{
	SDL_Color color(255, 0, 0, 255);

	sr.Update(position.x * 32.f, position.y * 32.f, color);
	sr.Draw();
}
