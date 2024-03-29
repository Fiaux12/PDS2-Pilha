#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento
{
    int valor;
    struct Elemento *anterior;
} Elemento;

typedef struct Pilha
{
    Elemento *topo;
} Pilha;

Pilha *criaPilha()
{
    Pilha *novaPilha = malloc(sizeof(Pilha));
    novaPilha->topo = NULL;
    return novaPilha;
}

void push(Pilha *pilha, int valor)
{
    Elemento *novoItem = malloc(sizeof(Elemento));
    if (novoItem == NULL)
    {
        printf("Erro: falha na alocação de memória\n");
        exit(1);
    }

    novoItem->valor = valor;
    novoItem->anterior = pilha->topo;
    pilha->topo = novoItem;
}

int pilhaVazia(Pilha *pilha) { return (pilha->topo == NULL); }

int pop(Pilha *pilha)
{
    if (pilhaVazia(pilha))
    {
        printf("Pilha vazia\n");
        exit(1);
    }

    // salva antiga pilha (para nao perder referencia a ele)
    Elemento *antigoTopo = pilha->topo;
    int valorAntigoTopo = antigoTopo->valor;

    // atualiza topo
    pilha->topo = antigoTopo->anterior;

    // libera elemento antigo
    free(antigoTopo);

    return valorAntigoTopo;
}

void pilhaLibera(Pilha *pilha)
{
    Elemento *libera = pilha->topo;
    Elemento *aux;
    while (libera != NULL)
    {
        aux = libera->anterior;
        free(libera);
        libera = aux;
    }
    free(pilha);
}

void imprimePilha(Pilha *pilha)
{
    Elemento *aux;
    for (aux = pilha->topo; aux != NULL; aux = aux->anterior)
    {
        printf("%d\n", aux->valor);
    }
}

int main()
{
    printf("Inicializando pilha\n");
    Pilha *novaPilha = criaPilha();
    push(novaPilha, 1);
    push(novaPilha, 2);
    push(novaPilha, 3);
    push(novaPilha, 4);
    push(novaPilha, 5);

    imprimePilha(novaPilha);
    printf("--------------\n");
    while (!pilhaVazia(novaPilha))
    {
        printf("popped: %d\n", pop(novaPilha));
    }

    printf("Liberando Pilha\n");
    pilhaLibera(novaPilha);
    return 0;
}