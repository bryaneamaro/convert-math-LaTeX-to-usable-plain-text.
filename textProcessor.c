#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.c"

int main() {
    printf("\nEnter Text Below:\n");

    char *text;
    text = malloc(200);

    FILE *input_ptr;
    FILE *output_ptr;
    
    /* Loop through scanf, getting a new line of text each time. */
    input_ptr = fopen("pasteTextIntoHere.txt", "r");
    output_ptr = fopen("GeneratedFiles_Temp/output.txt", "w");

    while( fgets(text, 200, input_ptr) != NULL  ) { /* Reads line of text from input file */
        
        /* reveal_decimal_values(text); */
        if(strlen(text) > 2 ){ /* Filters single-char text lines */

            if( strcspn(text, "=") > 0  ) { /* If the '=' char is present, but not at the start */

                /* Parse broken matrix text */
                

            } 
            
            text[strlen(text)-1] = ' '; /* at the end, replaces '\n' with a ' ' char */
            
            fputs(text, output_ptr ); /* WRites the text to output file */
        }
        

    }
    fclose(input_ptr);
    fclose(output_ptr);
    
    

    return 0;
}


