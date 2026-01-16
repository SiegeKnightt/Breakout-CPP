#include "brick.h"

Brick::Brick(int red, int green, int blue, int alpha, int health) {

	rect.w = BRICK_WIDTH;
	rect.h = BRICK_HEIGHT;

	r = red;
	g = green;
	b = blue;
	a = alpha;
	h = health;
}

void Brick::Draw(SDL_Renderer* renderer) {

	rect.x = position.x;
	rect.y = position.y;

	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderFillRect(renderer, &rect);
}

void Brick::SetBrick(int windowWidth, int windowHeight) {

	position.x = static_cast<float>(windowWidth) / 2;
	position.y = static_cast<float>(windowHeight) / 2;
}