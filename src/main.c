#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "./constants.h"

int game_is_running = false;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

struct ball {
	float x;
	float y;
	float width;
	float height;
} ball;

int initialize_window(void)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "Error initialiazing SDL.\n");
		return false;
	}

	window = SDL_CreateWindow(
			NULL,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			SDL_WINDOW_BORDERLESS
	);

	if(!window)
	{
		fprintf(stderr, "Error creating SDL Window. Give up\n");
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if(!renderer)
	{
		fprintf(stderr, "Error creating SDL Renderer. Give up\n");
		return false;
	}

	return true;
}

void process_input()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch(event.type)
	{
		case SDL_QUIT:
			game_is_running = false;
			break;
		case SDL_KEYDOWN:
			if(event.key.keysym.sym == SDLK_ESCAPE)
				game_is_running = false;
			break;
	}
}

void setup()
{
	ball.x = 20;
	ball.y = 20;
	ball.width = 15;
	ball.height = 15;
}

void update()
{
	ball.x += 1;
	ball.y += 1;
}

void render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_Rect ball_rect = {
		(int)ball.x,
		(int)ball.y,
		(int)ball.width,
		(int)ball.height
	};

	SDL_SetRenderDrawColor(renderer, 194, 58, 135, 255);
	SDL_RenderFillRect(renderer, &ball_rect);

	SDL_RenderPresent(renderer);
}

void destroy_window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main()
{
	game_is_running = initialize_window();

	setup();
	while(game_is_running)
	{
		process_input();
		update();
		render();
	}

	destroy_window();
	
	return 0;
}
