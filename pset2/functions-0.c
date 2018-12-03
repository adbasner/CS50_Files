#include <stdio.h>
#include <cs50.h>

void PrintName();

int main(void)
{
    printf("Your name: ");
    string s = GetString ();
    PrintName(s);
}

void PrintName(string name)
{
    printf("Hello, %s\n", name);
}
