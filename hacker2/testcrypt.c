#define _XOPEN_SOURCE   
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

int main (int argc, char*argv[])
{
    if (argc != 2)
    {
        printf("Need a valid pw noob\n");
        return 1;
        
    }
    
    printf("%s\n", crypt(argv[1], "ab")); 
 
 
 
 }       

