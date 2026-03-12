#include <stdint.h>

#define RCC_IOPENR (*(volatile uint32_t*) 0x40021034)
#define RCC_ENB (1 << 0)    //enable RCC
#define ODR_ENB (1 << 5)    //enable ODR fro PA5

volatile uint32_t* const systick_ctrl = (volatile uint32_t*) 0xE000E010;  //systic reg config
volatile uint32_t* const systick_load = (volatile uint32_t*) 0xE000E014;
volatile uint32_t* const systick_val = (volatile uint32_t*) 0xE000E018;

typedef struct
{
  uint32_t MODER;
  uint32_t OTYPER;
  uint32_t OSPEEDR;
  uint32_t PUPDR;
  uint32_t IDR;
  uint32_t ODR;
  uint32_t BSSR;
  uint32_t LCKR;
  uint32_t AFRL;
  uint32_t AFRH;
}GPIO_t;

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


volatile GPIO_t* const porta= (volatile GPIO_t*)0x40024400;

int main(){
  RCC_IOPENR |= RCC_ENB;

  uint32_t moder = porta->MODER;
  moder |= (1 << 10);   //enable pa5 using bit 10 and 11 in moder_a
  moder &= ~(1 << 11);
  porta->MODER = moder;

  while(1){
    porta->ODR |= ODR_ENB;
    sleep(500);
    porta->ODR &= ~ODR_ENB;
    sleep(500);
  }
}