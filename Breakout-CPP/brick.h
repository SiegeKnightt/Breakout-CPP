#ifndef BRICK_H
#define BRICK_H

#include <iostream>
#include <SDL3/SDL.h>
#include "global.h"
#include "vec2.h"

enum Color {
	BLANK = 0,
	RED = 1,
	YELLOW = 2,
	GREEN = 3
};

class Brick {
	private:
		int r, g, b, a = 0;
	public:
		Color c;
		int health;
		static const int BRICK_WIDTH = 75;
		static const int BRICK_HEIGHT = 25;
		static const int PADDING = 10;

		bool isDestroyed = false;

		void Init(Color color);

		void Draw(SDL_Renderer* renderer);

		void SetBrick(int col, int row, int windowWidth);

		void UpdateBrick();

		Vec2 position;

		SDL_FRect rect{};
};

#endif

