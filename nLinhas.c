#include <stdlib.h>
#include "nLinhas.h"

void FLVazia(tLista *ptrLista) //criar uma lista vazia com celula cabeça
{
    ptrLista->primeiro = (apontador) malloc(sizeof(tCelula)); //alocar espaço da celula cabeça
    //fazer os apontadores primeiro e ultimo apontarem para celula cabeça
    ptrLista->ultimo = ptrLista->primeiro;
    ptrLista->primeiro->prox = NULL; //fazer o campo prox da celula cabeça nulo
    ptrLista->cont = 0; //inicia o contador com 0
}

int LeVazia(tLista *ptrLista) //verifica se a lista esta vazia
{
    if(ptrLista->primeiro == ptrLista->ultimo)
        return 1;//lista vazia
    else if(ptrLista->primeiro == NULL)
        return 1;//lista vazia
    else
        return 0;
}

void Insere(tLista *ptrLista, tItem Item) //insere um item NO FINAL da lista
{
    if(Verifica(ptrLista, Item) == 0) //verifica se o item a ser inserido ja existe na lista
    {
        ptrLista->ultimo->prox = (apontador) malloc(sizeof(tCelula)); //cria um novo espaço para celula
        ptrLista->ultimo = ptrLista->ultimo->prox; //faz ultimo apontar para a nova celula criada
        ptrLista->ultimo->item = Item; //insere novo item no final
        ptrLista->ultimo->prox = NULL; //faz campo prox do ultimo nulo
        (ptrLista->cont)++; //ptrista->conta = ptrLista->conta + 1;
    }
}

int Verifica(tLista *ptrLista, tItem Item) //verifica se ja existe um item na lista
{
    apontador Aux;
    Aux = ptrLista->primeiro->prox;

    //percorre a lista
    while(Aux != NULL)
    {
        if(Item.nlinhas == Aux->item.nlinhas) //verifica os itens na lista
            return 1;
        Aux = Aux->prox;
    }
    return 0;
}

void RemoverFinal(tLista *ptrLista)
{
    apontador Aux1, Aux2;

    Aux1 = ptrLista->ultimo;
    Aux2 = ptrLista->primeiro->prox;

    //verifica se a lista esta vazia
    if(LeVazia(ptrLista)==1)
        return; //caso esteja nao faz nada

    //verifica se a lista possui apena 1 item
    if(ptrLista->cont == 1)
    {
        ptrLista->ultimo = ptrLista->primeiro; //faz o ultimo apontar para o primeiro
        ptrLista->primeiro->prox = NULL; //faz o campo prox do primeiro nulo
        free(Aux1); //desaloca espaço da celula q queremos retirar
        (ptrLista->cont)--; //decrementa o contador

    }
    else
    {
        //caso a lista tenha mais de 1 celula entra no while
        while(Aux2 != Aux1)
        {
            if(Aux2->prox == Aux1) //caso for verdade Aux2 é o penutimo e devera passar a ser o ultimo
            {
                Aux2->prox == NULL; //faz campo prox de Aux2 nulo
                free(Aux1); //desaloca o espaço da celula q foi retirada
                (ptrLista->cont)--; //decrementa o contador
            }
            Aux2 = Aux2->prox;
        }
    }
}

int QtdLinhas(tLista *lista) //retorna a quantidade de linhas
{
    return(lista->cont); //retorna o valor armazenado no contador
}

void Imprime(tLista lista) //imprime os itens contidos na lista
{
    apontador Aux;

    Aux = lista.primeiro->prox;

    if(LeVazia(&lista) == 1)
        printf("Lista vazia!\n");
    else{
        while(Aux != NULL) //percorre a lista printando seus itens
        {
            printf("Linha: %d\n", Aux->item.nlinhas);
            Aux = Aux->prox;
        }
    }
}

void ApagaLista(tLista *pLista) //apaga lista inteira
{
    apontador AuxCelula, Aux;

    AuxCelula = pLista->primeiro; //faz receber celula cabeça

    while(AuxCelula != NULL) //percorre lista apagando do inicio para o final
    {
        Aux = AuxCelula;
        AuxCelula = AuxCelula->prox;
        free(Aux);
    }

    pLista->primeiro = NULL; //inicia primeiro com nulo
}

