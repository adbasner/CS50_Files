#define _XOPEN_SOURCE       /* See feature_test_macros(7) */
#include <unistd.h>
#include <stdio.h>
#include <crypt.h>
#include <cs50.h>
#include <string.h>
#include <unistd.h>

//strncpy(salt, argv[1], 2);

//char *crypt(const char *key, const char *salt);

int main(int argc, char *argv[])
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
    
    printf("%s\n", salt);
}

    
