#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Seleciona os atributos a serem utilizados com base nos arquivos
"atributos.txt" e "atributosUsados.txt" e escreve no arquivo de saida. */
int gerarAtributosValidos(FILE **dataSet, FILE **atributos, FILE **atributosUsados, bool usarAtributo[]);

// Le uma instancia do itemSet e gera uma instancia do dataSet.
int lerLinhaItemSet(FILE **itemSet, char linha[]);

// Grava instancia no dataSet.
int gerarDataSet(FILE **dataSet, char linha[], bool usarAtributo[]);
