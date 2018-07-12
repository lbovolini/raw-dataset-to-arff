#include "funct.h"
#include "msg.h"
#include "globals.h"
#include "io.h"

/* Seleciona os atributos a serem utilizados com base nos arquivos
"atributos.txt" e "atributosUsados.txt" e escreve no arquivo de saida. */
int gerarAtributosValidos(FILE **dataSet, FILE **atributos, FILE **atributosUsados, bool usarAtributo[])
{
    int  tamanho = 0, i = 0;

    char temp0[100] = {'\0'},
         temp1[100] = {'\0'};

    fgets(temp0, sizeof(temp0), *(atributos));
    fgets(temp1, sizeof(temp1), *(atributosUsados));

    if(fprintf(*(dataSet), "@relation accidents\n") < 0)
    {
        erroEscrever();
    }

    /* Se o atributo esta presente nos arquivos "atributosUsados.txt" e
    "atributos.txt", marca atributo como valido. */
    for(i = 1; i <= NUMERO_ATRIBUTOS; i++)
    {
        if(strcmp(temp0, temp1) == 0)
        {
            tamanho = strlen(temp1) - 1;
            if(temp1[tamanho] == '\n')
            {
                temp1[tamanho] = '\0';
            }

            usarAtributo[i] = TRUE;
            if(fprintf(*(dataSet), "@attribute %s numeric\n", temp1) < 0)
            {
                erroEscrever();
            }

            fgets(temp1, sizeof(temp1), *(atributosUsados));
        }
        fgets(temp0, sizeof(temp0), *(atributos));
    }

    if(fprintf(*(dataSet), "\n@data\n") < 0)
    {
        erroEscrever();
    }

    return 0;
}


// Le uma instancia do itemSet e gera uma instancia do dataSet.
int lerLinhaItemSet(FILE **itemSet, char linha[])
{
    int numero = 0;

    do
    {
        if(fscanf(*(itemSet), "%d", &numero) !=1)
        {
            erroLer();
        }

        if (numero <= NUMERO_ATRIBUTOS)
        {
            linha[numero] = ATRIBUTO_PRESENTE;
        }

    } while((fgetc(*(itemSet)) != '\n') && !feof(*(itemSet)));

    return 0;
}

// Grava instancia no dataSet.
int gerarDataSet(FILE **dataSet, char linha[], bool usarAtributo[])
{
    int i = 0;

    for(i = 1; i <= NUMERO_ATRIBUTOS; i++)
    {
        if(usarAtributo[i])
        {
            if(fprintf(*(dataSet), "%c", linha[i]) < 0) exit(1);
            if(ultimoAtributoUsado(usarAtributo) != i)
            {
                if(fprintf(*(dataSet), ",") < 0) exit(1);
            }
        }
    }

    if(fprintf(*(dataSet), "\n") < 0) exit(1);
    return 0;
}
