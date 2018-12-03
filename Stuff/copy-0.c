#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    printf("Say something: ");
    string s = GetString();
    
    if (s == NULL)
    {
    return 1;
    }
    
    string t = malloc(strlen(s);
    
    printf("Capitalizing.... \n");
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
      
    }
    printf("Original: %s\n", s);
    printf("New: %s\n", t);
    
}    
