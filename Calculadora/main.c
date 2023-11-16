#include <stdio.h>
#include <stdlib.h>
#include "estandar.h"

int main()
{
    //Calculadora est�ndar
int opcion, a, b;

    do {
        imprimirMenuCalculadoraEstandar();
        // Leer la opci�n del usuario
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese dos n�meros para sumar:\n");
                printf("N�mero 1: ");
                if(scanf("%d", &a) != 1){
                    while (getchar() != '\n');
                    printf("Error: Ingrese un n�mero v�lido.\n");
                    continue;
                }
                printf("N�mero 2: ");
                if(scanf("%d", &b) != 1){
                    while (getchar() != '\n');
                    printf("Error: Ingrese un n�mero v�lido.\n");
                    continue;
                }
                suma(a, b);
                break;

            case 2:
                printf("Ingrese dos n�meros para restar:\n");
                printf("N�mero 1: ");
                if(scanf("%d", &a) != 1){
                    while (getchar() != '\n');
                    printf("Error: Ingrese un n�mero v�lido.\n");
                    continue;
                }
                printf("N�mero 2: ");
                if(scanf("%d", &b) != 1){
                    while (getchar() != '\n');
                    printf("Error: Ingrese un n�mero v�lido.\n");
                    continue;
                }
                resta(a, b);
                break;

            case 3:
                printf("Ingrese dos n�meros para multiplicar:\n");
                printf("N�mero 1: ");
                if(scanf("%d", &a) != 1){
                    while (getchar() != '\n');
                    printf("Error: Ingrese un n�mero v�lido.\n");
                    continue;
                }
                printf("N�mero 2: ");
                if(scanf("%d", &b) != 1){
                    while (getchar() != '\n');
                    printf("Error: Ingrese un n�mero v�lido.\n");
                    continue;
                }
                multiplicacion(a, b);
                break;

            case 4:
                printf("Ingrese dos n�meros para dividir:\n");
                printf("N�mero 1: ");
                if(scanf("%d", &a) != 1){
                    while (getchar() != '\n');
                    printf("Error: Ingrese un n�mero v�lido.\n");
                    continue;
                }
                printf("N�mero 2: ");
                if(scanf("%d", &b) != 1){
                    while (getchar() != '\n');
                    printf("Error: Ingrese un n�mero v�lido.\n");
                    continue;
                }
                division(a, b);
                break;

            case 0:
                printf("Volviendo al menu anterior\n");
                break;

            default:
                printf("Opci�n no v�lida. Por favor, ingrese una opci�n v�lida.\n");
                break;
        }

    } while (opcion != 0);
    //TODO volver al menu principal

    return 0;
}
