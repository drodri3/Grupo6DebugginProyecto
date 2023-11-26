#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "estandar.h"
#include "programador.h"
#include "cientifica.h"

void configurarLocale() {
    setlocale(LC_ALL, "");  // Utiliza la configuración regional del sistema
}

int main()
{
    configurarLocale();
    // Calculadora estándar
    int opcion;

    do {
        printf("\nMenu:\n");
        printf("1. Estándar\n");
        printf("2. Científica\n");
        printf("3. Programador\n");
        printf("0. Finalizar\n");
        printf("Ingrese su opción: ");
        // Leer la opción del usuario

        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            printf("Error: Ingrese una opción válida.\n");
            continue;
        }

        if (opcion < 0 || opcion > 3) {
            printf("Error: Ingrese una opción válida.\n");
            continue;
        }

        switch (opcion) {
            case 1:
                imprimirMenuCalculadoraEstandar();
                break;

            case 2:
                imprimirMenuCalculadoraCientifica();
                break;

            case 3:
                menuProgramador();
                break;

            case 0:
                printf("Finalizando...\n");
                break;

            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
                break;
        }

    } while (opcion != 0);

    return 0;
}

