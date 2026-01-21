#include "brick.h"

void Brick::Init(int red, int green, int blue, int alpha, int health) {

	rect.w = BRICK_WIDTH;
	rect.h = BRICK_HEIGHT;

	r = red;
	g = green;
	b = blue;
	a = alpha;
	h = health;

	isDestroyed = false;

	position = { 0,0 };
}

void Brick::Draw(SDL_Renderer* renderer) {

	rect.x = position.x;
	rect.y = position.y;

	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderFillRect(renderer, &rect);
}

void Brick::SetBrick(int x, int y, int windowWidth) {

	const int PADDING = 5;

	float offsetX = (windowWidth - (GAME_COLS * (BRICK_WIDTH + PADDING) - PADDING)) / 2.0f;
	float offsetY = 50.0f;
	 
	position.x = x * (BRICK_WIDTH + PADDING) + offsetX;
	position.y = y * (BRICK_HEIGHT + PADDING) + offsetY;
}
