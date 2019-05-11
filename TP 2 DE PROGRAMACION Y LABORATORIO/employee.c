#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "employee.h"

/** \brief muestra el menu del abm
 *
 * \return int muestra el menu
 *
 */
int menu()
{
    int opcion;
    system("cls");
    printf("  *** ABM Empleados ***  \n");
    printf("\n\n1 - ALTA \n2 - MODIFICACION \n3 - BAJA\n4 - LISTAR\n5 - SALIR\n\n");
    printf("seleccione una opcion\n");
    scanf("%d",&opcion);
    return opcion;
}
/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee list[], int len)
{
    for(int i=0; i < len; i++)
    {
        list[i].isEmpty = 1;
    }
    return 0;
}
/** \brief busca el lugar libre
 *
 * \param list[] Employee obtiene la estructura de empleados
 * \param len int obtiene el tamaño de los empleados
 * \return int devuelve si esta libre o no
 *
 */
int searchFree(Employee list[], int len)
{
    int i;
    int index=-1;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==1)
        {
            index = i;
            break;
        }
    }
    return index;
}
/** \brief calcula la mayor id de los empleados
 *
 * \param list[] Employee obtiene la estructura de empleados
 * \param len int obtiene el tamaño de los empleados
 * \return int devuelve la id mayor
 *
 */
int higherIdEmployee(Employee list[], int len)
{
    int i;
    int flag = 0;
    int aux = 0;
    for(i=0; i<len; i++)
    {
        if(flag==0 || list[i].id>aux)
        {
            aux = list[i].id;
            flag = 1;
        }
    }
    return aux;
}
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee obtiene la estructura de empleados
 * \param len int obtiene el tamaño de los empleados
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int addEmployee(Employee list[], int len)
{
    int i;
    i = searchFree(list, len);
    if(i!=-1)
    {
        list[i].id = higherIdEmployee(list, len) + 1;
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(list[i].name);
        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(list[i].lastName);
        printf("Ingrese salario: ");
        scanf("%f",&list[i].salary);
        printf("Ingrese sector: ");
        scanf("%d",&list[i].sector);
        list[i].isEmpty = 0;
    }
    else
    {
        printf("No hay espacio");
    }
    return -1;
}
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee obtiene la estructura de empleados
 * \param len int obtiene el tamaño de los empleados
 * \param id int localiza la id
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee list[], int len,int id)
{
    int index = -1;
    for(int i=0; i < len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee obtiene la estructura de empleados
 * \param len int obtiene el tamaño de los empleados
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee list[], int len)
{
    int i;
    int id;
    int loEncontro = 1;
    printEmployees(list, len);
    printf("Ingrese id a borrar: ");
    scanf("%d", &id);
    for(i=0; i<len; i++)
    {
        if(id == list[i].id)
        {
            list[i].isEmpty = 1;
            loEncontro = 0;
            break;
        }
    }
    if(loEncontro==1)
    {
        printf("El dato no existe");
    }
    return -1;
}
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee obtiene la estructura de empleados
 * \param len int obtiene el tamaño de los empleados
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee list[], int len)
{
    Employee aux;
    int i;
    int j;
    for(i = 0; i < len-1; i++)
    {
        for(j = i+1; j < len; j++)
        {
            if(list[i].lastName < list[j].lastName)
            {
                aux = list[i];
                list[i] = list[j];
                list[j] = aux;
            }
            else
            {
                if(strcmp(list[i].lastName,list[j].lastName))
                {
                    if(list[i].sector < list[j].sector)
                    {
                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                    }

                }
            }
        }
    }
    return 0;
}
/** \brief muestra un empleado
 *
 * \param anEmployee Employee obtiene la estructura de empleados
 * \return void muestra los resultados
 *
 */
void printEmployee(Employee anEmployee)
{
    printf("\tID\tNAME\tLASTNAME\tSALARY\tSECTOR\t\n");
    printf("%10d %10s %10s %10.2f %10d\n", anEmployee.id, anEmployee.name, anEmployee.lastName, anEmployee.salary, anEmployee.sector);
}
/** \brief print the content of employees array
 *
 * \param list Employee obtiene la estructura de empleados
 * \param len int obtiene el tamaño de los empleados
 * \return int
 *
 */
int printEmployees(Employee list[], int len)
{
    int i;
    printf("------------------------------\n");
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty!=1)
        {
            printEmployee(list[i]);
        }
    }
    printf("------------------------------\n");
    return 0;
}
/** \brief modifica los datos del empleado
 *
 * \param list[] Employee obtiene la estructura de empleados
 * \param len int obtiene el tamaño de los empleados
 * \return void no devuelve nada
 *
 */
void modificationEmployee(Employee list[], int len)
{
    int id;
    char confirma;
    int i;
    printEmployees(list, len);
    printf("Ingrese id: ");
    scanf("%d", &id);
    i = findEmployeeById(list, len, id);
    if(i == -1)
    {
        printf("\nEl id %d no esta registrado en el sistema\n", id);
    }
    else
    {
        printEmployee(list[i]);
        printf("\nQuiere cambiar el nombre? s/n \n");
        fflush(stdin);
        confirma = tolower(getche());
        if(confirma == 's')
        {
            printf("\nIngrese nuevo nombre: ");
            fflush(stdin);
            gets(list[i].name);
        }
        else
        {
            printf("\nNo se ha modificado el nombre\n");
        }
        printf("\nQuiere cambiar el apellido? s/n \n");
        fflush(stdin);
        confirma = tolower(getche());
        if(confirma == 's')
        {
            printf("\nIngrese nuevo apellido: ");
            fflush(stdin);
            gets(list[i].lastName);
        }
        else
        {
            printf("\nNo se ha modificado el apellido\n");
        }
        printf("\nQuiere cambiar el salario? s/n \n");
        fflush(stdin);
        confirma = tolower(getche());
        if(confirma == 's')
        {
            printf("\nIngrese nuevo salario: ");
            scanf("%f",&list[i].salary);
        }
        else
        {
            printf("\nNo se ha modificado el salario\n");
        }
        printf("\nQuiere cambiar el sector? s/n \n");
        fflush(stdin);
        confirma = tolower(getche());
        if(confirma == 's')
        {
            printf("\nIngrese nuevo sector: ");
            scanf("%d",&list[i].sector);
        }
        else
        {
            printf("\nNo se ha modificado el sector\n");
        }
    }
}
