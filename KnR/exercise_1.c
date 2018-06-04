#include <stdio.h>

int main(void){
    int c = getchar();
    printf("%d \n", c != EOF); // 1-6. verify if expression getchar() != EOF is 1 or 0

    printf("%d \n", EOF); // 1-7. print value of EOF. result: -1
    printf("%c \n", EOF); // result: gibberish
   
}