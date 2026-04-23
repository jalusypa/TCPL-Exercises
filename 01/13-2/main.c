#include <stdio.h>

#define MAX_WORD_LENGTH 12
#define MAX_BAR_LENGTH 20


/**********************************************************/
/* Program to print vertical histogram of the number of   */
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
    /* array holding the number of i+1 lengthed words */
    /* note that the last elem is for all words>12  */
    int word_lengths[MAX_WORD_LENGTH + 1];
    /* the histogram scaling factor */
    int hist_scaling;
    /* the maximum number of words (can be of any length */
    int max_no_words;
    /* temp word length var */
    int current_word_length;

    /* assign initial values */
    lastc = ' ';
    for (i = 0; i < MAX_WORD_LENGTH; ++i)
    {
        word_lengths[i] = 0;
    }
    max_no_words = 0;
    current_word_length = 0;

    /* Build the main word_lengths array and scale for histogram */
    /* ********************************************************** */
    /* build word_lengths array */
    while((c = getchar()) != EOF)
    {
        /* if last char is a blank */
        if (lastc == ' ' || lastc == '\n' || lastc == '\t')
        {
            /* if current char is also blank */
            if (c == ' ' || c == '\n' || c == '\t')
            {
                /* do nothing */
            }
            /* else if current char is beginning of new word */
            else
            {
                ++current_word_length;
            }
        }
        /* else if last char is not a blank letter */
        else
        {
            /* if current char is now blank and the word is complete*/
            if (c == ' ' || c == '\n' || c == '\t')
            {
                if (current_word_length <= MAX_WORD_LENGTH)
                {
                    /* add 1 to the correct elem for the word length array */
                    ++word_lengths[current_word_length-1];
                    /* reset current word length */
                    current_word_length = 0;
                }
                else
                {
                    /* add 1 to the last elem which are words > MAX letters long*/
                    ++word_lengths[MAX_WORD_LENGTH];
                    /* reset current word length */
                    current_word_length = 0;
                }
            }
            /* else if current char is still inside word */
            else
            {
                ++current_word_length;
            }
        }
        lastc = c;
    }

    
    /* find the max no of words */
    for (i = 0; i <= (MAX_WORD_LENGTH); ++i)
    {
        if (max_no_words < word_lengths[i])
        {
            max_no_words = word_lengths[i];
        }
    }

    /* scale the word_lengths array according to the MAX_BAR_LENGTH */
    if (max_no_words > MAX_BAR_LENGTH)
    {
        if (((max_no_words / MAX_BAR_LENGTH) * MAX_BAR_LENGTH) == max_no_words)
        {
            hist_scaling = max_no_words / MAX_BAR_LENGTH;
        }
        else
        {
            hist_scaling = (max_no_words + MAX_BAR_LENGTH) / MAX_BAR_LENGTH;
        }
    }
    else
    {
        hist_scaling = 1;
    }

    /* change the word_lengths array to be scaled (making it the number of bar units) */
    for (i = 0; i <= MAX_WORD_LENGTH; ++i)
    {
        word_lengths[i] = word_lengths[i] / hist_scaling;
    }

    /* print the top row headers */
    /* make it such that the width of the whole historgram is 5 + MAX_BAR_LENGTH */
    printf("This is a histogram showing the distribution of words within\n");
    printf("the input, according to the number of letters within each word.\n\n");

    printf("* = %d word/words\n", hist_scaling);

    /* use for loop to go through each nth row of histogram, peeling off of */
    /* the word_lengths array. */
    for (i = MAX_BAR_LENGTH; i >= 1; --i)
    {
        for (j = 0; j <= MAX_WORD_LENGTH; ++j)
        {
            if (word_lengths[j] == i)
            {
                printf("  *  ");
                --word_lengths[j];
            }
            else
            {
                printf("     ");
            }
        }

        printf("\n");
    }
    printf("|---||---||---||---||---||---||---||---||---||---||---||---||----|\n");
    printf("| 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9 ||10 ||11 ||12 ||>12 |\n");
    printf("------------------------------------------------------------------\n");
    printf("                           No. of Letters                         \n");

    printf("\n");
    
    return 0;
}
