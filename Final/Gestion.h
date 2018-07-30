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
void gestion_verifica(ArrayList* this, char* palabra );
int gestion_compara_con_String(void* letra,void* pElement);
int gestion_Existen_Letras(ArrayList* this , int (*functionFilter)(void* ,void*),char * cadLetras);
int compara_elementos_Estructura(void* pElementA,void* pElementB);

#endif // GESTION_H_INCLUDED
