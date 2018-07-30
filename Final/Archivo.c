#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Letra.h"
#include "Archivo.h"

#define MASCARA_ARCHIVO "%[^,],%[^,],%[^,],%[^\n]\n"

#define TIENE_ENCABEZADO 1

int cargarDesdeArchivo(ArrayList *this,const char* nombre)
{
	int flag = 0;
	FILE *pArchivo;

    if(this !=NULL && nombre !=NULL)
    {
        pArchivo=fopen(nombre,"r");
        if(pArchivo != NULL)
        {
            flag=0;
		//pArchivo= fopen("nombre", "wb");
            if(parserEstructura(pArchivo,this)==0)
            {
                flag= 1;
                fclose(pArchivo);
            }
        }
    }
        if(flag ==1)
        {
	    printf("Carga Correcta:\n");
    system("pause");
        }
        else
        {
            printf("No se pudo cargar\n");
            system("pause");
        }
	return flag;

}

int parserEstructura(FILE* pFile, ArrayList* this)
{
    int retorno = -1;
    int cantidadFilasLeidas = 0;
//    int cantidadDatosLeidos;
    char cabecera[50];
    int guardoDato;
    eLetra* record;
    char letra[5];
    char nom[21];
    char vocal[5];
    char conso[5];


    if(pFile != NULL && this!=NULL)
    {
        retorno = -2;
        if(TIENE_ENCABEZADO == 1)
        {
            //descarto la lectura del encabezado
            fgets(cabecera, 80, pFile);
        }

        while(!feof(pFile))
        {
            retorno = 0;
            record = nueva_letra();
            if(record != NULL)
            {

                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",letra,nom,vocal,conso);
                    eLetra_setLetra(record,letra);
                    eLetra_setNombre(record,nom);
                    eLetra_setVocal(record,atoi(vocal));
                    eLetra_setConsonante(record,atoi(conso));
                al_add(this, record);
                cantidadFilasLeidas++;
            }
            else if(record==NULL)//Sin memoria
            {
                printf("No hay memoria suficiente:\n");
                system("pause");
                break;

            }
        }
    }
    return retorno;

}
//***********Manejo de archivo
/*
int data_actualizarArchivo(ArrayList* this,char* nom_archivo)
{
    int retorno=-1;
    FILE* pArch;
    eProducto* prod=NULL;
    int i,cantidad;

    if(this !=NULL && nom_archivo!=NULL)
    {
        pArch=fopen(nom_archivo,"w");
        if(pArch==NULL)
        {
            retorno=0;
        }//fin If(pArch==
            else
            {
       //     fprintf(pArch,"Producto,Descripcion,Cantidad\n");
            cantidad=this->len(this);
            for(i=0;i<cantidad;i++)
            {
               // prod=this->get(this,i);
                prod = (eProducto*)al_get(this, i);
                if(prod!=NULL)
                {
                    fprintf(pArch,"%d,%s,%d\n",prod_get_id(prod),prod_get_descripcion(prod),prod_get_cantidad(prod));
                    retorno=1;
                }//fin if(prod)
            }//fin for
        }//else (if pArch==
    }//fin if(nom_archivo)
    fclose(pArch);
    if(retorno==1)
        {
            printf("Se actualizo el archivo: %s correctamente\n",nom_archivo);
            system("pause");
        }
        else
        {
            printf("No se pudo actualizar el archivo: %s\n",nom_archivo);
            system("pause");
        }
        return retorno;
}
int data_borrarProducto(ArrayList* this,ArrayList* that)
{
    int retorno=-1;
    int cod_prod,indice;
    char resp;
    eProducto* prod;

    if(this !=NULL && that !=NULL)
    {
        retorno=0;
        cod_prod=Valida_PedirEntero("Ingrese el Codigo del producto a dar de baja:\n");
        if(cod_prod >0)
        {
            indice=prod_buscarId(this,cod_prod);
            prod=al_get(this,indice);
            if(prod ==NULL)
            {
             indice=prod_buscarId(that,cod_prod);
             prod=al_get(that,indice);
             retorno=1;
            }
            if(prod ==NULL)
            {
                printf("No se encontro el producto\n");
                vista_pausar();
            }
            else if(prod !=NULL)
            {
            vista_Muestra1UnElemento(prod);
            resp=Valida_confirmacion("Confirma dar de baja este producto?");
            if(resp=='N')
                {
                    printf("Operacion cancelada\n");
                }
                else if(resp=='S')
                {
                 //prod=this->pop(this,this->indexOf(this, prod));
                 if(retorno==1)
                 {
                  prod = that->pop(that, prod);
                  free(prod);
                  that->sort(that,prod_comparaProducto,1);
                  data_actualizarArchivo(that,NOM_ARCH2);
                 }
                 else
                 {
                    prod = this->pop(that, prod);
                    free(prod);
                    this->sort(this,prod_comparaProducto,1);
                    data_actualizarArchivo(this,NOM_ARCH);
                 }
                 retorno=1;
                }
            }//fin else prod !=NULL

         }//fin if(cod_prod)

    }//fin if(this)
    if(retorno==1)
    {
        printf("se dio de baja exitosamente:\n");
    }
    return retorno;
}

*/
/*
int arch_Alta_Empleado(ArrayList* this)
{
    int retorno=-1;
    int i,id;
    char resp;
    if(this !=NULL)
    {
        eEmpleado* emp;
        eEmpleado aux;
        retorno=0;
        do
        {
            tools_ShowTitulo("INGRESO EMPLEADOS");
            aux.id=tools_siguienteId(this,get_id);
            ingresarTexto(aux.nombre,20,"Ingrese el nombre: ");
            ingresarTexto(aux.direccion,25,"Ingrese la direccion: ");
            aux.horas=ingresarInt("cantidad horas trabajadas",80,200);
            emp=archivo_nuevoEmp(aux.id,aux.nombre,aux.direccion,aux.horas);

            if(emp !=NULL)
            {
                retorno=1;
                tools_ShowTitulo("Empleado Nuevo:");
                Muestra1UnElemento(emp);
                resp=Responder("Confirma el ingreso de este empleado?");
                if(resp=='N')
                {
                    printf("Operacion cancelada\n");
                    system("pause");
                }
                else if(resp=='S')
                {
                    this->add(this,emp);
                    this->sort(this,ComparaNombre,1);
                }

            }

        }while(Responder("Continua ingresando:")=='S');

    }//fin if(this !=NULL)
}
*/
ArrayList* al_filter3(ArrayList* this, int (*pFunc)(void*, char*), char* localidad)
{
    int i;
    int size=0;
    int* auxiliar;

    ArrayList*lista;
    int contador=0;

    if(this!=NULL&& pFunc!=NULL)
    {
        lista=al_newArrayList();
        auxiliar=(void*)malloc(sizeof(int));
        if (auxiliar !=NULL && lista!=NULL)
        {
            for (i=0; i<(this->len(this)); i++)
            {
                if(pFunc(*(this->pElements+i), localidad))
                {
                    auxiliar=al_get(this, i);
                    size++;
                    al_add(lista, auxiliar);

                }

            }

        } //for j
    }

    return lista;
}

int GuardarArchivoT(ArrayList* this, const char* nombre)
{
        int retorno=-1;
        int i;
        int tamanio=0;
        if(this!=NULL)
        {
            eLetra* emp;
            FILE *f;
            f=fopen(nombre, "w");
            if(f==NULL)
            {
                retorno=0;
            }
            else
            {
                if(emp !=NULL)
                {
                    tamanio=al_len(this);
                    for (i=0; i<tamanio; i++)
                    {
                    emp = (eLetra*)al_get(this, i);
                   // fprintf(f,"%d,%s,%s,%s,%s\n",prod_get_id(emp),prod_get_nombre(emp),prod_get_dire(emp),prod_get_localidad(emp),prod_get_recibe(emp));
                    fprintf(f,"%c\t%s\t%d\t%d\t\n",eLetra_getLetra(emp),letra_get_nombre(emp),letra_get_vocal(emp),letra_get_conson(emp));
                   // fprintf(f,"%d,%s,%s,%d,%d\n",emp->id,emp->nombre,emp->direccion,emp->horas,emp->sueldo);
                    retorno=1;
                    }//fin for
                    }//fin if(aux!=NULL)
                fclose(f);
            }//fin else
        }// fin if(!=null)
        if(retorno==1)
        {
            printf("Se creo el archivo %s correctamente\n",nombre);
            system("pause");
        }
        else
        {
            printf("No se pudo crear el archivo %s\n",nombre);
            system("pause");
        }

        return retorno;

}
/*int GuardarArchivoB(ArrayList* this,char nombrearchivo[])
{
    int retorno=-1;
    int i;

    if(this!=NULL)
    {
        eProducto* aux;
        FILE *f;

        f=fopen(nombrearchivo, "wb");
        if(f==NULL)
        {
            retorno=0;
        }
        else
        {
            int tamanio;
            tamanio=al_len(this);
            for (i=0; i<tamanio; i++)
            {
                aux = (eEmpleado*)al_get(this, i);
                fwrite(aux,sizeof(eEmpleado),1,f);
                retorno=1;
            }
            fclose(f);
        }
    }
    return retorno;
}
*/
/*int ComparaEntero(void* eEmpleadoA,void* eEmpleadoB)
{
    eEmpleado *retorno;
   // if (((eEmpleado*)eEmpleadoA)->sueldo >((eEmpleado*)eEmpleadoB)->sueldo)
    if(get_sueldo(eEmpleadoA)> get_sueldo(eEmpleadoB))
    {
      retorno=eEmpleadoA;
    }
  //      if (((eEmpleado*)eEmpleadoA)->sueldo <((eEmpleado*)eEmpleadoB)->sueldo)
  //  {
     // retorno=eEmpleadoB;

  //  }
    return retorno;

}
*/
