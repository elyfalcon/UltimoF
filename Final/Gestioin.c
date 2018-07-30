#include <stdio.h>
#include <stdlib.h>

#include "Archivo.h"
#include "ArrayList.h"
#include "vista.h"
#include "Letra.h"
#include "tools.h"
#include "Gestion.h"

ArrayList* Lista_Localidad(ArrayList* this)
{
    int i;
    char local[25];
    ArrayList *ListAux;
    ArrayList *ListOrdenada;
    ListAux=NULL;
    ListOrdenada=NULL;
    if(this!=NULL)
    {
        ListAux=al_newArrayList();
        ListOrdenada=al_clone(this);
        void* prod;
        if(ListAux !=NULL)
        {
          //  ListOrdenada->sort(ListOrdenada,prod_ComparaLocalidad,1);
        }
    for(i=0;i<ListOrdenada->len(ListOrdenada);i++)
    {
     prod=this->get(this,i);
//     local=prod[i]->localidad;

   //  if(prod->localidad==local))
     {
         al_add(ListAux,prod);
     }

    }//fin for
    }//fin if(this!=NULL)
    return ListAux;
}



ArrayList* al_eliminaDuplicados(ArrayList* this, int (*pFunc)(void* ,void*))
{
    ArrayList* ListAux;
    if(this!= NULL && pFunc!=NULL )
    {
        ListAux=al_clone(this);
        if(ListAux!=NULL)
        {
            for(int i=0; i< ( ListAux->len(ListAux) ) -1 ;i++)
            {
                for(int j=i+1;j < ListAux->len(ListAux) ; )
                {
                    if(pFunc(al_get(ListAux,i),al_get(ListAux,j))==0)
                    {
                      ListAux->pop(ListAux,j);
                    }
                    else
                    {
                        j++;
                    }
                }//FIN for(int j=i+1;j < ListAux->len(ListAux) ;j++)
            }//FIN for(int i=0; i< ( ListAux->len(ListAux) ) -1 ;i++)
        }
    }
    return ListAux;
}
ArrayList* gestion_eliminaDuplicados(ArrayList* this, int (*pFunc)(void* ,void*))
{
    ArrayList* ListAux;
  //  ArrayList* ListDupl;
    if(this!= NULL && pFunc!=NULL )
    {
        ListAux=al_clone(this);
     //   ListDupl=al_newArrayList();
        if(ListAux!=NULL)
        {
            for(int i=0; i< ( ListAux->len(ListAux) ) -1 ;i++)
            {
                for(int j=i+1;j < ListAux->len(ListAux) ; )
                {
                    if(pFunc(al_get(ListAux,i),al_get(ListAux,j))==0)
                    {

                     ListAux->pop(ListAux,j);
                    }
                    else
                    {
                        j++;
                    }
                }//FIN for(int j=i+1;j < ListAux->len(ListAux) ;j++)
            }//FIN for(int i=0; i< ( ListAux->len(ListAux) ) -1 ;i++)
        }
                ListAux->sort(ListAux,compara_elementos_Estructura,1);
          }
    return ListAux;
}
ArrayList* gestion_Duplicados(ArrayList* this, int (*pFunc)(void* ,void*))
{
    ArrayList* ListAux;
    ArrayList* ListDupl;
    if(this!= NULL && pFunc!=NULL )
    {
        ListAux=al_clone(this);
        //ListDupl=al_newArrayList();
        if(ListAux!=NULL)
        {
            for(int i=0; i< ( ListAux->len(ListAux) ) -1 ;i++)
            {
                for(int j=i+1;j < ListAux->len(ListAux);j++ )
                {
                    if(pFunc(al_get(ListAux,i),al_get(ListAux,j))==0)
                    {

                    }
                    else
                    {
                    ListAux->pop(ListAux,j);
                    j=i+1;
                    }
                }//FIN for(int j=i+1;j < ListAux->len(ListAux) ;j++)
            }//FIN for(int i=0; i< ( ListAux->len(ListAux) ) -1 ;i++)
        }
        ListAux->sort(ListAux,compara_elementos_Estructura,0);
    }
    return ListAux;
}





int EsVocal(char Letra)
{
    int retorno=-1;
    if(isalpha(Letra))
    {
        retorno=0;
        Letra=toupper( Letra );
        if(Letra=='A'||Letra=='E'||Letra=='I'||Letra=='O'||Letra=='U')
        {
            retorno=1;
        }
    }
    return retorno;
}
int completa_VocalConsonante(eLetra * record)
{
    int retorno=-1;
    if(record !=NULL)
    {

        if( EsVocal(eLetra_getLetra(record) ) ==1 )
        {
            retorno= eLetra_setVocal(record, 1);
        }
        else if( EsVocal(eLetra_getLetra(record) ) ==0 )
        {
            retorno= eLetra_setConsonante(record, 1);
        }
    }
    //system("pause");
    return retorno;
}
int gestion_Completar(ArrayList *this,int (*pFunc)(void*) )
{
    int retorno=-1;
    int i;
    if(this!=NULL )
    {
        retorno=-2;

        if(this->isEmpty(this)==0)
        {//No esta vacio
            for(i=0; i<this->len(this) ; i++)
            {
                retorno=pFunc(al_get(this,i));

            }
        }//if(this->isEmpty(this)==0)

    }//if(this!=NULL && Titulo!=NULL)
    return retorno;
}
int compara_elementos_Estructura(void* pElementA,void* pElementB)
{
    int retorno;
    eLetra *tmp_1;
    eLetra *tmp_2;
    tmp_1=(eLetra * ) pElementA;
    tmp_2=(eLetra * ) pElementB;

    if(tmp_1->letra > tmp_2->letra)
    {
        retorno=1;
    }
    else
    {
        retorno=-1;
        if(tmp_1->letra < tmp_2->letra)
        {
            retorno=0;
        }
    }
    return retorno;
}


/*
ArrayList* al_eliminaDuplicados(ArrayList* this, int (*pFunc)(void* ,void*))
{
    ArrayList* ListAux;
    int i,j;

    if(this!= NULL && pFunc!=NULL )
    {
        ListAux=al_clone(this);
        if(ListAux!=NULL)
        {
            for(i=0;i < ListAux->len(ListAux) -1 ;i++)
            {
                for(j=i+1 ;j<ListAux->len(ListAux); )
                {

                    if(pFunc( al_get(ListAux,i), al_get (ListAux,j ) ) ==0)
                    if(pFunc( al_get(ListAux,i), al_get (ListAux,j )  ==0 ) )
                    {
                      ListAux->pop(ListAux,j);
                    }
                    else
                    {
                        if(pFunc( al_get(ListAux,i),al_get(ListAux,j )== -2 ))
                        {
                              printf("\n ERROR \n");
                              system("pause");
                        }
                        else
                        {
                            j++;
                        }

                    }//fin if(pfunc)
                }//fin 1er for
            }//fin 2 for
        }//fin 1er for
    }
   return ListAux;
}
*/

/*int gestion_quita_duplicados(void* eProductoA,void* eProductoB)
{
    int retorno=-1;
    int i,j;


    for(i=0;i<this->len(this);i++)
    {
        for(j=i+1;j<this->len(this)-1;j++)
        {
            if(prod_ComparaLocalidad())
        }


    }//fin for(i=


}*/
/*ArrayList* Gestion_Localidades(ArrayList* this)
{
    eProducto *auxprod;

    ArrayList* ListLocal;
    eLocalidad *auxlocal;
    char *localidad;

    int i;
    int cant;
    if(this!= NULL)
    {
        ListLocal=al_newArrayList();
        if(ListLocal!=NULL)
        {
            cant=this->len(this);
            for(i=0;i < cant ;i++)
            {
                auxprod=(al_get(this,i));//Obtengo producto
                localidad=prod_get_localidad(auxprod); //localidad del producto

                auxlocal=nueva();
                localidad_set_localidad(auxlocal,localidad);//cargo localidad en Recorset de localidades
                localidad_set_id(auxlocal,i+1);
                al_add(ListLocal,auxlocal); //Agrego el recorseet de localidades al ArrayList de localidades
            }//fin 1er for
        }//fin if(ListLocal!=NULL)
    }//fin if(this!= NULL)
    return ListLocal;
}

int gestion_buscarNombre(ArrayList* this, char nom[])
{
    int retorno=0;
    int i;
    eProducto* emp;
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
            if(prod_get_localidad(emp)==nom)
            {
                retorno=i;
                break;
            }//fin if
            else if(prod_get_localidad(emp)!=nom)
            {
                retorno=-1;
            }
            }//fin for
//        }//fin if(emp)
        }
    }//fin if(this!)
    return retorno;
}

int gestion_BuscarYGuardar(ArrayList* this,ArrayList* that)
{
    int retorno=-1;
    char nombre[25];
    int i,cod_prod,id,num_deposito,num;
    char resp;
    eProducto* prod;
    eLocalidad* local;
    ArrayList* Listreparto;

    if(this !=NULL && that!=NULL)
    {
        vista_MostrarElementosLocalidad(that,"LISTADO DE LOCALIDADES",0,that->len(that));
        num=ingresarInt("\Ingrese Nro que Desea Imprimir", 1, that->len(that));
        local=al_get(that,num-1);
        strcpy(nombre,local->localidad );
        //strcpy(nombre,(al_get(that,(num))) );
        Listreparto=al_filter3(this,prod_compareconLocalidad,nombre);
        if(Listreparto !=NULL)
        {
         strcat(nombre,".csv");
          al_MuestraElementos(Listreparto,"REPARTO DE LOCALIDADES",vista_Muestra1UnElemento,0,Listreparto->len(Listreparto),25);
          GuardarArchivoT(Listreparto,nombre);
        }
        else if(Listreparto==NULL)
        {
            printf("Lista vacia\n");
            system("pause");
        }

    }





  }*/

  int gestion_ComparaLetra(void* eLetraA,void* eLetraB)
{//-2 ERROR  y espues el standaroutput de strcmp
    int retorno=-2;
    eLetra *prd_1;
    eLetra *prd_2;

    if(eLetraA!=NULL && eLetraB!=NULL)
    {
        prd_1=(eLetra * ) eLetraA;
        prd_2=(eLetra * ) eLetraB;
        if(prd_1->letra == prd_2->letra)
       // retorno=strcmp( prd_1->letra,prd_2->letra );
       retorno=0;
    }
    return retorno;
}

int gestion_Existen_Letras(ArrayList* this , int (*functionFilter)(void* ,void*),char * cadLetras)
{//devuelve 1 si estan todas las letras.. 0 si no estan.

    int retorno=-1;
    if(this!=NULL && functionFilter!=NULL && cadLetras!=NULL )
    {
        retorno=1;

        for(int i=0;i<strlen(cadLetras);i++)
        {
            for(int j=0;j<this->len(this);j++)
            {
                if( functionFilter(cadLetras[i],this->get(this,j) )== 0 )
                {//Existe=0    NO esta la letra
                    retorno=0;
                    break;
                }
            }//fin for recorre ArrayList
        }//fin for recorre caracteres string
        return retorno;
    }
}
int gestion_compara_con_String(void* letra,void* pElement)
{
    int retorno;
    eLetra *tmp_1;
    tmp_1=(eLetra * ) pElement;
    char Aux=(char) letra;
    //char letra;

    if(tmp_1->letra > Aux)
    {
        retorno=1;
    }
    else
    {
        retorno=-1;
        if(tmp_1->letra == Aux)
        {
            retorno=0;
        }

    }
    return retorno;
}
/*void gestion_verifica(ArrayList* this, char* palabra )
{
    int retorno=0;
    eLetra* aux1=NULL;
    eLetra* aux2=NULL;
    int i,j;
    int existe=0;
    int longitud;
    ArrayList*aux;
    int auxiliarCuenta;


    if(this!= NULL)
    {
        aux=al_clone(this);
        auxiliarCuenta=aux->len(aux);

        if(aux!= NULL)
        {
            longitud=strlen(palabra);

            for (i=0; i<longitud; i++)
            {
                for (j = 0; j < auxiliarCuenta ; j++)
                {
                    aux1=(eLetra*)al_get(aux,j);

                    if(aux1!=NULL)
                    {
                        if (palabra[j]==letra_get_letra(aux1))
                        {
                            existe++;
                           al_remove(aux,j);
                            auxiliarCuenta--;
                            break;
                        }

                    }
                }
            }
            if (existe ==longitud)
            {
                printf("\nSE PUEDE FORMAR");
                system("pause");

            }
            else if(existe != longitud)
            {
                printf("\nNO SE PUEDE FORMAR");
                system("pause");
            }

        }// fin (if aux
    }//fin if(this !=

}
*/
