// Idea taken from https://jazergiles.com/

#include <cmath>  //trigonometric functions
#include <vector>

#include "raylib.h"
#include "raymath.h"

std::vector<Vector2> PolyCalcPoints(const size_t& n, const float& r,
                                    const float& s, const float& x,
                                    const float& y) {
  std::vector<Vector2> points;

  const float step = (2 * M_PI) / (n);
  float angle = s;

  for (auto i = 0; i != n; i++) {
    points.push_back({(r * cosf(angle)) + x, (r * sinf(angle)) + y});
    angle -= step;
  }

  return points;
}

void PolyDraw(const std::vector<Vector2>& v, const float& th,
              const Color& clr) {
  for (auto it = v.begin(); it != v.end() - 1; it++) {
    DrawLineEx(*it, *(it + 1), th, clr);
  }
  DrawLineEx(*v.rbegin(), *v.begin(), th, clr);
}

int main() {
  // Initialization
  //--------------------------------------------------------------------------------------
  int screenWidth = 800;
  int screenHeight = 450;
  SetConfigFlags(FLAG_MSAA_4X_HINT);

  InitWindow(screenWidth, screenHeight, "rotating polygons");

  SetTargetFPS(60);

  float n_vert{3};

  float angle_in{0};
  float angle_ex{0};

  const float r_ex{200};
  const float r_in{r_ex / 2};

  const float thick{2};

  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose())  // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here

    angle_ex += 0.01;
    angle_in -= 0.01;

    auto mouse_pos = GetMousePosition();
    auto center_dist =
        Vector2Distance(mouse_pos, {static_cast<float>(screenWidth) / 2,
                                    static_cast<float>(screenHeight) / 2});
    center_dist = center_dist > r_ex ? r_ex : center_dist;  // Clamp()
    n_vert = static_cast<size_t>(round(Remap(center_dist, 0, r_ex, 20, 3)));

    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(WHITE);

    auto points_ex = PolyCalcPoints(n_vert, r_ex, angle_ex, screenWidth / 2,
                                    screenHeight / 2);
    PolyDraw(points_ex, thick, BLACK);

    auto points_in = PolyCalcPoints(n_vert, r_in, angle_in, screenWidth / 2,
                                    screenHeight / 2);
    PolyDraw(points_in, thick, BLACK);

    for (auto& i : points_ex) {
      for (auto& j : points_in) {
        DrawLineEx(i, j, thick, BLACK);
      }
    }

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow();  // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
