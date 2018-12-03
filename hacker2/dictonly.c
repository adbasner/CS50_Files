#define _XOPEN_SOURCE   
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

const int CONST_WORD_SIZE = 128;
const int CONST_MAX_PASSWD_SIZE = 8;

bool try_passwd(const char *plain, const char *cipher, const char *salt);
bool dict_attack(const char *passwd, const char *salt);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Incorrect number of parameters\n");
        
        return 1;
    }
    
    
    
    // Extract the salt from a source
    char salt[2];
    
    strncpy(salt, argv[1], 2);
    
    printf("Using dictionary attack...\n");
    
    // First do a dictionary-based attack
    if (dict_attack(argv[1], salt))
        return 0;
        
    printf("Dictionary attack failed. Using brute-force...\n");
   
    printf("Encrypted key could not be deciphered.\n");
    
    return 0;
}
// Encodes the word and compares it to original encrypted password
bool try_passwd(const char *plain, const char *cipher, const char *salt)
{
    if (!strcmp(crypt(plain, salt), cipher))
    {
        printf("Cracking succesful. Matching password - %s\n", plain);
       
        
        return true;
    }
    
    return false;
}

// Deciphers the hashed password, and stores it into dest variable
bool dict_attack(const char *passwd, const char *salt)
{
    char cur_word[CONST_WORD_SIZE];
    FILE *f;
    
    // Prepare a dictionary
    f = fopen("/usr/share/dict/words", "r");
    
    if (!f)
    {
        printf("Error opening dictionary file.\n");
        
        return false;
    }
    
    // For each word in dictionary
    while (fgets(cur_word, CONST_WORD_SIZE, f))
    {
        cur_word[strlen(cur_word) - 1] = '\0';
        
        // Try currend word
        if (try_passwd(cur_word, passwd, salt))
            return true;
    }
    
    return false;
}



/*const int constant_word_size = 128;

int main (int argc, char*argv[])
{
    if (argc != 2)
    {
        printf("Need a valid pw noob\nn");
        return 1;
        
    }
    
    string crypted_pw = argv[1];
    //printf("%s\n", crypted_pw);
    
    char salt[3];
    strncpy(salt, crypted_pw, 2);
    salt[2] = '\0';
    char pw [9];
    //string pwcrypt;
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
        
        if (!strcmp(crypt(pw, salt), crypted_pw))
            {
            printf("cracked, pw is: %s\n", pw);
            return 0;
            }
        else 
        {
        return false;
        }
    }
}
 */
