#include "DISPARADOR.h"
#include "CARREGADOR.h"
#include "PILHA.h"
#include "FILA.h"
#include <stdio.h>
typedef struct {
    int id;
    double x;
    double y;
    Carregador car_esq;
    Carregador car_dir;
    Forma pd;
} disparador;

Disparador cria_disparador (int id, double x, double y) {
    disparador* d = (disparador*)malloc(sizeof(disparador));
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
    ((disparador*)d)->x = x;
    ((disparador*)d)->y = y;
}

void atch (Disparador d, Carregador car_esq, Carregador car_dir) {
    ((disparador*)d)->car_esq = car_esq;
    ((disparador*)d)->car_dir = car_dir;
}

void shft (Disparador d, char lado, int n) {
    if (lado == 'd') {
        if (((disparador*)d)->pd != NULL) {
            insere_pilha (((disparador*)d)->car_esq, ((disparador*)d)->pd);
        }
        ((disparador*)d)->pd = get_conteudo_pilha (((disparador*)d)->car_dir);
        remove_pilha (((disparador*)d)->car_dir);
        for (int i = 0; i < n-1; i++) {
            insere_pilha (((disparador*)d)->car_esq, ((disparador*)d)->pd);
            ((disparador*)d)->pd = get_conteudo_pilha (((disparador*)d)->car_dir);
            remove_pilha (((disparador*)d)->car_dir);
        }
    }
    if (lado == 'e') {
        if (((disparador*)d)->pd != NULL) {
            insere_pilha (((disparador*)d)->car_dir, ((disparador*)d)->pd);
        }
        ((disparador*)d)->pd = get_conteudo_pilha (((disparador*)d)->car_esq);
        remove_pilha (((disparador*)d)->car_esq);
        for (int i = 0; i < n-1; i++) {
            insere_pilha (((disparador*)d)->car_dir, ((disparador*)d)->pd);
            ((disparador*)d)->pd = get_conteudo_pilha (((disparador*)d)->car_esq);
            remove_pilha (((disparador*)d)->car_esq);
        }
    } else {
        printf ("ERRO. Não foi possível identifical qual botão deveria ser apertado.\n");
        exit(1);
    }
}

void dsp (Disparador d, double dx, double dy) {
    ((disparador*)d)->pd->x = ((disparador*)d)->x + dx;
    ((disparador*)d)->pd->y = ((disparador*)d)->y + dy;
    insere_fila (arena, ((disparador*)d)->pd);
    ((disparador*)d)->pd = NULL;
}

double get_x_disparador (Disparador d) {
    return ((disparador*)d)->x;
}

double get_y_disparador (Disparador d) {
    return ((disparador*)d)->y;
}

void libera_memoria_disparador (Disparador d) {}
