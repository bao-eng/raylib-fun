// https://github.com/DrKLO/Telegram/blob/ca13bc972dda0498b8ffb40276423a49325cd26d/TMessagesProj/src/main/java/org/telegram/ui/Components/CloseProgressDrawable2.java

#include <chrono>

#include "raylib.h"
#include "raymath.h"

void DrawRingExRoundEnd(Vector2 center_, float radius, float startAngle,
                        float endAngle, float thick, Color color) {
  float innerRadius = radius - thick / 2;
  float outerRadius = radius + thick / 2;

  int segments = static_cast<int>(round(abs(startAngle - endAngle) / 6));
  DrawRing(center_, innerRadius, outerRadius, startAngle, endAngle, segments,
           color);

  DrawCircleV({center_.x + radius * cosf((-startAngle + 90) * DEG2RAD),
               center_.y + radius * sinf((-startAngle + 90) * DEG2RAD)},
              thick / 2, color);
  DrawCircleV({center_.x + radius * cosf((-endAngle + 90) * DEG2RAD),
               center_.y + radius * sinf((-endAngle + 90) * DEG2RAD)},
              thick / 2, color);
}

void DrawLineExRoundEnd(Vector2 startPos, Vector2 endPos, float thick,
                        Color color) {
  DrawLineEx(startPos, endPos, thick, color);
  DrawCircleV(startPos, thick / 2, color);
  DrawCircleV(endPos, thick / 2, color);
}

class CloseProgressDrawable2 {
 public:
  CloseProgressDrawable2()
      : PaintColor_(WHITE),
        side_(100),
        StrokeWidth_(100 / 4),
        center_({0, 0}) {}

 public:
  void startAnimation() {
    animating_ = true;
    lastFrameTime_ = std::chrono::high_resolution_clock::now();
  }

  void stopAnimation() { animating_ = false; }

  bool isAnimating() { return animating_; }

  void setColor(Color value) { PaintColor_ = value; }

  void setSide(float value) {
    side_ = value;
    StrokeWidth_ = value / 4;
  }

  void setCenter(Vector2 value) { center_ = value; }

  void draw() {
    auto newTime = std::chrono::high_resolution_clock::now();
    bool invalidate = false;
    // if (lastFrameTime_ != 0) {
    auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(
                  newTime - lastFrameTime_)
                  .count();
    if (animating_ || angle_ != 0) {
      angle_ += 360 * dt / 500.0f;
      if (!animating_ && angle_ >= 720) {
        angle_ = 0;
      } else {
        angle_ -= (int)(angle_ / 720) * 720;
      }
      // invalidateSelf();
    }
    // }

    float progress1 = 1.0f;
    float progress2 = 1.0f;
    float progress3 = 1.0f;
    float progress4 = 0.0f;
    if (angle_ >= 0 && angle_ < 90) {
      progress1 = (1.0f - angle_ / 90.0f);
    } else if (angle_ >= 90 && angle_ < 180) {
      progress1 = 0.0f;
      progress2 = 1.0f - (angle_ - 90) / 90.0f;
    } else if (angle_ >= 180 && angle_ < 270) {
      progress1 = progress2 = 0;
      progress3 = 1.0f - (angle_ - 180) / 90.0f;
    } else if (angle_ >= 270 && angle_ < 360) {
      progress1 = progress2 = progress3 = 0;
      progress4 = (angle_ - 270) / 90.0f;
    } else if (angle_ >= 360 && angle_ < 450) {
      progress1 = progress2 = progress3 = 0;
      progress4 = 1.0f - (angle_ - 360) / 90.0f;
    } else if (angle_ >= 450 && angle_ < 540) {
      progress2 = progress3 = 0;
      progress1 = (angle_ - 450) / 90.0f;
    } else if (angle_ >= 540 && angle_ < 630) {
      progress3 = 0;
      progress2 = (angle_ - 540) / 90.0f;
    } else if (angle_ >= 630 && angle_ < 720) {
      progress3 = (angle_ - 630) / 90.0f;
    }

    if (progress1 != 0) {
      DrawLineOffset45({0, 0}, {0, side_ * progress1});
    }
    if (progress2 != 0) {
      DrawLineOffset45({-side_ * progress2, 0}, {0, 0});
    }
    if (progress3 != 0) {
      DrawLineOffset45({0, -side_ * progress3}, {0, 0});
    }
    if (progress4 != 1) {
      DrawLineOffset45({side_ * progress4, 0}, {side_, 0});
    }

    DrawRingExRoundEnd(
        center_, side_, (angle_ < 360 ? 135 : -(angle_ - 360) + 135),
        (angle_ < 360 ? -angle_ + 135 : -360 + 135), StrokeWidth_, PaintColor_);

    lastFrameTime_ = newTime;
  }

 private:
  void DrawLineOffset45(Vector2 p1, Vector2 p2) {
    DrawLineExRoundEnd(Vector2Add(Vector2Rotate(p1, -45), center_),
                       Vector2Add(Vector2Rotate(p2, -45), center_),
                       StrokeWidth_, PaintColor_);
  }

  Color PaintColor_;
  float StrokeWidth_;
  std::chrono::high_resolution_clock::time_point lastFrameTime_;
  float angle_{0};
  bool animating_;
  float side_;
  Vector2 center_;
};

int main() {
  // Initialization
  //--------------------------------------------------------------------------------------
  int screenWidth = 800;
  int screenHeight = 450;
  SetConfigFlags(FLAG_MSAA_4X_HINT);

  InitWindow(screenWidth, screenHeight, "TelegramCloseProgress");

  SetTargetFPS(60);

  CloseProgressDrawable2 btn;
  btn.setCenter({static_cast<float>(GetScreenWidth()) / 2,
                 static_cast<float>(GetScreenHeight()) / 2});
  btn.startAnimation();

  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose())  // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here

    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground({33, 45, 61, 100});
    btn.draw();

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow();  // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
