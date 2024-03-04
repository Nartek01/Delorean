/*
* sensor_readings.h
*
* Created: 2024-03-04 11:37:26
*  Author: Peter
*/

void swap();
void selectionSort();
void perf_sensor_right_reading ();


#ifndef SENSOR_READINGS_H_
#define SENSOR_READINGS_H_

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

uint16_t a;
uint16_t b;
uint16_t c;
uint16_t d;
uint16_t e;



void perf_sensor_right_reading ()
{
    uint16_t sensor_reading_arr [] = {a,b,c,d,e};
    
    for (uint8_t i = 0; i < 5; i++)
    {
        sensor_reading_arr[i] = read_analogue_input(0);
    }
    
    uint8_t n = sizeof(sensor_reading_arr) / sizeof(sensor_reading_arr[0]);
    selectionSort(sensor_reading_arr, n);
    
}

#endif /* SENSOR_READINGS_H_ */