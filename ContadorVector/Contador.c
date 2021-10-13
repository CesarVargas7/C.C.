#include <stdio.h>

#define MAX_NUM 10
#define OPCIONES_MENU 5
int valores[MAX_NUM] = {0};
int valoresMayores[MAX_NUM] = {0};   //Como no se sabe la cantidad de datos mayores al prom., se usará el mismo tamaño.
int datosRegistrados = 0;
float promedio;
int cantMayores = 0;

void mostrarMayoresProm(){
    printf("Los valores mayores al promedio(%i) son:\n");
    for(int i = 0; i <= cantMayores; i++) {                   //Se cicla para que imprima solo la cantidad de datos conocidos y no todo el registro.
      printf("%s \n", valoresMayores[i]);
    }
}

void mayoresProm() {
    for(int i = 0; i <= datosRegistrados; i++) {           //Se cicla solo durante la cantidad de datos conocidos(variable datosRegistrados)
        if(valores[i] > promedio) {                        //Evalúa si el valor de la casilla 'valores[i]' es mayor al promedio
            ++cantMayores;                                 //Aumenta en 1 la cantidad de datos mayores al promedio
            valoresMayores[i] = valores[i];                //Asigna el valor de la casilla evaluada a otro registro, este nuevo registro contiene los datos mayores al promedio.
        }
    }
    printf("La cantidad de datos mayores al promedio es de: %i", cantMayores);
}

void calcular_promedio() {
    int suma = 0;

    for(int i = 0; i <= datosRegistrados; i++) {
       suma += valores[i];
    }
    promedio = suma / datosRegistrados;
    printf("El promedio de los valores ingresdos(%i en total) es: %f", datosRegistrados, promedio);
}

void ingresarDatos() {
    int valor;
    if(datosRegistrados == MAX_NUM){                    //Valida la disponibilidad de espacio
        printf("Has llenado los campos disponibles");
    }
    else{
        printf("Ingresa un valor entero:\n- ");
        scanf("%i", &valor);
        valores[datosRegistrados++] = valor;            //Asigna el índice en que se guardará el dato, y luego incrementa en 1 el contador de cuántos datos se han registrado
    }
}

int presentamenu(const char* opciones[OPCIONES_MENU]) {
	int entrada;
	int entradavalida;
	int x;
	for (x = 1; x <= OPCIONES_MENU; x += 1) {
		printf("%i.-%s\n", x, opciones[x - 1]);
	}
	entrada = 0;
	entradavalida = 0;
	do {
		printf("Seleccione una opcion: \n");
		scanf_s("%i", &entrada);

		/* Validar la entrada */
		if (entrada >= 1 && entrada <= OPCIONES_MENU) {
			entradavalida = entrada;
		}
		else {
			printf("Entrada invalida, vuelva a intentar\n");
		}
	} while (entradavalida == 0);
	return entradavalida;
}

int main() {

    int dato;
    int seleccion;
    
	// Menu
	char* opciones[OPCIONES_MENU] =
	{
		"Ingresar valor.",
		"Mostrar el promedio.",
		"Cantidad de mayores al promedio.",
		"Mostrar los mayores al promedio.",        
		"Salir."
	};

    printf("        ---Contador en C---\n\n");
    do {
        printf("-----------------------------------------\n");
        seleccion = presentamenu(opciones);
		printf("------- %s -------\n", opciones[seleccion - 1]);
        switch (seleccion){
            case 1:
                ingresarDatos();
                break;
            case 2:
                calcular_promedio();
                break;
            case 3:
                mayoresProm();
                break;
            case 4:
                mostrarMayoresProm();
                break;
            case 5:
                printf("Hasta la proxima");
                break;
            default:
                printf("Error, inválida\n\a");
        }
	} while (seleccion != 5);

    return 0;
}
