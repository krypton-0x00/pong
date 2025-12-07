#include "ball.h"
#include <raylib.h>

void Ball::Draw() { DrawCircle(x, y, radius, WHITE); }