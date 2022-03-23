#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "Tipo_Dados.h"

typedef struct no
{
    PALAVRA   *Info;
    struct no *Prox;
}ELEMENTO, NO, *PtrNO;

typedef struct
{
    char Lingua[3];
    NO *Inicio;
    int NEL;
}Lista;

Lista *Criar_Lista(char *ling);
NO *Criar_No();
void lerElemento(PtrNO E);
void Add_Inicio(Lista *L, NO *X);
void Add_Fim(Lista *L, NO *X);
void Add_Ord(Lista *L, NO *X);
void Mostrar_Lista(Lista *L);
void Mostrar_Contrario_Lista(Lista *L);
PALAVRA *Pesquisar_Palavra(Lista *L, char *txt);
void Destruir_Lista(Lista *L);
int Ler_Ficheiro(Lista *L, char *ficheiro);
int Exportar_Ficheiro(Lista *L, char *ficheiro);
int Remover_Palavra(Lista *L, char *txt);
void inserir_elemento_fim(Lista* L, PtrNO E);
int validar_Elemento(PtrNO E);
void libertarElemento(PtrNO E);

#endif // LISTA_H_INCLUDED
