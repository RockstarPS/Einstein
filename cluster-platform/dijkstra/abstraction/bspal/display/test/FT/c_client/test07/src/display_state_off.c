

#include "dk_bspal_display.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  EBspalDisplayStatus_t l_state;
 
  printf("Start: %s\n", argv[0]);
  uint32_t retp = dk_bspal_display_set_power(0, EBspalDisplayPower_Off);
  if (retp == 0) {
    uint32_t ret = dk_bspal_display_get_state(0, &l_state);
    printf("Return value is :%d\n", ret);
    if (ret == 0) {
      printf("display state is %d\n", l_state);
    }
  }
  printf("Exit: %s\n", argv[0]);

  return 0;
}
