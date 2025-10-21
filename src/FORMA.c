#include <stdio.h>
#include "FORMA.h"
#include "CIRCULO.h"
#include "RETANGULO.h"
#include "LINHA.h"
#include "TEXTO.h"
#include "DISPARADOR.h"
#include "PILHA.h"
#include <math.h>

typedef struct {
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
        return get_id_linha (( ((forma*)F)->geometrica ));
    }
    else if (((forma*)F)->tipo == 't') {
        return get_id_texto (( ((forma*)F)->geometrica) );
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
        return get_x1_linha (( ((forma*)F)->geometrica ));
    }
    else if (((forma*)F)->tipo == 't') {
        return get_x_texto (( ((forma*)F)->geometrica) );
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
        return get_y1_linha (( ((forma*)F)->geometrica ));
    }
    else if (((forma*)F)->tipo == 't') {
        return get_y_texto (( ((forma*)F)->geometrica) );
    }
}

Forma get_info_forma (Pforma F) {
    return ((forma*)F)->geometrica;
}