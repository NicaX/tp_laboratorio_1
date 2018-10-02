#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

void initEmployees(eEmpleado arrayEmpleados[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        arrayEmpleados[i].isEmpty = 1;
    }
}

void menuPrincipal()
{
    printf("\n*********Bienvenido**********\n\n");
    printf("-------------------------\n");
    printf("1.Dar de alta un empleado\n");
    printf("2.Modificar datos de un empleado\n");
    printf("3.Dar de baja un empleado\n");
    printf("4.Mostrar los empleados\n");
    printf("5.Calcular Salarios\n");
    printf("6.Salir\n");
    printf("-------------------------\n");
    printf("\nIngrese una opcion: ");
}

int addEmployees(eEmpleado arrayEmpleados[],int cantidad)//listo
{
    int retorno=0;
    char alta = 's';
    do{
        system("cls");
        if(addOneEmployee(arrayEmpleados,buscarLibre(arrayEmpleados,cantidad),cantidad) == -1)
        {
            retorno=-1;
            break;
        }
        printf("\n\nQuiere seguir ingresando?(s/n) ");
        fflush(stdin);
        scanf("%c",&alta);
    }while(alta == 's');
    return retorno;
}

int addOneEmployee(eEmpleado arrayEmpleados[],int vacio,int cantidad)//listo
{
    int retorno = -1;
    printf("\nIngrese el nombre del empleado: ");
    fflush(stdin);
    scanf("%s",arrayEmpleados[vacio].nombre);
    printf("\nIngrese el apellido del empleado: ");
    fflush(stdin);
    scanf("%s",arrayEmpleados[vacio].apellido);
    arrayEmpleados[vacio].id = vacio + 1;
    printf("\nIngrese el salario del empleado: ");
    fflush(stdin);
    scanf("%f",&arrayEmpleados[vacio].salario);
    printf("\nIngrese el sector del empleado: ");
    fflush(stdin);
    scanf("%d",&arrayEmpleados[vacio].sector);
    arrayEmpleados[vacio].isEmpty = 0;
    retorno = 0;
    return retorno;
}

int buscarLibre(eEmpleado arrayEmpleados[],int cantidad)
{
    int i,retorno = -1;
    for(i=0;i<cantidad;i++)
    {
        if(arrayEmpleados[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}



void removeEmployee(eEmpleado arrayEmpleados[],int cantidad)//listo
{
    system("cls");
    int id,indice;
    printEmployees(arrayEmpleados,cantidad);
    printf("\n\nIngrese el id del empleado a dar de baja: ");
    fflush(stdin);
    scanf("%d",&id);
    indice = buscarId(arrayEmpleados,cantidad,id);
    arrayEmpleados[indice].isEmpty = 1;
}

void findEmployeeById(eEmpleado arrayEmpleados[],int cantidad)
{
    system("cls");
    int indice,id,modificar;
    printEmployees(arrayEmpleados,cantidad);
    printf("\n\nIngrese el id del empleado a modificar: ");
    fflush(stdin);
    scanf("%d",&id);
    indice = buscarId(arrayEmpleados,cantidad,id);
    printf("1_Nombre: %s\n",arrayEmpleados[indice].nombre);
    printf("2_Apellido: %s\n",arrayEmpleados[indice].apellido);
    printf("3_Salario: %f\n",arrayEmpleados[indice].salario);
    printf("4_Sector: %d\n",arrayEmpleados[indice].sector);
    fflush(stdin);
    scanf("%d",&modificar);
    system("cls");
    switch(modificar)
    {
        case 1:
            modificarNombre(arrayEmpleados,indice);
            break;
        case 2:
            modificarApellido(arrayEmpleados,indice);
            break;
        case 3:
            modificarSalario(arrayEmpleados,indice);
            break;
        case 4:
            modificarSector(arrayEmpleados,indice);
            break;
        default:
            system("cls");
            printf("Error: opcion no valida.");
            break;
    }
}

void modificarNombre(eEmpleado arrayEmpleados[],int indice)//listo
{
    char auxiliar[31];
    printf("Nombre nuevo: ");
    fflush(stdin);
    scanf("%s",auxiliar);
    strcpy(arrayEmpleados[indice].nombre,auxiliar);
}

void modificarApellido(eEmpleado arrayEmpleados[],int indice)//listo
{
    char auxiliar[31];
    printf("Apelldio nuevo: ");
    fflush(stdin);
    scanf("%s",auxiliar);
    strcpy(arrayEmpleados[indice].apellido,auxiliar);
}

void idMod(eEmpleado arrayEmpleados[],int indice)//listo
{
    printf("ID nuevo: ");
    fflush(stdin);
    scanf("%d",&arrayEmpleados[indice].id);
}

void modificarSector(eEmpleado arrayEmpleados[],int indice)//listo
{
    printf("Sector nuevo: ");
    fflush(stdin);
    scanf("%d",&arrayEmpleados[indice].sector);
}

void modificarSalario(eEmpleado arrayEmpleados[],int indice)//listo
{
    printf("Salario nuevo: ");
    fflush(stdin);
    scanf("%f",&arrayEmpleados[indice].salario);
}

int idUnico(eEmpleado arrayEmpleados[],int indice,int cantidad)
{
    int retorno = 0;
    int i,comparacion;
    printf("\nID: ");
    fflush(stdin);
    scanf("%d",&arrayEmpleados[indice].id);
    for(i=0;i<cantidad;i++)
    {
        if(arrayEmpleados[i].isEmpty == 0)
        {
            for(comparacion=i+1;comparacion<cantidad;comparacion++)
            {
                if((arrayEmpleados[comparacion].isEmpty == 0) && (arrayEmpleados[i].id == arrayEmpleados[comparacion].id))
                {
                    retorno = -1;
                }
            }
        }
    }
    return retorno;
}

void printEmployees(eEmpleado arrayEmpleados[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(arrayEmpleados[i].isEmpty == 0)
        {
            printf("\nLos datos del empleado son: \n");
            printf("Id: %d\t",arrayEmpleados[i].id);
            printf("Nombre: %s\t",arrayEmpleados[i].nombre);
            printf("Apellido: %s\n",arrayEmpleados[i].apellido);
            printf("Salario: %f\t",arrayEmpleados[i].salario);
            printf("Sector: %d\t",arrayEmpleados[i].sector);
        }
    }
}

void sortEmployees(eEmpleado arrayEmpleados[],int cantidad)
{
    int i;
    int comparacion;
    int contador=0;
    float totalSal,promedioSal;
    for(i=0;i<cantidad;i++)
    {
        if(arrayEmpleados[i].isEmpty == 0)
        {
            for(comparacion=i+1;comparacion<cantidad;comparacion++)
            {
                if((arrayEmpleados[comparacion].isEmpty==0) && (strcmp(arrayEmpleados[i].apellido,arrayEmpleados[comparacion].apellido)>0))
                {
                    intercambio(arrayEmpleados,i,comparacion);
                }
                else if((arrayEmpleados[comparacion].isEmpty==0) && (arrayEmpleados[i].sector<=arrayEmpleados[comparacion].sector))
                {
                    intercambio(arrayEmpleados,i,comparacion);
                }
            }
        }
    }
    printEmployees(arrayEmpleados,cantidad);
    for(i=0;i<cantidad;i++)
    {
        if(arrayEmpleados[i].isEmpty==0)
        {
            totalSal = totalSal + arrayEmpleados[i].salario;
            contador++;
        }
    }
    printf("\nSalario total: %f\n",totalSal);
    promedioSal = totalSal / contador;
    printf("Promedio de salarios: %f\n",promedioSal);
    contador=0;
    for(i=0;i<cantidad;i++)
    {
        if(arrayEmpleados[i].isEmpty==0 && arrayEmpleados[i].salario>promedioSal)
        {
            contador++;
        }
    }
    printf("Cantidad de empleados que superan el salario promedio: %d\n",contador);
}

void intercambio(eEmpleado arrayEmpleados[],int indice1,int indice2)
{
    eEmpleado aux;
    aux = arrayEmpleados[indice1];
    arrayEmpleados[indice1] = arrayEmpleados[indice2];
    arrayEmpleados[indice2] = aux;
}

int buscarId(eEmpleado arrayEmpleados[],int cantidad,int id)
{
    int i,retorno=-1;
    for(i=0;i<cantidad;i++)
    {
        if(arrayEmpleados[i].isEmpty == 0 && arrayEmpleados[i].id == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
