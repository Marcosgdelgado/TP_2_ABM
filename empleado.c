#include "empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "herramientas.h"

void inicializarEmpleados(eEmpleado lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        lista[i].isEmpty = 1;
    }
}

void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int tam)
{
    char descSector[20];

    obtenerSector(sectores, tam, unEmpleado.idSector, descSector);

    printf("%4d %10s %10s  %2c  %6.2f %10s\n", unEmpleado.legajo, unEmpleado.nombre,unEmpleado.apellido, unEmpleado.sexo, unEmpleado.sueldo, descSector);
}

void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamSector)
{

    system("cls");
    printf("Legajo   Nombre  Apellido  Sexo   Sueldo     Sector\n\n");

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 0)
        {
            mostrarEmpleado(lista[i], sectores, tamSector);
        }
    }

    printf("\n\n");


}


int buscarLibre(eEmpleado lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarEmpleado(eEmpleado lista[], int tam, int legajo)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].legajo == legajo && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;

}
void listarSectores(eSector sectores[], int tam)
{

    printf("Id  Descripcion\n\n");
    for(int i=0; i< tam; i++)
    {
        printf("%d   %10s\n", sectores[i].id, sectores[i].descripcion);

    }
    printf("\n\n");
}
void altaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector)
{
    int indice;
    int legajo;
    int existe;
    int idSector;
    char auxNombre[51];
    char auxApellido[51];
    char auxSexo;
    eEmpleado nuevoEmpleado;

    indice = buscarLibre(lista, tam);

    system("cls");
    printf("*** Alta empleado ***\n\n");

    if( indice == -1)
    {

        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        existe = buscarEmpleado(lista, tam, legajo);

        if( existe != -1)
        {

            printf("Ya existe un empleado con el legajo %d\n", legajo);
            //  mostrarEmpleado(lista[existe]);
            system("pause");

        }
        else
        {

            nuevoEmpleado.legajo = legajo;
            utn_getStringAvanzado(auxNombre,"Ingrese nombre\n","ERROR",51,3);
            strcpy(nuevoEmpleado.nombre,auxNombre);
            utn_getStringAvanzado(auxNombre,"Ingrese apellido\n","Error\n",51,3);
            strcpy(nuevoEmpleado.apellido,auxApellido);
            printf("Ingrese sexo: (m/f) ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);
            printf("Ingrese sueldo: ");
            scanf("%f", &nuevoEmpleado.sueldo);
            listarSectores(sectores, tamSector);
            printf("\nIngrese sector: ");
            scanf("%d", &idSector);
            nuevoEmpleado.idSector = idSector;
            nuevoEmpleado.isEmpty = 0;

            lista[indice] = nuevoEmpleado;

        }
    }

}


void bajaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector)
{

    int legajo;
    int indice;
    char seguir;

    system("cls");
    printf("  *** Baja empelado ***\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(lista, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado de legajo %d\n\n", legajo);
        system("pause");
    }
    else
    {
        mostrarEmpleado(lista[indice], sectores, tamSector);

        printf("\nConfima borrado s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Baja cancelada\n\n");

        }
        else

        {

            lista[indice].isEmpty = 1;
            printf("Borrado exitoso\n\n");
        }
        system("pause");
    }

}

void ModificarEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector)
{
    int legajo;
    int indice;
    char seguir;
    float nuevoSueldo;

    system("cls");
    printf("  *** Modificar  empleado ***\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(lista, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado de legajo %d\n\n", legajo);
        system("pause");
    }
    else
    {
        mostrarEmpleado(lista[indice], sectores, tamSector);

        printf("\nModifica sueldo? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);
            lista[indice].sueldo = nuevoSueldo;

            printf("Modificacion exitosa\n\n");
        }
        system("pause");
    }

}


/*void harcodearEmpleados(eEmpleado empleados[])
{

    eEmpleado x[]=
    {

        {1111, "juan", 'm', 23000,1,0},
        {2222, "luis", 'm', 18000, 1, 0},
        {1234, "ana", 'f', 21000, 5,0},
        {5643, "melisa", 'f', 24000, 2, 0},
        {2312, "mia", 'f', 34000, 3, 0},
        {7768, "mauro", 'm', 32000,5, 0},
        {1324, "alberto", 'm', 26000, 4,0},
        {9876, "valentina", 'f', 32000,5, 0}

    };

    for(int i=0; i < 8; i++)
    {

        empleados[i] = x[i];
    }




}*/

void obtenerSector(eSector sectores[], int tam, int idSector, char cadena[])
{

    for(int i=0; i < tam; i++)
    {

        if( sectores[i].id == idSector)
        {
            strcpy(cadena, sectores[i].descripcion);
        }
    }

}

void ordenarXSectorYNombre(eEmpleado x[],int tam, eSector sectores[], int tamSector)
{

    char descripcionI[20];
    char descripcionJ[20];
    eEmpleado auxEmpleado;

    for(int i=0; i<tam -1; i++)
    {
        for(int j = i +1; j < tam; j++)
        {
            obtenerSector(sectores, tamSector, x[i].idSector, descripcionI);
            obtenerSector(sectores, tamSector, x[j].idSector, descripcionJ);
            if( strcmp(descripcionI, descripcionJ) > 0)
            {
                auxEmpleado = x[i];
                x[i] = x[j];
                x[j] = auxEmpleado;
            }
            else if( strcmp(descripcionI, descripcionJ) == 0 && strcmp(x[i].apellido, x[j].apellido) > 0)
            {
                auxEmpleado = x[i];
                x[i] = x[j];
                x[j] = auxEmpleado;
            }
        }
    }
    printf("\nEmpleados ordenados con exito!!!\n\n");

}

void mostrarEmpleadosMasGanadores(eEmpleado x[],int tam, eSector sectores[], int tamSector)
{
    float maxSueldo;
    char descripcion[20];
    int flag;
    int flag2;

    system("cls");
    printf("\n*** Empleados que mas ganan por sector ***\n\n");

    for(int i=0; i < tamSector; i++)
    {

        obtenerSector(sectores, tamSector, sectores[i].id, descripcion);
        printf("Sector %s\n", descripcion);
        printf("--------------\n\n");
        flag = 0;
        flag2 = 0;
        for(int j=0; j < tam; j++)
        {
            if( (x[j].sueldo > maxSueldo && x[j].isEmpty == 0 && x[j].idSector == sectores[i].id) || flag == 0)
            {
                maxSueldo = x[j].sueldo;
                flag = 1;
            }

            if( x[j].isEmpty == 0 && x[j].idSector == sectores[i].id)
            {
                flag2 = 1;
            }

        }

        if(flag2 == 0)
        {
            printf("Sector Vacio\n");
        }
        else
        {

            for(int j=0; j < tam; j++)
            {
                if( x[j].sueldo == maxSueldo && x[j].isEmpty == 0)
                {
                    mostrarEmpleado(x[j], sectores, tamSector);
                }
            }

        }

        printf("\n\n");
    }
}
