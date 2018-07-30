#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Letra.h"
#include "vista.h"
#include "Gestion.h"
#define NOM_ARCH "datos.csv"
#define NOM_ARCH2 "datos_comp.csv"
#define NOM_ARCH3 "datos_dupl.csv"
#define NOM_ARCH4 "datos_sin.csv"

int main()
{
    int opcion;
    char seguir='S';

    ArrayList *ListaLetras;
    ListaLetras=al_newArrayList();
    ArrayList *ListRepetidas;
    ListRepetidas=al_newArrayList();
    ArrayList *ListSinRepetir;
    ListSinRepetir=al_newArrayList();
    char texto[20];


    if(ListaLetras !=NULL)
    {

     while(seguir=='S')
     {
         vista_ShowMenu("1:Altas\n2:Completar\n3:Comprobar\n4:Generar y Listar Sin Repetir\n5:Generar y Listar Repetidos\n");
         scanf("%d",&opcion);
        ValidaMenu(opcion,0,5);
          switch(opcion)
            {
            case 1:
                cargarDesdeArchivo(ListaLetras,NOM_ARCH);
                vista_MuestraElementos(ListaLetras,"LISTADO DE LETRAS",vista_Muestra1UnElemento,0,ListaLetras->len(ListaLetras),25);
                break;
            case 2:
                gestion_Completar(ListaLetras,completa_VocalConsonante);
                vista_MuestraElementos(ListaLetras,"LISTADO DE LETRAS",vista_Muestra1UnElemento,0,ListaLetras->len(ListaLetras),25);
                GuardarArchivoT(ListaLetras,NOM_ARCH2);
                break;
            case 3:
                vista_ingresarTexto(texto,21,"Ingrese un texto");
               if(gestion_Existen_Letras(ListaLetras,gestion_compara_con_String,texto)==0)
                {
                    printf("Existen las letras\n");
                    system("pause");
                }
                else
                {
                    printf("No existen las letras\n");
                    system("pause");
                }
                break;
            case 4:
                ListSinRepetir=gestion_eliminaDuplicados(ListaLetras,gestion_ComparaLetra);
                if(ListSinRepetir !=NULL)
                {
                    vista_MuestraElementos(ListSinRepetir,"LISTADO DE LETRAS",vista_Muestra1UnElemento,0,ListSinRepetir->len(ListSinRepetir),25);
                    GuardarArchivoT(ListaLetras,NOM_ARCH4);
                }
                else if(ListSinRepetir == NULL)
                {
                    printf("Lista vacia\n");
                    system("pause");
                }
                break;
            case 5:
                ListRepetidas=gestion_Duplicados(ListaLetras,gestion_ComparaLetra);
                if(ListRepetidas != NULL)
                {
                    vista_MuestraElementos(ListRepetidas,"LISTADO DE LETRAS",vista_Muestra1UnElemento,0,ListRepetidas->len(ListRepetidas),25);
                    GuardarArchivoT(ListaLetras,NOM_ARCH3);
                }
                else if(ListRepetidas == NULL)
                {
                    printf("Lista vacia\n");
                    system("pause");
                }
                break;
            case 0:
                seguir='N';
                break;
                }//fin switch
     }//fin while
    }//fin if

    return 0;
}
