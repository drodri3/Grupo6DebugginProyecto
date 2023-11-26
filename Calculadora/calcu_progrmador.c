#include <stdio.h>
#include "programador.h"

void decimalABinario() {
    int i = 0;
    int a;
    printf("Ingrese el n�mero a convertir:\n");
    if(scanf("%d", &a) != 1){
        while (getchar() != '\n');
        printf("Error: Ingrese un n�mero v�lido.\n");
        return;
    }
    if (a == 0) {
        printf("El n�mero en Binario es : 0\n");
        return;
    }
    if (a < 0) {
        unsigned int numeroNegativo = (unsigned int)-a;
        printf("El n�mero binario es: 1");
        for (int i = 30; i >= 0; i--) {
            int bit = (numeroNegativo >> i) & 1;
            printf("%d", bit);
        }

    } else {
        printf("El n�mero en Binario es : ");
        for (int i = 31; i >= 0; i--) {
            int bit = (a >> i) & 1;
            printf("%d", bit);
        }
    }
}

void decimalAHexadecimal() {
    int a;

    printf("Ingrese el n�mero a convertir:\n");
    if(scanf("%d", &a) != 1){
        while (getchar() != '\n');
        printf("Error: Ingrese un n�mero v�lido.\n");
        return;
    }
    if (a == 0) {
        printf("El n�mero binario es: 0\n");
        return;
    }

    if (a < 0) {
        unsigned int negativoNumero = (unsigned int)-a;

        printf("El n�mero en Hexadecimal es: -%X\n", negativoNumero);
    } else {
        printf("El n�mero en Hexadecimal es: %X\n", a);
    }
}

void binarioAHexadecimal() {
    printf("Test: Binario a Hexadecimal\n");
}

void hexadecimalADecimal() {
    printf("Test: Hexadecimal a Decimal\n");
}

void menuProgramador() {
    char opcion;

    do {
        printf("\n\n");
        printf("Modo Programador:\n");
        printf("1. Decimal a Binario\n");
        printf("2. Decimal a Hexadecimal\n");
        printf("3. Binario a Hexadecimal\n");
        printf("4. Hexadecimal a Decimal\n");
        printf("0. Volver al men� anterior\n");

        printf("Seleccione una opci�n: ");

        if (scanf(" %c", &opcion) != 1) {
            while (getchar() != '\n');
            printf("Error: Ingrese una opci�n v�lida.\n");
            continue;
        }

        if (opcion < '0' || opcion > '4') {
            printf("Error: Ingrese una opci�n v�lida.\n");
            continue;
        }

        switch (opcion) {
            case '1':
                decimalABinario();
                break;
            case '2':
                decimalAHexadecimal();
                break;
            case '3':
                binarioAHexadecimal();
                break;
            case '4':
                hexadecimalADecimal();
                break;
            case '0':
                printf("Saliendo del Modo Programador.\n");
                break;
            default:
                printf("Opci�n no v�lida. Intente de nuevo.\n");
        }
    } while (opcion != '0');
}
