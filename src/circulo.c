#include "circulo.h"
#include <stdbool.h>

typedef struct {
    int id;
    double x, y, r;
    char* corb, corp;
} circulo;

Circulo cria_circulo (int id, double x, double y, double r, char* corb, char* corp) {
    circulo *c = circulo malloc(sizeof(circulo));
    c->id = id;
    c->x = x;
    c->y = y;
    c->r = r;
    c->corb = (char*) malloc(strlen(corb)+1);
    if (c->corb == NULL) {
        printf("Erro na alocação de memória para a cor de borda do circulo %d.", c->id);
        exit(1);
    }
    strcpy(c->corb, corb);
    c->corp = (char *)malloc (strlen(corp)+1);
    if (c->corp == NULL) {
        printf("Erro na alocação de memória para a cor de preenchimento do circulo %d.", c->id);
        exit(1);
    }
    strcpy(c->corp, corp);

    return ((circulo*)c);
}