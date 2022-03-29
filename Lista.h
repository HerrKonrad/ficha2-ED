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
PtrNO Pesquisar_Palavra(Lista *L, PtrNO txt);
void Destruir_Lista(Lista *L);
int Ler_Ficheiro(Lista *L, char *ficheiro);
int Exportar_Ficheiro(Lista *L, char *ficheiro);
int Remover_Palavra(Lista *L, char *txt);
void inserir_elemento_fim(Lista* L, PtrNO E);
int validar_Elemento(PtrNO E);
void libertarElemento(PtrNO E);
int comparar_elementos(PtrNO A, PtrNO B);
void inserir_elemento_ordenado(Lista *L,PtrNO ele_novo);
PtrNO pesquisar_Recursivo(PtrNO c, PtrNO elementoPesquisar);
PALAVRA * Pertence_Rec(Lista *L, char *txt);
PALAVRA * Pertence_Rec_Nos(PtrNO P, char *txt);
int Repetidos(Lista *L);
Lista *Todos_Repetidos(Lista *L);

#endif // LISTA_H_INCLUDED
