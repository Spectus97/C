#include "peripherals.h"


#define ADDR_OFFSET(addr, offset) ((uint32_t*)((uint8_t*)(addr) + 0x20 * GET_PORT(p)))

void select_gpio_out_mode(uint32_t p)
{
    uint32_t register_idx = 2*GET_PORT(p);
    uint32_t pin = GET_PIN(p);
    volatile uint32_t *dir_register;

    if (pin >= 16)
    {
    	pin -= 16;
    	register_idx++;
    }
    /* Configure function */
    PINSEL[register_idx] &= ~(3 << (pin * 2)); /* Clear the two function bits -> gpio mode (p. 108) */

    /* Configure mode */
    PINMODE[register_idx] &= ~(3 << (pin * 2)); /* Clear the two mode bit -> pull-up resistor */

    /* Configure opendrain */
    PINMODE_OD[GET_PORT(p)] &= ~(1 << GET_PIN(p)); /* Clear bit -> normal (not opendrain) mode */

    /* Set GPIO mode to output */
    dir_register = ADDR_OFFSET(&FIO0DIR, 0x20 * GET_PORT(p));
    *dir_register |= (1 << GET_PIN(p)); /* set bit to 1 -> set pin to output */
}

/* Set pin to HIGH */
void set_pin(uint32_t p)
{
    volatile uint32_t *set_register = ADDR_OFFSET(&FIO0SET, 0x20 * GET_PORT(p));
    volatile uint32_t *mask_register = ADDR_OFFSET(&FIO0MASK, 0x20 * GET_PORT(p));

    *mask_register = ~(1 << GET_PIN(p)); /* Affected pin are those whose mask is 0 */
    *set_register = (1 << GET_PIN(p)); /* Set pin to HIGH */
}

/* Clear pin to GND */
void clr_pin(uint32_t p)
{
    volatile uint32_t *clr_register = ADDR_OFFSET(&FIO0CLR, 0x20 * GET_PORT(p));
    volatile uint32_t *mask_register = ADDR_OFFSET(&FIO0MASK, 0x20 * GET_PORT(p));

    *mask_register = ~(1 << GET_PIN(p)); /* Affected pin are those whose mask is 0 */
    *clr_register = (1 << GET_PIN(p)); /* Set pin to GND */
}


void wait(void)
{
    int i;
    uint32_t j;

    for (i=0 ; i < (105000) ; ++i)
    	j = FIO0MASK;
    /* avoids an unused variable 'j' warning */
    if (j == (1000000))
    	return ;
}

void nuance(int r, int color) // 1 red , 2 vert, 3 bleu
{
  int i = 0;
      for(i=0; i<1000;i++){

	if(color == 1){
	  clr_pin(MBED_BASE_DIP24);
	  clr_pin(MBED_BASE_DIP25);
	}else if(color == 2){
	  clr_pin(MBED_BASE_DIP23);
	  clr_pin(MBED_BASE_DIP25);
	}else if(color == 3){
	  clr_pin(MBED_BASE_DIP24);
	  clr_pin(MBED_BASE_DIP23);
	}
	
	int o;
	for(o = 0; o < 100; o++){
	  if(r == (100-o)){
	    if(color == 1){
	      set_pin(MBED_BASE_DIP24);
	      set_pin(MBED_BASE_DIP25);
	    }else if(color == 2){
	      set_pin(MBED_BASE_DIP23);
	      set_pin(MBED_BASE_DIP25);
	    }else if(color == 3){
	      set_pin(MBED_BASE_DIP23);
	      set_pin(MBED_BASE_DIP24);
	    }
	  }
	}
      }
}

void main(void)
{ 
    /* First select GPIO mode of LED PINS */
    select_gpio_out_mode(MBED_BASE_DIP23);
    select_gpio_out_mode(MBED_BASE_DIP24);
    select_gpio_out_mode(MBED_BASE_DIP25);

    while(1)
    {
      nuance(0,1);
      nuance(25,1);
      nuance(50,1);
      nuance(75,1);
      nuance(99,1);

      nuance(0,2);
      nuance(25,2);
      nuance(50,2);
      nuance(75,2);
      nuance(99,2);

      nuance(0,3);
      nuance(25,3);
      nuance(50,3);
      nuance(75,3);
      nuance(99,3);
    }
}
