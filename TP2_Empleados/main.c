#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.c"
//#include "ArrayEmployees.h"

int main()
{
    eEmpleado listaEmpleadosMain[MAX_EMPLEADOS];
    initEmployees(listaEmpleadosMain,MAX_EMPLEADOS);
    int opcion;
    int bandera=0;
    do
    {
        system("cls");
        menuPrincipal();

        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1://ALTA
                if(addEmployees(listaEmpleadosMain,MAX_EMPLEADOS)==0)
                {
                    bandera = 1;
                }
                break;
            case 2://MOD
                if(bandera == 1)
                {
                    findEmployeeById(listaEmpleadosMain,MAX_EMPLEADOS);
                }
                else
                {
                    printf("\nError!! Tiene que haber empleados ingresados primero!\n\n");
                }
                break;
            case 3://BAJA
                if(bandera == 1)
                {
                    removeEmployee(listaEmpleadosMain,MAX_EMPLEADOS);
                }
                else
                {
                    printf("\nError!! Tiene que haber empleados ingresados primero!\n\n");
                }
                break;
            case 4://INFO
                if(bandera == 1)
                {
                    sortEmployees(listaEmpleadosMain,MAX_EMPLEADOS);
                }
                else
                {
                    printf("\nError!! Tiene que haber empleados ingresados primero!\n\n");
                }
                break;
            case 5://SALIR
                printf("\nERROR. Elija una opcion correcta...\n\n");
                break;
            case 6:
                printf("\nSaliendo...\nQue tenga buen dia!!!\n\n");
                break;
            default:
                printf("Error: opcion no valida.");
                break;
        }
        system("pause"); //pausa la consola
        system("cls");  //limpia
    }while(opcion!=6);
    return 0;
}





/*int main()
{

    int opcion;



    do
    {

        printf("\n*********Bienvenido**********\n\n");
        printf("-------------------------\n");


        printf("1.\nDar de alta un empleado\n");
        printf("2.Modificar datos de un empleado\n");
        printf("3.Dar de baja un empleado\n");
        printf("4.Mostrar los empleados\n");
        printf("5.Calcular Salarios\n");
        printf("6.Salir\n");
        printf("-------------------------\n");
        printf("\nIngrese una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);


        switch(opcion)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:


            break;
        case 4:


            break;
        case 5:

            break;
        case 6:
            printf("\nSaliendo...\nQue tenga buen dia!!!\n\n");
            break;
        default:
            printf("\nERROR. Elija una opcion correcta...\n\n");
            break;

        }
        system("pause"); //pausa la consola
        system("cls");  //limpia
    }
    while (opcion!=6);
    return 0;
}
*/
