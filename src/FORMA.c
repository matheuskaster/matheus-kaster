#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "CIRCULO.h"
#include "RETANGULO.h"
#include "LINHA.h"
#include "FORMA.h"
#include "TEXTO.h"
#include "DISPARADOR.h"
#include "PILHA.h"
#include <math.h>

static int ULTIMO_ID = 0;

typedef struct forma {
    Forma geometrica;
    char tipo;
} forma;

Forma cria_forma_circulo (char tipo, int id, double x, double y, double r, char* corb, char* corp) {
    forma *F = (forma*)malloc(sizeof(forma));
    if (F == NULL){
        printf("Erro na alocação de memória para a criação da forma. \n");
        exit (1);
    }
    F->geometrica = cria_circulo (id, x, y, r, corb, corp);
    F->tipo = 'c';
    return ((forma*)F);
}

Forma cria_forma_retangulo (char tipo, int id, double x, double y, double w, double h, char* corb, char* corp) {
    forma *F = (forma*)malloc(sizeof(forma));
    if (F == NULL){
        printf("Erro na alocação de memória para a criação da forma. \n");
        exit (1);
    }
    F->geometrica = cria_retangulo (id, x, y, w, h, corb, corp);
    F->tipo = 'r';
    return ((forma*)F);
}

Forma cria_forma_linha (char tipo, int id, double x1, double y1, double x2, double y2, char *cor) {
    forma *F = (forma*)malloc(sizeof(forma));
    if (F == NULL){
        printf("Erro na alocação de memória para a criação da forma. \n");
        exit (1);
    }
    F->geometrica = cria_linha (id, x1, y1, x2, y2, cor);
    F->tipo = 'l';
    return ((forma*)F);
}

Forma cria_forma_texto (char tipo, int id, double x, double y, char *corb, char *corp, char a, char *txto) {
    forma *F = (forma*)malloc(sizeof(forma));
    if (F == NULL){
        printf("Erro na alocação de memória para a criação da forma. \n");
        exit (1);
    }
    F->geometrica = cria_texto (id, x, y, corb, corp, a, txto);
    F->tipo = 't';
    return ((forma*)F);
}

Forma get_info_forma (Pforma F) {
    return ((forma*)F)->geometrica;
}

char get_tipo_forma (Forma F) {
    return ((forma*)F)->tipo;
}

int get_id_forma (Forma F) {

    if (F == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((forma*)F)->tipo == 'c') {
        return get_id_circulo( ((forma*)F)->geometrica );
    }
    else if (((forma*)F)->tipo == 'r') {
        return get_id_retangulo( ((forma*)F)->geometrica ); 
    }
    else if (((forma*)F)->tipo == 'l') {
        return get_id_linha( ((forma*)F)->geometrica );
    }
    else if (((forma*)F)->tipo == 't') {
        return get_id_texto( ((forma*)F)->geometrica );
    }
}

double get_x_forma(Forma F){

    if (F == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((forma*)F)->tipo == 'c') {
        return get_x_circulo( ((forma*)F)->geometrica );
    }
    else if (((forma*)F)->tipo == 'r') {
        return get_x_retangulo( ((forma*)F)->geometrica ); 
    }
    else if (((forma*)F)->tipo == 'l') {
        return get_x1_linha( ((forma*)F)->geometrica );
    }
    else if (((forma*)F)->tipo == 't') {
        return get_x_texto( ((forma*)F)->geometrica );
    }
}

double get_y_forma(Forma F){

    if (F == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((forma*)F)->tipo == 'c') {
        return get_y_circulo( ((forma*)F)->geometrica );
    }
    else if (((forma*)F)->tipo == 'r') {
        return get_y_retangulo( ((forma*)F)->geometrica ); 
    }
    else if (((forma*)F)->tipo == 'l') {
        return get_y1_linha( ((forma*)F)->geometrica );
    }
    else if (((forma*)F)->tipo == 't') {
        return get_y_texto( ((forma*)F)->geometrica );
    }
}

double get_area_forma (Forma F) {
    if (F == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((forma*)F)->tipo == 'c') {
        return calcula_area_circulo( ((forma*)F)->geometrica );
    }
    else if (((forma*)F)->tipo == 'r') {
        return calcula_area_retangulo( ((forma*)F)->geometrica ); 
    }
    else if (((forma*)F)->tipo == 'l') {
        return calcula_area_linha( ((forma*)F)->geometrica );
    }
    else if (((forma*)F)->tipo == 't') {
        return calcula_area_texto( ((forma*)F)->geometrica );
    }
}

void set_corb_forma (Forma F, char *corb) {
    if (F == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((forma*)F)->tipo == 'c') {
        set_corb_circulo( ((forma*)F)->geometrica, corb );
    }
    else if (((forma*)F)->tipo == 'r') {
        set_corb_retangulo( ((forma*)F)->geometrica, corb ); 
    }
    else if (((forma*)F)->tipo == 'l') {
        set_cor( ((forma*)F)->geometrica, corb );
    }
    else if (((forma*)F)->tipo == 't') {
        set_corb_texto( ((forma*)F)->geometrica, corb );
    }
}

char* get_corb_forma(Forma F) {
    if (F == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((forma*)F)->tipo == 'c') {
        return get_corb_circulo( ((forma*)F)->geometrica );
    }
    else if (((forma*)F)->tipo == 'r') {
        return get_corb_retangulo( ((forma*)F)->geometrica ); 
    }
    else if (((forma*)F)->tipo == 'l') {
        return get_cor( ((forma*)F)->geometrica );
    }
    else if (((forma*)F)->tipo == 't') {
        return get_corb_texto( ((forma*)F)->geometrica );
    }
}

void set_corp_forma (Forma F, char *corp) {
    if (F == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((forma*)F)->tipo == 'c') {
        set_corp_circulo( ((forma*)F)->geometrica, corp );
    }
    else if (((forma*)F)->tipo == 'r') {
        set_corp_retangulo( ((forma*)F)->geometrica, corp ); 
    }
    else if (((forma*)F)->tipo == 'l') return;
    else if (((forma*)F)->tipo == 't') {
        set_corp_texto( ((forma*)F)->geometrica, corp );
    }
}

char* get_corp_forma(Forma F) {
    if (F == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((forma*)F)->tipo == 'c') {
        return get_corp_circulo( ((forma*)F)->geometrica );
    }
    else if (((forma*)F)->tipo == 'r') {
        return get_corp_retangulo( ((forma*)F)->geometrica ); 
    }
    else if (((forma*)F)->tipo == 'l') {
        char *cor = get_cor_linha( ((forma*)F)->geometrica );
        if (cor[0] != '#') return;
        int R, G, B;
        sscanf(cor, "#%02x%02x%02x", &R, &G, &B);
        int R_complem = 255 - R;
        int G_complem = 255 - G;
        int B_complem = 255 - B;
        char* cor_complem;
        sprintf (cor_complem, "#%02X%02X%02X", R_complem, G_complem, B_complem);
        return cor_complem;
    }
    else if (((forma*)F)->tipo == 't') {
        return get_corp_texto( ((forma*)F)->geometrica );
    }
}

double get_area_forma(Forma F) {
    if (F == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((forma*)F)->tipo == 'c') {
        return calcula_area_circulo( ((forma*)F)->geometrica );
    }
    else if (((forma*)F)->tipo == 'r') {
        return calcula_area_retangulo( ((forma*)F)->geometrica ); 
    }
    else if (((forma*)F)->tipo == 'l') {
        return calcula_area_linha( ((forma*)F)->geometrica );
    }
    else if (((forma*)F)->tipo == 't') {
        return calcula_area_texto( ((forma*)F)->geometrica );
    }
}

void armazena_ultimo_id(int ultimo_id) {
    ULTIMO_ID = ultimo_id + 1;
}

int get_ultimo_id() {
    return ULTIMO_ID;
}

Forma clona_forma(Forma F) {
    if (F == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    int novo_id = get_ultimo_id();

    if (((forma*)F)->tipo == 'c') {
        Circulo c = get_info_forma (F);
        double x = get_x_circulo(c);
        double y = get_y_circulo(c);
        double r = get_r_circulo(c);
        char* corb = get_corb_circulo(c);
        char* corp = get_corp_circulo(c);
        ULTIMO_ID++;
        return cria_forma_circulo ('c', novo_id, x, y, r, corb, corp);
    }
    else if (((forma*)F)->tipo == 'r') {
        Retangulo r = get_info_forma(F);
        double x = get_x_retangulo(r);
        double y = get_y_retangulo(r);
        double w = get_w_retangulo(r);
        double h = get_h_retangulo(r);
        char* corb = get_corb_retangulo(r);
        char* corp = get_corp_retangulo(r);
        ULTIMO_ID++;
        return cria_forma_retangulo('r', novo_id, x, y, w, h, corb, corp);
    }
    else if (((forma*)F)->tipo == 'l') {
        Linha l = get_info_forma(F);
        double x1 = get_x1_linha(l);
        double y1 = get_y1_linha(l);
        double x2 = get_x2_linha(l);
        double y2 = get_y2_linha(l);
        char* cor = get_cor(l);
        ULTIMO_ID++;
        return cria_forma_linha('l', novo_id, x1, y1, x2, y2, cor);
    }
    else if (((forma*)F)->tipo == 't') {
        Texto t = get_info_forma(F);
        double x = get_x_texto(t);
        double y = get_y_texto(t);
        char* corb = get_corb_texto(t);
        char* corp = get_corp_texto(t);
        char* a = get_a_texto(t);
        char* txto = get_txto(t);
        ULTIMO_ID++;
        return cria_forma_texto('t', novo_id, x, y, corb, corp, a, txto);
    }
}

void inverte_cores_forma(Forma F) {
    if (F == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((forma*)F)->tipo == 'c') {
        char *cbc = get_corb_circulo( ((forma*)F)->geometrica );
        char *cpc = get_corp_circulo( ((forma*)F)->geometrica );
        set_corb_circulo(((forma*)F)->tipo, cpc);
        set_corp_circulo(((forma*)F)->tipo, cbc);
    }
    else if (((forma*)F)->tipo == 'r') {
        char *cbr = get_corb_retangulo( ((forma*)F)->geometrica );
        char *cpr = get_corp_retangulo( ((forma*)F)->geometrica );
        set_corb_retangulo(((forma*)F)->tipo, cpr);
        set_corp_retangulo(((forma*)F)->tipo, cbr);
    }
    else if (((forma*)F)->tipo == 'l') {
        char *cor = get_cor_linha( ((forma*)F)->geometrica );
        if (cor[0] != '#') return;
        int R, G, B;
        sscanf(cor, "#%02x%02x%02x", &R, &G, &B);
        int R_complem = 255 - R;
        int G_complem = 255 - G;
        int B_complem = 255 - B;
        char *nova_cor_borda;
        sprintf (nova_cor_borda, "#%02X%02X%02X", R_complem, G_complem, B_complem);
        set_cor_linha (nova_cor_borda);
    }
    else if (((forma*)F)->tipo == 't') {
        char *cbt = get_corb_texto( ((forma*)F)->geometrica );
        char *cpt = get_corp_texto( ((forma*)F)->geometrica );
        set_corb_texto(((forma*)F)->tipo, cpt);
        set_corp_texto(((forma*)F)->tipo, cbt);
    }
}

void libera_forma(Forma F) {
}