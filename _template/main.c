#include "ch32fun.h"
#include <stdio.h>

int main(void) {
  SystemInit();
  funGpioInitAll();

  while(1) {
    Delay_Ms(500);
  }
}