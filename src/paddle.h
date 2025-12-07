#include <raylib.h>
struct Paddle {
  float x, y;
  float speed;
  float width, height;

  void Draw();
  Rectangle GetRect();
};