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

void Brick::SetBrick(int col, int row, int windowWidth) {

	const int PADDING = 5;

	float offsetX = (windowWidth - (GAME_COLS * (BRICK_WIDTH + PADDING) - PADDING)) / 2.0f;
	float offsetY = 50.0f;
	 
	position.x = row * (BRICK_WIDTH + PADDING) + offsetX;
	position.y = col * (BRICK_HEIGHT + PADDING) + offsetY;
}

void Brick::UpdateBrick() {

	h = h - 1;

	if (h == 0) {

		isDestroyed = true;
		r = 0;
		std::cout << "Brick destroyed" << std::endl;
	}
	else if (h == 1) {

		r = 255;
		g = 0;
		std::cout << "Updated to red brick" << std::endl;
	}
	else if (h == 2) {

		r = 255;
		g = 255;
		std::cout << "Updated to yellow brick" << std::endl;
	}
}