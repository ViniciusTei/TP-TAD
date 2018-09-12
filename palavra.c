#include <stdio.h>
#include <stdlib.h>
#include "palavra.h"
#include <string.h>

void FPalavraVazia(item_palavra *tpalavra) //cria palavra vazia
{
    strcpy(tpalavra->letra, " "); //faz palavra receber um espaço em branco
    FLVazia(&tpalavra->n_linhas); //cria lista de n_linhas vazia
}

void preenche(item_palavra *tpalavra, char *palavra)//preenche palavra
{
    strcpy(tpalavra->letra, palavra); //copia palavra dada na outra palavra
}

void insere_nlinha(item_palavra *tpalavra, int linha) //insere numero de linha
{
    tItem linhax;
    linhax.nlinhas = linha; //armazena meu inteiro em uma variavel do tipo tItem
    Insere(&tpalavra->n_linhas, linhax); //insere numero na lista de numeros de linhas
}

char* retorna(item_palavra *tpalavra) //retorna a palavra como string
{
    return(tpalavra->letra);
}

void imprime_palavra(item_palavra *tpalavra) //printa a palavra
{
    printf("Palavra: %s\n", tpalavra->letra);
}

void imprime_lista(item_palavra *tpalavra)
{
    printf("Palavra: %s\n", tpalavra->letra); //mostra a palavra
    Imprime(tpalavra->n_linhas); //chama funco para mostrar a lista de num de linhas
    printf("\n");
}
