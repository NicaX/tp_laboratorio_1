#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/*funcionalidad: funcion encargada de pedir un num y almacenarlo
parametros: recibe una direccion de memoria
retorno:
*/
/** \brief Pide un numero para calcular
*   \param void
*   \return float* pNumero
*/
void ingresarNumero(float* pNumero)
{
    printf("Ingrese un numero ");
    //__fpurge(stdin); //para windows no funca xd
    fflush(stdin);
    scanf("%f",pNumero);

}
float sumar(float numero1, float numero2)
{
    float resultado;
    resultado=numero1+numero2;
    return resultado;
}
float restar(float numero1, float numero2)
{
    float resultado;
    resultado=numero1-numero2;
    return resultado;
}
float multiplicar(float numero1, float numero2)
{
    float resultado;
    resultado=numero1*numero2;
    return resultado;
}
float dividir(float numero1, float numero2)
{
    float resultado;
    resultado=numero1/numero2;
    return resultado;
}
double factorizar(float numero1)
{
    int i;
    double resultado=1;
    for(i=(int)numero1;i>=1;i--)
    {
        resultado=resultado*i;
    }

    return (resultado);
}




