#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // variables
    float dollars = 0;
    int cents = 0;
    int coins_used = 0;
    
     
    // get amount in dollars
    do
    {
        printf("How much change is owed in dollars?\n");
        dollars = GetFloat ();
        if (dollars <= 0)
        {
            printf("Number should be greater than zero.\n");
        }
    }  
    while (dollars <= 0);
    
    // conver dollars to cents
    cents = (int) round(dollars * 100);
   
    // while quarters can be used
    // increse coin count and decrease cents by 25
    while (cents - 25 >= 0) 
    {
        cents = cents - 25;
        coins_used = coins_used + 1;
    }
     
    // while dimes can be used
    // increase coin count and decrease cents by 10
    while (cents - 10 >= 0)
    {
        cents = cents - 10;
        coins_used = coins_used + 1;
    }
    
    // while nickle can be used
    // increase coin count and decrease cents by 5
    while (cents - 5 >= 0)
    {
        cents = cents - 5;
        coins_used = coins_used + 1;
    }
    
    // while pennie can be used
    // increase coin count and decrease cents by 1
    while (cents - 1 >= 0)
    {
        cents = cents - 1;
        coins_used = coins_used + 1;
    }
    
    // print number of choins
    printf("%d\n", coins_used);
}
