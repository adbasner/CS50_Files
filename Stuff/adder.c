#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("please give me an int: ");
    int x = GetInt();
    
    printf("Please give me another int: ");
    int y = GetInt();
    
    printf("The sum %d and %d is %d.\n", x, y, x+y);
}
