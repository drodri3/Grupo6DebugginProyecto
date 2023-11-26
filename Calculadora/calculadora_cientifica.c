#include <stdio.h>
#include <math.h>
#include "cientifica.h"

void imprimirMenuCalculadoraCientifica() {
    int opcion, a, b;

    do {
        printf("\n\n");
        printf("Modo Científico:\n");
        printf("1. 10 exponente X\n");
        printf("2. X exponente N\n");
        printf("3. X exponente 2\n");
        printf("4. Raíz cuadrada de X\n");
        printf("0. Volver al menú anterior\n");

        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                potencia_de_10();
                break;
            case 2:
                potencia_de_x();
                break;
            case 3:
                cuadrado_de_x();
                break;
            case 4:
                raiz_cuadrada_de_x();
                break;
            case 0:
                printf("Saliendo del Modo Científico.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 0);
}



void potencia_de_10() {
    double exponente;

    // Validar la entrada del usuario
    printf("Ingrese el exponente: ");
    if (scanf("%lf", &exponente) != 1 || exponente < -99 || exponente > 99) {
        while (getchar() != '\n');  // Limpiar el búfer de entrada
        printf("\nError: Ingrese un exponente válido.\n");
        return;
    }

    double resultado;

    if (exponente >= 0) {
        // Potencia de 10 positiva
        resultado = pow(10, exponente);
    } else {
        // Potencia de 10 negativa
        resultado = 1.0 / pow(10, -exponente);
    }

    // Decidir si mostrar en notación científica o no
    if (resultado > 1e9 || resultado < 1e-6) {
        printf("%e\n", resultado);
    } else {
        printf("%g\n", resultado);
    }
}


void potencia_de_x() {
    double exponente;
    double base;

    printf("Ingrese la base: ");
    if (scanf("%lf", &base) != 1 || base < 1e-99 || base > 9.999999999e99) {
        while (getchar() != '\n');  // Limpiar el búfer de entrada
        printf("\nError: Ingrese una base válida.\n");
        return;
    }

    printf("Ingrese el exponente: ");
    if (scanf("%lf", &exponente) != 1 || exponente < -99 || exponente > 99) {
        while (getchar() != '\n');  // Limpiar el búfer de entrada
        printf("\nError: Ingrese un exponente válido entre -99 y 99.\n");
        return;
    }

    double resultado;

    if (exponente >= 0) {
        // Potencia de 10 positiva
        resultado = pow(base, exponente);
    } else {
        // Potencia de 10 negativa
        resultado = 1.0 / pow(base, -exponente);
    }

// Decidir si mostrar en notación científica o no
    if (resultado > 1e9 || resultado < 1e-6) {
        printf("%e\n", resultado);
    } else {
        printf("%g\n", resultado);
    }
}


void cuadrado_de_x() {
    double base;

    printf("Ingrese la base: ");
    if (scanf("%lf", &base) != 1 || base < 1e-99 || base > 9.999999999e99) {
        while (getchar() != '\n');  // Limpiar el búfer de entrada
        printf("\nError: Ingrese una base válida.\n");
        return;
    }

    double resultado = pow(base, 2);

    // Decidir si mostrar en notación científica o no
    if (resultado > 1e9 || resultado < 1e-6) {
        printf("%e\n", resultado);
    } else {
        printf("%g\n", resultado);
    }
}


void raiz_cuadrada_de_x() {
    double numero;

    printf("Ingrese el número: ");
    if (scanf("%lf", &numero) != 1) {
        while (getchar() != '\n');
        printf("Error: Ingrese un número válido.\n");
        return;
    }

    // Verificar si el número es no negativo antes de calcular la raíz cuadrada
    if (numero < 0) {
        printf("No se puede calcular la raíz cuadrada de un número negativo.\n");
    // Verificar si es un número infinito
    } else if (isinf(numero)) {
        printf("Entrada no válida (infinito).\n");
    } else {
        double resultado = sqrt(numero);

        // Decidir si mostrar en notación científica o no
        if (resultado == 0) {
            printf("0\n");
        } else if (resultado > 1e9 || resultado < 1e-6) {
            printf("%e\n", resultado);
        } else {
            printf("%g\n", resultado);
        }
    }
}
