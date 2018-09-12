#include <stdio.h>
#include <stdlib.h>
#include "lista_de_palavra.h"

void CriaListaVazia(lista_words *pLista)
{
    //aloca celula cabeça
    pLista->primeiro = (ponteiroCW) malloc(sizeof(tcelulaword));
    pLista->ultimo = pLista->primeiro;
    pLista->ultimo->prox = NULL;
    //inicia contador com 0
    pLista->cont = 0;
}

int verifica_palavra(lista_words *pLista, char *Ppalavra) //verifica se palavra ja existe na lista
{
    ponteiroCW aux;

    aux = pLista->primeiro;

    while(aux != NULL)
    {
        if(strcmp(Ppalavra, retorna(&aux->word2.word))==0){
            return 1; //retorna 1 caso a palavra ja exista na linha
        }
        aux = aux->prox;
    }
    return 0;
}

void insere_palavra(lista_words *pLista, char *Ppalavra, int NumLinha)
{
    ponteiroCW aux;
    if(VerificaListaVazia(pLista)==0 || verifica_palavra(pLista, Ppalavra)==0) //caso a palavra nao exista
    {
        pLista->ultimo->prox = (ponteiroCW) malloc(sizeof(tcelulaword)); //aloca uma nova celula
        pLista->ultimo = pLista->ultimo->prox;
        FPalavraVazia(&pLista->ultimo->word2.word);
        preenche(&pLista->ultimo->word2.word, Ppalavra); //armazena palavra na celula
        insere_nlinha(&pLista->ultimo->word2.word, NumLinha); //insere um item na lista de numeros de linha
        pLista->ultimo->prox = NULL;
        (pLista->cont)++;
    }
    else{ //caso a palavra ja exista
        aux = pLista->primeiro;
        while(aux != NULL)
        {
            if(strcmp(Ppalavra, retorna(&aux->word2.word))==0)
            {
                insere_nlinha(&aux->word2.word, NumLinha);
            }
            aux = aux->prox;
        }
    }
}

int RemovePalavraDada(lista_words *pLista, char *palavra) //remove palavra dada
{
    ponteiroCW aux, aux2;

    if(VerificaListaVazia(pLista)==0) //verifica se a lista esta vazia
        return 0;

    aux2 = pLista->primeiro;
    aux = aux2->prox;

    if(strcmp(retorna(&aux->word2.word), palavra)==0) //retira caso for a primeira celula
    {
        aux2->prox = aux->prox;
        ApagaLista(&aux->word2.word.n_linhas); //desaloca lista de numeros de linha
        free(aux);
        (pLista->cont)--;
        return 1;
    }

    while(aux != NULL)
    {
        if(aux->prox == NULL && (strcmp(retorna(&aux->word2.word), palavra)==0)) //retira caso for a ultima celula
        {
            aux2->prox = NULL;
            ApagaLista(&aux->word2.word.n_linhas); //desaloca lista de numeros de linha
            free(aux);
            (pLista->cont)--;
            return 1;
        }
        if(strcmp(retorna(&aux->word2.word), palavra)==0)//retira celula do meio
        {
            aux2->prox = aux->prox;
            ApagaLista(&aux->word2.word.n_linhas); //desaloca lista de numeros de linha
            free(aux);
            (pLista->cont)--;
            return 1;
        }
        aux2 = aux2->prox;
        aux = aux->prox;
    }
    return 0;
}

int VerificaListaVazia(lista_words *pLista) //verificia se a lista esta vazia
{
    if(pLista->primeiro == pLista->ultimo || pLista->primeiro == NULL)
        return 0;
    else
        return 1;
}

void ImprimeListaPalavra(lista_words pLista) //imprime palavra + lista de numero de linha
{
    ponteiroCW Aux;

    Aux = pLista.primeiro->prox;

    while(Aux != NULL)
    {
        imprime_lista(&Aux->word2.word); //chama função para imprimir
        Aux = Aux->prox; //percorre toda a lista
    }
}

int RetornaNumPalavras(lista_words *pLista) //conta quantas palavras existem na lista
{
    return(pLista->cont);
}

void RemovePalavraFinal(lista_words *pLista) //remove a ultima celula da lista
{
    ponteiroCW aux, aux2;

    aux = pLista->primeiro;
    aux2 = pLista->ultimo;

    while(aux != NULL)
    {
        if(aux->prox == aux2)
        {
            aux->prox = NULL;
            ApagaLista(&aux2->word2.word.n_linhas); //desaloca lista de numeros de linha
            free(aux2);
            (pLista->cont)--;
        }
        aux = aux->prox;
    }
}
