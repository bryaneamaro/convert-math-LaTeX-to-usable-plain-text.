#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("\nEnter Text Below:\n");

    char *text;
    text = malloc(200);

    FILE *input_ptr;
    FILE *output_ptr;
    
    /* Loop through scanf, getting a new line of text each time. */
    input_ptr = fopen("pasteTextIntoHere.txt", "r");
    output_ptr = fopen("GeneratedFiles_Temp/output.txt", "w");

    while( fgets(text, 200, input_ptr) != NULL  ) {
        /* Reads line of text from input file */

        text[strlen(text)-1] = ' ';
         /* replaces '\n' with a ' ' */
        

        fputs(text, output_ptr ); /* WRites the text to output file */

    }
    fclose(input_ptr);
    fclose(output_ptr);
    
    

    return 0;
}


