#include <stdlib.h>
#include <stdio.h>

typedef struct Item
{
    struct Item *proximo;
    int valor;
} Item;

typedef struct
{
    Item *inicio;
    Item *fim;
} Fila;

Fila *fila_cria()
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

int fila_retira(Fila *fila)
{
    if (fila->inicio == NULL)
    {
        return -999999;
    }

    int valor = fila->inicio->valor;
    Item *item = fila->inicio->proximo;
    free(fila->inicio);
    fila->inicio = item;
    if (fila->inicio == NULL)
        fila->fim = NULL;
    return valor;
}

void fila_insere(Fila *fila, int x)
{
    Item *item = malloc(sizeof(Item));

    item->valor = x;
    item->proximo = NULL;

    if (fila->inicio == NULL)
        fila->inicio = item;

    if (fila->fim != NULL)
        fila->fim->proximo = item;

    fila->fim = item;
}

void fila_libera(Fila *fila)
{
    free(fila);
}

void imprime_item(Item *item)
{
    if (item != NULL)
    {
        printf("%d ", item->valor);
        imprime_item(item->proximo);
    }
}

void fila_imprime(Fila *fila)
{
    imprime_item(fila->inicio);
}
