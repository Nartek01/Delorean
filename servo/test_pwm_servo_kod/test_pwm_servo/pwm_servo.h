/*
 * pwm_servo.h
 *
 * Created: 2024-03-04 11:21:44
 *  Author: Peter
 */ 


#ifndef PWM_SERVO_H_
#define PWM_SERVO_H_


void pwm_function (int16_t analog_value)
{
    if (analog_value < 123)
    {
        analog_value = 123;
    }
    else if (analog_value > 600)
    {
        //OCR1A = 0;
        analog_value = 600;
    }    
    /*OCR1AH = 0b00000010;
    OCR1AL = round((-1.452214*analog_value)+980.2448);*/
    /*OCR1A = round((-1.759887*analog_val       ue)+1055.932);*/
    OCR1A = round((-1.93501*analog_value)+1161);
}

void pwm_init ()
{
    DDRB |= (1<<1) | (1<<2);    // S�tter utg�ngar D9 och D10
    OCR1AH = 0x00;              // 
    //OCR1AL = 47;              // S�tter duty cycle 47 i mitten, 32 l�ngst �t h�ger, 62 l�ngst �t *****
    //OCR1BL = 150;
    /*ICR1H = 0b00000010;         // S�tter h�gstav�rdet den r�knar till ICR1H = 0b00000010; + ICR1L = 0b01101111; = 50 Hz
    ICR1L = 0b01101111;*/         // S�tter h�gstav�rdet den r�knar till
    ICR1 = 923;
    TCCR1A = 0xA2;              // 
    TCCR1B = 0b00010010;        // f�rsta nibble s�tter PWM-typen - sista nibble s�tter prescaler (detta �r 256 prescaler)
}


#endif /* PWM_SERVO_H_ */