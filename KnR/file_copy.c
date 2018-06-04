#include <stdio.h>

int main(void){
    int c;

    // Ctrl+D to enter EOF on terminal in Linux
    // This example is better suited for while loop. Here just to look at for.
    for(c = getchar(); c != EOF; c = getchar()){
        putchar(c);
    }

    return 0;
}