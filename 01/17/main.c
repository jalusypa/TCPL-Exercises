/****************************************************************
Program to print all input lines that are longer than 80 chars
-----------------------
Jaimin L. Symonds Patel
*****************************************************************/

#include <stdio.h>
#define MAXLINE 1000            /* maximum input line size */
#define LIMIT 80                /* limit of chars after which input is printed */

int getline2(char line[], int maxline);

int main(void)
{
    /* current line length */
    int len;

    /* current input line */
    char line[MAXLINE];

    while ((len = getline2(line, MAXLINE)) > 0)
    {
        if (len > LIMIT)
        {
            /* print each line taken as input only if its LIMIT chars or longer*/
            printf("%s\n", line);
            
        }
    }
    return 0;
}


/* define getline2 */
int getline2(char s[], int lim)
{
    /* variable to store each char, and variable for index of counting length of line */
    int c, i;
    /* variable to count the index of array to store the string */
    int j;
    j = 0;

    /* for loop to capture characters in line, no EOF, and no newline */
    /* limit of characters per line is ignored because arbitrarily long lines are handled */
    for (i = 0; ((c = getchar()) != EOF) && (c != '\n'); ++i)
    {
        /* store line chars in array when within limit where last two chars are \n, and \0. */
        /* therefore, indices 0-(lim-1) is total, but [lim-2]=\n (but choose not to store), and [lim-1]=\0 */
        if (i < (lim-1))
        {
            s[j] = c;
            ++j;
        }
    }

    /* if line has newline at end, don't capture newline in storage (it's easier to handle), */
    /* but don't count as character */
    if (c == '\n')
    {
        /* s[j] = c; */
        /* ++j; */
    }
    /* store ending null char */
    s[j] = '\0';
    return i;
}
