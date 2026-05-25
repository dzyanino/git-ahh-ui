#include "button.h"
#include "../../../lib/clay.h"

void ComponentButton(char* id, char* label, int variant, int color, int* disabled) {
  CLAY(
    CLAY_ID("button"),
    {
      .layout = {
        .sizing = {
          .width = CLAY_SIZING_FIXED(80),
          .height = CLAY_SIZING_FIXED(40)
        },
        .childAlignment = {
          .x = CLAY_ALIGN_X_CENTER,
          .y = CLAY_ALIGN_Y_CENTER
        },
        .childGap = 8,
        .layoutDirection = CLAY_LEFT_TO_RIGHT,
        .padding = CLAY_PADDING_ALL(4)
      }
    }
  ) {}
}
