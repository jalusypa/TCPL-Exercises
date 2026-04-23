#include <stdio.h>

#define MAX_BAR_LENGTH 20
#define TOTAL_LETTERS 26


/**********************************************************/
/* Program to print horizontal histogram of the number of */
/* words of a particular length                           */
/*                                                        */
/* Jaimin L. Symonds Patel                                */
/**********************************************************/

int main(void)
{
    /* Initialising Variables */
    /* ********************** */
    
    /* indexing vars */
    int i, j;
    /* current char */
    int c;
    /* last char */
    int lastc;
    /* create array to hold the frequencies of all characters */
    /* regardless of case */
    int char_freqs[TOTAL_LETTERS];
    /* array containing alphabet */
    char alphabet[TOTAL_LETTERS];
    /* the histogram scaling factor */
    int hist_scaling;
    /* maximum freq value - used for scaling */
    int max_freq;
    /* temp word length var */
    int current_word_length;

    /* assign initial values */
    for (i = 0; i < TOTAL_LETTERS; ++i)
    {
        char_freqs[i] = 0;
        /* initialise the alphabet array with all the capital letters */
        alphabet[i] = 65+i;
    }
    max_freq = 0;

    /* Build the main frequencies array and scale for histogram */
    /* ********************************************************** */
    /* build char_freq array */
    while((c = getchar()) != EOF)
    {
        /* for each letter, check if the letter matches any of the alphabet */
        for (i = 0; i < TOTAL_LETTERS; ++i)
        {
            if (c == alphabet[i] || (c - 32) == alphabet[i])
            {
                ++char_freqs[i];
            }
            else
            {
                /* do nothing */
            }
        }
    }

    
    /* find the max frequecy */
    for (i = 0; i < TOTAL_LETTERS; ++i)
    {
        if (max_freq < char_freqs[i])
        {
            max_freq = char_freqs[i];
        }
    }

    /* scale the word_lengths array according to the MAX_BAR_LENGTH */
    if (max_freq > MAX_BAR_LENGTH)
    {
        /* if the hist_scaling can be an integer */
        if (((max_freq / MAX_BAR_LENGTH) * MAX_BAR_LENGTH) == max_freq)
        {
            hist_scaling = max_freq / MAX_BAR_LENGTH;
        }
        /* if hist_scaling when calculated cannot be an integer, then round up */
        else
        {
            hist_scaling = (max_freq + MAX_BAR_LENGTH) / MAX_BAR_LENGTH;
        }
    }
    else
    {
        hist_scaling = 1;
    }

    /* change the char_freq array to be scaled (making it the number of bar units) */
    for (i = 0; i < TOTAL_LETTERS; ++i)
    {
        char_freqs[i] = char_freqs[i] / hist_scaling;
    }

    /* print the top row headers */
    /* make it such that the width of the whole historgram is 5 + MAX_BAR_LENGTH */
    printf("This is a histogram showing frequency of alphabetical letters\n");
    printf("within a body of text.\n\n");

    printf("* = %d count/counts\n", hist_scaling);
    printf("ltrs |");
    for (i = 0; i <= MAX_BAR_LENGTH; ++i)
    {
        printf(" ");
    }
    printf("\n");
    printf("-----|");
    for (i = 0; i <= MAX_BAR_LENGTH; ++i)
    {
        printf("-");
    }
    printf("\n");

    /* print the histogram bars */
    for (i = 0; i < TOTAL_LETTERS; ++i)
    {
        printf("%c    |", alphabet[i]);
        for (j = 1; j <= char_freqs[i]; ++j)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
