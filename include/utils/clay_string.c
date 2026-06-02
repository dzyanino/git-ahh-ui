#include "clay_string.h"
#include <string.h>

Clay_String DynamicClayString(char* string) {
  if (strlen(string) == 0) {
    return CLAY_STRING("");
  }
  return ((Clay_String) { .chars = string, .length = strlen(string), .isStaticallyAllocated = false });
}
