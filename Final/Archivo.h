#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"


#endif // ARCHIVO_H_INCLUDED

#define TIENE_ENCABEZADO 1

int cargarDesdeArchivo(ArrayList *this,const char* nombre);
int parserEstructura(FILE* pFile, ArrayList* this);
