#include <stdio.h>

/****************************************************************
Program to make conversion table from Celsius to Fahrenheit.
Using a funcion (this time)
-----------------------
Jaimin L. Symonds Patel
*****************************************************************/

float celsius2fahr(float);

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;
    
    lower = -10;
    upper = 150;
    step = 10;

    printf("Celsius | Fahrenheit\n");
    printf("--------|-----------\n");

    celsius = lower;
    while (celsius <= upper)
    {
        printf("%7.0f | %10.1f\n", celsius, celsius2fahr(celsius));
        celsius = celsius + step;
    }
    
}

float celsius2fahr(float c)
{
    float f;
    
    f = (9.0 * c / 5.0) + 32.0;
    return f;
}
    
