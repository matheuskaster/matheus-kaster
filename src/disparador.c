#include "DISPARADOR.h"
#include "CARREGADOR.h"
#include <stdio.h>
typedef struct {
    int id;
    double x;
    double y;
    Carregador car_esq;
    Carregador car_dir;
    Conteudo pd;
} disparador;

Disparador cria_disparador (int id, double x, double y) {
    disparador d = (diparador*)malloc(sizeof(disparador));
    if (d == NULL) {
        printf("Erro ao tentar alocar memória para o disparador.\n");
        exit(1);
    }
    d->id = id;
    d->x = x;
    d->y = y;
    return d;
}

void pd (Disparador d, double x, double y) {
    d->x = x;
    d->y = y;
}

void atch (Disparador d, Carregador car_esq, Carregador car_dir) {
    d->car_esq = car_esq;
    d->car_dir = car_dir;
}

void shft (Disparador d, char lado, int n) {
    if (lado == 'd') {
        if (d->pd != NULL) {
            insere_pilha (car_esq, d->pd);
        }
        d->pd = get_conteudo_topo_pilha (car_dir);
        remover_pilha (car_dir);
        for (int i = 0; i < n-1; i++) {
            insere_pilha (car_esq, d->pd);
            d->pd = get_conteudo_topo_pilha (car_dir);
            remover_pilha (car_dir);
        }
    }
    if (lado == 'e') {
        if (d->pd != NULL) {
            insere_pilha (car_dir, d->pd);
        }
        d->pd = get_conteudo_topo_pilha (car_esq);
        remover_pilha (car_esq);
        for (int i = 0; i < n-1; i++) {
            insere_pilha (car_dir, d->pd);
            d->pd = get_conteudo_topo_pilha (car_esq);
            remover_pilha (car_esq);
        }
    }
}

Forma dispara (Disparador d) {};

double get_x_disparador (Disparador d) {};

double get_y_disparador (Disparador d) {};

void libera_memoria_disparador (Disparador d) {};
