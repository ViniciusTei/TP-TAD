#include <stdlib.h>
#include <stdio.h>
#include "Letra.h"

void CriaLetraVazia(tLetras *pLetra) //cria lista vazia
{
    CriaListaVazia(&pLetra->ListaDePalavras); //chama função para criar uma lista de palavra vazia
}

void PreencheLetra(tLetras *pLetra, char letra) //recebe a letra inicial da palavra
{
    pLetra->letra_alfabeto =  letra; //armazena a letra
}

char RetornaLetra(tLetras *pLetra) //retorna letra
{
    return(pLetra->letra_alfabeto);
}

void ImprimeLetra(tLetras pLetra) //imprime lista de palavras + letra
{
    printf("\n----------------------\n");
    printf("Letra: %c\n", pLetra.letra_alfabeto);
    printf("Numero de palavras: %d\n", pLetra.ListaDePalavras.cont);
    printf("\n");
    ImprimeListaPalavra(pLetra.ListaDePalavras);
}

void InsereAlfabeto(tLetras *pLetra, char *palavra, int numlinha) //insere palavras na lista de palavras
{
    insere_palavra(&pLetra->ListaDePalavras, palavra, numlinha);
}
