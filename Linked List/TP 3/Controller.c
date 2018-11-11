#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "BibliotecaFunciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;

    pArchivo = fopen(path,"r");
    if(!parser_EmployeeFromText(pArchivo, pArrayListEmployee))
    {
        printf("Carga Exitosa!!!\n");
        retorno = 0;
    }
    else
    {
        printf("No se encontro un archivo de texto");
    }
    fclose(pArchivo);
    system("pause");
    return retorno;
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    pFile = fopen(path, "rb");
    if(pFile != NULL && parser_EmployeeFromBinary(pFile, pArrayListEmployee) == 0)
    {
        printf("Datos Cargados!\n");
        retorno = 0;
    }
    else
    {
        printf("Error!  No se pudieron cargar los datos!\n");
    }
    fclose(pFile);
    return retorno;
}

/** \brief Da de alta empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

    int retorno = -1;
    if(employee_cargarEmployee(pArrayListEmployee) == 0)
    {
         printf("Empleado cargado exitosamente\n");
        retorno = 0;
    }
    else
    {
        printf("Error!  No se pudo cargar el empleado!\n");
    }
    return retorno;
}

/** \brief Modificar  los datos de un empleado por Id
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(employee_modificarEmployee(pArrayListEmployee) == 0)
    {
        system("cls");
        printf("Modificacion Exitosa!\n");
        retorno = 0;
    }
    else
    {
        printf("Error!  No se pudo modificar el empleado\n");
    }
    return retorno;
}

/** \brief Da de baja un empleado por Id
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno =- 1;
    if(employee_borrarEmployee(pArrayListEmployee) == 0)
    {
        printf("Eliminacion Exitosa!");
        retorno=0;
    }
    else
    {
        printf("Error!  No se pudo dar de baja el empleado!\n");
    }
    return retorno;
}

/** \brief Muestra los empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    char nombre[128];
    int id;
    int sueldo;
    int horasTrabajadas;
    int size;
    size = ll_len(pArrayListEmployee);
    Employee* auxPunteroEmpleado;

    if(pArrayListEmployee != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(pArrayListEmployee);i++)
        {

             if(i%32==0)
            {

            system("pause");
            auxPunteroEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(auxPunteroEmpleado,&id);
            employee_getName(auxPunteroEmpleado,nombre);
            employee_getSalary(auxPunteroEmpleado,&sueldo);
            employee_getHoursWorked(auxPunteroEmpleado,&horasTrabajadas);

            printf("\n-----------------");
            printf("\nID: %d\nNombre: %s\nSueldo: %d\nHoras trabajadas: %d",id,nombre,sueldo,horasTrabajadas);
            printf("\n-----------------\n");
            }
            else
            {
            auxPunteroEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(auxPunteroEmpleado,&id);
            employee_getName(auxPunteroEmpleado,nombre);
            employee_getSalary(auxPunteroEmpleado,&sueldo);
            employee_getHoursWorked(auxPunteroEmpleado,&horasTrabajadas);

            printf("\n-----------------\n");
            printf("\nID: %d",id);
            printf("\nNombre: %s",nombre);
            printf("\nSueldo: %d",sueldo);
            printf("\nHoras trabajadas: %d",horasTrabajadas);
            printf("\n-----------------\n");
            printf("\n");


            }

        }

        printf("\nCantidad de Empleados: %d. \n" , size);
    }
    system("pause");
    return retorno;

}


/** \brief Ordenar empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno
 */

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee , employee_ordenarPorName,1);
        printf("\nLos empleados fueron ordenados por nombre exitosamente!!\n");
        retorno = 0;
    }
    else
    {
        printf("Error!  No se pudo ordenar!\n");
    }
    return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(employee_guardarDatosenTexto(pArrayListEmployee, path) == 0)
    {
        printf("Datos guardados Exitosamente!\n");
        retorno = 0;
    }
    else
    {
         printf("Error!  No se pudieron guardar los datos!\n");
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(employee_guardarDatosenBinario(pArrayListEmployee, path)==0)
    {
        printf("Los datos se guardaron correctamente\n");
        retorno = 0;
    }
    else
    {
        printf("Error! No se pudieron guardar los datos!\n");
    }
    return retorno;
}

