/*
----- Detail about Tiva LaunchPad I/O -----
- The built-in RGB LED is controlled with PF1 (LED_R), PF2 (LED_B), PF3 (LED_G)
- The built-in switches are controlled with PF0 (USR_SW2), PF4 (USR_SW1)

- GPIO Port F address range: 0x4002.5000 to 0x4002.5FFF
  ~NOTE: The GPIO Port clocks are disabled to save power.
         The Clock Gate Control Register (RCGCGPIO) is a 32 bit value at: 
         0x400F.E608. Bits 31-6 are reserved, bits 5-0 are for 
         clock enable on GPIO F-A.

  ~ In our case, we want to use GPIO Port F, so we enable the clock on port F via:
    (int *)0x400FE608 |= 0x00000020

- Before we can set or read GPIO Port values, we need to assign the
  data direction register for Port F. This way the controller knows if we
  intend to read, or write on each bit on the port.

- The offset (from 0x4002.5000) for GPIO direction (GPIODIR) is 0x400.
  ~ Setting a GPIODIR bit assigns the corresponding pin to be an OUTPUT.
  ~ Clearing a GPIODIR bit assigns the corresponding pin to be an INPUT.
  - In our case, we want PF1, PF2, and PF3. This corresponds to binary:
    0000.0000.0000.1110 == 0xE
  - Therefore, (int *)0x4002.5400 == 0x0000000E

- The offset (from 0x4002.5000) for GPRIO Digital Enable (GPIODEN) is 0x51C.
  ~ Required to use a pin as digital input, or output (since pins are tristate)
  ~ Therefore, (int *)0x4002.551C == 0x0000000E

- The offset (from 0x4002.5000) for GPIO data (GPIODATA) is 0x000.
  ~ There are 100 points of addressable memory for GPIO data (400 bytes).
  ~ This is because for efficiency, you write to the address which acts as a
    mask, so we don't have to mask our write operation in software.
  ~ Refer to datasheet 10.2.1.2 "Data Register Operation"
  ~ In our case, we use address 0x40025038
  ~ The value at that address should be: 2, 4, 6, 8, 10, 12, 14 
  ~ 0x00000002 gives RED
  ~ 0x00000004 gives BLUE
  ~ 0x00000008 gives GREEN
*/

void myDelay(int interval)
{
    int i = 0;
    interval *= 1000;
    while (i < interval) {
        ++i;
    }
}

int main()
{
    /* See datasheet section 10.2.1.2 for details on chosen address */
    unsigned int *gpio_portF_led = (unsigned int *)0x40025038U;
    
    /* Enable clock for GPIO Port F (RCGCGPIO bit 5) */
    *((unsigned int *)0x400FE608U) |= 0x00000020U;
    
    /* Assign data direction for Port F (GPIODIR) */
    *((unsigned int *)0x40025400U) |= 0x0000000EU;
    
    /* Enable digital read/write on Port F (GPIODEN) */
    *((unsigned int *)0x4002551CU) |= 0x0000000EU;
    
    /* Write to correctly masked Port F Data Address (GPIODATA) */
    /* We don't need `|=` because the optimized address masking architecture */
    *gpio_portF_led = 0x00000000U;/* Initialize the LEDS to be off */
   
    while (1) {
        *gpio_portF_led += 0x2U;
        
        if (*gpio_portF_led > 0xE) {
            *gpio_portF_led += 0x00000000U;
        }
          
        myDelay(1000);
    }
    
    return 0;
}
