#include <stdio.h>
#include <stdlib.h>
#include "fila.c"

int main()
{
    printf("Inicializando pilha\n");
    Fila *fila = fila_cria();

    fila_insere(fila, 1);
    fila_insere(fila, 2);
    fila_insere(fila, 3);
    fila_insere(fila, 4);
    fila_insere(fila, 5);
    fila_imprime(fila);

    printf("\n");
    fila_retira(fila);
    fila_retira(fila);

    fila_imprime(fila);

    fila_libera(fila);

    return 0;
}
