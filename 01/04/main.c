#include <stdio.h>

/****************************************************************

Program to make conversion table from Celsius to Fahrenheit.

Jaimin L. Symonds Patel

*****************************************************************/

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
        fahr = (9.0 * celsius / 5.0) + 32.0;
        printf("%7.0f | %10.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    
}
