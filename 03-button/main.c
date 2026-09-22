#include "ch32fun.h"
#include <stdio.h>

#define LED     PC1
#define BUTTON  PD2

int main(void) {
  SystemInit();
  funGpioInitAll();

  funPinMode(LED, GPIO_Speed_10MHz | GPIO_CNF_OUT_PP);
  funPinMode(BUTTON, GPIO_CNF_IN_PUPD);
  funDigitalWrite(BUTTON, FUN_HIGH);

  int led = 0, last = 0;
  while(1) {
    int now = funDigitalRead(BUTTON);
    if(last == 1 && now == 0) {
      Delay_Ms(20);
      if(funDigitalRead(BUTTON) == 0) {
        led = !led;
        funDigitalWrite(LED, led ? FUN_HIGH : FUN_LOW);
        printf("Press, led=%d\n", led);
      }
    }
    last = now;
    Delay_Ms(2);
  }
}