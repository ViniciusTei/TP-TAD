#ifndef PALAVRA_H_INCLUDED
#define PALAVRA_H_INCLUDED
#include "nLinhas.h"
#define maxtam 31

typedef struct{
    char letra[maxtam]; //armazena palavra
    tLista n_linhas; //lista com numero de linha em que as palavras aparecem
}item_palavra;

void FPalavraVazia(item_palavra *tpalavra);
void preenche(item_palavra *tpalavra, char *palavra);
void insere_nlinha(item_palavra *tpalavra, int linha);
char* retorna(item_palavra *tpalavra);
void imprime_palavra(item_palavra *tpalavra);
void imprime_lista(item_palavra *tpalavra);
void RetiraListaDeLinhas(item_palavra *item);



#endif // PALAVRA_H_INCLUDED
