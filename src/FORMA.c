#include <stdio.h>
#include <stdbool.h>
#include "CIRCULO.h"
#include "RETANGULO.h"
#include "LINHA.h"
#include "FORMA.h"
#include "TEXTO.h"
#include "DISPARADOR.h"
#include "PILHA.h"
#include <math.h>

static int MAIOR_ID = 0;

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
        return get_cor( ((forma*)F)->geometrica );
    }
    else if (((forma*)F)->tipo == 't') {
        return get_corp_texto( ((forma*)F)->geometrica );
    }
}

void get_corb_forma(Forma F) {
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

void armazenaMaiorId(int maior_id) {
    MAIOR_ID = maior_id + 1;
}

int getMaiorId() {
    return MAIOR_ID;
}

Forma clona_forma(Forma F) {
    if (F == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((forma*)F)->tipo == 'c') {
        double x = get_x_circulo( ((forma*)F)->geometrica );
        double y = get_y_circulo( ((forma*)F)->geometrica );
        double r = get_r_circulo( ((forma*)F)->geometrica );
        char* corb = get_corb_circulo( ((forma*)F)->geometrica );
        char* corp = get_corp_circulo( ((forma*)F)->geometrica );
        MAIOR_ID++;
        return cria_circulo (id, x, y, r, corb, corp);
    }
    else if (((forma*)F)->tipo == 'r') {
        double x = get_x_retangulo( ((forma*)F)->geometrica );
        double y = get_y_retangulo( ((forma*)F)->geometrica );
        double w = get_w_retangulo( ((forma*)F)->geometrica );
        double h = get_h_retangulo( ((forma*)F)->geometrica );
        char* corb = get_corb_retangulo( ((forma*)F)->geometrica );
        char* corp = get_corp_retangulo( ((forma*)F)->geometrica );
        MAIOR_ID++;
        return cria_retangulo(id, x, y, w, h, corb, corp);
    }
    else if (((forma*)F)->tipo == 'l') {
        double x1 = get_x1_linha( ((forma*)F)->geometrica );
        double y1 = get_y1_linha( ((forma*)F)->geometrica );
        double x2 = get_x2_linha( ((forma*)F)->geometrica );
        double y2 = get_y2_linha( ((forma*)F)->geometrica );
        char* cor = get_cor( ((forma*)F)->geometrica );
        MAIOR_ID++;
        return cria_linha(id, x1, y1, x2, y2, cor);
    }
    else if (((forma*)F)->tipo == 't') {
        double x = get_x_texto( ((forma*)F)->geometrica );
        double y = get_y_texto( ((forma*)F)->geometrica );
        char* corb = get_corb_texto( ((forma*)F)->geometrica );
        char* corp = get_corp_texto( ((forma*)F)->geometrica );
        char* a = get_a_texto( ((forma*)F)->geometrica );
        char* txto = get_txto( ((forma*)F)->geometrica );
        MAIOR_ID++;
        return cria_texto(id, x, y, corb, corp, a, txto);
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
    else if (((forma*)F)->tipo == 't') {
        char *cbt = get_corb_texto( ((forma*)F)->geometrica );
        char *cpt = get_corp_texto( ((forma*)F)->geometrica );
        set_corb_texto(((forma*)F)->tipo, cpt);
        set_corp_texto(((forma*)F)->tipo, cbt);
    }
}

void libera_forma(Forma F) {
}