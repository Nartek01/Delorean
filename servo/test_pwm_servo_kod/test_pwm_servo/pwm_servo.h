/*
 * pwm_servo.h
 *
 * Created: 2024-03-04 11:21:44
 *  Author: Peter
 */ 


#ifndef PWM_SERVO_H_
#define PWM_SERVO_H_


/*Funktion som tolkar om värdet till PWM-värde -50 -> 50*/
void pwm_function (int16_t analog_value)
{
    if (analog_value < 246)
    {
        analog_value = 246;
    }
    else if (analog_value > 600)
    {
        OCR1A = 0;
        analog_value = 600;
    }    
    /*OCR1AH = 0b00000010;
    OCR1AL = round((-1.452214*analog_value)+980.2448);*/
    OCR1A = round((-1.759887*analog_value)+1055.932);
}

void pwm_init ()
{
    DDRB |= (1<<1) | (1<<2);    // Sätter utgångar D9 och D10
    OCR1AH = 0x00;              // 
    //OCR1AL = 47;              // Sätter duty cycle 47 i mitten, 32 längst åt höger, 62 längst åt *****
    //OCR1BL = 150;
    /*ICR1H = 0b00000010;         // Sätter högstavärdet den räknar till ICR1H = 0b00000010; + ICR1L = 0b01101111; = 50 Hz
    ICR1L = 0b01101111;*/         // Sätter högstavärdet den räknar till
    ICR1 = 623;
    TCCR1A = 0xA2;              // 
    TCCR1B = 0b00010100;        // första nibble sätter PWM-typen - sista nibble sätter prescaler (detta är 256 prescaler)
}


#endif /* PWM_SERVO_H_ */