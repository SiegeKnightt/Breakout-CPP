#include <SDL3/SDL.h>
#include "paddle.h"
#include "ball.h"
#include "brick.h"
#include "scene.h"
#include "levels.h"
#include "global.h"

int main(int argc, char* argv[]) {

	if (!SDL_Init(SDL_INIT_VIDEO)) {

		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to initialize SDL! SDL error: %s", SDL_GetError());
	}

	SDL_Window* window = SDL_CreateWindow("Breakout", WINDOW_WIDTH, WINDOW_HEIGHT, NULL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

	Scene scene;
	scene.LoadLevel(LEVEL_1);
	scene.SetLevel(WINDOW_WIDTH, WINDOW_HEIGHT);

	Paddle paddle;
	paddle.SetPaddle(WINDOW_WIDTH, WINDOW_HEIGHT);

	Ball ball(Vec2((WINDOW_WIDTH / 2) - (Ball::BALL_WIDTH / 2), (WINDOW_HEIGHT / 2) - (Ball::BALL_HEIGHT / 2)), Vec2(Ball::BALL_VELOCITY_X, Ball::BALL_VELOCITY_Y));

	bool running = true;

	SDL_Log("Game started...");

	uint64_t lastTime = SDL_GetTicks();

	while (running) {

		uint64_t currentTime = SDL_GetTicks();
		float deltaTime = (currentTime - lastTime) / 1000.0f;

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

		// Draw the bricks
		scene.DrawLevel(renderer);

		ball.UpdateBall(WINDOW_WIDTH, WINDOW_HEIGHT, deltaTime);
		paddle.UpdatePaddle(WINDOW_WIDTH, deltaTime);

		ball.Draw(renderer);

		if (SDL_HasRectIntersectionFloat(&ball.rect, &paddle.rect)) {

			if (ball.velocity.y > 0) {

				ball.velocity.y *= -1;

				float paddleCenterX = paddle.rect.x + (paddle.rect.w / 2);
				float ballCenterX = ball.rect.x + (ball.rect.w / 2);

				float relativePositionX = (ballCenterX - paddleCenterX) / (paddle.rect.w / 2);

				ball.velocity.x = relativePositionX * Ball::MAX_BOUNCE_ANGLE;
			}
		}

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