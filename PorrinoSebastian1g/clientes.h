#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
{
  int codigoCliente;
  char nombre[51];
   char apellido[51];
   char sexo;
   int telefono[21];
   int isEmpty;
}eCliente;

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

int menuClientes();
int initCliente(eCliente list[],int len);
int searchFree(eCliente list[], int len);//busca libre
int addCliente(eCliente list[], int len, int codigoCliente, char name[51],char lastName[51],char sexo,int telefono);
int getCliente(eCliente aux,eCliente list[],int len,int codigoCliente);
eCliente newcliente(int codigoCliente, char name[51], char lastName[51], char sexo, int telefono);
int removeCliente(eCliente list[], int len, int codigoCliente);
int validationOfId(eCliente list[],int len,int codigoCliente);
int funtionRemoveCliente(eCliente list[], int len);
int findClienteId(eCliente list[], int len, int codigoCliente);
int printCliente(eCliente list[],int length);
int searcClienteActive(eCliente list[], int len);
int modifyCliente(eCliente list[], int len);
int sortCliente(eCliente list[], int len, int order);
