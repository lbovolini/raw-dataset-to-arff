#include "globals.h"
#include "funct.h"

// Preenche um vetor de caracteres com atributo faltante.
int inicializaVetorLinha(char linha[])
{
    int i = 0;

    for(i = 0; i <= NUMERO_ATRIBUTOS; i++)
    {
        linha[i] = ATRIBUTO_FALTANTE;
    }

    linha[NUMERO_ATRIBUTOS + 1] = '\0';
    return 0;
}


// Preenche um vetor de booleano com FALSE.
int inicializaVetorUsarAtributos(bool usarAtributos[])
{
    int i = 0;

    for(i = 0; i <= NUMERO_ATRIBUTOS; i++)
    {
        usarAtributos[i] = FALSE;
    }

    return 0;
}


// Retorna o ultimo atributo valido.
int ultimoAtributoUsado(bool usarAtributo[])
{
    int i = 0,
        ultimo = 0;

    for(i = 1; i <= NUMERO_ATRIBUTOS; i++)
    {
        if(usarAtributo[i] == TRUE)
        {
            ultimo = i;
        }
    }

    return ultimo;
}

