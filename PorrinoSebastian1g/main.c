#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "juegos.h"
#include "clientes.h"
#include "alquileres.h"
#define TAM 5
int main()
{

    eCliente listClientes[TAM];
    initCliente(listEmployees,TAM);
    int ultimoId=1;
    int respuesta;
    char seguir;
    eCliente auxEcliente;

    do
    {

        switch(menu())
        {
        case 1:

            respuesta = getCliente(auxEmploye,listEmployees,TAM,ultimoId);
            if(respuesta == 0)
            {
                ultimoId++;
            }
            break;

        case 2:
            modifyCliente(listClientes,TAM);

            break;

        case 3:
            funtionRemoveCliente(listClientes,TAM);

            break;

        case 4:
        int sortCliente(eCliente list,len, order)

        }
        printf("Para salir ingrese 'n'\n");
        fflush(stdin);
        seguir=getche();
        system("cls");
    }
    while(seguir!='n');

    return 0;
}

