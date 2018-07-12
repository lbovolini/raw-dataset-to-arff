#include <locale.h>
#include "io.h"
#include "globals.h"
#include "funct.h"
#include "msg.h"

// Main.
//argv[1] -> raw dataset
//argv[2] -> all attributes
//argv[3] -> required attributes
//argv[4] -> output 
int main(int argc, char *argv[])
{
    if (argc < 5) {
        printf("%s <raw dataset file> <all attributes file> <required attributes file> <output file>\n", argv[0]);
        return 0;
    }
    
    setlocale(LC_ALL, "");

    FILE *itemSet = NULL,
         *dataSet = NULL,
         *atributos = NULL,
         *atributosUsados = NULL;
    //int  progresso = 0;
    char linha[NUMERO_ATRIBUTOS + 1] = {'\0'};
    bool usarAtributo[NUMERO_ATRIBUTOS] = {'\0'};

    // Abre arquivo de entrada.
    itemSet = fopen(argv[1], "rt");
    erroArquivo(&itemSet);

    // Abre arquivo de atributos.
    atributos = fopen(argv[2], "rt");
    erroArquivo(&atributos);

    // Abre arquivo de atributos usados.
    atributosUsados = fopen(argv[3], "rt");
    erroArquivo(&atributosUsados);

    // Abre/cria arquivo de saida.
    dataSet = fopen(argv[4], "wt");
    erroArquivo(&dataSet);

    inicializaVetorUsarAtributos(usarAtributo);
    gerarAtributosValidos(&dataSet, &atributos, &atributosUsados, usarAtributo);

    while(!feof(itemSet))
    {
        inicializaVetorLinha(linha);
        lerLinhaItemSet(&itemSet, linha);
        if(!feof(itemSet))
        {
            if(gerarDataSet (&dataSet, linha, usarAtributo) != 0) exit (1);
            //printf("Progresso: %d linhas\n", ++progresso);
        }
    }

    printf("Concluido!\n");
    fclose(itemSet);
    fclose(dataSet);
    fclose(atributos);
    fclose(atributosUsados);

    itemSet = NULL;
    dataSet = NULL;
    atributos = NULL;
    atributosUsados = NULL;

    return 0;
}
