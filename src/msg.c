#include "globals.h"
#include "msg.h"

// Mensagem de erro ao escrever no arquivo.
void erroEscrever(void)
{
    fprintf(stderr, "Erro ao escrever no arquivo!\n");
    exit(EXIT_FAILURE);
}


// Mensagem de erro ao ler arquivo.
void erroLer(void)
{
    fprintf(stderr, "Erro ao ler arquivo!\n");
    exit(EXIT_FAILURE);
}


// Exibe mensagem de erro.
void erroArquivo(FILE **arquivo)
{
    if(!(*(arquivo)))
    {
		//fprintf(stderr, "Erro numero: %d\n", errno);
		fprintf(stderr, "Erro ao abrir arquivo: %s\n", strerror( errno ));
        exit(EXIT_FAILURE);
    }
}
