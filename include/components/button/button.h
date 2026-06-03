#ifndef BUTTON_H
#define BUTTON_H

#include "../../theme/colors.h"

void HandleClick(Clay_ElementId element_id, Clay_PointerData pointer_info, void *user_data);

void ComponentButton(char* id, char* label, int variant, m_color_id_t color_id, int* disabled, void (*callback)());

#endif
