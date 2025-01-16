#include "Snake.h"
#include "Food.h"
#include "ShapeRenderer.h"
Snake::Snake(ShapeRenderer& _sr) : body({ Vector2(0,0) }), direction(0, 0), sr(_sr)
{
}

void Snake::ProcessEvent(const SDL_Event& _event)
{


	switch (_event.type) {
	case SDL_KEYDOWN:
		// test keycode
		switch (_event.key.keysym.sym) {
			case SDLK_LEFT:
				direction = Vector2(-1, 0);
				break;
			case SDLK_RIGHT:
				direction = Vector2(1, 0);
				break;
			case SDLK_UP:
				direction = Vector2(0, -1);
				break;
			case SDLK_DOWN:
				direction = Vector2(0, 1);
				break;
		}
	
	}
}

const Vector2& Snake::GetNextPosition() const
{
	return body[0] + direction;
}

void Snake::Grow()
{
	body.push_back(body[body.size() - 1]);
}

void Snake::Move()
{
	for (int i = body.size() - 1; i > 0; --i) {
		body[i] = body[i - 1];
	}
	body[0] = GetNextPosition();
}

bool Snake::ProcessUpdate(Food& _food)
{
	if (direction.GetX() != 0 || direction.GetY() != 0) {
		Vector2 nextPosition = GetNextPosition();
		if (!IsPositionBody(nextPosition)) {
			if (nextPosition == _food.GetPosition()) {
				_food.GeneratePosition(*this);
				Grow();
			}
			Move();
		}
		else {
			return true;
		}
	}
	return false;
}

bool Snake::IsPositionBody(const Vector2& _pos) const
{
	return std::find(body.begin(), body.end(), _pos) != body.end();
}

void Snake::Draw()
{
	for (Vector2 p : body) {
		SDL_Color color(0, 255, 0, 255);
		sr.Update(p.GetX() * 32.f,p.GetY()*32.f,color);
		sr.Draw();
	}
}

const std::vector<Vector2>& Snake::GetBody() const
{
	return body;
}
