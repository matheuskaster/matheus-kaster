#include "DISPARADOR.h"
#include "CARREGADOR.h"
#include "FORMA.h"
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
            insere_pilha (((disparador*)d)->car_dir, ((disparador*)d)->pd);
        }
        ((disparador*)d)->pd = get_conteudo_pilha (((disparador*)d)->car_esq);
        remove_pilha (((disparador*)d)->car_esq);
        for (int i = 0; i < n-1; i++) {
            insere_pilha (((disparador*)d)->car_dir, ((disparador*)d)->pd);
            ((disparador*)d)->pd = get_conteudo_pilha (((disparador*)d)->car_dir);
            remove_pilha (((disparador*)d)->car_esq);
        }
    }

    if (lado == 'e') {
        if (((disparador*)d)->pd != NULL) {
            insere_pilha (((disparador*)d)->car_esq, ((disparador*)d)->pd);
        }
        ((disparador*)d)->pd = get_conteudo_pilha (((disparador*)d)->car_dir);
        remove_pilha (((disparador*)d)->car_dir);
        for (int i = 0; i < n-1; i++) {
            insere_pilha (((disparador*)d)->car_esq, ((disparador*)d)->pd);
            ((disparador*)d)->pd = get_conteudo_pilha (((disparador*)d)->car_esq);
            remove_pilha (((disparador*)d)->car_dir);
        }
    } else {
        printf ("ERRO. Não foi possível identificar qual botão deveria ser apertado.\n");
        exit(1);
    }
}

void dsp (Disparador d, double dx, double dy, Fila arena) {
    disparador *D = (disparador*) d;
    Pontprastruct PD = D->pd;
    char tipo = get_tipo_forma (PD);
    if (tipo == 'c') {
        Circulo c = PD->geometrica;
        double x_c = get_x_circulo (c);
        double novo_x = x_c + dx;
        set_x_circulo (c, novo_x);

        double y_c = get_y_circulo (c);
        double novo_y = y_c + dy;
        set_y_circulo (c, novo_y);
    }
    if (tipo == 'r') {
        Retangulo r = PD->geometrica;
        double x_r = get_x_retangulo (r);
        double novo_x = x_r + dx;
        set_x_retangulo (r, novo_x);

        double y_r = get_y_retangulo (r);
        double novo_y = y_r + dy;
        set_y_retangulo (r, novo_y);
    }
    if (tipo == 'l') {

        Linha l = PD->geometrica;
        double x1_l = get_x1_linha (l);
        double novo_x1 = x1_l + dx;
        set_x1_linha (l, novo_x1);

        double x2_l = get_x2_linha (l);
        double novo_x2 = x2_l + dx;
        set_x2_linha (l, novo_x2);

        double y1_l = get_y1_linha (l);
        double novo_y1 = y1_l + dy;
        set_y1_linha (l, novo_y1);

        double y2_l = get_y2_linha (l);
        double novo_y2 = y2_l + dy;
        set_y2_linha (l, novo_y2);
    }
    if (tipo == 't') {
        Texto t = PD->geometrica;
        double x_t = get_x_texto (t);
        double novo_x = x_t + dx;
        set_x_texto (t, novo_x);

        double y_r = get_y_texto (t);
        double novo_y = y_r + dy;
        set_y_texto (t, novo_y);
    }
}

double get_x_disparador (Disparador d) {
    return ((disparador*)d)->x;
}

double get_y_disparador (Disparador d) {
    return ((disparador*)d)->y;
}

void libera_memoria_disparador (Disparador d) {}
