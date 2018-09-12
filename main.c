#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 1000
#include "DICIONARIO.h"

int main()
{
    FILE *arq;
    int NumLinha, j;
    int controle, nLinha;
    char Frase[tam], *pFrase, *pPalavra;
    char palavra[tam], letra;
    ListaAlfabeto Dicionario;

    NumLinha = 1; //variavel que conta o numero de linhas do texto

    arq = fopen("teste.txt", "r");

    PreencheAlfabeto(&Dicionario); //cria uma lista vazia para cada letra do alfabeto

    if(arq == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }
    else
    {
        pFrase = fgets(Frase, sizeof(Frase), arq); //armazena a primeira linha do arquivo

        while(pFrase != NULL) //vai ate o final do texto
        {
            pPalavra = strtok(pFrase, " "); //divide as linhas a cada espaço

            while(pPalavra != NULL)
            {
                for(j=0; j<strlen(pPalavra); j++)
                {
                    //chama funcao que remove o '\n' da string
                    if(pPalavra[j] == '\n')
                        remove_char(pPalavra, '\n');
                }
                InsereNaLista(&Dicionario, pPalavra, NumLinha); //insere a palavra na lista
                pPalavra = strtok(NULL, " "); //pega a proxima palavra
            }
            pFrase = fgets(Frase, sizeof(Frase), arq); //pega a proxima linha do texto
            NumLinha++; //incrementa o numero de linha
        }
    }

    //interface:

    /*printf("    ----- Lista de comandos -----\n");
    printf("    1. Inserir uma palavra na lista\n");
    printf("    2. Remover uma palavra da lista\n");
    printf("    3. Exibir lista de uma determinada letra\n");
    printf("    4. Exibir toda a lista\n");
    printf("    5. Fechar\n\n");
    printf("Digite o numero da opcao desejada: ");
    scanf("%d", &controle);*/

    do
    {
        printf("\n");
        printf("    ----- Lista de comandos -----\n");
        printf("    1. Inserir uma palavra na lista\n");
        printf("    2. Remover uma palavra da lista\n");
        printf("    3. Exibir lista de uma determinada letra\n");
        printf("    4. Exibir toda a lista\n");
        printf("    5. Fechar\n\n");
        printf("Digite o numero da opcao desejada: ");
        scanf("%d", &controle);

        switch (controle)
        {
            case 1:
                printf("Digite a palavra e o numero da linha que ela deve ser inserida:\n");
                printf("   Palavra: ");
                scanf("%s", &palavra);
                printf("   Linha: ");
                scanf("%d", &nLinha);
                InsereNaLista(&Dicionario, palavra, nLinha);
                printf("Palavra inserida com sucesso!\n");
                break;
            case 2:
                printf("Digite a palavra a ser removida do texto: ");
                scanf("%s", &palavra);
                RemovePalavra(&Dicionario, palavra);
                //printf("Palavra removida com sucesso!\n");
                break;
            case 3:
                printf("Digite a letra a ser exibida: ");
                fflush(stdin);
                letra = getc(stdin);
                ImprimeAlfabeto(&Dicionario, letra);
                break;
            case 4:
                ImprimeDicionario(Dicionario);
                break;
            case 5:
                printf("Fechar!\n");
                break;
            default:
                printf("\n");
                printf("Opcao invalida!\n");
                break;
        }
        /*printf("\n");
        printf("    ----- Lista de comandos -----\n");
        printf("    1. Inserir uma palavra na lista\n");
        printf("    2. Remover uma palavra da lista\n");
        printf("    3. Exibir lista de uma determinada letra\n");
        printf("    4. Exibir toda a lista\n");
        printf("    5. Fechar\n\n");
        printf("Digite o numero da opcao desejada: ");
        scanf("%d", &controle);*/
    }while(controle != 5);

    fclose(arq);


    return 0;
}
