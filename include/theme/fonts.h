#ifndef FONTS_H
#define FONTS_H

#include <stdint.h>

typedef enum : uint16_t {
  M_FONT_REGULAR = 0,
  M_FONT_SEMIBOLD = 1,
  M_FONT_BOLD = 2,

  M_FONT_DISPLAY_BOLD = 3,
  M_FONT_DISPLAY_ITALIC = 4,

  M_FONT_MONO_REGULAR = 5,
  M_FONT_MONO_BOLD = 6,
  M_FONT_MONO_ITALIC = 7,
} FontID; // just for convenience

#endif
