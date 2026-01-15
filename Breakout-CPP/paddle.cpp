#include "paddle.h"

Paddle::Paddle() {

	rect.w = PADDLE_WIDTH;
	rect.h = PADDLE_HEIGHT;
}

void Paddle::Draw(SDL_Renderer* renderer) {

	rect.x = position.x;
	rect.y = position.y;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void Paddle::SetPaddle(int windowWidth, int windowHeight) {

	position.x = (static_cast<float>(windowWidth) / 2) - (PADDLE_WIDTH / 2);
	position.y = (static_cast<float>(windowHeight) / 1.1f) - PADDLE_HEIGHT;
}

void Paddle::UpdatePaddle(int windowWidth, float deltaTime) {

	const bool* state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT]) {

		velocity = -400;
	}
	else if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT]) {

		velocity = 400;
	}
	else {

		velocity = 0.0;
	}

	position.x += velocity * deltaTime;

	if (position.x < 0) {

		position.x = 0;
	}
	else if ((position.x + PADDLE_WIDTH) > windowWidth) {

		position.x = windowWidth - PADDLE_WIDTH;
	}
}