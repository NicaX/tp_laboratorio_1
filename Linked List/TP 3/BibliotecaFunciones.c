#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BibliotecaFunciones.h"
#include <ctype.h>

static int obtenerChar(char* pBufferString,int limite);
static int obtenerEntero(int* pResultado);
static int obtenfloat(float* pResultado);
static int esFlotante(char* pBuffer);
int esLetra(char* pBuffer);
int EnteroConGuiones(char* pBuffer);
int esEntero(char* pBuffer);

int ObtenerName(char* pNombre, char* msg, char* msgError)
{
    int retorno = -1;
    int max=50;
    char bufferString[max];
    if(pNombre != NULL && msg != NULL && msgError != NULL)
    {
        printf("%s", msg);
        if(obtenerChar(bufferString, max) == 0 && esLetra(bufferString) == 0 && esEntero(bufferString) != 0)
        {
            retorno = 0;
            strncpy(pNombre, bufferString, max);
        }else
        {
            printf("%s", msgError);
            system("pause");
        }
    }
    return retorno;
}



int BibliotecaObtenerEntero(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo)
{
    int auxiliarNum;
    int retorno = -1;
    for(;reint>0;reint--)
    {
        printf(msg);
        if(obtenerEntero(&auxiliarNum) == 0)
        {
            if(auxiliarNum > minimo && auxiliarNum < maximo)
            {
                *pNum = auxiliarNum;
                retorno = 0;
                break;
            }else
            {
                printf(msgError);
            }
        }else
        {
            printf(msgError);
        }
    }
    return retorno;
}


int ObtenerNumeroSinLimitacion(int* pNum, int reint, char* msg, char* msgError)
{
    int auxiliarNum;
    int retorno = -1;
    for(;reint>0;reint--)
    {
        printf(msg);
        if(obtenerEntero(&auxiliarNum) == 0)
        {
                *pNum = auxiliarNum;
                retorno = 0;
                break;
        }else
        {
            printf(msgError);
        }
    }
    return retorno;
}



int obtenerNumeroConComa(float *pNum, int reint, char* msg, char* msgError,float maximo,float minimo)
{
    float buffer;
    int retorno = -1;

    if(pNum != NULL && msg != NULL && msgError !=NULL && minimo<=maximo && reint >= 0)
    {
        do
        {
            reint--;
            printf("%s",msg);
            if(obtenfloat(&buffer) == 0 && buffer <= maximo && buffer >= minimo)
            {
                *pNum = buffer;
                retorno = 0;
                break;
            }else
            {
                printf("%s",msgError);
                fflush(stdin);
            }
        }while(reint >= 0);
    }
    return retorno;
}



static int obtenerChar(char* pBufferString,int limite)
{
    fflush(stdin);
    fgets(pBufferString,limite,stdin);
    if(pBufferString[strlen(pBufferString)-1]=='\n')
    {
        pBufferString[strlen(pBufferString)-1]='\0';
    }
    return 0;
}


static int obtenerEntero(int* pResultado)
{
    int retorno=-1;
    char bufferString[4096];
    if(pResultado != NULL)
    {
        if(obtenerChar(bufferString,4096) == 0 && esEntero(bufferString)==0)
        {
            *pResultado=atof(bufferString);
            retorno=0;
        }
    }
    return retorno;
}


static int obtenfloat(float* pResultado)
{
    int retorno=-1;
    char bufferString[4096];
    if(pResultado != NULL)
    {
        if(obtenerChar(bufferString,4096) == 0 && esFlotante(bufferString)==0)
        {
            *pResultado=atof(bufferString);
            retorno=0;
        }
    }
    return retorno;
}


static int esFlotante(char* pBuffer)
{
    int i=0;
    int retorno=0;
    int contadorPuntos=0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i]=='.' && contadorPuntos==0)
        {
            contadorPuntos++;
            i++;
        }
        if((pBuffer[i] < '0' || pBuffer[i] > '9'))
        {

            retorno=-1;
            break;
        }
        i++;
    }
    if(contadorPuntos > 2)
    {
        retorno=-1;
    }
    return retorno;
}


int esEntero(char* pBuffer)
{
    int i=0;
    int retorno=0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] < '0' || pBuffer[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}


int EnteroConGuiones(char* pBuffer)
{
    int i = 0;
    int retorno = 0;
    int contadorDeGuiones = 0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] == '-' && contadorDeGuiones == 0)
        {
            contadorDeGuiones++;
            i++;
            continue;
        }
        if(pBuffer[i] < '0' || pBuffer[i] > '9')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}



int esLetra(char* pBuffer)
{
    int i = 0;
    int retorno = 0;
    int flag = 0;
    int contadorGuiones=0;
    while(pBuffer[i] != '\0')
    {
        if(flag == 0)
        {
            pBuffer[i] = toupper(pBuffer[i]);
            flag = 1;
        }else if ((pBuffer[i] != ' ') && (pBuffer[i] < 'A' || pBuffer[i] > 'Z') &&
                (pBuffer[i] < 'a' || pBuffer[i] > 'z') && pBuffer[i] != '-')
        {
            retorno = -1;
            break;
        }
        if(pBuffer[i] == '-')
        {
            contadorGuiones++;
        }
        i++;
    }
    return retorno;
}


