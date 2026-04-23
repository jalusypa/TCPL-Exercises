#include <stdio.h>

/****************************************************************

replace tabs with \t, backspaces by \b, and each backsalsh by \\

Jaimin L. Symonds Patel

*****************************************************************/

int main(void)
{
    int c; // output of getchar()

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
            printf("\\t");
        if (c == '\b')
            printf("\\b");
        if (c == '\\')
            printf("\\\\");

        /* else print char if above chars not matched */
        if (c != '\t')
            if (c != '\b')
                if (c != '\\')
                    putchar(c);
    }

    return 0;
}
