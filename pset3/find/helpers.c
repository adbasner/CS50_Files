/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int max = n - 1;
    int min = 0;
    
    while (min <= max)
    {
        int mid = (min + max) / 2;
        
        if (values[mid] == value)
        {
            return true;
        }
        
        else if (value < values[mid])
        {
            max = mid - 1;
        }
        
        else if (values[mid] < value)
        {
            min = mid + 1;
        }
    }
    return false;
    /* 
    if (n <= 0)
    {
        return false;
    }
    for (int i = 0; i <= n; i++)
    {
        if (values[i] == value)
        {
            return true;
        }
    }
    return false; 
    */
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    
    // implement an O(n^2) sorting algorithm
    
    
    for (int i = 0; i < n; i++)
    {
        int counters = 0;
        for (int j = 0; j < n - 1; j++) 
        {
            if (values[j] > values[j + 1])
            {
                int temp = values[j + 1];
                values[j + 1] = values[j];
                values[j] = temp;    
                counters++;
            }  
        }
             
        if (counters == 0)
        {
            
            return;
        }
    } 
}               
    
    
