#include <stdio.h>
#include <stdlib.h>
#include "Archivo.h"
#include "Letra.h"
#include "ArrayList.h"


void vista_ShowMenu(char *opcion)
{
    int op;
    system("cls");
    printf("\n\n");
    printf("**********MENU PRINCIPAL**********\n\n");
    printf("Ingrese una opcion: \n");
    printf("%s \n",opcion);
    printf("\n0.  Salir \n");


}
void vista_ShowTitulo(char titulo[])
{
    printf("%s----\n\n",titulo);
}
int vista_Muestra1UnElemento(eLetra * prod)
{
    int retorno=-1;
    if(prod !=NULL)
    {
        retorno=0;
        printf("%c\t%s\t%d\t%d\t\n",eLetra_getLetra(prod),letra_get_nombre(prod),letra_get_vocal(prod),letra_get_conson(prod)); //definir una mascara


    }
    return retorno;
}
int vista_MuestraUnElementoLocalidad(void * prod)
{
    int retorno=-1;
    int i;
    void* local;
    if(prod !=NULL)
    {
        retorno=0;
      //  printf("%d\t%15s\n",local->id,prod->localidad);//,prod_get_nombre(prod),prod->direccion,,prod->recibe); //definir una mascara
       // printf("%d\t%s\t%d\n",prod_get_id(emp),/*emp->descrip*/prod_get_descripcion(emp),prod_get_cantidad(emp));

    }
    return retorno;
}

int vista_MuestraElementoLocalidad(void * local)
{
    int retorno=-1;
    int i;
  //  eLocalidad* local;
    if(local !=NULL)
    {
        retorno=0;
//        printf("%d\t%15s\n",local->id,local->localidad);//,prod_get_nombre(prod),prod->direccion,,prod->recibe); //definir una mascara
       // printf("%d\t%s\t%d\n",prod_get_id(emp),/*emp->descrip*/prod_get_descripcion(emp),prod_get_cantidad(emp));

    }
    return retorno;
}

void vista_MostrarElementos(ArrayList *this,char *Titulo,int desde, int hasta)
{
    int i;
    int cont_lineas=0;
   // if(this !=NULL && desde>=0 && hasta < this->len(this))
   if(this !=NULL)
    {
        system("cls");
        printf("\n\n--------%s--------\n\n",Titulo);
        //printf("\nId Producto\tDireccion\tLocalidad\tRecibe\n\n");
        vista_ShowTitulo("\nId\t Producto\t\t\tDireccion\\t\tLocalidad\tRecibe");
        if(this->isEmpty(this)==0)
        {//No esta vacio
            for(i=desde;i<hasta;i++)
            {
                vista_Muestra1UnElemento(al_get(this,i));
                cont_lineas++;
                if(cont_lineas==15)
                {
                    system("pause");
                   // cont_lineas=0;
                }
            }//fin for i
        }
      //  system("\npause");
        else
        {
            printf("Lista vacia\n");
            system("pause");
        }
    }
}
void vista_MostrarElementosLocalidad(ArrayList *this,char *Titulo,int desde, int hasta)
{
    int i;
    int cont_lineas=0;
   // if(this !=NULL && desde>=0 && hasta < this->len(this))
   if(this !=NULL)
    {
        system("cls");
        printf("\n\n--------%s--------\n\n",Titulo);
        //printf("\nId Producto\tDireccion\tLocalidad\tRecibe\n\n");
        vista_ShowTitulo("\n----------Localidad");
        if(this->isEmpty(this)==0)
        {//No esta vacio
            for(i=desde;i<hasta;i++)
            {
                vista_MuestraElementoLocalidad(al_get(this,i));
                cont_lineas++;
                if(cont_lineas==15)
                {
                    system("pause");
                   // cont_lineas=0;
                }
            }//fin for i
        }
      //  system("\npause");
        else
        {
            printf("Lista vacia\n");
            system("pause");
        }
    }
}

int vista_MuestraElementos(ArrayList *this,char *Titulo,int (*pFunc)(void*) ,int desde,int hasta,int paginado)
{
    int retorno=-1;
    int cont=0;
    if(this!=NULL && Titulo!=NULL)
    {
        retorno=0;
        system("cls");
        printf("\n\n-------- %s --------\n",Titulo);
        printf("\nLETRA\tNOMBRE\tVOCAL\tCONSONANTE\n\n");
        if(this->isEmpty(this)==0)
        {//No esta vacio

            for(int index=desde;index<hasta;index++)
            {
                if(cont!=0 && cont %paginado==0)
                {
                    system("pause");
                    system("cls");
                    printf("\n\n-------- %s --------\n",Titulo);
                }
                pFunc(al_get(this,index));
                cont++;
            }
            if(cont!=0)
            {//pausa la ultima tanda de elementos mostrados
                system("pause");
            }
        }//if(this->isEmpty(this)==0)
        else
        {//o con error o sin datos a mostrar
            printf("\n Sin Datos a Motrar...\n");
            system("pause");
        }
    }//if(this!=NULL && Titulo!=NULL)

    return retorno;
}
int vista_Pedir_Localidad(int choice)
{
    int retorno=0;
    system("cls");
    vista_ShowTitulo("\n\t\tGENERAR REPARTO EN LOCALIDADES\n");


    return retorno;
}
void vista_ingresarTexto (char texto[], int cantTexto, char pregunta[])
{
    char titulo [50];
    char auxtitulo [cantTexto-1];
    int i;

    printf("%s\t", pregunta);
    fflush(stdin);
    gets (titulo);
    for (i=0; i<cantTexto; i++)
    {
        auxtitulo[i]=titulo[i];
    }
    strcpy(texto, auxtitulo);
}
