#include <stdio.h>
#include <math.h>
#include "cientifica.h"

void imprimirMenuCalculadoraCientifica() {
    int opcion, a, b;

    do {
        printf("\n\n");
        printf("Modo Cient�fico:\n");
        printf("1. 10 exponente X\n");
        printf("2. X exponente N\n");
        printf("3. X exponente 2\n");
        printf("4. Ra�z cuadrada de X\n");
        printf("0. Volver al men� anterior\n");

        printf("Seleccione una opci�n: ");
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
                printf("Saliendo del Modo Cient�fico.\n");
                break;
            default:
                printf("Opci�n no v�lida. Intente de nuevo.\n");
        }
    } while (opcion != 0);
}



void potencia_de_10() {
    double exponente;

    // Validar la entrada del usuario
    printf("Ingrese el exponente: ");
    if (scanf("%lf", &exponente) != 1 || exponente < -99 || exponente > 99) {
        while (getchar() != '\n');  // Limpiar el b�fer de entrada
        printf("\nError: Ingrese un exponente v�lido.\n");
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

    // Decidir si mostrar en notaci�n cient�fica o no
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
        while (getchar() != '\n');  // Limpiar el b�fer de entrada
        printf("\nError: Ingrese una base v�lida.\n");
        return;
    }

    printf("Ingrese el exponente: ");
    if (scanf("%lf", &exponente) != 1 || exponente < -99 || exponente > 99) {
        while (getchar() != '\n');  // Limpiar el b�fer de entrada
        printf("\nError: Ingrese un exponente v�lido entre -99 y 99.\n");
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

// Decidir si mostrar en notaci�n cient�fica o no
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
        while (getchar() != '\n');  // Limpiar el b�fer de entrada
        printf("\nError: Ingrese una base v�lida.\n");
        return;
    }

    double resultado = pow(base, 2);

    // Decidir si mostrar en notaci�n cient�fica o no
    if (resultado > 1e9 || resultado < 1e-6) {
        printf("%e\n", resultado);
    } else {
        printf("%g\n", resultado);
    }
}


void raiz_cuadrada_de_x() {
    double numero;

    printf("Ingrese el n�mero: ");
    if (scanf("%lf", &numero) != 1) {
        while (getchar() != '\n');
        printf("Error: Ingrese un n�mero v�lido.\n");
        return;
    }

    // Verificar si el n�mero es no negativo antes de calcular la ra�z cuadrada
    if (numero < 0) {
        printf("No se puede calcular la ra�z cuadrada de un n�mero negativo.\n");
    // Verificar si es un n�mero infinito
    } else if (isinf(numero)) {
        printf("Entrada no v�lida (infinito).\n");
    } else {
        double resultado = sqrt(numero);

        // Decidir si mostrar en notaci�n cient�fica o no
        if (resultado == 0) {
            printf("0\n");
        } else if (resultado > 1e9 || resultado < 1e-6) {
            printf("%e\n", resultado);
        } else {
            printf("%g\n", resultado);
        }
    }
}
