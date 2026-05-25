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
      CLAY_ID("empty-state-card"),
      {
        .layout = {
          .layoutDirection = CLAY_TOP_TO_BOTTOM,
          .sizing = {
            .width = CLAY_SIZING_FIXED(400),
            .height = CLAY_SIZING_FIXED(200)
          },
          .childAlignment = {
            .x = CLAY_ALIGN_X_CENTER
          },
          .childGap = 4,
          .padding = CLAY_PADDING_ALL(16)
        },
        .backgroundColor = theme_colors[M_COLOR_BACKGROUND],
        .cornerRadius = 5
      }
    ) {
      CLAY_TEXT(CLAY_STRING("There is no repository here"), {
        .fontId = M_FONT_DISPLAY_BOLD, .fontSize = 24, .textColor = theme_colors[M_COLOR_TEXT_WHITE]
      });
      CLAY_TEXT(CLAY_STRING("Open one to get started"), {
        .fontId = M_FONT_REGULAR, .fontSize = 18, .textColor = theme_colors[M_COLOR_TEXT_DIM]
      });
    }
  }
}
