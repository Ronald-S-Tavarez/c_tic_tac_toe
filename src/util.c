#include <stdio.h>
#include "util.h"

void prompt_user_for_input(const char * prompt, const char * control, void * pointer) {
  printf(prompt);
  scanf(control, pointer);
}
