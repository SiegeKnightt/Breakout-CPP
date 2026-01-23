#ifndef SCENE_H
#define SCENE_H

#include "brick.h"
#include "paddle.h"
#include "ball.h"
#include "global.h"

// 8 across
// 36 down
// 2D array 8 x 36 of bricks in "scene" class
// Render and draw the scene rather than the bricks individually
// Can create as many scenes for different levels
// How do I instantiate different levels?
// Load from a file?
// How do I switch levels?
// Does the scene class include a level select menu?
// Unlock a level after beating previous?
// Save functionality to keep progress?

class Scene {
	public:
		int level[GAME_ROWS][GAME_COLS] = {};

		Brick bricks[GAME_ROWS][GAME_COLS] = {};

		Scene();
		void LoadLevel(const int levelData[GAME_ROWS][GAME_COLS]);
		void DrawLevel(SDL_Renderer* renderer);
		void SetLevel(int windowWidth, int windowHeight);
		Ball CheckForCollision(Ball ball, Paddle paddle);
};

#endif 



