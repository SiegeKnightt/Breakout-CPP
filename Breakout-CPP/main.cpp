#include <SDL3/SDL.h>
#include "paddle.h"

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 800;

int main(int argc, char* argv[]) {

	if (!SDL_Init(SDL_INIT_VIDEO)) {

		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to initialize SDL! SDL error: %s", SDL_GetError());
	}

	SDL_Window* window = SDL_CreateWindow("Breakout", WINDOW_WIDTH, WINDOW_HEIGHT, NULL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

	Paddle paddle;
	paddle.SetPaddle(WINDOW_WIDTH, WINDOW_HEIGHT);

	bool running = true;

	SDL_Log("Game started...");

	uint64_t lastTime = SDL_GetTicks();

	while (running) {

		uint64_t currentTime = SDL_GetTicks();
		float deltaTime = (currentTime - lastTime) / 1000.0;

		SDL_Event event;

		while (SDL_PollEvent(&event)) {

			if (event.key.key == SDLK_ESCAPE || event.type == SDL_EVENT_QUIT) {
				
				SDL_Log("Quitting game...");

				running = false;
			}
		}
		
		// Draw the black background
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		paddle.UpdatePaddle(WINDOW_WIDTH, deltaTime);

		paddle.Draw(renderer);

		// Present the back buffer at the end of the frame
		SDL_RenderPresent(renderer);

		lastTime = currentTime;
	}

	// Cleanup
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}