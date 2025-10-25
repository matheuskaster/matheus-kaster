#include "DISPARADOR.h"
#include "CARREGADOR.h"
#include "FORMA.h"
#include "CIRCULO.h"
#include "RETANGULO.h"
#include "LINHA.h"
#include "TEXTO.h"
#include "PILHA.h"
#include "FILA.h"
#include "DIVISORIA.h"
#include <stdio.h>

#include <stddef.h>

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

void pd (int id, double x, double y, Divisoria D) {
    Disparador d = busca_elem_div(D, id, 'd');
    ((disparador*)d)->x = x;
    ((disparador*)d)->y = y;
}

void atch (int id, int car_esq, int car_dir, Divisoria D) {
    Disparador d = busca_elem_div(D, id, 'd');
    ((disparador*)d)->car_esq = car_esq;
    ((disparador*)d)->car_dir = car_dir;
}

void shft (int id, char lado, int n, Divisoria D, FILE* arq_txt) {
    Disparador d = busca_elem_div(D, id, 'd');
    
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

    fprintf(arq_txt, "Comando assionado 'shft' apertando o botão %c do disparador %d %d vezes.\n", lado, ((disparador*)d)->id, n);
    if ( ((disparador*)d)->pd != NULL ) {
        fprintf(arq_txt, "A forma colocada em posição de disparo é a de id: %d, do tipo: %c.\n", get_id_forma(((disparador*)d)->pd), get_tipo_forma(((disparador*)d)->pd));
    }
}

void dsp (int id, double dx, double dy, char eh_visivel, Fila arena, Divisoria D, FILE* arq_txt, int *num_disparos) {
    Disparador d = busca_elem_div(D, id, 'd');
    disparador *disp = (disparador*) d;
    Forma f = disp->pd;
    char tipo = get_tipo_forma(f);

    if (tipo == 'c') {
        Circulo c = get_info_forma (disp);
        double x_c = get_x_circulo (c);
        double novo_x = x_c + dx;
        set_x_circulo (c, novo_x);

        double y_c = get_y_circulo (c);
        double novo_y = y_c + dy;
        set_y_circulo (c, novo_y);
    }
    else if (tipo == 'r') {
        Retangulo r = get_tipo_forma (disp);
        double x_r = get_x_retangulo (r);
        double novo_x = x_r + dx;
        set_x_retangulo (r, novo_x);

        double y_r = get_y_retangulo (r);
        double novo_y = y_r + dy;
        set_y_retangulo (r, novo_y);
    }
    else if (tipo == 'l') {

        Linha l = get_tipo_forma (disp);
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
    else if (tipo == 't') {
        Texto t = get_tipo_forma (disp);
        double x_t = get_x_texto (t);
        double novo_x = x_t + dx;
        set_x_texto (t, novo_x);

        double y_r = get_y_texto (t);
        double novo_y = y_r + dy;
        set_y_texto (t, novo_y);
    }

    fprintf(arq_txt, "Comando assionado 'dsp' disparando o disparador %d.\n", ((disparador*)d)->id);
    fprintf(arq_txt, "A forma disparada é a de id %d, depois desse comando ela se encontra na arena, com coordenadas X: %.1f e Y:%.1f, ocuparndo uma área de %.2f u.a.\n", get_id_forma(disp), get_x_forma(disp), get_y_forma(disp), calcula_area_forma(disp));

    insere_fila (arena, disp);
    (*num_disparos)++;
    ((disparador*)d)->pd = NULL;
}

void rjd (int id, char lado, double dx, double dy, double ix, double iy, Fila arena, Divisoria D, FILE* arq_txt, int *num_disparos) {
    Disparador d = busca_elem_div(D, id, 'd');
    disparador *disp = (disparador*) d;
    Carregador c_e = disp->car_esq;
    Carregador c_d = disp->car_dir;
    pont topo_e = get_conteudo_pilha(c_e);
    pont topo_d = get_conteudo_pilha(c_d);
    int i = 0;
    if (lado == 'd') {
        while (topo_e != NULL) {
            shft (id, lado, 1, D, arq_txt);
            dsp (id, dx+i*ix, dy+i*iy, 'v', arena, D, arq_txt, num_disparos);
            i++;
        }
    }
    if (lado == 'e') {
        while (topo_d != NULL) {
            shft (id, lado, 1, D, arq_txt);
            dsp (id, dx+i*ix, dy+i*iy, 'v', arena, D, arq_txt, num_disparos);
            i++;
        }
    }
}

void set_id_disparador (Disparador d, int id) {
    ((disparador*)d)->id = id;
}

int get_id_disparador (Disparador d) {
    return ((disparador*)d)->id;
}

void set_x_disparador (Disparador d, double x) {
    ((disparador*)d)->x = x;
}

double get_x_disparador (Disparador d) {
    return ((disparador*)d)->x;
}

void set_y_disparador (Disparador d, double y) {
    ((disparador*)d)->y = y;
}

double get_y_disparador (Disparador d) {
    return ((disparador*)d)->y;
}

void libera_memoria_disparador (Disparador d) {
    disparador* lmd = (disparador*) d;
    free (lmd);
}

size_t size_of (Disparador d) {
    return sizeof(disparador);
}