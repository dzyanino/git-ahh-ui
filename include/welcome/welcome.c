#include "welcome.h"
#include "../theme/colors.h"
#include "../theme/fonts.h"

void LayoutWelcome() {
  CLAY(
    CLAY_ID("welcome"),
    {
      .layout = {
        .sizing = {
          .width = CLAY_SIZING_GROW(0),
          .height = CLAY_SIZING_GROW(0)
        },
        .childAlignment = {
          .x = CLAY_ALIGN_X_CENTER,
          .y = CLAY_ALIGN_Y_CENTER
        }
      }
    }
  ) {
    CLAY(
      CLAY_ID("empty-card"),
      {
        .layout = {
          .sizing = {
            .width = CLAY_SIZING_FIXED(400),
            .height = CLAY_SIZING_FIXED(200)
          },
          .padding = CLAY_PADDING_ALL(16)
        },
        .backgroundColor = {128, 130, 166, 255},
        .cornerRadius = 10
      }
    ) {
      CLAY_TEXT(CLAY_STRING("Ok test leka"), {
        .fontId = M_FONT_DISPLAY_BOLD, .fontSize = 24, .textColor = theme_colors[M_COLOR_TEXT_WHITE]
      });
    }
  }
}
