#ifndef DICIONARIO_H_INCLUDED
#define DICIONARIO_H_INCLUDED
#include "Letra.h"
#define inicio 0
#define tammax 26

typedef struct{
    tLetras texto;
}tAlfabeto;

typedef struct{
    tAlfabeto alfabeto[tammax];
    //int primeiro, ultimo;
}ListaAlfabeto;

void PreencheAlfabeto (ListaAlfabeto *Alfabeto);
void InsereNaLista(ListaAlfabeto *Alfabeto, char *palavra, int numerolinha);
void RemovePalavra(ListaAlfabeto *Alfabeto, char *palavra);
void ImprimeAlfabeto(ListaAlfabeto *Alfabeto, char letra);
void ImprimeDicionario(ListaAlfabeto Alfabeto);
void remove_char(char* str, char c);


#endif // DICIONARIO_H_INCLUDED
