#include <stdio.h>

/****************************************************************

Replace instances of one or more blanks with one space.

Jaimin L. Symonds Patel

*****************************************************************/

int main(void)
{
    int c; // output of getchar()
    int lastc; // the previous character in input stream

    /* initially set lastc to an arbitrary non-blank char */
    lastc = 'a';

    while ((c = getchar()) != EOF)
    {
        if (c != ' ') // output non blank chars normally
            putchar(c);
        if (c == ' ') // if char is a space, then:
            if (lastc != ' ')
                putchar(' '); // print it normally if it is preceded by non-blank

        // otherwise, print nothing

        /* set the last char to the current one for next loop */
        lastc = c;
    }

    return 0;
}
