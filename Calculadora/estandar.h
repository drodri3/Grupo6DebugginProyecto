#ifndef ESTANDAR_H_INCLUDED
#define ESTANDAR_H_INCLUDED



void imprimirMenuCalculadoraEstandar()
{
    // Imprimir el men�
        printf("\nMenu:\n");
        printf("1. Sumar\n");
        printf("2. Restar\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("0. Volver al menu anterior\n");
        printf("Ingrese su opci�n: ");
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
