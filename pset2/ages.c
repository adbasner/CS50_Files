#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        printf("Number of people in room: ");
        n = GetInt();
    }
    while (n < 1);
    
    int ages[n];
    
    for (int i = 0; i < n; i++)
    {
        printf("Age of person #%d: ", i+1);
        ages[i] = GetInt(); 
    }
    for (int i = 0; i < n; i++)
    {
        printf("A year from now, person #%d will be %i years old.\n", i+1, ages[i] + 1);
    }
}
