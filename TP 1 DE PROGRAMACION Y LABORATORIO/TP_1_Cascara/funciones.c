#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

/** \brief En esta función sirve para que sume A y B y tambien que muestre el resultado de A + B.
 *
 * \param A: tiene un numero flotante.
 * \param B: tiene un numero flotante.
 * \return resultado: obtiene el resultado de la suma de A y B.
 *
 */
float addition(float A,float B)
{
    int resultado;
    resultado = A + B;
    return resultado;
}

/** \brief En esta función sirve para que reste A y B y tambien que muestre el resultado de A - B.
 *
 * \param A: tiene un numero flotante.
 * \param B: tiene un numero flotante.
 * \return resultado: obtiene el resultado de la resta de A y B.
 *
 */
float substraction(float A,float B)
{
    float resultado;
    resultado = A - B;
    return resultado;
}

/** \brief En esta función sirve para que divida A y B y que muestre el resultado de A / B.
 *
 * \param A: tiene un numero flotante.
 * \param B: tiene un numero flotante.
 * \return resultado: obtiene el resultado de la división de A y B.
 *
 */
float division(float A,float B)
{

    float resultado;
    resultado = A / B;
    return resultado;
}

/** \brief En esta función sirve para que multiplique A y B y tambien que muestre el resultado de A * B.
 *
 * \param A: tiene un numero flotante.
 * \param B: tiene un numero flotante.
 * \return resultado: obtiene el resultado de la multiplicación de A y B.
 *
 */
float multiplication(float A,float B)
{
    float resultado;
    resultado = A * B;
    return resultado;
}

/** \brief En esta función sirve para que factorice A y que muestre el resultado de A!.
 *
 * \param A: tiene un numero entero.
 * \param B: tiene un numero entero.
 * \return resultado: obtiene el resultado del factorial A.
 *
 */
int factorial1(int A)
{
    int resultado = 1;
    if(A > 0)
    {
        int i;
        for(i=A; i>0; i--)
        {
            resultado = resultado * i;
        }
    }
    return resultado;
}

/** \brief En esta función sirve para que factorice B y que muestre el resultado de B!.
 *
 * \param A: tiene un numero entero.
 * \param B: tiene un numero entero.
 * \return resultado: obtiene el resultado del factorial B.
 *
 */
int factorial2(int B)
{
    int resultado = 1;
    if(B > 0)
    {
        int i;
        for(i=B; i>0; i--)
        {
            resultado = resultado * i;
        }
    }
    return resultado;
}
