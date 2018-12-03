/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// # of words in dict
int wordCount = 0;

// hash table size
#define htSize 3000

// node for linked list
typedef struct node
    {
        char word[LENGTH + 1];
        struct node* next;
    }
    node;
  
node* hashTable[htSize];

int hash(const char* word)
{
    int wordLen = 0;
    wordLen = strlen(word);
    int hashSum = 0;
    
    for(int i = 0; i < wordLen; i++)
    {
        hashSum += word[i];
    }
    return hashSum%htSize;
} 




/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
 
bool load(const char* dictionary)
{
    
    char dictWord[LENGTH + 1];
    int bucket = 0;
    
    FILE *fp = fopen(dictionary, "r");
    
    if(fp == NULL)
    {
    return false;
    }
    
    while(fscanf(fp,"%s\n", dictWord) != EOF)
    {
        node* newNode = malloc(sizeof(node));
        strcpy(newNode->word, dictWord);
        
        bucket = hash(dictWord);
        
        wordCount++;
        
        if(hashTable[bucket]== NULL)
        {
            hashTable[bucket] = newNode;
            newNode -> next = NULL;
           
        }
        else
        {
            newNode -> next = hashTable[bucket];
            hashTable[bucket] = newNode;
        }
    }
    fclose(fp);
    return true;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    char unchecked[LENGTH+1];
    char lowercase;
   
    for(int i = 0; i < strlen(word); i++)
    {
        lowercase = tolower(word[i]);
        unchecked[i] = (char)lowercase;
    }
    
    unchecked[strlen(word)] = '\0';
    
    int bucket = hash(unchecked);
    
    node* tempnode = hashTable[bucket];
    if(tempnode == NULL)
    {
        return false;
    }
    
    while(tempnode != NULL)
    {
        if(!strcmp(tempnode->word, unchecked))
        {
            return true;
        }
        tempnode = tempnode->next;
    }
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return wordCount;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    node* cursor = NULL;
    
    for(int i = 0; i < htSize; i++)
    {
        cursor = hashTable[i];
        
        while (cursor != NULL)
        {
            node* tempnode = cursor;
            cursor = cursor->next;
            free(tempnode);
        }
    }
    return true;
}
