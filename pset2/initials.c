#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string name = GetString();
               
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        // capitalizes the first letter of the first name 
        if (i == 0)
        {
            printf("%c", toupper(name[0]));
        }
        
        // checks for a space, and capitalizes the letter afterwards   
        else if (name[i] == ' ')
        {
            printf("%c", toupper(name[i + 1]));
        }
    }
        
    printf("\n");
}
    // Get first and last name

