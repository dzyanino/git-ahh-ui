#ifndef BUTTON_H
#define BUTTON_H

#include "../../theme/colors.h"
#include "../../theme/variants.h"

void HandleClick(Clay_ElementId element_id, Clay_PointerData pointer_info, void *user_data);

void ComponentButton(char* id, char* label, m_variant_id_t variant_id, m_color_id_t color_id, int* disabled, void (*callback)());

#endif
