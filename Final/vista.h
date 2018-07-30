#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Letra.h"


void vista_ShowMenu(char *opcion);
void vista_ShowTitulo(char titulo[]);
int vista_MuestraUnElemento(void * emp);
int vista_Muestra1UnElemento(eLetra * prod);
void vista_MostrarElementos(ArrayList *this,char *Titulo,int desde, int hasta);
//void vista_MostrarElementos(ArrayList *this,char *Titulo,int desde, int hasta);
//int vista_MuestraUnElementoLocalidad(eProducto * prod);
//void vista_MostrarElementosLocalidad(ArrayList *this,char *Titulo,int desde, int hasta);
int vista_MuestraElementos(ArrayList *this,char *Titulo,int (*pFunc)(void*) ,int desde,int hasta,int paginado);
//int vista_MuestraElementoLocalidad(eLocalidad * local);



#endif // VISTA_H_INCLUDED
