/* Finds the lexicgraphically first and last ranked words in a series of words
 * entered by the user, and prints these - user input terminates when a string
 * of length four is entered */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 21
#define TERMINATE_LEN 4

/* function prototypes */
int read_str(char str[], int n);

int main(void)
{
    char usr_str[MAX_LEN], max_word[MAX_LEN], min_word[MAX_LEN];
    int i;

    /* we must take the user's first word and arbitrarily appoint it both the 
     * largest and smallest word - since we aren't making comparisons as with 
     * folowing words, this portion must be outside the for loop */
    printf("\nEnter word: ");

    /* read_str() returns -1 if the user's word was too long - since the while
     * loop calls read_str every time it evaluates its condition, and since
     * read_str() takes care of reading characters into usr_str, this loop 
     * constitutes a complete error check for strings longer than 20 
     * characters */
    while (read_str(usr_str, MAX_LEN) == -1) {
        printf("\nPlease try again: \n");
    }

    /* arbitrarily put the user's first word into both max_word and min_word -
     * should this first word be four characters long, this will be both the 
     * largest and the smallest string, and the program will print output and
     * terminate */
    strcpy(max_word, usr_str);
    strcpy(min_word, usr_str);

    if (strlen(usr_str) == TERMINATE_LEN) {
        printf("\nSmallest word: %s\n", min_word);
        printf("\nLargest word: %s\n", max_word);
        return 0;
    }

    /* infinite for loop - breaks when the user enters a word of four characters,
     * but only after the word is compared to the current largest and smallest 
     * words */
    for (;;) {
        printf("Enter word: ");

        while (read_str(usr_str, MAX_LEN) == -1) {
            printf("\nPlease try again: ");
        }

        if (strcmp(usr_str, max_word) > 0) {
            strcpy(max_word, usr_str);
        } else if (strcmp(usr_str, min_word) < 0) {
            strcpy(min_word, usr_str);
        }
        
        if (strlen(usr_str) == TERMINATE_LEN) {
            break;
        }
    }

    /* output is printed here if the user's first word was not four characters 
     * in length */
    printf("\nSmallest word: %s\n", min_word);
    printf("\nLargest word: %s\n", max_word);

    return 0;
}

/* while getchar() does not fetch a newline character, each character is fed 
 * into the string parameter that will be returned as usr_str - if the index
 * of the next character to be added reaches the maximum length of the 
 * char [] (20 characters), leaving no room for the null terminator, the 
 * function prints an error message and returns with error status - otherwise
 * the null character is tacked on to the end and the function returns normally */
int read_str(char str[], int n)    
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < n) {
            str[i++] = ch;
        } else {
            printf("\nError: the word you entered is too long\n");
            for (i = 0; i < n; i++ ) {
                str[i] = '\0';
            }
            return -1;
        }
    }
    str[i] = '\0';
    return 0;
}
