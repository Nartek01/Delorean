/*
 * PWM.c
 *
 * Created: 2024-03-04 10:51:14
 *  Author: Peter
 */ 

#define F_CPU 16000000UL
#include <xc.h>
#include <util/delay.h>
#include <stdint.h>

void pwm_init ()
{
    DDRB |= (1<<1) | (1<<2);    // Sätter utgångar D9 och D10
    OCR1AH = 0x00;              //
    //OCR1AL = 47;                // Sätter duty cycle 47 i mitten, 32 längst åt höger, 62 längst åt *****
    //OCR1BL = 150;
    ICR1H = 0b00000010;         // Sätter högstavärdet den räknar till ICR1H = 0b00000010; + ICR1L = 0b01101111; = 50 Hz
    ICR1L = 0b01101111;         // Sätter högstavärdet den räknar till
    TCCR1A = 0xA2;              //
    TCCR1B = 0b00010100;        // första nibble sätter PWM-typen - sista nibble sätter prescaler (detta är 256 prescaler)
}    