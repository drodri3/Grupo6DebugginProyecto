#ifndef ESTANDAR_H_INCLUDED
#define ESTANDAR_H_INCLUDED



void imprimirMenuCalculadoraEstandar()
{
    // Imprimir el men�
    int opcion, a, b;

    do {
        printf("\nMenu:\n");
        printf("1. Sumar\n");
        printf("2. Restar\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("0. Volver al men� anterior\n");
        printf("Ingrese su opci�n: ");
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
    printf("El resultado de la multiplicaci�n de %d por %d es igual a %d\n", a, b, a*b);
}

void division(int a, int b)
{
    if (b != 0) {
        printf("El resultado de la divisi�n de %d entre %d es igual a %d\n", a, b, a / b);
    } else {
        printf("Error: No se puede dividir entre cero.\n");
    }
}
#endif // ESTANDAR_H_INCLUDED
