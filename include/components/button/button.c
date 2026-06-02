#include "button.h"
#include "../../../lib/clay.h"
#include "../../theme/fonts.h"
#include <string.h>

void ComponentButton(char* id, char* label, int variant, m_color_id_t color_id, int disabled) {
  CLAY(
    CLAY_SID(((Clay_String) {.isStaticallyAllocated = false, .length = strlen(id), .chars = id})),
    {
      .layout = {
        .sizing = {
          .width = CLAY_SIZING_FIT(0),
          .height = CLAY_SIZING_FIXED(30)
        },
        .childAlignment = {
          .x = CLAY_ALIGN_X_CENTER,
          .y = CLAY_ALIGN_Y_CENTER
        },
        .childGap = 8,
        .layoutDirection = CLAY_LEFT_TO_RIGHT,
        .padding = {16, 16, 8, 8}
      },
      .cornerRadius = 5,
      .backgroundColor = Clay_Hovered() ? theme_colors[M_COLOR_DARK_PRIMARY] : theme_colors[color_id]
    }
  ) {
    CLAY_TEXT(((Clay_String) {.isStaticallyAllocated = false, .length = strlen(label), .chars = label}), {
      .fontId = M_FONT_SEMIBOLD, .fontSize = 18, .textColor = theme_colors[M_COLOR_TEXT_WHITE]
    });
  }
}
