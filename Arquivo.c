#include<stdio.h>
#include<stdlib.h>

/* 1 - O seu programa deve receber como argumento o nome de um arquivo qualquer; 2 - O arquivo recebido contém números inteiros, sendo um número por linha; 3 - O seu programa deve abrir o arquivo no modo leitura e carregar os números na memória; 4 - O seu programa deve gerar um arquivo de saída chamado "saida.txt" que contém os mesmos números do arquivo lido mas em ordem crescente; */

void swap(int* n1, int* n2){
    int aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

void bubble_sort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i; j < n; j++){
            if(arr[i] > arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int mai(int argc, char* argv[]){

    FILE *fp = fopen(argv[1], "r");

    if(fp == NULL){
        printf("Erro ao abrir arquivo %s\n", argv[1]);
        exit(1);
    }

    int i;
    int qtd_n = 0;
    int *vetor_n;

    while(fscanf(fp, "%d\n", &i) != EOF){
        qtd_n++;
    }
    vetor_n = malloc(sizeof(int)*qtd_n);

    rewind(fp);
    i = 0;
    while(fscanf(fp, "%d\n", &vetor_n[i]) != EOF){
        i++;
    }

    fclose(fp);

    bubble_sort(vetor_n, qtd_n);

    FILE* arq_saida = fopen("saida.txt", "w");
    if(arq_saida == NULL){
        printf("Erro ao abrir arquivo saida.txt");
        exit(1);
    }

    for(i = 0; i < qtd_n; i++){
        fprintf(arq_saida, "%d\n", vetor_n);
    }

    fclose(arq_saida);

    exit(0);

}