#include "ch32fun.h"
#include <stdio.h>

#define LED PC1

int main(void) {
  SystemInit();
  funGpioInitAll();

  funPinMode(LED, GPIO_Speed_10MHz | GPIO_CNF_OUT_PP);

  while(1) {
    funDigitalWrite(LED, FUN_HIGH);
    Delay_Ms(250);
    funDigitalWrite(LED, FUN_LOW);
    Delay_Ms(250);
  }
}