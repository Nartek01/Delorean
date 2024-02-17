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
        /*analogue_value = L�ser analogv�rde till variabel med hj�lp av Martins bibliotek fr�n P2.
        av_divided = Rundar av v�rdet fr�n analogporten och delar med 1,023 f�r att f� ett v�rde mellan 0-1000
        on_value = PWM-h�g grunden �r 1 ms (delay �r �ndrad till us i p2.h) och adderas av av_devided
        off_value = PWM-l�g grunden �r 19000 ms f�r skapa en hel cykel som servot kan klara av*/
        
        uint16_t analogue_value = read_analogue_input(0);
        //uint16_t av_divided = round(analogue_value / 1.023);
        //uint16_t on_value = 1000+av_divided;
        //uint16_t off_value = 29000-av_divided;

        void turn_left() {
            //uint16_t analogue_value = read_analogue_input(0);
            //uint16_t av_divided = round(analogue_value / 1.023);
            //uint16_t on_value = 900+av_divided;
            //uint16_t off_value = 14000-av_divided;

            write_digital_output_portb(1,1);
            _delay_ms(1);
            write_digital_output_portb(1,0);
            _delay_ms(1);
        }

        void turn_right() {
            uint16_t analogue_value = read_analogue_input(0);
            uint16_t av_divided = round(analogue_value / 1.023);
            uint16_t on_value = 900+av_divided;
            uint16_t off_value = 14000-av_divided;
            write_digital_output_portb(1,1);
            _delay_ms(2.5);
            write_digital_output_portb(1,0);
            _delay_ms(2.5);
        }

        void turn_straight() {
            write_digital_output_portb(1,1);
            _delay_ms(1.5);
            write_digital_output_portb(1,0);
            _delay_ms(1.5);
        }
        
        /*PWM-signal i en for-loop med en wait emellan*/
        turn_right();
        _delay_ms(1000);
        turn_straight();
        _delay_ms(1000);
        turn_left();
        _delay_ms(1000);
        
        //for (uint8_t i = 0; i < 3; i++)
        //{
        //write_digital_output_portb(1,1);
        //_delay_us();
        //write_digital_output_portb(1,0);
        //_delay_us();
        //}
    }
}