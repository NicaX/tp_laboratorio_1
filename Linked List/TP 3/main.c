#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "BibliotecaFunciones.h"

int main()
{
    int opcion = 0;
    //holamundo
    LinkedList* listaEmpleadosMain = ll_newLinkedList();
    do{

        printf("\n                                  Bienvenido!                                           "
            "\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)"
            "\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados \n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)"
            "\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n10. Eliminar LinkedList\n11. Salir\nIngrese una opcion (1/11): ");
        scanf("%d" , & opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                controller_loadFromText("data.csv",listaEmpleadosMain);
                break;
            case 2:
                system("cls");
                controller_loadFromBinary("data.bin", listaEmpleadosMain);
                system("pause");
                break;
            case 3:
                system("cls");
                controller_addEmployee(listaEmpleadosMain);
                system("pause");
                break;
            case 4:
                system("cls");
                controller_editEmployee(listaEmpleadosMain);
                system("pause");
                break;
            case 5:
                system("cls");
                controller_removeEmployee(listaEmpleadosMain);
                system("pause");
                break;
            case 6:
                system("cls");
                controller_ListEmployee(listaEmpleadosMain);
                break;
            case 7:
                system("cls");
                controller_sortEmployee(listaEmpleadosMain);
                system("pause");
                break;
            case 8:
                system("cls");
                controller_saveAsText("data.csv", listaEmpleadosMain);
                system("pause");
                break;
            case 9:
                system("cls");
                controller_saveAsBinary("data.bin", listaEmpleadosMain);
                system("pause");
                break;
            case 10:
                system("cls");
                ll_deleteLinkedList(listaEmpleadosMain);
                system("pause");
            break;
        }
        system("cls");  //limpia
    }while(opcion != 11);

    return 0;
}
