#include <stdio.h>
#include <stdlib.h>
#include "estandar.h"

int main()
{
    //Calculadora estándar
int opcion, a, b;

    do {
        imprimirMenuCalculadoraEstandar();
        // Leer la opción del usuario
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese dos números para sumar:\n");
                printf("Número 1: ");
                if(scanf("%d", &a) != 1){
                    while (getchar() != '\n');
                    printf("Error: Ingrese un número válido.\n");
                    continue;
                }
                printf("Número 2: ");
                if(scanf("%d", &b) != 1){
                    while (getchar() != '\n');
                    printf("Error: Ingrese un número válido.\n");
                    continue;
                }
                suma(a, b);
                break;

            case 2:
                printf("Ingrese dos números para restar:\n");
                printf("Número 1: ");
                if(scanf("%d", &a) != 1){
                    while (getchar() != '\n');
                    printf("Error: Ingrese un número válido.\n");
                    continue;
                }
                printf("Número 2: ");
                if(scanf("%d", &b) != 1){
                    while (getchar() != '\n');
                    printf("Error: Ingrese un número válido.\n");
                    continue;
                }
                resta(a, b);
                break;

            case 3:
                printf("Ingrese dos números para multiplicar:\n");
                printf("Número 1: ");
                if(scanf("%d", &a) != 1){
                    while (getchar() != '\n');
                    printf("Error: Ingrese un número válido.\n");
                    continue;
                }
                printf("Número 2: ");
                if(scanf("%d", &b) != 1){
                    while (getchar() != '\n');
                    printf("Error: Ingrese un número válido.\n");
                    continue;
                }
                multiplicacion(a, b);
                break;

            case 4:
                printf("Ingrese dos números para dividir:\n");
                printf("Número 1: ");
                if(scanf("%d", &a) != 1){
                    while (getchar() != '\n');
                    printf("Error: Ingrese un número válido.\n");
                    continue;
                }
                printf("Número 2: ");
                if(scanf("%d", &b) != 1){
                    while (getchar() != '\n');
                    printf("Error: Ingrese un número válido.\n");
                    continue;
                }
                division(a, b);
                break;

            case 0:
                printf("Volviendo al menu anterior\n");
                break;

            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
                break;
        }

    } while (opcion != 0);
    //TODO volver al menu principal

    return 0;
}
