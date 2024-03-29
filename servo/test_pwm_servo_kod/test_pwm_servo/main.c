/*
* main.c
*
* Created: 2/5/2024 12:39:31 PM
*  Author: Peter
*/

#define F_CPU 16000000UL
#include <xc.h>
#include <stdint.h>
#include <util/delay.h>
#include <math.h>
#include "pwm_servo.h"
#include "sensor_readings.h"
#define frwd 7
#define bkwrd 8

int main(void)
{
    DDRD = 0b01000000; // D7 utg�ng
    DDRC = 0b00000000; //alla ing�ngar
    
    pwm_init();
    
    while(1)
    {
        PORTD = 0b01000000; // D7
        perf_sensor_front_reading();
        pwm_function(c);
        /*OCR1AH = 0b00000001;
        OCR1AL = 0b00110111;*/
        /*OCR1A = 50;*/
    }
}

