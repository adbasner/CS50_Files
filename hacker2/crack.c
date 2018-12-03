/********************************************************
* crack.c
*
* cs50
* Jerry Feng
*
* take in a DES-based encrypted poassword from a single
* command-line argument
* crack it and print the key out
********************************************************/

#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

// global variables; "a"s are just arbitrary initializations
char *key = "a";
//char *temp = "a";
// assume the password is maximum 8 characters long
char kie[8];

// prototype
void try(int index, char *salty, char *passcode);

int
main(int argc, char *argv[])
{
    // check for difficult users
    if (argc != 2)
        return 1;
    
    // store password to be cracked in a char * type
    char *password = argv[1]; 
    /*
    * copy the first two characters of the encrypted code
    * to a variable called salt, which will later be used
    * to generate possible passwords
    */
    char slt[2];
    strncpy(slt, password, 2);
    char *salt = (char *) slt;

    

    /*
    * use try function to test all possible keys
    * that are shorter than or equal to 8 characters long
    */
    for(int i = 0; i < 8; i++)
    {
        try(i, salt, password);
    }

}

/*
* parameters: index is the number of characters in the
* possible key; salty is just salt, used to generate possible
* password along with the key; passcode is the password
* entered by the user to compare with generated ones
*
* the function recursively test all combinations of small
* letters that are index characters long
*/
void try(int index, char *salty, char *passcode)
{
    for(int j = 97; j < 123; j++)
    {
        // first assign the index-th character to 'a'
        kie[index] = (char) j;
        key = (char *) kie;
        
        /*
        * each time a letter is changed, generate a
        * password using crypt function
        * then check if the password is correct
        */
        char *temp = crypt(key, salty);
        
        // if it is, exit the program
        if (strcmp(temp, passcode) == 0)
        {
            printf("%s\n", key);
            exit(1);
        }
        
        /*
        * before the index-th character is changed to another
        * letter, check if it is the first character
        * if not, call try function again, but let index
        * decrease by one
        * this calling itself will keep occuring until it
        * is the first character
        */
        if (index > 0)
            try(index-1, salty, passcode);
    }
}

