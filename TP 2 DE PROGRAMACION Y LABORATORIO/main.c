#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "employee.h"
#define ELEMENTS 1000
int main()
{
    char seguir = 's';
    char confirma;
    Employee arrayEmployees[ELEMENTS];
    initEmployees(arrayEmployees, ELEMENTS);
    int flag = 0;
    printf("\n\t\t\t----------ADVERTENCIA-----------\t\t\t\n");
    printf("SI USTED HUBIERA PREFERIDO ALGO MEJOR, HUBIERAN PUESTO LA FECHA DE ENTREGA UN DIA QUE NO SEA SEMANA DE PARCIAL\n");
    printf("EL TP SE HISO VIERNES 10 DE MAYO DE 18:15HS A 22:45HS\n");
    printf("CAPAZ NOTE ALGUNAS COSAS EN ESTE PARCIAL PERO SE HISO LO QUE SE PUDO EN TAN POCO TIEMPO\n");
    printf("NO SOLO ESTOY CURSANDO PROGRAMACION Y LABORATORIO SINO OTRAS MATERIAS MAS\n\n");
    printf("PRECIONE CUALQUIER TECLA PARA VER EL MENU\n");
    system("pause");
    system("cls");
    do
    {
        switch(menu())
        {
        case 1:
            printf("\nAlta empleado\n\n");
            addEmployee(arrayEmployees, ELEMENTS);
            flag = 1;
            system("pause");
            system("cls");
            break;
        case 2:
            if(flag == 1)
            {
                printf("\nModificacion empleado\n\n");
                modificationEmployee(arrayEmployees, ELEMENTS);
            }
            else
            {
                printf("ERROR, tienes que ingresar por lo menos un alta. \n");
            }
            system("pause");
            system("cls");
            break;
        case 3:
            if(flag == 1)
            {
                printf("\nBaja empleado\n\n");
                removeEmployee(arrayEmployees, ELEMENTS);
            }
            else
            {
                printf("ERROR, tienes que ingresar por lo menos un alta. \n");
            }
            system("pause");
            system("cls");
            break;
        case 4:
            if(flag == 1)
            {
                printf("\nListar empleados\n\n");
                sortEmployees(arrayEmployees, ELEMENTS);
                printEmployees(arrayEmployees, ELEMENTS);
            }
            else
            {
                printf("ERROR, tienes que ingresar por lo menos un alta. \n");
            }
            system("pause");
            system("cls");
            break;
        case 5:
            printf("\nConfirma salida s/n?: ");
            setbuf(stdin,NULL);
            confirma = getche();
            if(tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            else if(tolower(confirma) == 'n')
            {
                seguir = 's';
            }
            else
            {
                printf("\nERROR, ingrese S para salir o N para quedarse \n");
                system("pause");
            }
            break;
        default:
            printf("Opcion invalida\n\n");
            system("pause");
            system("break");
        }
    }
    while(seguir == 's');
    return 0;
}
