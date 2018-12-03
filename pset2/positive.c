#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    do
    {
        printf("Enter a positive integer: ");
        n = GetInt (); 
    }
    while (n <1);
    printf("Thanks for the positive integer!\n");
}

