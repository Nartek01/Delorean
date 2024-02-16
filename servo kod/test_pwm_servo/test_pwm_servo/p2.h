/*
 * p2.h
 *
 * Created: 2023-11-08 10:47:32
 *  Author: mardea0831
 */ 


#ifndef P2_H_
#define P2_H_
#define F_CPU 16000000UL // 16 MHz klockfrekvens.
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>

/************************************************************************/
/* Function Name: wait(uint16_t ms)                                     */
/* parameter: int ms, milliseconds to wait                              */
/* Return: void                                                         */
/* Description:                                                         */
/* The program waits a amount of milliseconds                           */
/************************************************************************/
void wait(uint16_t wait_ms) {
    for (uint16_t i = 0;i<wait_ms;i++) {
        _delay_us(1);
    }
}

void setup_p2(void) {

    /*sätter i/o för PORTB
    Bit     Arduino pin     Funktion        i/o 1 = out
    0       pin 8           digit 2         1
    1       pin 9           digit 1         1
    2       pin 10          Funktionsval 4  0
    3       pin 11          Funktionsval 3  0
    4       pin 12          Funktionsval 2  0
    5       pin 13          Funktionsval 1  0
    6       crystal         Används ej      0
    7       crystal         Används ej      0

    bit      76543210     */
    DDRB = 0b00000011;
    
    /*sätter i/o för PORTC
    Bit     Arduino pin     Funktion        i/o 1 = out
    0       pin A0          Volt låg        0
    1       pin A1          Volt hög        0
    2       pin A2          Resistans låg   0
    3       pin A3          Resistans hög   0
    4       pin A4          Batterikontroll 0
    5       pin A5          Reserv                
    6       reset           Används ej 
    7       ---             Används ej 
    bit      76543210     */
    DDRC = 0b00000000;

    /*sätter i/o för PORTD
    Bit     Arduino pin     Funktion        i/o 1 = out
    0       pin 0           BCD 0           1
    1       pin 1           BCD 1           1
    2       pin 2           BCD 2           1
    3       pin 3           BCD 3           1
    4       pin 4           Buzzer          1
    5       pin 5           Ledig           
    6       pin 6           decimalpunkt    1
    7       pin 7           digit 3         1
    bit       76543210       */
    DDRD = 0b11011111;

    /*Initiera analogingångar*/
    ADMUX = (1 << REFS0);
    ADCSRA = ((1 << ADEN) | (1 << ADSC) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2));
    while ((ADCSRA & (1 << ADIF)) == 0) ;
    ADCSRA = (1 << ADIF);
    return;
}


/************************************************************************/
/* uint16_t read_analogue_input(uint8_t input_number)                   */
/*                                                                      */
/* Argument:                                                            */
/* uint8_t input_number                                                 */
/* Reprecenterar den ingång (0 - 5) som skall läsas av                  */
/*                                                                      */
/* Return:                                                              */
/* Det returnerande värdet är ett 16-bitars uint-tal mellan 0 - 1023    */
/************************************************************************/
         
uint16_t read_analogue_input(uint8_t input_number) {
    ADMUX = ((1 << REFS0) | input_number);
    ADCSRA = ((1 << ADEN) | (1 << ADSC) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2));
    while ((ADCSRA & (1 << ADIF)) == 0) ;
    ADCSRA = (1 << ADIF);
    return ADC;
}

/************************************************************************/
/* bool read_digital_input_portb(uint8_t bit)                           */
/*                                                                      */
/* Argument:                                                            */
/* uint8_t bit                                                          */
/* Reprecenterar den bit på PORTB som skall läsas av                    */
/*                                                                      */
/* Return:                                                              */
/* True eller False beroende på om ingången är hög eller låg            */
/************************************************************************/
bool read_digital_input_portb(uint8_t bit) {
    return PINB & (1 << bit);
}

/************************************************************************/
/* bool read_digital_input_portc(uint8_t bit)                           */
/*                                                                      */
/* Argument:                                                            */
/* uint8_t bit                                                          */
/* Reprecenterar den bit på PORTC som skall läsas av                    */
/*                                                                      */
/* Return:                                                              */
/* True eller False beroende på om ingången är hög eller låg            */
/* OBS! normalt används PORTC för analog läsning                        */
/************************************************************************/
bool read_digital_input_portc(uint8_t bit) {
    return PINC & (1 << bit);
}

/************************************************************************/
/* bool read_digital_input_portd(uint8_t bit)                           */
/*                                                                      */
/* Argument:                                                            */
/* uint8_t bit                                                          */
/* Reprecenterar den bit på PORTD som skall läsas av                    */
/*                                                                      */
/* Return:                                                              */
/* True eller False beroende på om ingången är hög eller låg            */
/************************************************************************/

bool read_digital_input_portd(uint8_t bit) {
    return PIND & (1 << bit);
}

/************************************************************************/
/* bool write_digital_output_portb(uint8_t bit, bool value)             */
/*                                                                      */
/* Argument:                                                            */
/* uint8_t bit                                                          */
/* Reprecenterar den bit på PORTB som skall skrivas till                */
/*                                                                      */
/* bool value                                                           */
/* true eller false beroende på om man vill sätta utgången till hög/låg */
/*                                                                      */
/* Return:                                                              */
/* Void                                                                 */
/************************************************************************/

void write_digital_output_portb(uint8_t bit, bool value) {
    if(value) {
        PORTB |= (1 << bit);
        }else {
        PORTB &= ~(1 << bit);
    }
}

/************************************************************************/
/* bool write_digital_output_portc(uint8_t bit, bool value)             */
/*                                                                      */
/* Argument:                                                            */
/* uint8_t bit                                                          */
/* Reprecenterar den bit på PORTC som skall skrivas till                */
/*                                                                      */
/* bool value                                                           */
/* true eller false beroende på om man vill sätta utgången till hög/låg */
/*                                                                      */
/* Return:                                                              */
/* Void                                                                 */
/* OBS! normalt används PORTC för analog läsning                        */
/************************************************************************/
void write_digital_output_portc(uint8_t bit, bool value) {
    if(value) {
        PORTC |= (1 << bit);
        }else {
        PORTC &= ~(1 << bit);
    }
}

/************************************************************************/
/* bool write_digital_output_portd(uint8_t bit, bool value)             */
/*                                                                      */
/* Argument:                                                            */
/* uint8_t bit                                                          */
/* Reprecenterar den bit på PORTD som skall skrivas till                */
/*                                                                      */
/* bool value                                                           */
/* true eller false beroende på om man vill sätta utgången till hög/låg */
/*                                                                      */
/* Return:                                                              */
/* Void                                                                 */
/************************************************************************/
void write_digital_output_portd(uint8_t bit, bool value) {
    if(value) {
        PORTD |= (1 << bit);
        }else {
        PORTD &= ~(1 << bit);
    }
}






#endif /* P2_H_ */