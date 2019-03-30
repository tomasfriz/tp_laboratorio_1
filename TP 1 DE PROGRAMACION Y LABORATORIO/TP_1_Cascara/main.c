#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main()
{
    char seguir = 's';
    int opcion = 0;
    float A = 0;
    float B = 0;
    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%.2f)\n",A);
        printf("2- Ingresar 2do operando (B=%.2f)\n",B);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                printf("Ingrese el valor de A=X \n");
                scanf("%f", &A);
                printf("A = %.2f\n",A);
                system("pause");
                system("cls");
                break;
            case 2:
                printf("Ingrese el valor de B=Y \n");
                scanf("%f", &B);
                printf("B = %.2f\n",B);
                system("pause");
                system("cls");
                break;
            case 3:
                printf("El resultado de la suma es: %.2f\n",suma(A,B));
                system("pause");
                system("cls");
                break;
            case 4:
                printf("El resultado de la resta es: %.2f\n",resta(A,B));
                system("pause");
                system("cls");
                break;
            case 5:
                if(B == 0)
                {
                    printf("error, no se puede dividir por 0\n");
                }
                else
                {
                    printf("El resultado de la division es: %.2f\n",division(A,B));
                }
                system("pause");
                system("cls");
                break;
            case 6:
                printf("El resultado de la multiplicacion es: %.2f\n",multiplicacion(A,B));
                system("pause");
                system("cls");
                break;
            case 7:
                if(A < 0)
                {
                    printf("error, no se puede factorizar con numeros negativos.\n");
                }
                else
                {
                     printf("el resultado del factorial A es: %d y del B es: %d \n",factorial1(A),factorial2(B));
                }
                system("pause");
                system("cls");
                break;
            case 8:
                printf("toque cualquier tecla para salir.\n");
                seguir = 'n';
                break;
            default:
                printf("error, opcion invalida, reingrese la opcion \n");
                system("pause");
                system("cls");
        }
    }
    return 0;
}
