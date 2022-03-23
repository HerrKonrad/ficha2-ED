#ifndef TIPO_DADOS_H_INCLUDED
#define TIPO_DADOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



#define MAX_PALAVRA 50

typedef struct
{
    char TEXTO[MAX_PALAVRA];
}PALAVRA;

PALAVRA *Criar_Palavra(char *txt);
void Mostrar_Palavra(PALAVRA *Pal);
#endif // TIPO_DADOS_H_INCLUDED
