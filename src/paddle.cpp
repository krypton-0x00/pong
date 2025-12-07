#include "paddle.h"
#include <raylib.h>

void Paddle::Draw() { DrawRectangleRec(GetRect(), WHITE); }

Rectangle Paddle::GetRect() {
  return Rectangle{x - width / 2, y - height / 2, width, height};
}