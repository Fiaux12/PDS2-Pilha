#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846

typedef struct Circulo
{
    float x;
    float y;
    float raio;
} Circulo;

Circulo *circ_cria(float x, float y, float r)
{
    Circulo *circulo = malloc(sizeof(Circulo));
    circulo->x = x;
    circulo->y = y;
    circulo->raio = r;
    return circulo;
}

void circ_libera(Circulo *c)
{
    free(c);
}

float circ_area(Circulo *c)
{
    float area = M_PI * c->raio * c->raio;
    return area;
}

int circ_concentricos(Circulo *c1, Circulo *c2)
{
    return c1->x == c2->x && c1->y == c2->y;
}

float circ_raio(Circulo *c)
{
    return c->raio;
}
