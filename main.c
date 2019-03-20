#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* memset */

char* stringBuff;

int main(int argc,char* argv[]) 
{ 
    int counter; 
    printf("Program Name Is: %s",argv[0]); 
    if(argc==1){
        printf("\nNo Extra Command Line Argument Passed Other Than Program Name"); 
        return 0;
    }else if(argc>=2){ 
        printf("\nNumber Of Arguments Passed: %d",argc); 
        printf("\n----Following Are The Command Line Arguments Passed----"); 
        for(counter=0;counter<argc;counter++) 
            printf("argv[%d]: %s\n",counter,argv[counter]); 
    } 



    return 0; 
} 

// Used to find the length of the string for initiasation of our string buffer
int bufLen(char* stringPointer){
    int length = 0;
    int count = 0;

    while (stringPointer != NULL && *stringPointer != '\0'){ // If the pointer passed is not NULL and the value of the pointer is not the ending character
        if(*stringPointer == '_'){
            length += 3; // 3 Pixels of space -- e.g. 3 sets of 8 Zeros in HEX
        }else{
            length += 8; // 6 Characters are 6 pixels wide -- 6 sets of 8 HEX values
        }
        count++;
    }

    return length;
}