#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    printf("Say something: ");
    string s = GetString();
    
    printf("Say something else: ");
    string t = GetString();
    
    if ( s== t)
    {
        printf("You typed the same thing");
    }
    
    else
    {
        printf("You typed something different");
    }
    printf("\n")
    
}    
