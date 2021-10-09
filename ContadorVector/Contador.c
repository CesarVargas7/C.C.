#include <stdio.h>

void SolicitaCampo(char* formato, char* nombre, void* valor, int bufer) {
	printf("%s: ", nombre);
	scanf_s(formato, valor, bufer);
}

#define MAX_NUM 10
#define MAX_NOMBRE 15

int main() {
    int valores[MAX_NUM] = {0};
    int dato;
    char nombre[MAX_NOMBRE] = {0};
    
    printf("-----------------\n");
    printf("Hola Nene\n");
    printf("-----------------\n");

    for(int c = 0; c < MAX_NUM; ++c) {
        sprintf_s(nombre, MAX_NOMBRE, "dato %d", c+1);
        SolicitaCampo("%d", nombre, &dato, sizeof(dato));
        valores[c] = dato;
    }

    printf("-----------------\n");
    printf("Datos capturados:\n");
    
    for(int c = 0; c < MAX_NUM; ++c) {
        printf("%d\n", valores[c]);
    }

    return 0;
}