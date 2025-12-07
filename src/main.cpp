#include "ball.h"
#include "paddle.h"
#include <cmath>
#include <iostream>
#include <raylib.h>

int main() {

  InitWindow(800, 600, "PONG");
  SetWindowState(FLAG_VSYNC_HINT);

  Ball ball;
  ball.x = GetScreenWidth() / 2.0f;
  ball.y = GetScreenHeight() / 2.0f;
  ball.radius = 5;
  ball.speedX = 300;
  ball.speedY = 300;

  Paddle leftPaddle;
  leftPaddle.x = 50;
  leftPaddle.y = GetScreenHeight() / 2;
  leftPaddle.width = 10;
  leftPaddle.height = 100;
  leftPaddle.speed = 500;

  Paddle rightPaddle;
  rightPaddle.x = GetScreenWidth() - 50;
  rightPaddle.y = GetScreenHeight() / 2;
  rightPaddle.width = 10;
  rightPaddle.height = 100;
  rightPaddle.speed = 500;

  const char *winnerText = nullptr;

  while (!WindowShouldClose()) {
    // Updates
    ball.x += ball.speedX * GetFrameTime();
    ball.y += ball.speedY * GetFrameTime();

    // bounce of top and bottom
    if (ball.y + ball.radius >= GetScreenHeight()) {
      ball.y = GetScreenHeight() - ball.radius;
      ball.speedY *= -1;
    }
    if (ball.y - ball.radius <= 0) {
      ball.y = ball.radius;
      ball.speedY *= -1;
    }

    if (IsKeyDown(KEY_W)) {
      leftPaddle.y -= leftPaddle.speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_S)) {
      leftPaddle.y += leftPaddle.speed * GetFrameTime();
    }

    if (IsKeyDown(KEY_UP)) {
      rightPaddle.y -= rightPaddle.speed * GetFrameTime();
    }

    if (IsKeyDown(KEY_DOWN)) {
      rightPaddle.y += rightPaddle.speed * GetFrameTime();
    }

    if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius,
                                leftPaddle.GetRect())) {
      if (ball.speedX < 0) {

        ball.x = leftPaddle.x + leftPaddle.width / 2 + ball.radius;

        ball.speedX *= -1.1f;
        ball.speedY = (ball.y - leftPaddle.y) / (leftPaddle.height / 2) *
                      fabs(ball.speedX);
      }
    }

    if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius,
                                rightPaddle.GetRect())) {
      if (ball.speedX > 0) {

        ball.x = rightPaddle.x - rightPaddle.width / 2 - ball.radius;

        ball.speedX *= -1.1f;
        ball.speedY = (ball.y - rightPaddle.y) / (rightPaddle.height / 2) *
                      -fabs(ball.speedX);
      }
    }

    if (ball.x < 0)
      winnerText = "Right player wins";

    if (ball.x > GetScreenWidth())
      winnerText = "Left player wins";

    if (winnerText && IsKeyPressed(KEY_SPACE)) {
      ball.x = GetScreenWidth() / 2;
      ball.y = GetScreenHeight() / 2;
      ball.speedX = 300;
      ball.speedY = 300;
      winnerText = nullptr;
    }

    BeginDrawing();

    ClearBackground(BLACK);

    ball.Draw();
    leftPaddle.Draw();
    rightPaddle.Draw();

    if (winnerText) {
      int textWidth = MeasureText(winnerText, 60);
      DrawText(winnerText, GetScreenWidth() / 2 - textWidth / 2,
               GetScreenHeight() / 2 - 30, 60, GREEN);
    }
    DrawFPS(10, 10);
    EndDrawing();
  }

  CloseWindow();
}