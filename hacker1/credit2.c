#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    
    long long int cc_num;
    int cc_length;
    //int cc_check = 51;
    char cc_string[17];
    
    // get valid cc number
    
    do
    {
        printf("Enter a cc# please: ");
        cc_num = GetLongLong();
               
        
       
    }
    while (cc_num < 1);
    
    sprintf(cc_string, "%lld", cc_num);
        cc_length = strlen(cc_string);
        
    if  (cc_length < 13 ||cc_length > 16)
            {
                printf("INVALID\n");
                printf("INVALID\n");
            }
            
    else if (cc_string[0] == '4')
        {
            if (strlen(cc_string) == 13 || strlen(cc_string) == 16)
            {
                printf("VISA");
            }
            else 
            {
                printf("INVALID");
            }
        }
    else if (cc_string[0] == '3' && (cc_string[1] = '4' || cc_string[1] == '7'))
        {
            if (strlen(cc_string) == 15)
            {
                printf("AMEX");
            }
            else 
            {
                printf("INVALID");
            }
        }
    else if (cc_string[0] == '5' && (cc_string[1] >=  49 && cc_string[1] <= 53))
        {
            if (strlen(cc_string) == 16)
            {
                printf("MASTERCARD");
            }
            else 
            {
                printf("INVALID");
            }
        }       
    else
        {
            printf("go suck a dick bitch");
        }
        
        printf("INVALID\n");
    // do math
    
    // check to see if valid
    
    // print valid or not
    
    //if (cc_check % 2 == 0 )
    //{
   //     printf("\nYour card is valid\n");
   // }
   // else
   // {
   //     printf("\nYour card is not valid\n");
   // }
}
