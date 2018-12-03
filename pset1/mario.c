#include <cs50.h>
#include <stdio.h>

int main(void)
{  
    // declare some variables
    int n;
    int i;
    i = 0;
    
    // do while to get value between 1 and 23
    do
    {
        printf("Enter a value for the half-pyramid height,");
        printf(" must be between 0 and 24:\n");
        n = GetInt();
    }
    while (n < 0 || n > 23);
    
    for (int i = 0; i < n; i++)
    {
        // print spaces
        for (int j = 0; j <= n - (i + 2); j++)
        {
            printf(" ");
        }
        // print # signs
        for (int k = 0; k < i + 2; k++)
        {
            printf("#"); 
        }
        
        // print new line
        printf("\n");
    }
}
