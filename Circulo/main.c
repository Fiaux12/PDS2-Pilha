#include <stdio.h>
#include <stdlib.h>
#include "circulo.c"

int main()
{
    printf("Inicializando Circulos\n");
    Circulo *circulo1 = circ_cria(5, 3, 2);
    Circulo *circulo2 = circ_cria(5, 3, 5);
    Circulo *circulo3 = circ_cria(9, 4, 2);

    printf("circulo 1 \n     Area : %.2f\n     Raio: %.2f \n", circ_area(circulo1), circ_raio(circulo1));
    printf("circulo 2 \n     Area : %.2f\n     Raio: %.2f \n", circ_area(circulo2), circ_raio(circulo2));
    printf("circulo 3 \n     Area : %.2f\n     Raio: %.2f \n", circ_area(circulo3), circ_raio(circulo3));
    printf("--------------\n");

    printf("Circulo 1 e 2 sao concentricos? %d \n", circ_concentricos(circulo1, circulo2));
    printf("Circulo 2 e 3 sao concentricos? %d \n", circ_concentricos(circulo2, circulo3));

    printf("Liberando circulos\n");
    circ_libera(circulo1);
    circ_libera(circulo2);
    circ_libera(circulo3);

    return 0;
}