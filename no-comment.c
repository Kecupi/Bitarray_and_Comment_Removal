// no-comment.c
// Řešení IJC-DU1, příklad a), 16.3.2026
// Autor: Štěpán Hořenek, FIT
// Přeloženo: gcc 14.2
// ...popis příkladu - poznámky, omezení, atd
#include <stdio.h>
#include "error.h"

int main(int argc, char** argv){
    FILE* input = stdin;
    if (argc > 1){
        input = fopen(argv[1], "r");
        if (input == NULL){
            error_exit("Couldn't open file");
        }
    }
    int c;
    int state = 0;
    while ((c = fgetc(input)) != EOF){
        switch(state){
            case 0:
                if (c == '/'){
                    state = 1;
                } else if (c == '"'){
                    state = 4;
                    putchar(c);
                } else if (c == '\''){
                    state = 9;
                    putchar(c);
                } else {
                    putchar(c);
                }
                break;
            case 1:
                if (c == '/'){
                    state = 6;
                } else if (c == '*'){
                    state = 2;
                } else {
                    putchar('/');
                    putchar(c);
                    if (c == '\"'){
                        state = 4;
                    } else if (c == '\''){
                        state = 9;
                    } else {
                        state = 0;
                    }
                }
                break;
            case 2:
                if (c == '*'){
                    state = 3;
                }
                break;
            case 3:
                if (c == '/'){
                    putchar(' ');
                    state = 0;
                } else if (c != '*'){
                    state = 2;
                }
                break;
            case 4:
                if (c == '"'){
                    putchar(c);
                    state = 0;
                } else if (c == '\\'){
                    state = 5;
                    putchar(c);
                } else {
                    putchar(c);
                }
                break;
            case 5:
                putchar(c);
                state = 4;
                break;
            case 6:
                if (c == '\n'){
                    putchar(' ');
                    putchar(c);
                    state = 0;
                } else if (c == '\\'){
                    state = 7;
                }
                break;
            case 7:
                if (c == '\n'){
                    state = 6;
                } else if (c != '\\'){
                    state = 8;
                }
                break;
            case 8:
                if (c == '\n'){
                    state = 0;
                    putchar(' ');
                    putchar(c);
                } else if (c == '\\'){
                    state = 7;
                }
                break;
            case 9:
                if (c == '\''){
                    putchar(c);
                    state = 0;
                } else if (c == '\\'){
                    state = 10;
                    putchar(c);
                } else {
                    putchar(c);
                }
                break;
            case 10:
                putchar(c);
                state = 9;
                break;
            default:
                break;
        }
    }
    if (state == 6){
        state = 0;
        putchar(' ');
    }
    if (state != 0){
        error_exit("Unclosed comment");
    }
    if (argc > 1){
        fclose(input);
    }
}