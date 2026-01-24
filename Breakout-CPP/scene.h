#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include "brick.h"
#include "paddle.h"
#include "ball.h"
#include "global.h"

class Scene {
	public:
		int level[GAME_ROWS][GAME_COLS] = {};

		Brick bricks[GAME_ROWS][GAME_COLS] = {};

		Scene();

		void LoadLevel(const int levelData[GAME_ROWS][GAME_COLS]);

		void DrawLevel(SDL_Renderer* renderer);

		void SetLevel(int windowWidth, int windowHeight);

		Ball CheckForPaddleCollision(Ball ball, Paddle paddle);

		Ball CheckForBrickCollision(Ball ball);
};

#endif 



