#include <stdio.h>

/****************************************************************

Verify that the expression getchar() != EOF is 0 or 1.

Jaimin L. Symonds Patel

*****************************************************************/

int main(void)
{
    int c;
                 
    while (c = (getchar() != EOF))
    {
        printf("%d\n", c);
    }
    
    printf("The last character signifies EOF\n");

    return 0;
}
