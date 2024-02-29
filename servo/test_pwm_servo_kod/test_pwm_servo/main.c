/*
 * main.c
 *
 * Created: 2/5/2024 12:39:31 PM
 *  Author: Peter
 */ 

#define F_CPU 16000000UL
#include <xc.h>
#include <util/delay.h>
#include "p2.h"
#include <math.h>

/*Funktion som tolkar om v�rdet till PWM-v�rde -50 -> 50*/
void servo_function (int8_t turning_value)
{
    OCR1AH = 0x00;
    OCR1AL = round((0.3*turning_value)+47);
}


int main(void)
{
    setup_p2();
    
    DDRB |= (1<<1) | (1<<2);    // S�tter utg�ngar D9 och D10
    OCR1AH = 0x00;              // 
    OCR1AL = 47;                // S�tter duty cycle 47 i mitten, 32 l�ngst �t h�ger, 62 l�ngst �t *****
    //OCR1BL = 150;             
    ICR1H = 0b00000010;         // S�tter h�gstav�rdet den r�knar till ICR1H = 0b00000010; + ICR1L = 0b01101111; = 50 Hz
    ICR1L = 0b01101111;         // S�tter h�gstav�rdet den r�knar till
    TCCR1A = 0xA2;              // 
    TCCR1B = 0b00010100;        // f�rsta nibble s�tter PWM-typen - sista nibble s�tter prescaler (detta �r 256 prescaler)
    
    while(1)
    {
        servo_function(23);
    }
}

