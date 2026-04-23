#include <stdio.h>

/****************************************************************

Program to make conversion table from Celsius to Fahrenheit.

Jaimin L. Symonds Patel

*****************************************************************/

int main(void)
{
    int fahr;
    
    printf("Fahrenheit | Celsius\n");
    printf("-----------|--------\n");


    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
    {
        printf("%10d | %7.1f\n", fahr, ((5.0 / 9.0) * (fahr - 32)));
    }
}
