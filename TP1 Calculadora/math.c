#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/** \brief encargada de pedir un num y almacenarlo
 *
 * \param pNumero float* la direccion de memoria
 * \return void
 *
 */
void ingresarNumero(float* pNumero)
{
    printf("Ingrese un numero ");
    //__fpurge(stdin); //para windows no funca xd
    fflush(stdin);
    scanf("%f",pNumero);

}

/** \brief la funcion toma 2 numeros y los suma
 *
 * \param numero1 float
 * \param numero2 float
 * \return float  el resultado de numero1 + numero2
 *
 */
float sumar(float numero1, float numero2)
{
    float resultado;
    resultado=numero1+numero2;
    printf("\nEl resultado de la suma es %.2f\n", resultado);
    return resultado;
}
/** \brief la funcion toma 2 numeros y los resta
 *
 * \param numero1 float
 * \param numero2 float
 * \return float el resultado de numero1 - numero2
 *
 */
float restar(float numero1, float numero2)
{
    float resultado;
    resultado=numero1-numero2;
    printf("El resultado de la resta es %.2f\n", resultado);
    return resultado;
}
/** \brief la funcion toma 2 numeros y los multiplica
 *
 * \param numero1 float
 * \param numero2 float
 * \return float  el resultado de numero1 * numero2
 *
 */
float multiplicar(float numero1, float numero2)
{
    float resultado;
    resultado=numero1*numero2;
    printf("El resultado de la multiplicacion es %.2f\n", resultado);
    return resultado;
}
/** \brief la funcion toma 2 numeros y los divide
 *
 * \param numero1 float
 * \param numero2 float
 * \return float  el resultado de numero1 / numero2
 *
 */
float dividir(float numero1, float numero2)
{
    float resultado;
    resultado=numero1/numero2;


    printf("El resultado de la division es %.2f\n", resultado);
    return resultado;

}
/** \brief la funcion toma un numero y lo factoriza
 *
 * \param numero1 float
 * \return double la factorizacion de numero1
 *
 */
double factorizar(float numero1)
{
    int i;
    double resultado=1;
    for(i=(int)numero1;i>=1;i--)
    {
        resultado=resultado*i;
    }
    printf("El factorial de %.2f es %.2lf \n",numero1, resultado);
    return (resultado);
}




