#include "Lista.h"
#include "utils.h"



Lista *Criar_Lista(char *ling)
{
    //printf("[%s] Ainda nao implementada\n", __FUNCTION__);
    Lista *L = (Lista *)malloc(sizeof(Lista));
    L->Inicio = NULL;
    L->NEL = 0;
    if (strlen(ling) == 2)
        strcpy(L->Lingua, ling);
    else
        strcpy(L->Lingua, "??");
    return L;
}
NO *Criar_No()
{
   // printf("[%s] Ainda nao implementada\n", __FUNCTION__);
     ELEMENTO *P = (ELEMENTO *)malloc(sizeof(ELEMENTO));
    //PtrNO P = (PtrNO)malloc(sizeof(NO));
    P->Info = (PtrNO) malloc(sizeof(PALAVRA));
    P->Prox = NULL;
    return P;
}
void Add_Inicio(Lista *L, NO *X)
{
    //printf("[%s] Ainda nao implementada\n", __FUNCTION__);
    if (!L) return;
    if (!X) return;
    X->Prox = L->Inicio;
    L->Inicio = X;
    L->NEL++;
}
void Add_Fim(Lista *L, NO *X)
{
    printf("[%s] Ainda nao implementada\n", __FUNCTION__);
}
void Add_Ord(Lista *L, NO *X)
{
    printf("[%s] Ainda nao implementada\n", __FUNCTION__);
}
void Mostrar_Lista(Lista *L)
{
    if (!L) return;
    printf("LINGUA = [%s]\n", L->Lingua);
    printf("NEL = %d\n", L->NEL);
    NO *P = L->Inicio;
    while (P != NULL)
    {
        Mostrar_Palavra(P->Info);
        P = P->Prox;
    }
}
void Mostrar_Contrario_Lista(Lista *L)
{
    printf("[%s] Ainda nao implementada\n", __FUNCTION__);
}
PtrNO Pesquisar_Palavra(Lista *L, PtrNO txt)
{
    if(!L || !txt) return NULL;
    PtrNO aux = L->Inicio;
    while(aux)
    {
        if(comparar_elementos(aux, txt))
        {
            return aux;
        }
        aux = aux->Prox;
    }
    return NULL;
}

void Destruir_Lista(Lista *L)
{
    if(!L) return;
    PtrNO no = L->Inicio;
    PtrNO aux;

    while(no != NULL)
    {
        aux = no->Prox;
        libertarElemento(no);
        no = aux;
    }
    free(L);
}


int Ler_Ficheiro(Lista *L, char *ficheiro)
{
    //printf("[%s] Ainda nao implementada\n", __FUNCTION__);
    if (!L) return 0;
    if (!ficheiro) return 0;
    FILE *F = fopen(ficheiro, "r");
    if (!F) return 0;
    char BUFFER[MAX_PALAVRA];
    while (!feof(F))
    {
        fscanf(F, "%s", BUFFER);
        PALAVRA *PAL = Criar_Palavra(BUFFER);
        NO *X = Criar_No();
        X->Info = PAL;
        Add_Inicio(L, X);
    }
    fclose(F);
    return 1;
}
int Exportar_Ficheiro(Lista *L, char *ficheiro)
{
    //printf("[%s] Ainda nao implementada\n", __FUNCTION__);
    if (!L) return 0;
    if (!ficheiro) return 0;
    FILE *F = fopen(ficheiro, "w");
    if (!F) return 0;
    NO *P = L->Inicio;
    while (P)
    {
        fprintf(F, "%s\n", P->Info->TEXTO);
        P = P->Prox;
    }
    fclose(F);
    return 0;
}
int Remover_Palavra(Lista *L, char *txt)
{
    printf("[%s] Ainda nao implementada\n", __FUNCTION__);
    return 0;
}

void inserir_elemento_fim(Lista* L, PtrNO E)
{
    if(!L) return;

    PtrNO P = L->Inicio;
    E->Prox = NULL;

    if( L->Inicio == NULL )
    {
        L->Inicio = E;
    }
    else
    {
        while (P->Prox != NULL)
            P = P->Prox;
        P->Prox = E;
    }
    L->NEL++;
}


void lerElemento(PtrNO E)
{
    int valido;
    if(!E) return;
    do
    {
        char * string[50];

        printf("Qual a palavra? \n");
        scanf("%s", string);
        strcpy(E->Info->TEXTO, string);
        valido = validar_Elemento(E);
        if(!valido)
        {
            printf("Introduza apenas letras [a-z, A-Z] sem caracteres acentuados");
        }

    } while(!valido);
}


int validar_Elemento(PtrNO E)
{
    if(!E) return;
    char * PALAVRA = E->Info->TEXTO;
    int i;
    for ( i = 0 ; i < strlen(E->Info->TEXTO) ; i++)
    {
        if(PALAVRA[i] < 0 || PALAVRA[i] > 128 || !isalpha(PALAVRA[i])) return 0;
    }
    return 1;
}

void libertarElemento(PtrNO E)
{
    free(E->Info);
    free(E);
}

int comparar_elementos(PtrNO A, PtrNO B)
{
    return strcmp(A->Info->TEXTO, B->Info->TEXTO);
}

void inserir_elemento_ordenado(Lista *L, PtrNO ele_novo)
{
    if(!L) return;

    int av = 1;
    PtrNO ant, act;

    if(L->Inicio == NULL)
    {
        ele_novo->Prox = NULL;
        L->Inicio = ele_novo;
    }
    else
    {
        ant = act = L->Inicio;
        while(av)
            if(act==NULL)
            av = 0;
        else if(comparar_elementos(act, ele_novo) > 0)
            av = 0;
        else
        {
            ant = act;
            act = act->Prox;
        }
        if( act == L->Inicio )
        {
            ele_novo->Prox = L->Inicio;
            L->Inicio = ele_novo;
        }
        else
        {
            ant->Prox = ele_novo;
            ele_novo->Prox = act;
        }
    }
    L->NEL++;
}

PtrNO pesquisar_Recursivo(PtrNO c, PtrNO elementoPesquisar)
{

}

PALAVRA * Pertence_Rec(Lista *L, char *txt)
{
    if(!L) return NULL;
    return Pertence_Rec_Nos(L->Inicio, txt);
}

PALAVRA * Pertence_Rec_Nos(PtrNO P, char *txt)
{
    if(!P) return NULL;
    if(stricmp(P->Info->TEXTO, txt) == 0)
        return P->Info;
    return Pertence_Rec_Nos(P->Prox, txt);

}

int Repetidos(Lista *L)
{
    if(!L) return 0;
    PtrNO P = L->Inicio; // Elemento que ser? comparado
    PtrNO Q = NULL; // Percorredor da lista

    while(P)
    {
        Q = P->Prox; // j? que n?o se deve comparar a si mesmo
        while(Q) // percorre toda a lista em busca do elemento
        {
            if(comparar_elementos(Q, P) == 1)
                return 1;
            Q = Q->Prox;
        }
        P = P->Prox; // vai para o pr?ximo elemento
    }
}

Lista *Todos_Repetidos(Lista *L)
{
    if(!L) return NULL;

    Lista *lista_elementos = Criar_Lista("PT");


    PtrNO Q = NULL; // Percorredor da lista

    for(PtrNO P ; P ; P = P->Prox)
    {
        Q = P->Prox; // j? que n?o se deve comparar a si mesmo

        while(Q) // percorre toda a lista em busca do elemento
        {
            if(comparar_elementos(Q, P) == 1)
            {
                Add_Inicio(lista_elementos, P->Info);
                break; // para n?o achar repetidos
            }
            Q = Q->Prox;
        }
        P = P->Prox; // vai para o pr?ximo elemento
    }
    return lista_elementos;
}

