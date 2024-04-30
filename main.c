#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
    int x;
    float y;
}Ponto;

void calcularMedia(Ponto *pontos, int num_registros, float *media_x, float *media_y){
    float soma_x = 0, soma_y = 0;
    for(int i = 0; i < num_registros; i++){
        soma_x += pontos[i].x;
        soma_y += pontos[i].y;
    }
    *media_x = soma_x/num_registros;
    *media_y = soma_y/num_registros;
}

float calcularInclincao(Ponto *pontos, int num_registros, float media_x, float media_y){
    float numerador = 0, denominador = 0;
    for(int i = 0; i < num_registros; i++){
        numerador = (pontos[i].x - media_x) * (pontos[i].y - media_y);
        denominador = pow(numerador,2); //a função pow é usada para obter a potência de um número
    }
    return numerador/denominador;;
}

float calcularIntersecao(float inclinacao, float media_x, float media_y){
    return media_y - inclinacao * media_x;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Uso: %s dados.csv\n", argv[0]);
        return 1;
    }
    FILE *arquivo; //ponteiro para dados.csv
    arquivo = fopen(argv[1], "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    int num_registros = 0;
    while(fget(arquivo) != EOF){
        if(fgetc(arquivo) == '\n'){
            num_registros++;
        }
    }
    rewind(arquivo);

    Ponto *pontos = (Ponto*)malloc(sizeof(Ponto));
    if(pontos == NULL){
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    for(int i = 0; i < num_registros; i++){
        if(fscanf(arquivo, "%d,%f", &pontos[i].x, &pontos[i].y) != 2){
            printf("Erro ao ler o arquivo\n");
            return 1;
        }
    }

    fclose(arquivo);

    float media_x, media_y;
    calcularMedia(pontos, num_registros, &media_x, &media_y);

    float inclinacao = calcularInclincao(pontos, num_registros, media_x, media_y);

    float intersecao = calcularIntersecao(inclinacao, media_x, media_y);

    printf("y = %.2f + %.2f\n", inclinacao, intersecao);

    free(pontos);
    return 0;

}