#include "scene.h"

Scene::Scene() {

}

void Scene::SetLevel(int windowWidth, int windowHeight) {

	for (int row = 0; row < GAME_ROWS; row++) {
		for (int col = 0; col < GAME_COLS; col++) {

			// Red = 1
			// Yellow = 2
			// Green = 3
			if (level[row][col] == 1) {
				
				bricks[row][col].Init(255, 0, 0, 0, 1);
			}
			else if (level[row][col] == 2) {

				bricks[row][col].Init(255, 255, 0, 0, 2);
			}
			else if (level[row][col] == 3) {

				bricks[row][col].Init(0, 255, 0, 0, 3);
			}

			bricks[row][col].SetBrick(row, col, windowWidth);
		}
	}
}

void Scene::DrawLevel(SDL_Renderer* renderer) {

	for (int row = 0; row < GAME_ROWS; row++) {
		for (int col = 0; col < GAME_COLS; col++) {

			if (level[row][col] != 0) {

				bricks[row][col].Draw(renderer);
			}
		}
	}
}

void Scene::LoadLevel(const int levelData[GAME_ROWS][GAME_COLS]) {

	for (int row = 0; row < GAME_ROWS; row++) {
		for (int col = 0; col < GAME_COLS; col++) {
			
			level[row][col] = levelData[row][col];
		}
	}
}

Ball Scene::CheckForPaddleCollision(Ball ball, Paddle paddle) {

	if (SDL_HasRectIntersectionFloat(&ball.rect, &paddle.rect)) {

		if (ball.velocity.y > 0) {

			ball.velocity.y *= -1;

			float paddleCenterX = paddle.rect.x + (paddle.rect.w / 2);
			float ballCenterX = ball.rect.x + (ball.rect.w / 2);

			float relativePositionX = (ballCenterX - paddleCenterX) / (paddle.rect.w / 2);

			ball.velocity.x = relativePositionX * Ball::MAX_BOUNCE_ANGLE;
		}
	}

	return ball;
}

Ball Scene::CheckForBrickCollision(Ball ball) {

	for (int row = 0; row < GAME_ROWS; row++) {
		for (int col = 0; col < GAME_COLS; col++) {

			if (SDL_HasRectIntersectionFloat(&ball.rect, &bricks[row][col].rect) && !bricks[row][col].isDestroyed) {

				if (ball.velocity.y != 0) {

					ball.velocity.y *= -1;

					float brickCenterX = bricks[row][col].rect.x + (bricks[row][col].rect.w / 2);
					float ballCenterX = ball.rect.x + (ball.rect.w / 2);

					float relativePositionX = (ballCenterX - brickCenterX) / (bricks[row][col].rect.w / 2);

					ball.velocity.x = relativePositionX * Ball::MAX_BOUNCE_ANGLE;
				}

				bricks[row][col].UpdateBrick();
				SDL_Delay(SDL_DELAY_MS);

				std::cout << "Brick Row: " << row << std::endl;
				std::cout << "Brick Column: " << col << std::endl;
				std::cout << "Brick Health: " << bricks[row][col].h << std::endl;
				std::cout << "Brick isDestroyed: " << bricks[row][col].isDestroyed << std::endl;
				std::cout << "Brick PositionX: " << bricks[row][col].position.x << std::endl;
				std::cout << "Brick PositionY: " << bricks[row][col].rect.x << std::endl;
				std::cout << "Brick Red Value: " << bricks[row][col].r << std::endl;
				std::cout << "Brick Green Value: " << bricks[row][col].g << std::endl << std::endl;
			}
		}
	}

	return ball;
}