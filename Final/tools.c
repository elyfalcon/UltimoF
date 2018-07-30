#include <stdio.h>
#include <stdlib.h>

#include "Archivo.h"

int ValidarCantCaracteres(char* cadena,int cantidad)
{
    int longi,flag;
    longi=strlen(cadena);
    flag=0;
    if(longi<=cantidad)
    {
        flag=1;
    }
    return flag;
}
void RemoveSpaces(char* source)
{
  char* i = source;
  char* j = source;

  while(*j != 0)
  {
    *i = *j++;
    if(*i != ' ')
    {
    i++;
    }
  }
  *i = 0;
}
int ComparaFrases(char* frase1,char* frase2)
 {
    char aux[20]={};
    char aux2[20]={};
    printf("Ingrese una frase\n");
    gets(frase1);
    printf("Ingrese una frase\n");
    gets(frase2);
    RemoveSpaces(frase1);
    RemoveSpaces(frase2);
    strlwr(frase1);
    strlwr(frase2);
    printf("frase1:%s",frase1);
    printf("frase1:%s",frase2);
    if(strcmp(frase1,frase2)==0)
    {
        printf("ya ingreso esa frase:");
    }
    else
        printf("Son distintas");
}
int PedirEntero(char mensaje[])
{
    int auxiliar;

    do
    {
    printf("%s",mensaje);
    fflush(stdin);
    }while(scanf("%d",&auxiliar)==0);
    return auxiliar;
}
char Responder(char mensaje[])
{
    char resp;
    //int flag=-1;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",&resp);
    resp=toupper(resp);
    while(resp!='S'&& resp!='N')
    {
      printf("\nDebe ingresar S(si) N(no)\n");
      scanf("%s",&resp);
      resp=toupper(resp);
    }
    return resp;
}

void ValidaMenu(int opcion,int limite_inferior,int limite_superior)
{
     if(opcion <limite_inferior || opcion >limite_superior)
        printf("Debe elegir una opcion entre %d y %d: \n",limite_inferior,limite_superior);
}

void ShowMenu(char *opcion)
{
    system("cls");
    printf("MENU PRINCIPAL\n\n");
    printf("Ingrese una opcion: \n");
    printf("%s \n",opcion);
    printf("\n0.  Salir \n");
}
int funcionFiltro(void* aux)
{
    int retorno=0;
    void *emp;
    emp=(void * ) aux;

  //  if(prod_get_id(emp) > 20000)
    {
        retorno=1;
    }
    return retorno ;
}
int ingresarInt (char pregunta[], int minimo,int maximo)
{
    int numero;

    printf("%s\t", pregunta);
    fflush(stdin);
    scanf("%d", &numero);

    while(numero>maximo|| numero<minimo|| isalpha(numero))
    {
        fflush(stdin);
        printf("\nReingrese %s\t", pregunta);
        scanf("%d", &numero);
    }
    return numero;
}
/*eEmpleado* BuscaMaximo(ArrayList* this, int (*pFunc)(void* ,void*),int valor)
{
   int returnAux = -1;
    ArrayList* aux;
    int i=0;
    eEmpleado *emp;

    if(this!= NULL && pFunc!=NULL && (valor==0 || valor==1))
    {
        if(aux!=NULL)
        {
            aux=(al_get(this,i));
            for(i=1;i < al_len(this)-1;i++)
            {
                if(valor==1)
                {
                    if(pFunc(aux,al_get(this,i))==1)
                    {
                       emp=aux;
                       returnAux=0;
                    }//fin if(pfunc)
                    else
                    {
                        aux=al_get(this,i);
                        emp=aux;
                    }
                    }//fin if(valor)
                if(valor==0)
                {
                    if(pFunc(aux,al_get(this,i))==-1)
                    {
                        emp=aux;
                      //  aux=al_get(this,i);
                    }
                else
                {
                 aux=al_get(this,i);
                 emp=aux;
                }
                returnAux=0;

                }//fin if

            }//fin 1er for

          //  } //fin 2do for

        }//fin 1er for
    }
    return emp;

}*/
/*
int prod_buscarId(ArrayList* this, int cod)
{
    int retorno=0;
    int i;
    eProducto* prod;
    if(this!=NULL && cod >0)
    {
        if(this->isEmpty(this)==0)
       {
        retorno=1;
    //    if(prod !=NULL)
    //    {
            for(i=0;i<this->len(this);i++)
            {
            prod=this->get(this,i);
            if(prod_get_id(prod)==cod)
            {
                retorno=i;
                break;
            }//fin if
            else if(prod_get_id(prod)!=cod)
            {
                retorno=-1;
            }
            }//fin for
//        }//fin if(prod)
        }
    }//fin if(this!)
    return retorno;
}

int prod_mover(ArrayList* this,ArrayList* that,int id)
{
    int retorno=-1;
    eProducto* prod=NULL;
    if(this!=NULL && that!=NULL)
    {
        retorno=0;
      // prod = this->pop(this, this->indexOf(this, prod));
        prod = this->pop(this, id);
       if(prod!=NULL)
       {
           that->add(that,prod);
           this->sort(this,prod_comparaProducto,1);
           that->sort(that,prod_comparaProducto,1);
           printf("se movio correctamente\n");
           system("pause");
       }

        else
        {
            printf("No hay nada para mover\n");
            system("pause");
        }

    }
    return retorno;
}
int prod_BuscarYMover(ArrayList* this,ArrayList* that)
{
    int retorno=-1;
    int cod_prod,id,num_deposito;
    char resp;
    eProducto* prod;
    switch(vista_Pedir_Deposito(num_deposito))
    {
    case 0:
        vista_MostrarElementos(this,"Productos Deposito Nro 0",0,this->len(this));
        cod_prod=Valida_PedirEntero("Ingrese el Codigo del producto a mover:\n");
        if(cod_prod >0)
        {
            retorno=0;
            id=prod_buscarId(this,cod_prod);
            vista_Muestra1UnElemento(al_get(this,id));
            resp=Valida_confirmacion("Confirma mover este producto del deposito 0 al 1?");
            if(resp=='S')
            {
           // retorno=prod_mover(this,that,id);
            prod = this->pop(this, id);
            that->add(that,prod);
            this->sort(this,prod_comparaProducto,1);
            that->sort(that,prod_comparaProducto,1);
            printf("se movio correctamente\n");
            system("pause");
           // printf("retorno: %d",retorno);
           // system("pause");
           // retorno=1;
            }//fin if(resp)
        else
        {
            printf("Se cancelo la operacion:\n");
            retorno=2;
        }
    }//fin if(cod_prod)
    else
    {
        printf("Error no se encontro el codigo\n");
    }
    if(retorno=1)
    {
        printf("Se movio correctamente\n");
    }
    break;
    case 1:
        vista_MostrarElementos(that,"Productos Deposito Nro 1",0,that->len(that));
        cod_prod=Valida_PedirEntero("Ingrese el Codigo del producto a mover:\n");
        if(cod_prod >0)
        {
            retorno=0;
            id=prod_buscarId(that,cod_prod);
            vista_Muestra1UnElemento(al_get(that,id));
            resp=Valida_confirmacion("Confirma mover este producto del deposito 1 al 0?");
            if(resp=='S')
            {
           // retorno=prod_mover(this,that,id);
            prod = that->pop(that, id);
            this->add(this,prod);
            this->sort(this,prod_comparaProducto,1);
            that->sort(that,prod_comparaProducto,1);
            printf("se movio correctamente\n");
            system("pause");
           // printf("retorno: %d",retorno);
           // system("pause");
           // retorno=1;
            }//fin if(resp)
        else
        {
            printf("Se cancelo la operacion:\n");
            retorno=2;
        }
    }//fin if(cod_prod)
    else
    {
        printf("Error no se encontro el codigo\n");
    }
    if(retorno=1)
    {
        printf("Se movio correctamente\n");
    }
    break;
    }//fin switch

    return retorno;
}*/
/*
eEmpleado* BuscaMaximo(ArrayList* this, int (*pFunc)(void* ,void*),int valor)
{
   int returnAux = -1;
    ArrayList* aux;
    int i=0;
    eEmpleado *emp;

    if(this!= NULL && pFunc!=NULL && (valor==0 || valor==1))
    {
        if(aux!=NULL)
        {
            aux=(al_get(this,i));
            for(i=1;i < al_len(this)-1;i++)
            {
                if(valor==1)
                {
                    if(pFunc(aux,al_get(this,i))==1)
                    {
                       emp=aux;
                       returnAux=0;
                    }//fin if(pfunc)
                    else
                    {
                        aux=al_get(this,i);
                        emp=aux;
                    }

                    }//fin if(valor)
                if(valor==0)
                {
                    if(pFunc(aux,al_get(this,i))==-1)
                    {
                        emp=aux;
                      //  aux=al_get(this,i);
                    }
                else
                {
                 aux=al_get(this,i);
                 emp=aux;
                }
                returnAux=0;
                }//fin if
            }//fin 1er for
          //  } //fin 2do for
        }//fin 1er for
    }

    return emp;
}
*/
/*
int emp_buscarNombre(ArrayList* this, char nom[])
{
    int retorno=0;
    int i;
    eEmpleado* emp;
    if(this!=NULL && nom !=NULL)
    {
        if(this->isEmpty(this)==0)
       {
        retorno=1;
    //    if(emp !=NULL)
    //    {
            for(i=0;i<this->len(this);i++)
            {
            emp=this->get(this,i);
            if(get_Nombre(emp)==nom)
            {
                retorno=i;
                break;
            }//fin if
            else if(get_Nombre(emp)!=nom)
            {
                retorno=-1;
            }
            }//fin for
//        }//fin if(emp)
        }
    }//fin if(this!)
    return retorno;
}*/
void ingresarTexto (char texto[], int cantTexto, char pregunta[])
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
