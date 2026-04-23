#include <stdio.h>

#define IN 1
#define OUT 0

/****************************************************************

Program to print output one word per line.

1. start scanning through - ignore any initial whitespace
2. state is IN until end of word
3. upon state change to OUT, insert newline
4. repeat

Jaimin L. Symonds Patel

*****************************************************************/

int main(void)
{
    int c, state, laststate;

    state = OUT;
    laststate = OUT;

    while ((c = getchar()) != EOF)
    {
        /* check if current char is not blank - if so then in word */
        if (c != ' ' && c != '\n' && c != '\t')
        {
            state = IN;
            putchar(c);
        }
        /* else, if current char is blank, then determine if at end of word */
        else
        {
            state = OUT;

            /* if currently finished word, then print newline for next word  */
            if (laststate == IN && state == OUT)
            {
                printf("\n");
            }
        }

        laststate = state;
    }

    return 0;
}
