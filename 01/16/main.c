/****************************************************************
program to capture the longest line, and correctly print the
length of arbitrarily long input lines, and as much of the text
as possible

NOTE!!!
cannot use "getline" as name of defined function because of
function of same name being introduced into the c lib stdio.h
around 2010.
-----------------------
Jaimin L. Symonds Patel
*****************************************************************/

#include <stdio.h>
#define MAXLINE 1000            /* maximum input line size */

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    /* current line length */
    int len;
    /* max length seen so far */
    int max;

    /* current input line */
    char line[MAXLINE];
    /* longest line is saved here */
    char longest[MAXLINE];

    max = 0;
    while ((len = getline2(line, MAXLINE)) > 0)
    {
        /* print each line taken as input */
        printf("%d: \"%s\"", len, line);
        /* if line is longest, store it and record length */
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    /* if there was a line taken in input, then print the max line */
    if (max > 0)
    {
        printf("Longest line: \t%s", longest);
        printf("Length of line:\t%d", max);
    }
    return 0;
}


/* define getline2 */
int getline2(char s[], int lim)
{
    int c, i;

    /* for loop to capture characters in line, no EOF, and no newline */
    /* limit of characters per line is ignored because arbitrarily long lines are handled */
    for (i = 0; ((c = getchar()) != EOF) && (c != '\n'); ++i)
    {
        /* store line chars in array when within limit where last two chars are \n, and \0. */
        /* therefore, indices 0-(lim-1) is total, but [lim-2]=\n, and [lim-1]=\0 */
        if ()
        {
            
        }
        
    }
    /* if line has newline at end, capture newline */
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* define copy to copy char arrays */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}
