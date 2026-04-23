#include <stdio.h>

/****************************************************************

count blanks, tabs, and newlines in a character text stream

Jaimin L. Symonds Patel

*****************************************************************/

int main(void)
{
    int c; // output of getchar()
    int nb; // number of blanks
    int nt; // number of tabs
    int nn; // number of newlines
    
    nb = 0;
    nt = 0;
    nn = 0;                 

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++nb;
        if (c == '\t')
            ++nt;
        if (c == '\n')
            ++nn;
    }

    printf("Number of blank spaces:\t%d\n", nb);
    printf("Number of tabs:\t\t%d\n", nt);
    printf("Number of newlines:\t%d\n", nn);    

    return 0;
}
