#include<stdio.h>
#include<stdlib.h>

/* Criar um programa que receba N números inteiros; O seu programa deve imprimir uma mensagem de erro caso nenhum número seja informado; Caso receba um ou mais números, o seu programa deverá imprimir: 1- A quantidade de números recebidos; 2- O valor médio dos números; 3- O menor número; 4- O maior número; 5- A lista de números em ordem crescente.*/

int mai(int argc, char* argv[]){

    //variáveis
    int quantidade = argc -1;
    int soma = 0;
    float media = 0;
    int menor = atoi(argv[1]);
    int maior = atoi(argv[1]);
    int vetor_ordem_c[quantidade];

    //operações
    for(int i = 1; i <= quantidade; i++){
        int n = atoi(argv[i]);
        vetor_ordem_c[i-1] = n;
        soma += n;

        if(menor > n){
            menor = n;
        }

        if(n > maior){
            maior = n;
        }
    }

    media = (float) soma/quantidade;

    //saída
    printf("\n Quantidade de números recebidos: %d", quantidade);
    printf("\n Valor medio dos numeros: %.2f", media);
    printf("\n Maior numero: %d", maior);
    printf("\n Menor numero: %d", menor);

    //operação e saída vetor_ordem_c
    for(int i = 0; i < quantidade-1; i++){
        for(int j = i; j < quantidade; j++){
            if(vetor_ordem_c[i] > vetor_ordem_c[j]){
                int aux = vetor_ordem_c[j];
                vetor_ordem_c[j] = vetor_ordem_c[i];
                vetor_ordem_c[i] = aux;
            }
        }
    }

    for(int i = 0; i < quantidade; i++){
        printf("\n Lista ordem crescente: %d", vetor_ordem_c);
    }

    exit(0);

}