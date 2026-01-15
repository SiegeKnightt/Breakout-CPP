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