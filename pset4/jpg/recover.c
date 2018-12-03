/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    //counter for jpg number
    int jpg = 0;
    
    // defines file name
    FILE* raw;
    
       
    // makes buffer a 512 array of bytes
    uint8_t buffer[512];
    
    
    // open input file 
    raw = fopen("card.raw", "r");
    
   
    // check for valid file
    if (raw == NULL)
    {
        printf("Could not open %s.\n", "cards.raw");
        return 1;
    }
    
    FILE* img = NULL;
    // loops through file 1 block at a time (512 bytes at a time, stores them in buffer)
    while (fread(buffer, 512, 1, raw))
    {
        
        // checks for valid jpg sequence
        if ((buffer [0] ==  0xff && buffer [1] == 0xd8 && buffer [2] == 0xff && buffer [3] == 0xe0) 
        | (buffer [0] == 0xff && buffer [1] == 0xd8 && buffer [2] == 0xff && buffer [3] == 0xe1))
        {
        
            if (img)
                {
                    fclose(img);
                }
            char jpgname [8];
            sprintf(jpgname, "%03d.jpg", jpg);
        
            img = fopen(jpgname, "w");
            
            jpg = jpg +1;
        }
        
        if (img)
            {
                fwrite (buffer, 512, 1, img);
            }     
    } 
    
    if (img)
    { 
        fclose (img);    
    }
    
    fclose (raw);
    
    
    // TODO
}
