#ifndef BRICK_H
#define BRICK_H

#include <SDL3/SDL.h>
#include "global.h"
#include "vec2.h"

// Green = 3 health
// Yellow = 2 health
// Red = 1 health

class Brick {
	public:
		int r, g, b, a;
		int h;
		static const int BRICK_WIDTH = 75;
		static const int BRICK_HEIGHT = 25;

		bool isDestroyed = false;

		void Init(int red, int green, int blue, int alpha, int health);

		void Draw(SDL_Renderer* renderer);

		void SetBrick(int col, int row, int windowWidth);

		Vec2 position;

		SDL_FRect rect{};
};

#endif

