
#define SDL_MAIN_HANDLED
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include "Snake.h"
#include "Food.h"
#include "ShapeRenderer.h"
#include <SDL2/SDL.h>
using namespace std;

int window_width = 800;
int window_height = 600;
int main(int argc, char** args)
{
	SDL_Surface* winSurface = NULL;
	SDL_Window* window = NULL;
	SDL_Renderer* _renderer = NULL;
	

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Error initializing SDL: " << SDL_GetError() << endl;
		system("pause");
		// End the program
		return 1;
	}

	window = SDL_CreateWindow("Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN);
	if (!window) {
		cout << "Error creating window: " << SDL_GetError() << endl;
		system("pause");
		// End the program
		return 1;
	}

	_renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);

	int square_size = 32;

	// Définir la "zone de rendu" pour déplacer l'origine
	ShapeRenderer renderer(*_renderer);
	
	Snake snake(renderer);
	Food food(snake, renderer);

	float time_between_move = 0.1f;
	float current_timer_between_move = 0.f;

	bool gameover = false;

	sf::Clock c;
	while (window)
	{
		SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
		SDL_RenderClear(_renderer);
		float deltaTime = c.restart().asSeconds();

		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type) {
				case SDL_QUIT:
				{
					SDL_DestroyWindow(window);
					// Quit SDL
					SDL_Quit();
				}
			
			
			}
			snake.ProcessEvent(e);
		}


		if (gameover) {

		}
		else {
			if (current_timer_between_move <= 0) {
				gameover = snake.ProcessUpdate(food);
				current_timer_between_move += (time_between_move - 0.01f * snake.GetBody().size() < 0.06f) ? 0.06f : (time_between_move - 0.01f * snake.GetBody().size());
			}
			else {
				current_timer_between_move -= deltaTime;
			}
			snake.Draw();
			food.Draw();
		}
		SDL_RenderPresent(_renderer);
	}

	return 0;
}
