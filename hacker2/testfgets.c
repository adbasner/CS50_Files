#define _XOPEN_SOURCE   
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

const int constant_word_size = 128;

int main (int argc, char*argv[])
{
    if (argc != 2)
    {
        printf("Need a valid pw noob\n");
        return 1;
        
    }
    
    printf("%s\n", crypt(argv[1], "ab")); 
    string salt = "ab";
    string pw = argv[1];
    string cryptedpw = (crypt(argv[1], "ab"));
    
    char word[constant_word_size];
    FILE *dict;
    dict = fopen("/usr/share/dict/words", "r");
    
    if (!dict)
    {
        printf("Error opening dictionary file.\n");
        
        return 1;
    }
    
    
    while (fgets(word, constant_word_size, dict))
    {
        word[strlen(word) -1] = '\0';
        
        if (!strcmp(crypt(pw, salt), cryptedpw))
            {
            printf("cracked, pw is: %s\n", pw);
            return 0;
            }
    }
}
  
