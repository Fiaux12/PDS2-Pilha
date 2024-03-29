#include <stdio.h>
#include <stdlib.h>

struct Pilha;
typedef struct Pilha
{
    int valor;
    struct Pilha *anterior
} Pilha;

Pilha *criaPilha()
{
    Pilha *novoItem;
    novoItem = (Pilha *)malloc(sizeof(Pilha));
    novoItem->valor = 0;
    novoItem->anterior = NULL;
    return novoItem;
}

void push(Pilha **pilha, int valor)
{
    Pilha *novoItem;
    novoItem = (Pilha *)malloc(sizeof(Pilha));
    if (novoItem == NULL)
    {
        printf("Erro: falha na alocação de memória\n");
        exit(1);
    }

    novoItem->valor = valor;
    novoItem->anterior = *pilha;
    *pilha = novoItem;
}

int pilhaVazia(Pilha *pilha)
{
    return (pilha->anterior == NULL);
}

int pop(Pilha **pilha)
{
    Pilha *antigaPilha = *pilha;
    int valorTopo;
    if (pilhaVazia(*pilha))
    {
        printf("Pilha vazia\n");
        exit(1);
    }
    antigaPilha = *pilha;
    valorTopo = antigaPilha->valor;
    *pilha = antigaPilha->anterior;
    free(antigaPilha);
    return valorTopo;
}

void pilhaLibera(Pilha *pilha)
{
    Pilha *libera = pilha->anterior;
    while (libera != NULL)
    {
        Pilha *aux = libera->anterior;
        free(libera);
        libera = aux;
    }
    free(pilha);
}

void imprimePilha(Pilha *pilha)
{
    Pilha *aux = pilha->anterior;

    for (aux = pilha->anterior; aux != NULL; aux = aux->anterior)
    {
        printf("%d\n", aux->valor);
    }
}

int main()
{
    Pilha *novaPilha = criaPilha();
    push(&novaPilha, 5);
    push(&novaPilha, 6);
    push(&novaPilha, 1);
    push(&novaPilha, 9);
    push(&novaPilha, 8);
    imprimePilha(novaPilha);
    printf("--------------");

    return 0;
}