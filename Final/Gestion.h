#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED

ArrayList* Lista_Localidad(ArrayList* this);

ArrayList* al_eliminaDuplicados(ArrayList* this, int (*pFunc)(void* ,void*));
ArrayList* Gestion_Localidades(ArrayList* this);
int completa_VocalConsonante(eLetra * record);
int EsVocal(char Letra);
int gestion_Completar(ArrayList *this,int (*pFunc)(void*));
ArrayList* gestion_eliminaDuplicados(ArrayList* this, int (*pFunc)(void* ,void*));
int gestion_ComparaLetra(void* eLetraA,void* eLetraB);

#endif // GESTION_H_INCLUDED
