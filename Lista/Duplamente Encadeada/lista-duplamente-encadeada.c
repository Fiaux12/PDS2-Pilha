#include <stdio.h>
#include <stdlib.h>
#include "lista-duplamente-encadeada.h"

struct ListaDE
{
    int info;
    struct ListaDE *ant;
    struct ListaDE *prox;
};

typedef struct ListaDE ListaDE;

ListaDE *listaDE_cria()
{
    return NULL;
}

ListaDE *listaDE_insere(ListaDE *lista, int v)
{
    ListaDE *novo = (ListaDE *)malloc(sizeof(ListaDE));
    novo->info = v;
    novo->prox = lista;
    novo->ant = NULL;
    if (lista != NULL)
        lista->ant = novo;

    return novo;
}

ListaDE *listaDE_busca(ListaDE *lista, int v)
{
    ListaDE *p;
    for (p = lista; p != NULL; p = p->prox)
    {
        if (p->info == v)
        {

            return p;
        }
    }
    return NULL;
}

ListaDE *listaDE_retira(ListaDE *lista, int v)
{
    ListaDE *p = listaDE_busca(lista, v);
    if (p == NULL)
        return lista;

    if (lista == p)
        lista = p->prox;
    else
        p->ant->prox = p->prox;

    if (p->prox != NULL)
        p->prox->ant = p->ant;

    free(p);

    return lista;
}

void listaDE_imprime(ListaDE *lista)
{
    ListaDE *p;
    for (p = lista; p != NULL; p = p->prox)
    {
        printf(" %d ", p->info);
    }
}