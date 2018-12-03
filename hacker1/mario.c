#include <cs50.h>
#include <stdio.h>

int main(void)
{  
    // declare some variables
    int n;
   
        
    // do while to get value between 1 and 23
    do
    {
        printf("Enter a value for the half-pyramid height,");
        printf(" must be between 0 and 24: ");
        n = GetInt();
    }
    while (n < 0 || n > 23);
    
    for (int i = 0; i < n; i++)
    {
        // print spaces
        for (int j = 0; j < n - (i +1) ; j++)
        {
            printf(" ");
        }
        // print # signs
        for (int k = 0; k < i+1 ; k++)
        {
            printf("#"); 
        }
        
        printf("  ");
        
        for (int l = 0; l < i+1 ; l++)
        {
            printf("#"); 
        }
        
        
        // print new line
        printf("\n");
    }
}
