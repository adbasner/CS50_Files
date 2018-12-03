/***************************************************************************
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 ***************************************************************************/
 
// standard libraries
#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Checks to see if the user entered a valid command line argument
    // returns comment and 1 if not.
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // assings an int n, and the atoi coverts argv[1], which is a string, 
    // to an int and assigns it to n.
    int n = atoi(argv[1]);

    // If a see was entered in argv[2], it is converted to an int via atoi
    // The function srand48() sets the first 32 bits to the seed
    // then feeds into drand48 as a starting point or if argc != 3
    // it returns null.
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // Iterates over the value entered for number of random ints
    // using the srand48 memory as a starting point.  
    
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
