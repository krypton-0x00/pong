#include <iostream>
#include <raylib.h>
int main() {

  InitWindow(800, 600, "PONG");
  SetWindowState(FLAG_VSYNC_HINT);

  float ballX = GetScreenWidth() / 2.0f;
  float ballY = GetScreenHeight() / 2.0f;
  float ballRadius = 5;
  float ballSpeedX = 100;
  float ballSpeedY = 300;

  while (!WindowShouldClose()) {
    // Updates
    float DeltaTime = GetFrameTime();
    ballX += ballSpeedX * DeltaTime;
    ballY += ballSpeedY * DeltaTime;

    // bounce of top and bottom
    if (ballY > GetScreenHeight()) {
      ballY = GetScreenHeight();
      ballSpeedY *= -1;
    }
    if (ballY <= 0) {
      ballY = 0;
      ballSpeedY *= -1;
    }

    BeginDrawing();

    ClearBackground(BLACK);

    DrawCircle((int)ballX, (int)ballY, ballRadius, WHITE);
    DrawRectangle(50, GetScreenHeight() / 2 - 50, 10, 100, WHITE);
    DrawRectangle(GetScreenWidth() - 50 - 10, GetScreenHeight() / 2 - 50, 10,
                  100, WHITE);

    DrawFPS(10, 10);
    EndDrawing();
  }

  CloseWindow();
}