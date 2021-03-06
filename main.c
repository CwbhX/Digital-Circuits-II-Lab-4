#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* memset */

// ---- CONSTANTS ----
const int BITLENGTH = 32; // 4bits * 8 hex values representing a row each (e.g. one full column)
const int BYTELENGTH = BITLENGTH / 8;


// ---- FUNCTION DECLARATIONS ----
int setupStringBuff(char* stringBuff, int messageLength){
    int requiredMemorySize = BYTELENGTH * messageLength;
    stringBuff = malloc(requiredMemorySize); // Allocate memory for our array of bits (malloc accepts bytes) by taking the number of bits per column and how many columns (width) of text we have
    printf("Allocated array of size: %d\n", requiredMemorySize);

    if (!stringBuff){ // If we could not allocate memory
        perror("Error allocating memory");
        abort();
    }
    memset(stringBuff, 0, requiredMemorySize); // Initialise all the data with zeros to prevent erroneous data from lingering
    return requiredMemorySize;
}
// Used to find the length of the string for initiasation of our string buffer
int bufLen(char* stringPointer){
    int length = 0;
    int count;
    printf("Length of String: %lu\n", strlen(stringPointer));

    for (count = 0; count < strlen(stringPointer); count++){ // Iterate through the string since the null character method and while loop was not working
        if(stringPointer[count] == '_'){
            length += 3; // 3 Pixels of space -- e.g. 3 sets of 8 Zeros in HEX
        }else{
            length += 6; // 6 Characters are 6 pixels wide -- 6 sets of 8 HEX values
        }
    }
    return length; // Return length in width of pixels that our string is
}

// Reverse an array of length 6th for we can get the right order for our output
unsigned int* reverseArray6(unsigned int array[6]){
    unsigned int* rArray = malloc(sizeof(int)*6); // Initialise array with size of 6 ints, didn't use [6] since complier gave off warnings for the return type
    int counter;
    
    for (counter = 1; counter <= 6; counter++){
        rArray[6-counter] = array[counter-1];
    }

    return rArray; // Return a pointer to the new reversed array since C doesn't support returning whole arrays
}


// ---- MAIN -----
int main(int argc,char* argv[]) {
    int colourMap; // Int gives us 4 Bytes of data == 32 Bits which gives us 8 Hex values
    char* stringBuff;

    int counter; 
    printf("Program Name Is: %s",argv[0]); 
    if(argc==1){
        printf("\nNo Extra Command Line Argument Passed Other Than Program Name"); 
        return 0;
    }else if(argc>=2){ 
        printf("\nNumber Of Arguments Passed: %d",argc); 
        printf("\n----Following Are The Command Line Arguments Passed----\n"); 
        for(counter=0;counter<argc;counter++) 
            printf("argv[%d]: %s\n",counter,argv[counter]);
        
        if (argc == 2){ // If we do not supply a colour mask value, apply all white
            colourMap = 0xFFFFFFFF;
        }else{          // Otherwise apply our specified mask value
            colourMap = (int) strtol(argv[2], NULL, 16);
        }
    } 

    int messageLength = bufLen(argv[1]);
    int allocatedSize = setupStringBuff(stringBuff, messageLength);

    printf("\n");
    printf("Message Length: %d\n", messageLength);
    printf("Allocated Size in Bytes: %d\n", allocatedSize);
    printf("Colour Mask Value: %d\n", colourMap);

    return 0; 
} 