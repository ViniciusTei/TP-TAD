#include <stdlib.h>
#include <stdio.h>
#include "DICIONARIO.h"

//cria lista de alfabeto vazia
void PreencheAlfabeto (ListaAlfabeto *Alfabeto)
{
    int i, letra;

    letra = 97;

    for(i=0; i<26; i++)
    {
        PreencheLetra(&Alfabeto->alfabeto[i].texto, letra);
        CriaLetraVazia(&Alfabeto->alfabeto[i].texto);
        letra++;
    }
}

//insere palavra na lista
void InsereNaLista(ListaAlfabeto *Alfabeto, char *palavra, int numerolinha)
{
    int letra;

    letra = palavra[0];

    letra -= 97;

    InsereAlfabeto(&Alfabeto->alfabeto[letra].texto, palavra, numerolinha);
}

//remove palavra digitada pelo usuario
void RemovePalavra(ListaAlfabeto *Alfabeto, char *palavra)
{
    int letra;

    letra = palavra[0];

    letra -= 97;

    if((RemovePalavraDada(&Alfabeto->alfabeto[letra].texto.ListaDePalavras, palavra))==1)
        printf("\nPalavra removida com sucesso!\n");
    else if((RemovePalavraDada(&Alfabeto->alfabeto[letra].texto.ListaDePalavras, palavra))==0)
        printf("\nNao foi possive remover essa palavra!\n");
    //RemovePalavraDada(&Alfabeto->alfabeto[letra].texto.ListaDePalavras, palavra);
}

//imprime a lista de palavras de uma determinada letra
void ImprimeAlfabeto(ListaAlfabeto *Alfabeto, char letra)
{
    int x;
    x = letra;

    x -= 97;

    printf("\n");
    printf("---- Palavras com a letra %c ----\n", letra);

    ImprimeLetra(Alfabeto->alfabeto[x].texto);
}

//imprime a lista de palavras completa
void ImprimeDicionario(ListaAlfabeto Alfabeto)
{
    int i;

    printf("---- Dicionario Completo ----\n");
    printf("\n");

    for(i=0; i<26; i++)
    {
        ImprimeLetra(Alfabeto.alfabeto[i].texto);
    }
}

//função para remover o \n
void remove_char(char* str, char c)
{
    char *pr= str, *pw = str;

    while(*pr)
    {
        *pw = *pr++;
        pw += (*pw != c);
    }

    *pw = '\0';
}
