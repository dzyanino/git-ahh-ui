#include "button.h"
#include "../../../lib/clay.h"
#include "../../theme/fonts.h"
#include "../../utils/clay_string.h"
#include <raylib.h>
#include <stdio.h>

void HandleClick(Clay_ElementId element_id, Clay_PointerData pointer_info, void *user_data) {
  if (pointer_info.state == CLAY_POINTER_DATA_PRESSED_THIS_FRAME) {
    printf("Nice it works\n");
    void (*callback)() = user_data;
    if (callback) callback();
  }
}

void ComponentButton(char* id, char* label, int variant, m_color_id_t color_id, int* disabled, void (*callback)()) {
  CLAY(
    CLAY_SID(DynamicClayString(id)),
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
      .backgroundColor = Clay_Hovered()
        ? (*disabled)
          ? (SetMouseCursor(MOUSE_CURSOR_NOT_ALLOWED), theme_colors[M_COLOR_ACCENT])
          : (SetMouseCursor(MOUSE_CURSOR_POINTING_HAND), theme_colors[M_COLOR_DARK_PRIMARY])
        : (SetMouseCursor(MOUSE_CURSOR_DEFAULT), theme_colors[color_id])
    }
  ) {
    if (!(*disabled)) Clay_OnHover(HandleClick, callback);
    CLAY_TEXT(DynamicClayString(label), {
      .fontId = M_FONT_SEMIBOLD,
      .fontSize = 18,
      .textColor = (*disabled)
        ? theme_colors[M_COLOR_TEXT_DIMMED]
        : theme_colors[M_COLOR_TEXT_WHITE]
    });
  }
}
