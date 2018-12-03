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
        printf("Number: ");
        cc_num = GetLongLong();
        
    }
    while (cc_num < 1);
    
    sprintf(cc_string, "%lld", cc_num);
    cc_length = strlen(cc_string);
    
    int sum = 0;
    for (int i = cc_length - 2 ; i >= 0 ; i = i - 2)
        if (cc_string [i] >= '5')
            {
                sum = sum + (2*(cc_string[i]-'0')-9);
            }
        else
            {
                sum = sum + 2*(cc_string[i]-'0');
            }
    
    for (int i = cc_length-1 ; i >= 0 ; i = i - 2)
          sum = sum + (cc_string[i]-'0');
           
    if  (cc_length < 13 ||cc_length > 16)
            {
                printf("INVALID\n");
                
            }
            
    else if (cc_string[0] == '4' && sum % 10 == 0)
        {
            if (strlen(cc_string) == 13 || strlen(cc_string) == 16)
            {
                printf("VISA\n");
            }
            else 
            {
                printf("INVALID\n");
            }
        }
    else if (cc_string[0] == '3' && (cc_string[1] = '4' || cc_string[1] == '7') && sum % 10 == 0)
        {
            if (strlen(cc_string) == 15)
            {
                printf("AMEX\n");
            }
            else 
            {
                printf("INVALID\n");
            }
        }
    else if (cc_string[0] == '5' && (cc_string[1] >=  49 && cc_string[1] <= 53) && sum % 10 == 0)
        {
            if (strlen(cc_string) == 16)
            {
                printf("MASTERCARD\n");
            }
            else 
            {
                printf("INVALID\n");
            }
        } 
    else
        {
            printf("INVALID\n");
        }      
}
