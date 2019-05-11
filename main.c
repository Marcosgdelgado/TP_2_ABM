#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "herramientas.h"
#define TAM 10


int main()
{
    char seguir = 's';

    eSector sectores[5];
    cargarSectores(sectores);
    eEmpleado empleados[TAM];
    inicializarEmpleados(empleados,TAM);
    //harcodearEmpleados(empleados);

    do
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(empleados, TAM, sectores, 5);
            break;
        case 2:
            bajaEmpleado(empleados,TAM, sectores, 5);
            break;
        case 3:
            ModificarEmpleado(empleados, TAM, sectores, 5);
            system("pause");
            break;
        case 4:
            mostrarEmpleados(empleados, TAM, sectores, 5);
            system("pause");
            break;
        case 5:
            ordenarXSectorYNombre(empleados, TAM, sectores, 5);
            system("pause");
            break;
        case 6:
            mostrarEmpleadosMasGanadores(empleados, TAM, sectores, 5);
            system("pause");
            break;

        case 10:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("\n*** Menu de Opciones ***\n\n");
    printf(" 1-  Alta\n");
    printf(" 2-  Baja\n");
    printf(" 3-  Modificacion\n");
    printf(" 4-  Listar Empleados\n");
    printf(" 5-  Ordenar Empleados x Sector y Apellido\n");
    printf(" 6-  Listar empleados ganadores\n");
    printf(" 10- Salir\n\n");
    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
void cargarSectores(eSector sectores[])
{
    eSector sec[]=
    {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
    };

    for(int i=0; i < 5; i++)
    {
        sectores[i] = sec[i];
    }
}

