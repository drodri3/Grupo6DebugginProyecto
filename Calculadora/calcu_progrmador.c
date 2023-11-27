#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "programador.h"

void decimalABinario() {
    int i = 0;
    int a;

    // Solicitar al usuario que ingrese un n�mero decimal
    printf("Ingrese el n�mero a convertir:\n");

     // Leer el n�mero decimal desde la entrada est�ndar
    if(scanf("%d", &a) != 1){
        // Limpiar el b�fer de entrada si la entrada no es v�lida
        while (getchar() != '\n');
        printf("Error: Ingrese un n�mero v�lido.\n");
        return;
    }
    // Verificar si el n�mero es 0
    if (a == 0) {
        printf("El n�mero en Binario es : 0\n");
        return; // Salir de la funci�n si el n�mero es 0
    }
    // Convertir n�meros negativos a binario (representaci�n en complemento a 2)
    if (a < 0) {
        // Convertir el n�mero negativo a su representaci�n en complemento a 2
        unsigned int numeroNegativo = (unsigned int)-a;
        // Imprimir el bit de signo para n�meros negativos
        printf("El n�mero binario es: 1");
        // Imprimir los bits del n�mero negativo en orden inverso (de mayor a menor)
        for (int i = 30; i >= 0; i--) {
            int bit = (numeroNegativo >> i) & 1;
            printf("%d", bit);
        }

    } else {
        // Convertir n�meros positivos a binario
        printf("El n�mero en Binario es : ");
        // Imprimir los bits del n�mero en orden inverso (de mayor a menor)
        for (int i = 31; i >= 0; i--) {
            int bit = (a >> i) & 1;
            printf("%d", bit);
        }
    }
}

void decimalAHexadecimal() {
    int a;

    // Solicitar al usuario que ingrese un n�mero decimal
    printf("Ingrese el n�mero a convertir:\n");

    // Leer el n�mero decimal desde la entrada est�ndar
    if (scanf("%d", &a) != 1) {
        // Limpiar el b�fer de entrada si la entrada no es v�lida
        while (getchar() != '\n');
        printf("Error: Ingrese un n�mero v�lido.\n");
        return;
    }

    // Verificar si el n�mero es 0
    if (a == 0) {
        printf("El n�mero en Hexadecimal es: 0\n");
        return; // Salir de la funci�n si el n�mero es 0
    }

    // Convertir n�meros negativos a hexadecimal (representaci�n en complemento a 2)
    if (a < 0) {
        // Convertir el n�mero negativo a su representaci�n en complemento a 2
        unsigned int negativoNumero = (unsigned int)-a;

        // Imprimir el signo negativo y el valor hexadecimal
        printf("El n�mero en Hexadecimal es: -%X\n", negativoNumero);
    } else {
        // Convertir n�meros positivos a hexadecimal
        printf("El n�mero en Hexadecimal es: %X\n", a);
    }
}

// Funci�n que verifica si una cadena contiene solo d�gitos binarios (0 y 1)
bool esBinarioValido(const char* str){
    // Recorrer cada caracter en la cadena
    while (*str != '\0') {
        // Verificar si el caracter actual no es '0' ni '1'
        if (*str != '0' && *str != '1') {
            return false; // No es un d�gito binario v�lido
        }
        str++;// Moverse al siguiente caracter en la cadena
    }
    return true; // Todos los caracteres son binarios
}

// Funci�n que convierte un n�mero binario a hexadecimal
void binarioAHexadecimal() {
    char binarioStr[64];  // Suficientemente grande para manejar la entrada
    long long binarioNumber = 0, hex = 0, i = 1, remainder;

    printf("Ingrese el n�mero binario: ");

    // Leer la cadena binaria
    if (scanf("%s", binarioStr) != 1 || !esBinarioValido(binarioStr)) {
        // Verificar si la entrada es inv�lida y mostrar un mensaje de error
        printf("Error: Ingrese un n�mero binario v�lido (solo 0 y 1).\n");
        while (getchar() != '\n');  // Limpiar el b�fer de entrada
        return;
    }

    // Convertir binario a decimal
    sscanf(binarioStr, "%lld", &binarioNumber);

    // Convertir binario a hexadecimal
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
            return -1;  // Indica que la entrada no es v�lida
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

    // Llamar a la funci�n convertirhexadecimalADecimal para obtener el valor decimal
    long long decimal = convertirhexadecimalADecimal(hexadecimal);

    // Verificar si la conversi�n fue exitosa antes de imprimir el resultado
    if (decimal != -1) {
        printf("El n�mero en Decimal es: %lld\n", decimal);
    }
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
