#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string name = GetString();
               
    for (int i = 0, n = strlen(name); i < n; i++)
        {
            if (i == 0 && name[0] != ' ')
            {
                printf("%c", toupper(name[0]));
            }
            
            else if (name[i] == ' ' && name[1+i] != ' ' && name[i+1] != 0)
            {
                printf("%c", toupper(name[i+1]));
            }
        }
        
        printf("\n");
}
    //Get first and last name

