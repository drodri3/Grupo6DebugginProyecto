#ifndef ESTANDAR_H_INCLUDED
#define ESTANDAR_H_INCLUDED



void imprimirMenuCalculadoraEstandar()
{
    // Imprimir el menú
    int a, b;
    char opcion;

    do {
        printf("\nModo Estándar:\n");
        printf("1. Sumar\n");
        printf("2. Restar\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("0. Volver al menú anterior\n");
        printf("Ingrese su opción: ");

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
                printf("Ingrese dos números para sumar:\n");
                printf("Número 1: ");
                if (scanf("%d", &a) != 1) {
                    while (getchar() != '\n');
                    printf("Error: Ingrese un número válido.\n");
                    continue;
                }
                printf("Número 2: ");
                if (scanf("%d", &b) != 1) {
                    while (getchar() != '\n');
                    printf("Error: Ingrese un número válido.\n");
                    continue;
                }
                suma(a, b);
                break;

            case '2':
                printf("Ingrese dos números para restar:\n");
                printf("Número 1: ");
                if (scanf("%d", &a) != 1) {
                    while (getchar() != '\n');
                    printf("Error: Ingrese un número válido.\n");
                    continue;
                }
                printf("Número 2: ");
                if (scanf("%d", &b) != 1) {
                    while (getchar() != '\n');
                    printf("Error: Ingrese un número válido.\n");
                    continue;
                }
                resta(a, b);
                break;

            case '3':
                printf("Ingrese dos números para multiplicar:\n");
                printf("Número 1: ");
                if (scanf("%d", &a) != 1) {
                    while (getchar() != '\n');
                    printf("Error: Ingrese un número válido.\n");
                    continue;
                }
                printf("Número 2: ");
                if (scanf("%d", &b) != 1) {
                    while (getchar() != '\n');
                    printf("Error: Ingrese un número válido.\n");
                    continue;
                }
                multiplicacion(a, b);
                break;

            case '4':
                printf("Ingrese dos números para dividir:\n");
                printf("Número 1: ");
                if (scanf("%d", &a) != 1) {
                    while (getchar() != '\n');
                    printf("Error: Ingrese un número válido.\n");
                    continue;
                }
                printf("Número 2: ");
                if (scanf("%d", &b) != 1) {
                    while (getchar() != '\n');
                    printf("Error: Ingrese un número válido.\n");
                    continue;
                }
                division(a, b);
                break;

            case '0':
                printf("Volviendo al menu anterior\n");
                break;

            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
                break;
        }
    } while (opcion != '0');
}

void suma(int a, int b)
{
    printf("El resultado de la suma de %d mas %d es igual a %d\n", a, b, a+b);
}

void resta(int a, int b)
{
    printf("El resultado de la resta de %d menos %d es igual a %d\n", a, b, a-b);
}

void multiplicacion(int a, int b)
{
    printf("El resultado de la multiplicación de %d por %d es igual a %d\n", a, b, a*b);
}

void division(int a, int b) {
    if (b != 0) {
        double resultado = (double)a / b;

        // Verificar si hay decimales que no son ceros
        if (resultado == (int)resultado) {
            printf("El resultado de la división de %d entre %d es %d\n", a, b, (int)resultado);
        } else {
            printf("El resultado de la división de %d entre %d es %.3f\n", a, b, resultado);
        }
    } else {
        printf("Error: No se puede dividir entre cero.\n");
    }
}
#endif // ESTANDAR_H_INCLUDED
