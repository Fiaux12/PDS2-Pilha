#include <stdio.h>
#include <stdlib.h>
#include "lista-duplamente-encadeada.c"

int main()
{
    printf("Inicializando lista duplamente encadeada\n");
    ListaDE *novaLista = listaDE_cria();

    novaLista = listaDE_insere(novaLista, 1);
    novaLista = listaDE_insere(novaLista, 2);
    novaLista = listaDE_insere(novaLista, 3);
    novaLista = listaDE_insere(novaLista, 4);
    novaLista = listaDE_insere(novaLista, 5);
    listaDE_imprime(novaLista);
    printf("\n------------------------\n");

    novaLista = listaDE_retira(novaLista, 2);
    listaDE_imprime(novaLista);

    return 0;
}