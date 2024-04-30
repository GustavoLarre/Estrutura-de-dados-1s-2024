#include<stdio.h>
#include<stdlib.h>
#include<math.h>

 typedef struct{
        int x;
        int y;
    }Ponto;

    void ler_pontos(FILE *arquivo, Ponto *pontos, int n){
        for(int i = 0; i < n; i++){
            fscanf(arquivo, "%d,%f\n" &pontos[i].x, &pontos[i].y);
        }
    }

    float calcular_media_x(int* valores , int n ){
        int soma =0;
        for(int i = 0 ; i<n ; i++){
            soma += valores[i];
        }return(float)soma /n ;
    }

    float calcular_media_y(float* valores , int n ){
        float soma =0;
        for(int i = 0 ; i<n ; i++){
            soma += valores[i];
        }return soma / n ;
    }

    int main(int argc,char* argv[]){
    

    
    return 0;
}