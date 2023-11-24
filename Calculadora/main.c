#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "estandar.h"
#include "programador.h"

void configurarLocale() {
    setlocale(LC_ALL, "");  // Utiliza la configuraci�n regional del sistema
}

int main()
{
    configurarLocale();
    //Calculadora est�ndar
int opcion, a, b;

    do {
        printf("\nMenu:\n");
        printf("1. Est�ndar\n");
        printf("2. Cient�fica\n");
        printf("3. Programador\n");
        printf("0. Finalizar\n");
        printf("Ingrese su opci�n: ");
        // Leer la opci�n del usuario
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                imprimirMenuCalculadoraEstandar();
                break;

            case 2:

                break;

            case 3:
                menuProgramador();
                break;
            case 0:
                printf("Finalizando...\n");
                break;

            default:
                printf("Opci�n no v�lida. Por favor, ingrese una opci�n v�lida.\n");
                break;
        }

    } while (opcion != 0);
    //TODO volver al menu principal

    return 0;
}
