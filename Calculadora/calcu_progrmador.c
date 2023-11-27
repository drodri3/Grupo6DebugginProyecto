#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "programador.h"

void decimalABinario() {
    int i = 0;
    int a;

    // Solicitar al usuario que ingrese un número decimal
    printf("Ingrese el número a convertir:\n");

     // Leer el número decimal desde la entrada estándar
    if(scanf("%d", &a) != 1){
        // Limpiar el búfer de entrada si la entrada no es válida
        while (getchar() != '\n');
        printf("Error: Ingrese un número válido.\n");
        return;
    }
    // Verificar si el número es 0
    if (a == 0) {
        printf("El número en Binario es : 0\n");
        return; // Salir de la función si el número es 0
    }
    // Convertir números negativos a binario (representación en complemento a 2)
    if (a < 0) {
        // Convertir el número negativo a su representación en complemento a 2
        unsigned int numeroNegativo = (unsigned int)-a;
        // Imprimir el bit de signo para números negativos
        printf("El número binario es: 1");
        // Imprimir los bits del número negativo en orden inverso (de mayor a menor)
        for (int i = 30; i >= 0; i--) {
            int bit = (numeroNegativo >> i) & 1;
            printf("%d", bit);
        }

    } else {
        // Convertir números positivos a binario
        printf("El número en Binario es : ");
        // Imprimir los bits del número en orden inverso (de mayor a menor)
        for (int i = 31; i >= 0; i--) {
            int bit = (a >> i) & 1;
            printf("%d", bit);
        }
    }
}

void decimalAHexadecimal() {
    int a;

    // Solicitar al usuario que ingrese un número decimal
    printf("Ingrese el número a convertir:\n");

    // Leer el número decimal desde la entrada estándar
    if (scanf("%d", &a) != 1) {
        // Limpiar el búfer de entrada si la entrada no es válida
        while (getchar() != '\n');
        printf("Error: Ingrese un número válido.\n");
        return;
    }

    // Verificar si el número es 0
    if (a == 0) {
        printf("El número en Hexadecimal es: 0\n");
        return; // Salir de la función si el número es 0
    }

    // Convertir números negativos a hexadecimal (representación en complemento a 2)
    if (a < 0) {
        // Convertir el número negativo a su representación en complemento a 2
        unsigned int negativoNumero = (unsigned int)-a;

        // Imprimir el signo negativo y el valor hexadecimal
        printf("El número en Hexadecimal es: -%X\n", negativoNumero);
    } else {
        // Convertir números positivos a hexadecimal
        printf("El número en Hexadecimal es: %X\n", a);
    }
}

// Función que verifica si una cadena contiene solo dígitos binarios (0 y 1)
bool esBinarioValido(const char* str){
    // Recorrer cada caracter en la cadena
    while (*str != '\0') {
        // Verificar si el caracter actual no es '0' ni '1'
        if (*str != '0' && *str != '1') {
            return false; // No es un dígito binario válido
        }
        str++;// Moverse al siguiente caracter en la cadena
    }
    return true; // Todos los caracteres son binarios
}

// Función que convierte un número binario a hexadecimal
void binarioAHexadecimal() {
    char binarioStr[64];  // Suficientemente grande para manejar la entrada
    long long binarioNumber = 0, hex = 0, i = 1, remainder;

    printf("Ingrese el número binario: ");

    // Leer la cadena binaria
    if (scanf("%s", binarioStr) != 1 || !esBinarioValido(binarioStr)) {
        // Verificar si la entrada es inválida y mostrar un mensaje de error
        printf("Error: Ingrese un número binario válido (solo 0 y 1).\n");
        while (getchar() != '\n');  // Limpiar el búfer de entrada
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

    printf("El número en Hexadecimal es: %lX\n", hex);
}


long long convertirhexadecimalADecimal(char* hexadecimal) {
    long long decimal = 0;

    // Procesar cada dígito hexadecimal
    for (int i = 0; hexadecimal[i] != '\0'; i++) {
        char caracter = hexadecimal[i];

        // Obtener el valor del dígito hexadecimal
        int valor;
        if (caracter >= '0' && caracter <= '9') {
            valor = caracter - '0';
        } else if (caracter >= 'A' && caracter <= 'F') {
            valor = 10 + caracter - 'A';
        } else if (caracter >= 'a' && caracter <= 'f') {
            valor = 10 + caracter - 'a';
        } else {
            // Caracter no válido
            printf("Error: \"%c\" no es un dígito hexadecimal válido.\n", caracter);
            return -1;  // Indica que la entrada no es válida
        }

        // Actualizar el valor decimal
        decimal = decimal * 16 + valor;
    }

    return decimal;
}

void hexadecimalADecimal() {
    char hexadecimal[20];

    printf("Ingrese el número hexadecimal: ");
    scanf("%s", hexadecimal);

    // Llamar a la función convertirhexadecimalADecimal para obtener el valor decimal
    long long decimal = convertirhexadecimalADecimal(hexadecimal);

    // Verificar si la conversión fue exitosa antes de imprimir el resultado
    if (decimal != -1) {
        printf("El número en Decimal es: %lld\n", decimal);
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
        printf("0. Volver al menú anterior\n");

        printf("Seleccione una opción: ");

        if (scanf(" %c", &opcion) != 1) {
            while (getchar() != '\n');
            printf("Error: Ingrese una opción válida.\n");
            continue;
        }

        if (opcion < '0' || opcion > '4') {
            printf("Error: Ingrese una opción válida.\n");
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
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != '0');
}
