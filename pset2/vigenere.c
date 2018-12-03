#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    // bool the make sure key is valid
    bool validKey = false;

    int keylength;
    do
    {
        if (argc != 2)
    
        {
            printf("Submit a valid keyword\n");  
            return 1;
        }
     
        else if (argv[1])
        {
        // sets keylength int to # of char in the keyword
            keylength = strlen(argv[1]); 
        
        // loop to check each char of keyword
            for(int i = 0; i < keylength; i++) 
            {
                if (!isalpha(argv[1][i])) 
                {
                    printf("Invalid character, try another keyword\n");
                    return 1;
                }
            
                else
                {
                    validKey = true; 
                }
            }
        }
    }   
    
    // sets key to false to make sure key is valid
    while(validKey == false);

    string key = argv[1];
    string phrase = GetString();
    
    // need to modulo this
    int startInt = 0;  
    
    // location of key currently, make an array
    int position = 0; 

    for(int i = 0; i < keylength;i++)

    // change key to all lower case and set to 0-25
    {
        // this is setting first letter to null
        key[i] = tolower(key[i]) - 97;
        
    }

    // iterates over each part of the phrase
    for(int i = 0, n = strlen(phrase); i < n; i++) 
    {
        if (isalpha(phrase[i]))
        {
            // sets key position, module resets it back to a if beyond z
            position = startInt % keylength;
            // checks lower case
            if (islower(phrase[i]))
            {
                printf("%c", ((((phrase[i] - 97) + (int) key[position]) % 26) + 97));
            }
            // checks upper
            else if (isupper(phrase[i]))
            {
                printf("%c", ((((phrase[i] - 65) + (int) key[position]) % 26) + 65));
            }
            startInt++;
            
        }
    
    // prints char if letter or something similar
        else
        {
            printf("%c", phrase[i]);
        }
        
    }
    printf("\n");
}
