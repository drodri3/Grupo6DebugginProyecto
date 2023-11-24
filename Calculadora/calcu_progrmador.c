#include <stdio.h>
#include "programador.h"

void decimalABinario() {
    printf("Test: Decimal a Binario\n");
}

void decimalAHexadecimal() {
    printf("Test: Decimal a Hexadecimal\n");
}

void binarioAHexadecimal() {
    printf("Test: Binario a Hexadecimal\n");
}

void hexadecimalADecimal() {
    printf("Test: Hexadecimal a Decimal\n");
}

void menuProgramador() {
    int opcion, a, b;

    do {
        printf("Modo Programador:\n");
        printf("1. Decimal a Binario\n");
        printf("2. Decimal a Hexadecimal\n");
        printf("3. Binario a Hexadecimal\n");
        printf("4. Hexadecimal a Decimal\n");
        printf("0. Volver al menú anterior\n");

        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                decimalABinario();
                break;
            case 2:
                decimalAHexadecimal();
                break;
            case 3:
                binarioAHexadecimal();
                break;
            case 4:
                hexadecimalADecimal();
                break;
            case 0:
                printf("Saliendo del Modo Programador.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 0);
}
