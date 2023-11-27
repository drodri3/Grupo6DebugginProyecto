#include <stdio.h>
#include <stdlib.h>
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

int esBinario(long long n) {
    int tieneDecimales = 0;  // Variable para verificar si hay decimales

    while (n != 0) {
        int digito = n % 10;

        // Verificar si el d�gito no es 0 ni 1
        if (digito != 0 && digito != 1) {
            return 0; // No es un d�gito binario
        }

        // Verificar si ya se encontr� un d�gito decimal
        if (tieneDecimales && (digito == '.' || digito == ',')) {
            return 0; // Hay m�s de un d�gito decimal
        }

        // Si el d�gito es un punto decimal, marcar que se encontr� un decimal
        if (digito == '.' || digito == ',') {
            tieneDecimales = 1;
        }

        n /= 10;
    }

    return 1; // Todos los d�gitos son binarios
}

void binarioAHexadecimal() {
    long long binarioNumber, hex = 0, i = 1, remainder;

    printf("Ingrese el n�mero binario: ");
    if (scanf("%lld", &binarioNumber) != 1 || !esBinario(binarioNumber)) {
        while (getchar() != '\n');
        printf("Error: Ingrese un n�mero binario v�lido.\n");
        return;
    }

    while (binarioNumber != 0) {
        remainder = binarioNumber % 10;
        hex += remainder * i;
        i *= 2;
        binarioNumber /= 10;
    }

    printf("El n�mero en Hexadecimal es: %lX\n", hex);
}

long long convertirhexadecimalADecimal(char* hexadecimal) {
    long long decimal = 0;

    // Procesar cada d�gito hexadecimal
    for (int i = 0; hexadecimal[i] != '\0'; i++) {
        char caracter = hexadecimal[i];

        // Obtener el valor del d�gito hexadecimal
        int valor;
        if (caracter >= '0' && caracter <= '9') {
            valor = caracter - '0';
        } else if (caracter >= 'A' && caracter <= 'F') {
            valor = 10 + caracter - 'A';
        } else if (caracter >= 'a' && caracter <= 'f') {
            valor = 10 + caracter - 'a';
        } else {
            // Caracter no v�lido
            printf("Error: \"%c\" no es un d�gito hexadecimal v�lido.\n", caracter);
            exit(EXIT_FAILURE);
        }

        // Actualizar el valor decimal
        decimal = decimal * 16 + valor;
    }

    return decimal;
}

void hexadecimalADecimal() {
    char hexadecimal[20];

    printf("Ingrese el n�mero hexadecimal: ");
    scanf("%s", hexadecimal);

    long long decimal = convertirhexadecimalADecimal(hexadecimal);

    printf("El n�mero en Decimal es: %lld\n", decimal);
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
