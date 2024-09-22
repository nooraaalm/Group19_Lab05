#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
void init (void);
void GPIO_Handler(void);
void init(void)
{
    SYSCTL_RCGCGPIO_R |= 0x20;         // Enable clock for port F
    GPIO_PORTF_LOCK_R = 0x4C4F434B;    // Unlock GPIO port F
    GPIO_PORTF_CR_R |= 0x10;           // Commit register for PF4

    GPIO_PORTF_DIR_R = 0x02;           // Set PF1 (LED) as output
    GPIO_PORTF_DEN_R = 0x12;           // Enable digital function on PF1 and PF4

    GPIO_PORTF_PUR_R = 0x10;           // Enable pull-up on PF4

    GPIO_PORTF_IS_R = 0x00;            // Set edge-sensitive triggering
    GPIO_PORTF_IBE_R = 0x00;           // Interrupt controlled by IEV
    GPIO_PORTF_IEV_R = 0x00;           // Falling edge detection for interrupt
    GPIO_PORTF_ICR_R = 0x10;           // Clear previous interrupt on PF4
    GPIO_PORTF_IM_R = 0x10;            // Unmask interrupt on PF4

    NVIC_EN0_R = 0x40000000;           // Enable interrupt in NVIC for GPIO port F

}

// Main function
int main(void)
{
    init();                            // Initialize GPIO and interrupts
    GPIO_PORTF_DATA_R = 0x00;          // Turn off the red LED initially
    while(1)
    {
        // Main loop, waiting for interrupt to occur
    }
}

// Interrupt handler for GPIO Port F
void GPIO_Handler(void)
{
}
