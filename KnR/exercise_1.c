#include <stdio.h>

void testEOF();
float charCounter();
float lineCounter();
void blankTabNewlineCounter();
void removeExtraBlanks();


int main(void){
    // testEOF();
    
    /* 
        float charCount = charCounter();
        printf("%.0f \n", charCount);
    */

    /*
    float lineCount = lineCounter();
    printf("%.0f \n", lineCount);
    */

    // blankTabNewlineCounter();

    removeExtraBlanks();
}

void testEOF(){
     int c = getchar();
    printf("%d \n", c != EOF); // 1-6. verify if expression getchar() != EOF is 1 or 0

    printf("%d \n", EOF); // 1-7. print value of EOF. result: -1
    printf("%c \n", EOF); // result: gibberish
}

float charCounter(){
    float nc;

    for(nc = 0; getchar() != EOF; ++nc)
        ; // null statement 
    
    return nc;
}

float lineCounter(){
    float nc;
    char currentChar;

    while((currentChar = getchar()) != EOF){
        if(currentChar == '\n'){
            ++nc;
        }
    }

    return nc;
}

void blankTabNewlineCounter(){
    // 1-8
    float blanks = 0;
    float tabs = 0;
    float newlines = 0;
    char currentChar;

    while((currentChar = getchar()) != EOF){
        if(currentChar == ' '){
            ++blanks;
        } else if(currentChar == '\t'){
            ++tabs;
        } else if(currentChar == '\n'){
            ++newlines;
        }
    }

    printf("Blanks: %.0f, Tabs: %.0f, Newlines: %.0f \n", blanks, tabs, newlines);
}

void removeExtraBlanks(){
    // 1-9
    int blankCount = 0;
    char currentChar;

    while((currentChar = getchar()) != EOF){
        if(currentChar == ' '){
            ++blankCount;
        } else {
           blankCount = 0;
        }

        if(blankCount == 0 || blankCount == 1){
            putchar(currentChar);
        }
    }
}