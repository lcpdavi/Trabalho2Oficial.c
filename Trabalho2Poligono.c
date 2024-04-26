#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definição da struct Ponto
typedef struct {
    double x;
    double y;
} Ponto;

// Função para calcular a área de um triângulo
double AreadoTriangulo(Ponto A, Ponto B, Ponto C) {
    return fabs(0.5 * ((A.x*(B.y-C.y)) + (B.x*(C.y-A.y)) + (C.x*(A.y-B.y))));
}

// Função para calcular a área de um polígono
double AreadoPoligono(Ponto* vertices, int num_vertices) {
    double area = 0.0;
    for(int i = 0; i < num_vertices-2; i++) {
        area += AreadoTriangulo(vertices[0], vertices[i+1], vertices[i+2]);
    }
    return fabs(area);
}

// Função principal
int main(){
    FILE *arquivo;
    int numVertices;
    Ponto *vertices;

    // Abre o arquivo para escrita
    arquivo = fopen("vertices.txt", "w");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo para escrita.");
        return 1;
    }

    // Pede ao usuário o número de vértices
    printf("Coloque o numero de vertice do poligono: ");
    scanf("%d", &numVertices);

    // Aloca memória para os vértices
    vertices = (Ponto *)malloc(numVertices * sizeof(Ponto));
    if(vertices == NULL){
        printf("Erro de alocação de memoria.");
        return 1;
    }

    // Pede ao usuário para inserir as coordenadas dos vértices e as escreve no arquivo
    printf("Insira as coordenadas dos vertices (formato: x y):\n");
    for(int i = 0; i < numVertices; i++){
        printf("Vertice %d: ", i + 1);
        scanf("%lf %lf", &vertices[i].x, &vertices[i].y);
        fprintf(arquivo, "%.2lf %.2lf\n", vertices[i].x, vertices[i].y);
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Calcula a área do polígono
    double area = AreadoPoligono(vertices, numVertices);

    // Imprime o resultado
    printf("A area do poligono e: %.2f\n", area);

    // Libera a memória alocada
    free(vertices);

    return 0;
}
