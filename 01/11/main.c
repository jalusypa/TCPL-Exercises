#include <stdio.h>

#define IN 1
#define OUT 0

/****************************************************************

program to count words - how would you test it?

Jaimin L. Symonds Patel

*****************************************************************/

int main(void)
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }

    printf("Characters:\t%d\n", nc);
    printf("Words:\t\t%d\n", nw);
    printf("New Lines:\t%d\n", nl);

    return 0;
}
