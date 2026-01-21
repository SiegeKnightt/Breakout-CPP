#include "scene.h"

Scene::Scene() {

}

void Scene::SetLevel(int windowWidth, int windowHeight) {

	for (int x = 0; x < GAME_ROWS; x++) {
		for (int y = 0; y < GAME_COLS; y++) {

			// Red = 1
			// Yellow = 2
			// Green = 3
			if (level[x][y] == 1) {
				
				bricks[x][y].Init(255, 0, 0, 0, 1);
			}
			else if (level[x][y] == 2) {

				bricks[x][y].Init(255, 255, 0, 0, 2);
			}
			else if (level[x][y] == 3) {

				bricks[x][y].Init(0, 255, 0, 0, 3);
			}

			bricks[x][y].SetBrick(x, y, windowWidth);
		}
	}
}

void Scene::DrawLevel(SDL_Renderer* renderer) {

	for (int x = 0; x < GAME_ROWS; x++) {
		for (int y = 0; y < GAME_COLS; y++) {

			if (level[x][y] != 0 && !bricks[x][y].isDestroyed) {

				bricks[x][y].Draw(renderer);
			}
		}
	}
}

void Scene::LoadLevel(const int levelData[GAME_ROWS][GAME_COLS]) {

	for (int y = 0; y < GAME_ROWS; ++y) {
		for (int x = 0; x < GAME_COLS; ++x) {
			
			level[y][x] = levelData[y][x];
		}
	}
}