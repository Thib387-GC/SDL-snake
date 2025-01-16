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
	const std::vector<Vector2> body = _snake.GetBody();
	bool found;
	do {
		found = false;
		Vector2 tmpPosition((int)(gen() % 23) - 11, (int)(gen() % 17) - 8);
		if (_snake.IsPositionBody(tmpPosition) || tmpPosition == _snake.GetNextPosition()) {
			found = true;
		}
		position = tmpPosition;
	} while (found);
}

const Vector2& Food::GetPosition()
{
	return position;
}

void Food::Draw()
{
	SDL_Color color(255, 0, 0, 255);

	sr.Update(position.GetX() * 32.f, position.GetY() * 32.f, color);
	sr.Draw();
}
