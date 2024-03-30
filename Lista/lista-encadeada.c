#include <stdio.h>
#include <stdlib.h>
struct Lista
{
    int info;
    struct Lista *prox;
};

typedef struct Lista Lista;

Lista *lista_cria()
{
    return NULL;
}

Lista *lista_insere(Lista *lista, int i)
{
    Lista *novaLista = (Lista *)malloc(sizeof(Lista));
    novaLista->info = i;
    novaLista->prox = lista;
    return novaLista;
}

void lista_imprime(Lista *lista)
{
    Lista *aux;
    for (aux = lista; aux != NULL; aux = aux->prox)
    {
        printf(" %d ", aux->info);
    }
}

int lista_vazia(Lista *lista)
{
    return lista == NULL;
}

Lista *lista_busca(Lista *lista, int v)
{
    Lista *aux;
    for (aux = lista; aux != NULL; aux = aux->prox)
    {
        if (aux->info == v)
        {
            return aux;
        }
    }

    return NULL;
}

void lista_libera(Lista *lista)
{
    Lista *aux = lista;
    while (aux != NULL)
    {
        Lista *listaTroca = aux->prox;
        free(aux);
        aux = listaTroca;
    }
}

Lista *lista_retira(Lista *lista, int v)
{
    Lista *antiga = NULL;
    Lista *aux = lista;

    while (aux != NULL && aux->info != v)
    {
        antiga = aux;
        aux = aux->prox;
    }

    if (aux == NULL)
    {
        return lista;
    }

    if (antiga == NULL)
    {
        lista = aux->prox;
    }
    else
    {
        antiga->prox = aux->prox;
    }

    free(aux);

    return lista;
}

int lista_igual(Lista *lista1, Lista *lista2)
{
    Lista *copLista1 = lista1;
    Lista *copLista2 = lista2;

    while (copLista1 != NULL && copLista2 != NULL)
    {

        if (copLista1->info != copLista2->info)
        {
            return 0;
        }
        else if (copLista1->info == copLista2->info)
        {
            return 1;
        }
    }
}

Lista *lista_insere_ordenado(Lista *l, int v)
{

    Lista *novo;
    Lista *ant = NULL;
    Lista *p = l;

    while (p != NULL && p->info < v)
    {
        ant = p;
        p = p->prox;
    }

    novo = (Lista *)malloc(sizeof(Lista));
    novo->info = v;

    if (ant == NULL)
    {
        novo->prox = l;
        l = novo;
    }

    else
    {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}
