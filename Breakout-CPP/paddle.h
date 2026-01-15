#ifndef PADDLE_H
#define PADDLE_H

#include <SDL3/SDL.h>
#include "vec2.h"

class Paddle {
public:
	static const int PADDLE_WIDTH = 90;
	static const int PADDLE_HEIGHT = 15;

	Paddle();

	void Draw(SDL_Renderer* renderer);

	void SetPaddle(int windowWidth, int windowHeight);

	Vec2 position;

	SDL_FRect rect{};
};

#endif
