#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"stack.h"

int main (int argc, char* argv[]){
    StackNode* top = NULL;

    push(&top, 'A');
    push(&top, 'B');
    push(&top, 'C');

    display(top);

    printf("%c \n", pop(&top));

    display(top);

    printf("%c \n", peek(&top));

    printf("%c \n", pop(&top));
    printf("%c \n", pop(&top));

    exit(0);
    
}