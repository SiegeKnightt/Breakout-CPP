#include "ball.h"

Ball::Ball(Vec2 position, Vec2 velocity) : position(position), velocity(velocity) {

	rect.w = BALL_WIDTH;
	rect.h = BALL_HEIGHT;
}

void Ball::Draw(SDL_Renderer* renderer) {

	rect.x = position.x;
	rect.y = position.y;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void Ball::UpdateBall(int windowWidth, int windowHeight, float deltaTime) {

	position.x += velocity.x * deltaTime;
	position.y += velocity.y * deltaTime;

	if (position.x < 0) {

		position.x = 0;
		velocity.x *= REBOUND_SPEED;
	}
	else if ((position.x + BALL_WIDTH) > windowWidth) {

		position.x = static_cast<float>(windowWidth) - static_cast<float>(BALL_WIDTH);
		velocity.x *= REBOUND_SPEED;
	}

	if (position.y < 0) {

		position.y = 0;
		velocity.y *= REBOUND_SPEED;
	}
	else if ((position.y + BALL_HEIGHT) > windowHeight) {

		position.x = (static_cast<float>(windowWidth) / 2) - (static_cast<float>(BALL_WIDTH) / 2);
		position.y = (static_cast<float>(windowHeight) / 2) - (static_cast<float>(BALL_HEIGHT) / 2);

		velocity.x = 0.0;
		velocity.y = BALL_VELOCITY_Y;
		
		PLAYER_LIVES -= 1;

		SDL_Log("Lives decreased to %d!", PLAYER_LIVES);
	}

	if (velocity.y > MAX_BALL_VELOCITY) {

		velocity.y = MAX_BALL_VELOCITY;
	}
	else if (velocity.y < MIN_BALL_VELOCITY) {

		velocity.y = MIN_BALL_VELOCITY;
	}
	
	if (velocity.x > MAX_BALL_VELOCITY) {

		velocity.x = MAX_BALL_VELOCITY;
	}
	else if (velocity.x < MIN_BALL_VELOCITY) {

		velocity.x = MIN_BALL_VELOCITY;
	}
}