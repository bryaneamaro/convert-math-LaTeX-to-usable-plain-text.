#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* remove_non_ascii(char *);
char* truncate_spaces(char *);

int main() {

    char string[] = "Example:  Let  A = [ 1 2 3 0 4 5 0 0 6 ] A=  ⎣ ⎢ ⎡ ​    1 0 0 ​    2 4 0 ​    3 5 6 ​    ⎦ ⎥ ⎤ ​  .  If possible, find an invertible matrix  P P and a diagonal matrix  D D such that  A = P D P − 1 A=PDP  −1  .  You do not have to compute  P − 1 P  −1   ";
    printf("\n -> %d \n", strcspn(string, "[") );
    printf("\n -> %d \n", strcspn(string, "]") );

    /* There has been a matrix defined using brackets "[]" */

    /* Now, Find the redundant/garbage-text generated from that- */
    /* This will almost-certainly have these chars {} */
    

    char *subString = &( string[ strcspn(string, "]") + 1] );
    printf("\nInput_text :%s \n", subString);

    /* This is just a separate char-array! that holds a copy of the substring! */
    /* char separate_subString[strlen(subString) ]; */
    /* strcpy(separate_subString, subString); */
    char* separate_subString = "A=  ⎣ ⎢ ⎡ ​    1 0 0 ​    2 4 0 ​    3 5 6 ​    ⎦ ⎥ ⎤ ​  . ";

    printf("\n Old String -> %s\n", separate_subString );
    char* new_string = remove_non_ascii( separate_subString );
    printf("\n New String -> %s\n", new_string);

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