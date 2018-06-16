#include <stdio.h>

#define IN 1 /* inside the word */
#define OUT 2 /* outside a word */
#define ASCII_a 97
#define ASCII_z (122 + 1)

void testEOF();
float charCounter();
float lineCounter();
void blankTabNewlineCounter();
void removeExtraBlanks();
void replaceTabBackspaceBackslash();
void printWordPerLine();
void wordLenghHistogram();
void uniqueCharsHistogram();


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

    // removeExtraBlanks();

    // replaceTabBackspaceBackslash();

    // printWordPerLine();

    // wordLenghHistogram();

    uniqueCharsHistogram();

    return 0;
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

void replaceTabBackspaceBackslash(){
    // 1-10. without switch.
    char currentChar;

    while((currentChar = getchar()) != EOF){
        if(currentChar == '\t'){ // tab
            putchar('\\');
            putchar('t');
        } else if (currentChar == '\b') {
            putchar('\\');
            putchar('b');
        } else if (currentChar == '\\') {
            putchar('\\');
            putchar('\\');
        } else{
            putchar(currentChar);
        }
    }
}

void printWordPerLine(){
    // 1-12
    char currentChar;
    int state = OUT;

    while((currentChar = getchar()) != EOF){
       
        if(currentChar == ' ' || currentChar == '\t'){
           if(state == IN){
                putchar('\n');
           }
           state = OUT;
        } else {
            state = IN;
            putchar(currentChar);
        }
       
    }
}

void wordLenghHistogram(){
    // 1-13
    char currentChar;
    int currentWordLength = 0;
    int state = OUT;
    int histogram[10]; // histogram with words upto 10 char in length

    for(int i = 0; i < 10; ++i){
        histogram[i] = 0;
    }

    while((currentChar = getchar()) != EOF){
        if(currentChar == ' ' || currentChar == '\t' || currentChar == '\n'){
           if(state == IN){
                histogram[currentWordLength - 1] += 1;
                currentWordLength = 0;
           }
           state = OUT;
        } else {
            state = IN;
            ++currentWordLength;
        }

    }

    printf("%s %s \n", "|Word Length|", "|Frequency|");
    printf("%s %s \n", " __________", "  _________");
    for(int j = 0; j < 10; ++j){
        
        if(histogram[j] > 0){
            printf("%7d %12d", j+1, histogram[j]);

            if(histogram[j] > 0){
                int len = histogram[j];
                while(len){
                    putchar('-');
                    --len;
                }
            }
            
            putchar('\n');
        }
    }
}


void uniqueCharsHistogram(){
    // 1-14
    // assuming only small chars. 97 - 122
    int charCount = 0;
    int chars[ASCII_z];
    char currentChar;

    for(int i = 0; i < ASCII_z; ++i){
        chars[i] = 0;
    }

    while((currentChar = getchar()) != EOF){
        if(currentChar >= 'a' && currentChar <= 'z'){
            chars[currentChar] += 1;
        }
    }
    
    for(int i = ASCII_a; i < ASCII_z; ++i){
        if(chars[i] == 0){
            continue;
        }

        printf("%7c %12d", i, chars[i]);

        int len = chars[i];
        while(len){
            putchar('-');
            --len;
        }

        putchar('\n');
    }

}