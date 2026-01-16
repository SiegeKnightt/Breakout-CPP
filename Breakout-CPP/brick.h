#ifndef BRICK_H
#define BRICK_H

#include <SDL3/SDL.h>
#include "vec2.h"

// Brick update function for changing color/health?
// Green = 3 health
// Yellow = 2 health
// Red = 1 health

class Brick {
	private:
		int r, g, b, a;
		int h;
	public:
		static const int BRICK_WIDTH = 75;
		static const int BRICK_HEIGHT = 25;

		bool isDestroyed = false;

		Brick(int red, int green, int blue, int alpha, int health);

		void Draw(SDL_Renderer* renderer);

		void SetBrick(int windowWidth, int windowHeight);

		Vec2 position;

		SDL_FRect rect{};
};

#endif

