#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* remove_non_ascii(char *);
char* truncate_spaces(char *);
void* reveal_decimal_values(char *);
void print_matrix_section(char *text_line, FILE *in, FILE *out, int *line_count);
int index_of(char *string, char target);

int main() {

    char *text;
    FILE *file_ptr;
    FILE *out_ptr;
    int line_num = 1;
    int *count_ptr = &line_num;
    file_ptr = fopen("experimental_input.txt", "r");
    out_ptr = fopen("GeneratedFiles_Temp/output.txt", "w");
    
    text = malloc(200 + 1);

    if( file_ptr == NULL || out_ptr == NULL ) {
        printf("\nBOO! FileIO failed!\n");
    }
    printf("HEEWO\n");
    while( fgets(text, 200, file_ptr) != NULL ) { /* Reads line of text from input file */
        /* If we don't have a line like "A= " */
        
        
        if(strlen(text) > 2 ) { /* Filters "useless" single-char text lines */
            /* fputs("!", out_ptr); */
            
            if (index_of(text, '=') > 0) {  /* !Formatted Matrix Processing! */
                /* printf("Line %d :%s\n", line_num, text); */
                
                print_matrix_section(text, file_ptr, out_ptr, count_ptr);
                
                /* at the end, replaces '\n' with a ' ' char */
            }
            else {  /* Line does not have equals sign */

                if(text[0] >= 0) {
                    /* text[0] is An ASCII char */
                    
                    text[strlen(text)-1] = ' ';
                    fputs(text, out_ptr );
                    /* fputs("\n", out_ptr ); */
                } else {
                    /* Annoying Non-Ascii char */
                }
                
                

            }
            
            
        }
        
        
        line_num++;
    }

    printf("\n\nMatrices in LaTeX end with: \n\n ⎣ ⎢ ⎢ ⎢⎡ ​ \n");
    char test_string[] = "⎣⎢⎢⎢⎡ ​ \n";
    reveal_decimal_values(test_string);

    char* test1 = ("A= ");
    char* test2 = ("âŽ£");
    /* 
     == strlen(test1)-1
     
     == strlen(test2)-1
     */

    printf("{%d}\n", test1[1] );
    printf("{%d}\n", test2[1] );


    return 0;
}

char* remove_non_ascii(char *string) {
    /* Counts valid ASCII characters to determine size of the buffer */
    /* Uses a string buffer (of determined size) and adds characters of 0-128 */
    int buffer_size = 0;
    char *ptr_iterator = string;
    char *new_string;
    for( ptr_iterator ; *ptr_iterator != '\0' ; ptr_iterator++) {
        
        if( (int)(*ptr_iterator) < 128 ) { /* Contains valid std-ASCII values */
            buffer_size++;
        } else {
            /* char is not std-ASCII */
        }

    }
    

    new_string = malloc(buffer_size + 1); /* Creates new string of required size */
    ptr_iterator = string;
    int index = 0;
    
    while(*ptr_iterator != '\0') {

        if( (*ptr_iterator) > 0 ) { /* Contains valid std-ASCII values */
            /* printf("={%d}=\n", *ptr_iterator); */
            new_string[index] = *ptr_iterator; /* copies char over to new_string */
            index++;               /* moves to next string for new_string */
        } else {
            
        }
        ptr_iterator++;
    }
    
    /* new_string[strlen(new_string) ] = '\0'; */
    
    return new_string;

}

char* truncate_spaces(char *string) {

}

void* reveal_decimal_values(char *string) {
    while(*string != '\0') {
        printf("={%d}=\n", *string);
        string++;
    }
}


void print_matrix_section(char *text_line, FILE *in, FILE *out, int *line_count) {
    int matrix_end_found = 0;

    /* fputs("{!}{!}{!}", out); */
    text_line[strlen(text_line)-1] = ' ';
    fputs(text_line, out );
    /* fputs("\n", out ); */
    while (fgets(text_line, 100, in) != NULL && matrix_end_found == 0) {
        text_line[strlen(text_line)-1] = ' ';
        fputs(text_line, out );
        /* fputs("\n", out ); */
        /* printf("Line %d |%s", *line_count, text_line); */
        
        if (index_of(text_line, '.') >= 0) {
            matrix_end_found = 1;
        }
        (*line_count)++;
    }
    /* fputs("{!}{!}{!}", out); */
}

int index_of(char *string, char target) /* Return index where char (target) appears */
{
    return (strchr(string, target) - string);
}