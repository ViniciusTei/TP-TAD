#ifndef LISTA_DE_PALAVRA_H_INCLUDED
#define LISTA_DE_PALAVRA_H_INCLUDED
#include "palavra.h"

typedef struct{
    item_palavra word; //armazena palavra + lista de numero de linhas
}tipo_word;

typedef struct celulaword *ponteiroCW;
typedef struct celulaword{
    tipo_word word2;
    ponteiroCW prox;
}tcelulaword;

typedef struct{
    ponteiroCW primeiro;
    ponteiroCW ultimo;
    int cont;
}lista_words;

void CriaListaVazia(lista_words *pLista);
int verifica_palavra(lista_words *pLista, char *Ppalavra);
void insere_palavra(lista_words *pLista, char *Ppalavra, int NumLinha);
int RemovePalavraDada(lista_words *pLista, char *palavra);
int VerificaListaVazia(lista_words *pLista);
void ImprimeListaPalavra(lista_words pLista);
int RetornaNumPalavras(lista_words *pLista);
void RemovePalavraFinal(lista_words *pLista);



#endif // LISTA_DE_PALAVRA_H_INCLUDED
