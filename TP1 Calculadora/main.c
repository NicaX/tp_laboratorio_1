#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"
#include "math.c"


int ingresarOpcion(void);

int main()
{
    float numeroA;
    float numeroB;
    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicacion;
    float resultadoDivision;
    double resultadoFactoreoA;
    double resultadoFactoreoB;
    int flagA=0;
    int flagB=0;
    int calculosHechos=0;
    int opcion;
    do
    {

        printf("\nBienvenido!!!\n\n");
        if(flagA==1)
        {
        printf("1.Ingrese numero (A=%.2f)\n",numeroA);
        }else
        {
        printf("1.Ingrese numero (A=x)\n");
        }
        if(flagB==1)
        {
        printf("2.Ingrese numero (B=%.2f)\n",numeroB);
        }else{
        printf("2.Ingrese numero (B=x)\n");
        }
        printf("3.Realizar los Calculos\n");
        printf("4.Mostrar los resultados\n");
        printf("5.Salir\n");

        opcion=ingresarOpcion();
        switch(opcion)
        {
        case 1:
            flagA=1;
            ingresarNumero(&numeroA);
            break;
        case 2:
            flagB=1;
            ingresarNumero(&numeroB);
            break;
        case 3:
            if(flagA==1 && flagB==1)
            {
                printf("Calculando la suma %.2f + %.2f ...\n",numeroA,numeroB);
                printf("Calculando la resta %.2f - %.2f ...\n",numeroA,numeroB);
                printf("Calculando la multiplicacion %.2f * %.2f ...\n",numeroA,numeroB);
                if(numeroB==0)
                {
                    printf("No se puede dividir por 0!!!!\n");
                }else
                {
                    printf("Calculando la division %.2f / %.2f ...\n",numeroA,numeroB);
                }
                if(numeroA < 0)
                {
                    printf("(Error %.2f) No se pueden factorizar los numeros negativos!!!\n",numeroA);
                }else
                {
                    printf("Calculando el factorial de %.2f...\n",numeroA);
                }
                if(numeroB < 0)
                {
                    printf("(Error %.2f)No se pueden factorizar los numeros negativos!!!\n", numeroB);
                }else
                {
                    printf("Calculando el factorial de %.2f...\n",numeroB);
                }


            }else
            {
                printf("Error! Ingrese los 2 numeros...\n");
            }
            calculosHechos=1;
            break;
        case 4:

            if(calculosHechos==1&&flagA==1 && flagB==1)
            {
            resultadoSuma=sumar(numeroA,numeroB);
            printf("El resultado de la suma es %.2f\n", resultadoSuma);

            resultadoResta=restar(numeroA,numeroB);
            printf("El resultado de la resta es %.2f\n", resultadoResta);

            resultadoMultiplicacion=multiplicar(numeroA,numeroB);
            printf("El resultado de la multiplicacion es %.2f\n", resultadoMultiplicacion);

            if(numeroB==0)
            {
                printf("No se puede dividir por 0!!!!\n");
            }else
            {
                resultadoDivision=dividir(numeroA,numeroB);
                printf("El resultado de la division es %.2f\n", resultadoDivision);
            }

            if( numeroA < 0)
                {
                    printf("(Error %.2f) No se pueden factorizar los numeros negativos!!!\n",numeroA);
                }else
                {
                    resultadoFactoreoA=factorizar(numeroA);
                    printf("El factorial de %.2f es %.2lf \n",numeroA, resultadoFactoreoA);
                }
            if(numeroB < 0)
                {
                    printf("(Error %.2f) No se pueden factorizar los numeros negativos!!!\n",numeroB);
                }else
                {
                resultadoFactoreoB=factorizar(numeroB);
                printf("El factorial de %.2f es %.2lf \n",numeroB,resultadoFactoreoB);
                }
            }
            else
            {
                printf("Error!!! Aun no hiciste los calculos!!\n");
            }
            break;
        case 5:
            printf("Saliendo...\n");
            break;
        default:
            printf("Elegi un numero del 1 al 5 capo...\n");
            break;

        }
        system("pause"); //pausa la consola
        system("cls");  //limpia
    }
    while (opcion!=5);
    return 0;
}

int ingresarOpcion(void)
{
    int opcion;
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;
}








