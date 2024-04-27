#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Definicao da struct Ponto
typedef struct {
    double x;
    double y;
}Ponto;
// Calcular a area de um triângulo
double AreadoTriangulo(Ponto A, Ponto B, Ponto C) {
    return fabs(0.5 * ((A.x*(B.y-C.y)) + (B.x*(C.y-A.y)) + (C.x*(A.y-B.y))));
}
// Calcular a area de um poligono
double AreadoPoligono(Ponto* vertices, int num_vertices) {
    double area = 0.0;
    for(int i = 0; i < num_vertices-2; i++) {
        area += AreadoTriangulo(vertices[0], vertices[i+1], vertices[i+2]);
    }
    return fabs(area);
}
int main(){
    FILE *arquivo;
    int numVertices;
    Ponto *vertices;

    arquivo = fopen("vertices.txt", "w");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo para escrita.");
        return 1;
    }
    printf("Coloque o numero de vertice do poligono: ");
    scanf("%d", &numVertices);

    // Aloca memoria para os vertices
    vertices = (Ponto *)malloc(numVertices * sizeof(Ponto));
    if(vertices == NULL){
        printf("Erro de alocacao de memoria.");
        return 1;
    }
    // Pede ao usuario para inserir as coordenadas dos vertices e assim escreve no arquivo
    printf("Insira as coordenadas dos vertices (formato: x y):\n");
    for(int i = 0; i < numVertices; i++){
        printf("Vertice %d: ", i + 1);
        scanf("%lf %lf", &vertices[i].x, &vertices[i].y);
        fprintf(arquivo, "%.2lf %.2lf\n", vertices[i].x, vertices[i].y);
    }
    fclose(arquivo);

    double area = AreadoPoligono(vertices, numVertices);

    printf("A area do poligono e: %.2f\n", area);

    // Libera a memoria alocada
    free(vertices);

    return 0;
}
