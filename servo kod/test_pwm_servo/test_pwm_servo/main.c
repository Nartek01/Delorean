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

/*Kommentar*/

int main(void)
{
    
    while(1)
    {
        uint16_t analogue_value = read_analogue_input(0);
        uint16_t av_divided = round(analogue_value / 1.023);
        uint16_t on_value = 1000+av_divided;
        uint16_t off_value = 19000-av_divided;
        
        for (uint8_t i = 0; i < 10; i++)
        {
            write_digital_output_portb(1,1);
            wait(on_value);
            write_digital_output_portb(1,0);
            wait(off_value);
        }
    }
}