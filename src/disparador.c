#include "DISPARADOR.h"
#include <stdio.h>
#include <stdlib.h>
#include "FORMA.h"
#include "CIRCULO.h"
#include "RETANGULO.h"
#include "LINHA.h"
#include "TEXTO.h"
#include "PILHA.h"
#include "FILA.h"
#include "CARREGADOR.h"

#include <stddef.h>

typedef struct {
    int id;
    double x;
    double y;
    Carregador car_esq;
    Carregador car_dir;
    Geometria pd;
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
    d->car_esq = NULL;
    d->car_dir = NULL;
    d->pd = NULL;
    return d;
}

void pd (Disparador d, double x, double y) {
    //Disparador d = busca_elem_div_dis(D, id);
    ((disparador*)d)->x = x;
    ((disparador*)d)->y = y;
}

void atch (Disparador d, Carregador car_esq, Carregador car_dir) {
    //Disparador d = busca_elem_div_dis(D, id);
    ((disparador*)d)->car_esq = car_esq;
    ((disparador*)d)->car_dir = car_dir;
}

void shft (Disparador d, char lado, int n, FILE* arq_txt) {
    //Disparador d = busca_elem_div_dis(D, id);
    printf("id_disparador = %d \n", get_id_disparador((disparador*)d));
    
    if (d == NULL) {
        printf("Erro, o disparador encontrado na divisória é nulo. \n");
    }
    
    if (lado == 'd') {
        if (((disparador*)d)->pd != NULL) {
            insere_carregador (((disparador*)d)->car_dir, ((disparador*)d)->pd);
        }
        ((disparador*)d)->pd = remove_carregador (((disparador*)d)->car_esq);
        arruma_coordenada(((disparador*)d), ((disparador*)d)->pd);
        
        //printf("id_geometria = %d \n", get_id_forma(((disparador*)d)->pd));

        for (int i = 0; i < n-1; i++) {
            insere_carregador (((disparador*)d)->car_dir, ((disparador*)d)->pd);
            ((disparador*)d)->pd = remove_carregador (((disparador*)d)->car_esq);
            arruma_coordenada(((disparador*)d), ((disparador*)d)->pd);
            //remove_pilha (((disparador*)d)->car_esq);
        }
    }
    else if (lado == 'e') {
        if (((disparador*)d)->pd != NULL) {
            insere_carregador (((disparador*)d)->car_esq, ((disparador*)d)->pd);
        }
        ((disparador*)d)->pd = remove_carregador (((disparador*)d)->car_dir);
        arruma_coordenada(((disparador*)d), ((disparador*)d)->pd);
        //remove_pilha (((disparador*)d)->car_dir);
        for (int i = 0; i < n-1; i++) {
            insere_carregador (((disparador*)d)->car_esq, ((disparador*)d)->pd);
            ((disparador*)d)->pd = remove_carregador (((disparador*)d)->car_dir);
            arruma_coordenada(((disparador*)d), ((disparador*)d)->pd);
            //remove_pilha (((disparador*)d)->car_dir);
        }
    } else {
        printf ("ERRO. Não foi possível identificar qual botão deveria ser apertado.\n");
        exit(1);
    }
    //printf("id_geometria = %d \n", get_id_forma(((disparador*)d)->pd));
    fprintf(arq_txt, "Comando assionado 'shft' apertando o botão %c do disparador %d %d vezes.\n", lado, get_id_disparador(d), n);
    if ( ((disparador*)d)->pd != NULL ) {
        fprintf(arq_txt, "A geometria colocada em posição de disparo é a de id: %d, do tipo: %c.\n", get_id_forma(((disparador*)d)->pd), get_tipo_forma(((disparador*)d)->pd));
    }
}

void dsp (Disparador d, double dx, double dy, char eh_visivel, Fila arena, FILE* arq_txt, FILE* arq_svg, int *num_disparos) {
    //Disparador d = busca_elem_div_dis(D, id);
    disparador *disp = (disparador*) d;
    if (disp->pd == NULL) {
        printf("Tentou disparar sem ter forma na posicao de disparo!\n");
        return;
    }

    Geometria g = disp->pd;
    char tipo = get_tipo_forma(g);
    int id_forma = get_id_forma(g);
    double x_forma, y_forma, area_forma;    

    if (tipo == 'c') {
        Circulo c = get_info_forma (g);
        double x_c = get_x_circulo (c);
        double novo_x = x_c + dx;
        set_x_circulo (c, novo_x);

        double y_c = get_y_circulo (c);
        double novo_y = y_c + dy;
        set_y_circulo (c, novo_y);
        x_forma = novo_x;
        y_forma = novo_y;
        area_forma = calcula_area_circulo(c);
    }
    else if (tipo == 'r') {
        Retangulo r = get_info_forma (g);
        double x_r = get_x_retangulo (r);
        double novo_x = x_r + dx;
        set_x_retangulo (r, novo_x);

        double y_r = get_y_retangulo (r);
        double novo_y = y_r + dy;
        set_y_retangulo (r, novo_y);
        x_forma = novo_x;
        y_forma = novo_y;
        area_forma = calcula_area_retangulo(r);
    }
    else if (tipo == 'l') {

        Linha l = get_info_forma (g);
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

        x_forma = novo_x1;
        y_forma = novo_y1;
        area_forma = calcula_area_linha(l);
    }
    else if (tipo == 't') {
        Texto t = get_info_forma (g);
        double x_t = get_x_texto (t);
        double novo_x = x_t + dx;
        set_x_texto (t, novo_x);

        double y_r = get_y_texto (t);
        double novo_y = y_r + dy;
        set_y_texto (t, novo_y);

        x_forma = novo_x;
        y_forma = novo_y;
        area_forma = calcula_area_texto(t);
    }

    if (eh_visivel == 'v') {
        desenha_dimensoes_de_disparo(arq_svg, d, dx, dy);
    }

    fprintf(arq_txt, "Comando assionado 'dsp' disparando o disparador %d.\n", ((disparador*)d)->id);
    fprintf(arq_txt, "A geometria disparada é a de id %d, depois desse comando ela se encontra na arena, com coordenadas X: %.1f e Y:%.1f, ocuparndo uma área de %.2f u.a.\n", get_id_forma(g), x_forma, y_forma, area_forma);

    insere_fila (arena, disp->pd);
    (*num_disparos)++;
    ((disparador*)d)->pd = NULL;
}

void rjd (Disparador d, char lado, double dx, double dy, double ix, double iy, Fila arena, FILE* arq_txt, FILE* arq_svg, int *num_disparos) {
    //Disparador d = busca_elem_div_dis(D, id);
    disparador *disp = (disparador*) d;

    int i = 0;
    if (lado == 'd') {
        while (!esta_vazio(disp->car_esq)) {
            shft (d, lado, 1, arq_txt);
            dsp (d, dx+i*ix, dy+i*iy, 'i', arena, arq_txt, arq_svg, num_disparos);
            i++;
        }
    }
    else if (lado == 'e') {
        while (!esta_vazio(disp->car_dir)) {
            shft (d, lado, 1, arq_txt);
            dsp (d, dx+i*ix, dy+i*iy, 'i', arena, arq_txt, arq_svg, num_disparos);
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

void arruma_coordenada(Disparador d, Geometria g) {
    disparador* dis = ((disparador*)d);
    double x = dis->x;
    double y = dis->y;
    set_x_forma(g, x);
    set_y_forma(g, y);
}

void libera_memoria_disparador (Disparador d) {
    disparador* lmd = (disparador*) d;
    free (lmd);
}

size_t size_of (Disparador d) {
    return sizeof(disparador);
}