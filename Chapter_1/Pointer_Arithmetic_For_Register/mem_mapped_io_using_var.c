#include <stdint.h>


volatile uint32_t* const porta_moder = (volatile uint32_t*) 0x50000000;
volatile uint32_t* const porta_odr = (volatile uint32_t*) 0x50000014;
#define RCC_IOPENR   (*(volatile uint32_t *)0x40021034)


volatile uint32_t* const systick_ctrl = (volatile uint32_t*) 0xE000E010;
volatile uint32_t* const systick_load = (volatile uint32_t*) 0xE000E014;
volatile uint32_t* const systick_val = (volatile uint32_t*) 0xE000E018;


void sleep(uint32_t ms){
  for(uint32_t i = 0; i < ms; i++){
   // 1. Set Load value for 1ms.
   // Assuming 48MHz clock (adjust if your chip is different)
   *systick_load = 48000 - 1;


   // 2. Reset the current value register
   *systick_val = 0;


   // 3. Enable SysTick, use Processor Clock
   *systick_ctrl = (1 << 0)|(1 << 2);


   // 4. Wait for the COUNTFLAG to become 1
   while (!(*systick_ctrl & (1 << 16))) {
    // Wait...


  }
}
}


int main(void){
  RCC_IOPENR |= (1 << 0);
  uint32_t moder = *porta_moder;
  moder |= (1 << 10);
  moder &= ~(1 << 11);
  *porta_moder = moder;


while(1){
  *porta_odr |= (1 << 5);
  sleep(500);
  *porta_odr &= ~(1 << 5);
  sleep(500);
}
}
