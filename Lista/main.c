#include <stdio.h>
#include <stdlib.h>
#include "lista-encadeada.c"

int main()
{
    printf("Inicializando lista encadeada\n");
    Lista *novaLista = lista_cria();

    novaLista = lista_insere(novaLista, 1);
    novaLista = lista_insere(novaLista, 2);
    novaLista = lista_insere(novaLista, 3);
    novaLista = lista_insere(novaLista, 4);
    novaLista = lista_insere(novaLista, 5);
    lista_imprime(novaLista);
    printf("------------------------\n");

    novaLista = lista_retira(novaLista, 2);
    lista_imprime(novaLista);

    lista_libera(novaLista);

    return 0;
}