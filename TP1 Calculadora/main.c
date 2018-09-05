#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"
#include "math.c"


int main()
{
    float numeroA;
    float numeroB;
    int flagA=0;
    int flagB=0;
    int calculosHechos=0;
    int opcion;



    do
    {

        printf("\n*********Bienvenido**********\n\n");
        printf("-------------------------\n");
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
        printf("-------------------------\n");
        printf("\nIngrese una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);



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
                printf("\nCalculando la suma %.2f + %.2f ...\n",numeroA,numeroB);
                printf("Calculando la resta %.2f - %.2f ...\n",numeroA,numeroB);
                printf("Calculando la multiplicacion %.2f * %.2f ...\n",numeroA,numeroB);
                printf("Calculando la division %.2f / %.2f ...\n",numeroA,numeroB);
                printf("Calculando el factorial de %.2f...\n",numeroA);
                printf("Calculando el factorial de %.2f...\n",numeroB);
                printf("Si ingreso un numero con decimal, los factoriales se van a redondear a enteros\n\n");

            }else
            {
                printf("\nError! Ingrese los 2 numeros...\n\n");
            }
            calculosHechos=1;
            break;
        case 4:

            if(calculosHechos==1&&flagA==1 && flagB==1)
            {
            sumar(numeroA,numeroB);
            restar(numeroA,numeroB);
            multiplicar(numeroA,numeroB);

            if(numeroB==0)
            {
                printf("No se puede dividir por 0!!!!\n");
            }else
            {
                dividir(numeroA,numeroB);
            }

            if( numeroA < 0)
                {
                    printf("(Error %.2f) No se pueden factorizar los numeros negativos!!!\n",numeroA);
                }else
                {
                    factorizar(numeroA);

                }
            if(numeroB < 0)
                {
                    printf("(Error %.2f) No se pueden factorizar los numeros negativos!!!\n",numeroB);
                }else
                {
                    factorizar(numeroB);
                }
            }
            else
            {
                printf("\nError!!! Aun no hiciste los calculos!!\n\n");
            }
            break;
        case 5:
            printf("\nSaliendo...\nQue tenga buen dia!!!\n\n");
            break;
        default:
            printf("\nERROR. Elija un numero del 1 al 5...\n\n");
            break;

        }
        system("pause"); //pausa la consola
        system("cls");  //limpia
    }
    while (opcion!=5);
    return 0;
}










