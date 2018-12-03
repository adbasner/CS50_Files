#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    printf("Say something: ");
    char* s = GetString();
    
    printf("Say something else: ");
    char* t = GetString();
    
    if (s != NULL && t != NULL)
    {
    if (strcmp(s,t) == 0)
    {
        printf("You typed the same thing");
    }
    
    else
    {
        printf("You typed something different");
    }
    printf("\n");
    }
    
}    
