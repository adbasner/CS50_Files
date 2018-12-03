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
        printf("Need a valid pw noob\nn");
        return 1;
        
    }
    
    string crypted_pw = argv[1];
    //printf("%s\n", crypted_pw);
    
    char salt[3];
    strncpy(salt, crypted_pw, 2);
    salt[2] = '\0';
    char pw [9];
    string pwcrypt;
        
    //printf("%s\n", salt);
    for (int i = 48; i<123; i++)
        {
        pw [0] = i;
        pw [1] = '\0';
                                    
        pwcrypt = crypt(pw, salt);
                                    
        if (strcmp(pwcrypt, crypted_pw) == 0)
        {
            printf("%s\n", pw);
        } 
        for (int j = 48; j<123; j++)
            {
            for (int k = 48; k<123; k++)
                {
                for (int l = 48; l<123; l++)
                    {
                    for (int m = 48; m<123; m++)
                        {
                        for (int n = 48; n<123; n++)
                            {
                            for (int o = 48; o<123; o++)
                                {
                                pw [0] = i;
                                pw [1] = j;
                                pw [2] = k;
                                pw [3] = l;
                                pw [4] = m;
                                pw [5] = n;
                                pw [6] = o;
                                pw [7] = '\0';
                                
                                pwcrypt = crypt(pw, salt);
                                    
                                if (strcmp(pwcrypt, crypted_pw) == 0)
                                    {
                                        printf("%s\n", pw);
                                    } 
                                    
                                for (int p = 48; p<123; p++)
                                    {
                                    pw [0] = i;
                                    pw [1] = j;
                                    pw [2] = k;
                                    pw [3] = l;
                                    pw [4] = m;
                                    pw [5] = n;
                                    pw [6] = o;
                                    pw [7] = p;
                                    pw [8] = '\0';
                                    
                                    pwcrypt = crypt(pw, salt);
                                    
                                    if (strcmp(pwcrypt, crypted_pw) == 0)
                                        {
                                            printf("%s\n", pw);
                                        } 
                                      
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
}       

