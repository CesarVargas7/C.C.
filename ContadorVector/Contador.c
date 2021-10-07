#include <stdio.h>

void SolicitaCampo(char* formato, char* nombre, void* valor, int bufer) {
	printf("%s: ", nombre);
	scanf_s(formato, valor, bufer);
}

int main() {
    int valores[3] = {0};
    int dato;
    printf("Hola Nene\n");
    SolicitaCampo("%d", "dato", &dato, sizeof(dato));
    valores[0] = dato;

    return 0;
}