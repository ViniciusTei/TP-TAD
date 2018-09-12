#ifndef LETRA_H_INCLUDED
#define LETRA_H_INCLUDED
#include "lista_de_palavra.h"

typedef struct{
    char letra_alfabeto; //armazena uma letra
    lista_words ListaDePalavras; //lista de palavras com a letra armazenada
}tLetras;

void CriaLetraVazia(tLetras *pLetra);
void PreencheLetra(tLetras *pLetra, char letra);
char RetornaLetra(tLetras *pLetra);
void ImprimeLetra(tLetras pLetra);
void InsereAlfabeto(tLetras *pLetra, char *palavra, int numlinha);

#endif // LETRA_H_INCLUDED
