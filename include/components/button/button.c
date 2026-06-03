#include "button.h"
#include "../../../lib/clay.h"
#include "../../theme/fonts.h"
#include "../../utils/clay_string.h"
#include <raylib.h>

void HandleClick(Clay_ElementId element_id, Clay_PointerData pointer_info, void *user_data) {
  if (pointer_info.state == CLAY_POINTER_DATA_PRESSED_THIS_FRAME) {
    void (*callback)() = user_data;
    if (callback) callback();
  }
}

void ComponentButton(char* id, char* label, m_variant_id_t variant_id, m_color_id_t color_id, int* disabled, void (*callback)()) {
  bool is_outline = variant_id == M_VARIANT_OUTLINE;
  bool is_disabled = *disabled;

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

      .cornerRadius = (Clay_CornerRadius) {5, 5, 5, 5},

      .border = is_outline
        ? (Clay_BorderElementConfig) {
            .width = CLAY_BORDER_ALL(2),
            .color = is_disabled ? theme_colors[M_COLOR_BORDER] : theme_colors[color_id]
          }
        : is_disabled
          ? (Clay_BorderElementConfig) {
              .width = CLAY_BORDER_ALL(2),
              .color = theme_colors[M_COLOR_BORDER]
            }
          : (Clay_BorderElementConfig) {0},

      .backgroundColor = Clay_Hovered()
        ? is_disabled
          ? (
              SetMouseCursor(MOUSE_CURSOR_NOT_ALLOWED),
              is_outline
                ? (Clay_Color){0, 0, 0, 0}
                : theme_colors[M_COLOR_BORDER]
            )
          : is_outline
            ? (SetMouseCursor(MOUSE_CURSOR_POINTING_HAND), theme_colors[M_COLOR_BORDER])
            : (SetMouseCursor(MOUSE_CURSOR_POINTING_HAND), theme_colors[M_COLOR_DARK_PRIMARY])
        : is_disabled
          ? is_outline
            ? (Clay_Color){0, 0, 0, 0}
            : theme_colors[M_COLOR_BORDER]
          : is_outline
            ? (Clay_Color){0, 0, 0, 0}
            : theme_colors[color_id]
    }
  ) {
    if (!is_disabled) Clay_OnHover(HandleClick, callback);
    CLAY_TEXT(DynamicClayString(label), {
      .fontId = M_FONT_SEMIBOLD,
      .fontSize = 18,
      .textColor = is_disabled
        ? theme_colors[M_COLOR_TEXT_DIMMED]
        : is_outline
          ? theme_colors[color_id]
          : theme_colors[M_COLOR_TEXT_WHITE]
    });
  }
}
