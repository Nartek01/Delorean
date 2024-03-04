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
    DDRB |= (1<<1) | (1<<2);    // S�tter utg�ngar D9 och D10
    OCR1AH = 0x00;              //
    //OCR1AL = 47;                // S�tter duty cycle 47 i mitten, 32 l�ngst �t h�ger, 62 l�ngst �t *****
    //OCR1BL = 150;
    ICR1H = 0b00000010;         // S�tter h�gstav�rdet den r�knar till ICR1H = 0b00000010; + ICR1L = 0b01101111; = 50 Hz
    ICR1L = 0b01101111;         // S�tter h�gstav�rdet den r�knar till
    TCCR1A = 0xA2;              //
    TCCR1B = 0b00010100;        // f�rsta nibble s�tter PWM-typen - sista nibble s�tter prescaler (detta �r 256 prescaler)
}    