#include "brick.h"

void Brick::Init(Color color) {

	rect.w = BRICK_WIDTH;
	rect.h = BRICK_HEIGHT;

	isDestroyed = false;

	switch(color) {
		case(BLANK):
			r = 0;
			g = 0;
			b = 0;
			a = 0;
			health = 0;
			isDestroyed = true;
			break;
		case(RED):
			r = 255;
			g = 0;
			b = 0;
			a = 0;
			health = 1;
			break;
		case(YELLOW):
			r = 255;
			g = 255;
			b = 0;
			a = 0;
			health = 2;
			break;
		case(GREEN):
			r = 0;
			g = 255;
			b = 0;
			a = 0;
			health = 3;
			break;
	}	

	c = color;

	position = { 0,0 };
}

void Brick::Draw(SDL_Renderer* renderer) {

	rect.x = position.x;
	rect.y = position.y;

	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderFillRect(renderer, &rect);
}

void Brick::SetBrick(int col, int row, int windowWidth) {

	float offsetX = (windowWidth - (GAME_COLS * (BRICK_WIDTH + PADDING) - PADDING)) / 2.0f;
	float offsetY = 50.0f;
	 
	position.x = row * (BRICK_WIDTH + PADDING) + offsetX;
	position.y = col * (BRICK_HEIGHT + PADDING) + offsetY;
}

void Brick::UpdateBrick() {

	health -= 1;

	if (c == RED) {

		isDestroyed = true;
		r = 0;
		c = BLANK;
		SDL_Log("Brick destroyed!");
	}
	else if (c == YELLOW) {

		r = 255;
		g = 0;
		c = RED;
		SDL_Log("Updated to red brick!");
	}
	else if (c == GREEN) {

		r = 255;
		g = 255;
		c = YELLOW;
		SDL_Log("Updated to yellow brick!");
	}

	SDL_Log("Updated values: ");
}