#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

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