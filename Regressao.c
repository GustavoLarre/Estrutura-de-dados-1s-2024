#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int main(int argc, char* argv[]){
    typedef struct Ponto{
    int x;
    float y;
 }Ponto;

    if(argc != 2){
        printf("Uso: %s<dados.csv>\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if(arquivo == NULL){
        printf("nao foi possivel abrir o arquivo\n");
        return 1;
    }

    //conta o número de linhas do arquivo para determinar oa tamanho do array
    int tamanho = 0;
    char linha[1024];
    while(fgets(linha, sizeof(linha), arquivo));
    tamanho++;
    rewind(arquivo);

    //Aloca memória para o array de pontos
    Ponto* pontos = (Ponto*)malloc(tamanho* sizeof(Ponto));
    if(pontos == NULL){
        printf("Falha ao alocar memoria\n");
        return 1;
    }

    //Lê os pontos do arquivo
    int i = 0;
    while(fgets(linha, sizeof(linha), arquivo)){
        pontos[i].x = atoi(strtok(linha, ","));
        pontos[i].y = atof(strtok(NULL, ","));
        i++;
    }
    fclose(arquivo);

    //cálculo da média
    int totalx = 0;
    float totaly = 0;
    for(int j = 0; j < tamanho; j++){
        totalx += pontos[j].x;
        totaly += pontos[j].y;
    }
    int media_x = totalx / tamanho;
    float media_y = totaly / (float)tamanho;

    //cálculo da inclinação
    float soma_cima = 0;
    float soma_baixo = 0;
    for(int j = 0; j < tamanho; j++){
        soma_cima += (pontos[j].x - media_x) * (pontos[j].y - media_y);
        soma_baixo += (pontos[j].x - media_x) * (pontos[j].x - media_x);
    }

    float inclina = soma_cima / soma_baixo;
    int intercepta = media_y - inclina * media_x;
    printf("y = %.1fx + %i", inclina, intercepta);

    free(pontos);
    
    exit(0);

}