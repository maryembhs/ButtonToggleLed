
#include "led.h"
#define OFFSET_ODR           (0x14/4)
#define OFFSET_IDR           (0X10/4)


void InputOutputConfig (uint32_t *GPIOx, uint8_t Pin, uint8_t Mode){

  EMB_ASSERT(GPIOx == GPIOA || GPIOx == GPIOD );
  EMB_ASSERT(Pin==PIN0 || Pin   == PIN12   || Pin == PIN15 );
  EMB_ASSERT(Mode  == INPUT  || Mode == OUTPUT );
  uint16_t *RCCAHB1 = (uint16_t *)(0x40023830);
  
  if(GPIOx == GPIOA)
  {
    *RCCAHB1 |= (1<<0);
  }

  else if(GPIOx == GPIOD)
  {
    *RCCAHB1 |= (1<<3);
  }
  *GPIOx &= ~(0x3 << Pin*2);
  *GPIOx |= (Mode << Pin*2);
  
  


}
uint8_t  ButtonToggleLed(uint32_t *GPIOx, uint8_t Pin) {

  if(GPIOx == GPIOA && Pin == PIN0 ){
    *(GPIOx + OFFSET_ODR) &= ~(1<<Pin);
    *(GPIOx + OFFSET_ODR) |=  (1<<Pin);
    if((*(GPIOx + OFFSET_ODR))== 1 ){
      return (((*(GPIOD + OFFSET_IDR) >> PIN12) & 1) && ((*(GPIOD + OFFSET_IDR) >> PIN15) & 1));
    }
    else{
      return (((*(GPIOD + OFFSET_IDR) >> PIN12) & 0) && ((*(GPIOD + OFFSET_IDR) >> PIN15) & 1));
      
      
  
  }



  }

}

