#include <cmath>  //trigonometric functions
#include <iostream>
#include <string>  //vertices numbers
#include <vector>

#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "polygon_name.h"
#include "raygui.h"  // Required for GUI controls

// using namespace std;

// ToDo return
std::vector<Vector2> poly(const float& n, const float& r, const float& s,
                          const float& x, const float& y) {
  std::vector<Vector2> points;
  int n_vert;
  bool fl = 1;
  if (floorf(n) == n) {
    n_vert = static_cast<int>(n);
  } else {
    n_vert = trunc(n) + 1;
  }

  float angle_small = (2 * M_PI / n) * (n - trunc(n));

  const float step = (2 * M_PI - angle_small) / (trunc(n));
  float angle = s - step;

  for (auto i = 0; i != n_vert - 1; i++) {
    points.push_back({(r * cosf(angle)) + x, (r * sinf(angle)) + y});
    angle -= step;
  }
  points.push_back({(r * cosf(s)) + x, (r * sinf(s)) + y});

  return points;
}

int main() {
  // Initialization
  //--------------------------------------------------------------------------------------
  int screenWidth = 800;
  int screenHeight = 450;
  SetConfigFlags(FLAG_MSAA_4X_HINT);

  InitWindow(screenWidth, screenHeight, "polygons");
  GuiLoadStyle("../ashes/ashes.rgs");

  SetTargetFPS(60);

  float n_vert = 3;
  float n_vert_trgt = 3;

  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose())  // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here

    if (abs(n_vert - n_vert_trgt) > 0.1) {
      if (n_vert < n_vert_trgt) {
        n_vert += 0.1;
      } else {
        n_vert -= 0.1;
      }
    } else {
      n_vert = n_vert_trgt;
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(GRAY);
    n_vert_trgt = roundf(GuiSliderBar((Rectangle){190, 410, 500, 40}, NULL,
                                      NULL, n_vert_trgt, 3, 101));

    DrawCircle(400, 200, 200, WHITE);

    auto points = poly(n_vert, 200, -M_PI / 2, 400, 200);

    DrawTriangleFan(&(points[0]), (int)points.size(), ORANGE);

    auto DrawNum = [](size_t i, size_t n, float x, float y) {
      size_t low1{3};
      size_t high1{100};
      float low2{25};
      float high2{5};
      int font_size = round(low2 + (n - low1) * (high2 - low2) / (high1 - low1));
      DrawText(std::to_string(i + 1).c_str(), x, y, font_size, BLACK);
    };

    for (auto i = 0; i != points.size(); i++) {
      DrawNum(i, points.size(), points[i].x, points[i].y);
    }

    DrawText(PolygonName::GetPolygonName(points.size()).primary.c_str(), 200,
             410, 35, BLACK);

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow();  // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
