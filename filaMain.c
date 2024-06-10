#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"fila.h"

int main(int argc, char argv[]){
    QueueNode* root = NULL;

    enqueue(&root, "AA");
    enqueue(&root, "AB");
    enqueue(&root, "AC");

    printf("%c \n", peek(root));
    printf("%c \n", dequeue(&root));
    display(root);

    exit(0);
}