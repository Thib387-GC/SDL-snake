#include "Snake.h"
#include "Food.h"
#include "ShapeRenderer.h"
Snake::Snake(ShapeRenderer& _sr) : body({ sf::Vector2f(0,0) }), direction(0, 0), sr(_sr)
{
}

void Snake::ProcessEvent(const SDL_Event& _event)
{


	switch (_event.type) {
	case SDL_KEYDOWN:
		// test keycode
		switch (_event.key.keysym.sym) {
			case SDLK_LEFT:
				direction = sf::Vector2f(-1, 0);
				break;
			case SDLK_RIGHT:
				direction = sf::Vector2f(1, 0);
				break;
			case SDLK_UP:
				direction = sf::Vector2f(0, -1);
				break;
			case SDLK_DOWN:
				direction = sf::Vector2f(0, 1);
				break;
		}
	
	}
}

const sf::Vector2f& Snake::GetNextPosition() const
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
	if (direction.x != 0 || direction.y != 0) {
		sf::Vector2f nextPosition = GetNextPosition();
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

bool Snake::IsPositionBody(const sf::Vector2f& _pos) const
{
	return std::find(body.begin(), body.end(), _pos) != body.end();
}

void Snake::Draw()
{
	for (sf::Vector2f p : body) {
		SDL_Color color(0, 255, 0, 255);
		sr.Update(p.x * 32.f,p.y*32.f,color);
		sr.Draw();
	}
}

const std::vector<sf::Vector2f>& Snake::GetBody() const
{
	return body;
}
