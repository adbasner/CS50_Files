#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    bool validKey = false;
    int key = 0;
 
 
    do
    {
        if (argc != 2)
    
        {
            printf("Submit a valid cypher key\n");  
            return 1;
        }
     
        else
        {
            key = atoi(argv[1]); 
            // changes the string to inter
            validKey = true; 
        }
    }
    
    while(validKey == false);
 
    // printf("Enter a word or phrase to cyper\n"); causes  check to bounce back
    string phrase = GetString();
   
    // c = (p+k)% 26 , start with ascii values -> to alphabetical values 
    // the to -> print asccii values
    // isalpha, isupper, islower, are booleans, good for conditions

    for(int i = 0, n = strlen(phrase); i < n; i++)  
    {
        if (isalpha(phrase[i]))
        {
            if (islower(phrase[i]))
            {
            // lower goes from 97 to 122, change to 0-25
            // then back to ascii values.  subtract 97 from the value,add key,
            // then do the %26 and add 97
                printf("%c", ((((phrase[i] - 97) + key) % 26) + 97));
            }
            else if (isupper(phrase[i]))
            {
            // lower goes from 65 to 90, this needs to be xfered to 0-25
            // then back to ascii values.  Subtract 65 from the value,add key
            // then do the %26, add 65 afterwards.
                printf("%c", ((((phrase[i] - 65) + key) % 26) + 65));
            }
}

        else
        {
            printf("%c", phrase[i]);
        }

        
    }
    
    printf("\n");
}
