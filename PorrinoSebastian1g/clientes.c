#include "clientes.h"

int menuClientes()// Menu de opciones para Clientes;
{
    int opcionCliente;

    system("cls");
    printf("****** ABM Clientes *******\n\n");
    printf(" 1-Alta Clientes\n");
    printf(" 2-Baja Clientes\n");
    printf(" 3-Modificar Clientes\n");
    printf(" 4-Listar Clientes\n");
    printf(" 5-Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcionCliente);

    return opcionCliente;
}


int initCliente(eCliente list[],int len)
{
    int flag=-1;
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty=1;
    }
    flag=1;

    return flag;

}

int searchFree(eCliente list[], int len)
{
    int indice=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==1)
        {
            indice=i;

            break;
        }
    }
}
int addCliente(eCliente list[], int len, int codigoCliente, char name[51],char lastName[51],char sexo,int telefono)
{
    int indice = searchFree(list, len);
    int todoOk=-1;

    system("cls");
    printf("****Alta Cliente****\n\n");

    if(indice==-1)
    {
        printf("Sistema lleno\n");
    }
    else
    {
        list[indice].codigoCliente = codigoCliente;
        strcpy(list[indice].nombre,nombre);
        strcpy(list[indice].apellido,apellido);
        strcpy(list[indice].sexo,sexo);
        list[indice].telefono = telefono;
        list[indice].isEmpty=0;

        todoOk = 0;
        printf("Alta exitosa!!\n\n");
    }
    return todoOk;

}
int getCliente(eCliente aux,eCliente list[],int len,int codigoCliente)
{



    char nombre[51];
    char apellido[51];
    char sexo;
    int telefono;
    int validaNumero;

    system("cls");
    printf("****Alta Cliente****\n");

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nombre);
    while(strlen(nombre)<=0)
    {
        printf("Nombre Incorrecto. Ingrese nombre: ");
        gets(nombre);
    }

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(apellido);
    while(strlen(apellido)<=0)
    {
        printf("Apellido Incorrecto. Ingrese apellido: ");
        gets(apellido);
    }

    printf("Ingrese Sexo: ");
    fflush(stdin);
    gets(sexo);
    while(strlen(sexo)<=0 )
    {
        printf("Incorrecto, reingrese sexo");
        fflush(stdin);
        gets(sexo);
    }

    printf("Ingrese Telefono: ");
    validaNumero = scanf("%d",&telefono);
    while(validaNumero != 1)
    {
        printf("Incorrecto, ingrese Telefono: ");
        fflush(stdin);
        validaNumero = scanf("%d",&telefono);
    }

    int resultado=addEmployee(list,len,codigoCliente,nombre,apellido,sexo,telefono);

    printEmployees(list,len);

    return resultado;
}



int findClienteId(eCliente list[], int len, int codigoCliente)
{
    int lastCodigo=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0 && list[i].codigoCliente==codigoCliente)
        {
            printf("%d %10s %10s %10S %3d\n")list.codigoCliente,list[i].nombre,list[i].apellido,list[i].sexo,list[i].telefono);
            lastCodigo=i;
            break;
        }
    }
    return lastCodigo;
}






int removeCliente(eCliente list[], int len, int codigoCliente)
{
    int flag=-1;
    for(int i=0; i<len; i++)
    {
        if(list[i].codigoCliente==codigoCliente)
        {
            list[i].isEmpty=1;
            flag=0;
            break;
        }
    }
    return flag;
}
int validationOfId(eCliente list[],int len,int codigoCliente)
{
    int ok;

    for(int i=0; i<len; i++)
    {
        if(list[i].codigoCliente == codigoCliente && list[i].isEmpty == 0)
        {
            ok=1;
            break;
        }
        else
        {
            ok=0;
        }
    }

    return ok;
}
int funtionRemoveCliente(eCliente list[], int len)
{
    int idClienteRemove;
    int flag1=0;
    int flagId=0;
    char confirmacion;
    int resultado;

    int validaNumeroClientes;
    validaNumeroClientes = searchEmloyeeActive(list,len);
    if(validaNumeroClientes >=1)
    {

        printf("****Baja Cliente****\n\n");
        printEmployees(list,len);
        printf("Ingrese el Codigo del cliente a eliminar:\n");
        flag1 = scanf("%d",&idClienteRemove);
        flagId = validationOfId(list,len,idClienteRemove);
        if(flag1 && flagId)
        {
            printf("El Cliente es: \nCODIGO   NOMBRE       APELLIDO      SEXO    TELEFONO\n");
            findEmployeeById(list,len,idClienteRemove);

            printf("Confirme eliminacion. Ingrese n para anular: ");
            fflush(stdin);
            confirmacion = getche();
            if(confirmacion !='n')
            {
                resultado = removeCliente(list,len,idClienteRemove);
                if(resultado == 0)
                {
                    printf("\nBaja exitosa!!!\n");
                }
                else
                {
                    printf("\n No pudo concretarce la baja\n");
                }
            }
            else
            {
                printf("\nOperacion anulada\n");

            }
        }
        else
        {
            printf("\nEl codigo ingresado no existe\n");
        }
    }
    else
    {
        printf("Primero ingrese al punto 1, no hay empleados para eliminar\n\n");
    }

    return 0;
}
int printCliente(eCliente list[],int length)
{
    int flag=-1;
    printf("ID\tNOMBRE\tAPELLIDO\tSEXO\t  TELEFONO\n");
    for(int i=0; i<length; i++)
    {
        if(list[i].isEmpty==0)
        {
            findClienteId(list,length,list[i].codigoCliente);
            flag=0;
        }
    }
    return flag;

}

int searcClienteActive(eCliente list[], int len)
{


    int indice=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            indice=i;
        }
    }

    return indice+1;

}
int modifyCliente(eCliente list[], int len)
{

    int validaNumeroClientes;

    validaNumeroCliente = searcClienteActive(list,len);
    if(validaNumeroClientes >=1)
    {

        printf("%d",searcClienteActive(list,len));
        printf("****Modificar Cliente***\n\n");
        char seguirModificacion;
        int opcionCodigoCliente;
        char opcionModificar;
        char nombre[51];
        char apellido[51];
        char sexo;
        int telefono;
        int validaNumero;
        int idAModificar;
        int validaSiEsNumero;

        printEmployees(list,len);
        printf("Ingrese el codigo de cliente a modificar: ");
        validaSiEsNumero = scanf("%d",&opcionCodigoCliente);

        if(validationOfId(list,len,opcionCodigoCliente) && validaSiEsNumero)
        {
            printf("El usuario ingresado es: \n");

            idAModificar=findClienteId(list,len,opcionCodigoCliente);

            printf("\nDesea modificar este usuario? elija s o n \n");
            fflush(stdin);
            scanf("%c",&seguirModificacion);

            if(seguirModificacion=='s')
            {
                printf("Para modificar nombre ingrese s: \n");
                fflush(stdin);
                scanf("%c",&opcionModificar);

                if(opcionModificar=='s')
                {
                    printf("Ingrese el nuevo nombre: ");
                    fflush(stdin);
                    gets(nombre);
                    strcpy(list[idAModificar].nombre,nombre);
                    printf("Nombre modificado con exito\n");

                }
                printf("Para modificar apellido ingrese s: ");
                fflush(stdin);
                scanf("%c",&opcionModificar);

                if(opcionModificar=='s')
                {
                    printf("Ingrese el nuevo apellido: ");
                    fflush(stdin);
                    gets(apellido);
                    strcpy(list[idAModificar].apellido,apellido);
                    printf("Apellido modificado con exito\n");
                }
                printf("Para modificar el sexo ingrese s: ");
                fflush(stdin);
                scanf("%c",&opcionModificar);



                printf("Para modificar el telefono ingrese s: ");
                fflush(stdin);
                scanf("%c",&opcionModificar);

                if(opcionModificar=='s')
                {
                    printf("Ingrese el nuevo telefono: ");
                    scanf("%d",&telefono);
                    list[idAModificar].telefono=telefono;
                    printf("telefono modificado con exito\n");
                }

            }
            else
            {
                printf("ID incorrecto\n");
            }
        }
        else
        {
            printf("Primero ingrese en el punto 1, no hay empleados para modificar\n\n");
        }
        return 0;
    }

    int sortCliente(eCliente list[], int len, int order)
    {
        eCliente auxiliar;
        int flag=-1;

        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(order==0)
                {
                    if(strcmp(list[i].apellido,list[j].apellido)>0)
                    {
                        auxiliar=list[i];
                        list[i]=list[j];
                        list[j]=auxiliar;
                        flag=0;
                    }
                    else
                    {
                        if(strcmp(list[i].apellido,list[j].apellido)==0)
                        {
                            if(list[j].nombre < list[i].nombre)
                            {
                                auxiliar=list[i];
                                list[i]=list[j];
                                list[j]=auxiliar;
                                flag=0;
                            }
                        }
                    }
                }
                else if(order==1)
                {
                    if(strcmp(list[j].apellido,list[i].apellido)>0)
                    {
                        auxiliar=list[j];
                        list[j]=list[i];
                        list[i]=auxiliar;
                        flag=0;
                    }
                    else
                    {
                        if(strcmp(list[j].apellido,list[i].apellido)==0)
                        {
                            if(list[i].nombre < list[j].nombre)
                            {
                                auxiliar=list[j];
                                list[j]=list[i];
                                list[i]=auxiliar;
                                flag=0;
                            }
                        }
                    }
                }
            }
        }

        return flag;
    }
