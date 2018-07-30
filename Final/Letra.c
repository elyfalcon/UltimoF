#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Letra.h"

eLetra* nueva_letra(void)
{
    eLetra* returnAux;
    returnAux = (eLetra*)malloc(sizeof(eLetra));
    return returnAux;
}
//+++++++++++++++++++++getters

char* letra_get_letra(eLetra* this)
{
    return this->letra;
}
char* letra_get_nombre(eLetra* this)
{
    return this->nombre;
}
int letra_get_vocal(eLetra* this)
{
    return this->vocal;
}
int letra_get_conson(eLetra* this)
{
    return this->consonante;
}

//  ------ SET -------
int eLetra_setLetra(eLetra* this, char *dato)
{
    this->letra=dato[0];
    return 0;
}

int eLetra_setNombre(eLetra* this, const char* dato)
{
    strcpy(this->nombre, dato);
    return 0;
}

int eLetra_setVocal(eLetra* this, int dato)
{
    this->vocal = dato;
    return 0;
}

int eLetra_setConsonante(eLetra* this, int dato)
{
    this->consonante = dato;
    return 0;
}

// --------- GETERS -------------------
char eLetra_getLetra(void * record)
{
    eLetra *tmp_1;
    tmp_1=(eLetra * ) record;

    return tmp_1->letra;
}




/*

//++++++++++++++++++++++++
int letra_set_vocal(eLetra* this, int dato)
{
    if(this!=NULL && dato !=NULL)
    {
        this->vocal = dato;
    }
    return 0;
}
int letra_set_nombre(eLetra* this, char* dato)
{
    strcpy(this->nombre,dato);
    return 0;
}
int letra_set_letra(eLetra* this, char* dato)
{
    strcpy(this->letra,dato);
    return 0;
}
int letra_set_conso(eLetra* this, int dato)
{
    if(this!=NULL && dato !=NULL)
    {
        this->consonante = dato;
    }
    return 0;
}
*/
