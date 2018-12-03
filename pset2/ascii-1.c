#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    for (char c = 'A'; c <= 'Z'; c++) 
    {
        printf("%i is %c\n", (int) c, c);
    }
}

