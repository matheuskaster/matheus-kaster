#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "PILHA.h"
#include "FILA.h"
#include "CARREGADOR.h"

typedef struct carregador {
    int id;
    Pilha p;
} carregador;

Carregador cria_carregador (int id) {
    carregador *car = (carregador*) malloc (sizeof(carregador));
    if (car == NULL) {
        printf ("Erro ao alocar memoria para o carregador");
        exit (1);
    }
    Pilha p = cria_pilha();
    car->id = id;
    car->p = p;

    return ((carregador*)car);
}

//void load_carregador (int id, int n, Fila chao, Divisoria D, FILE* arq_txt) {
void load_carregador (Carregador car, int n, Fila chao, FILE* arq_txt) {

    //Carregador car = busca_elem_div_car(D, id);

    fprintf(arq_txt, "Comando acionado 'lc' carregando o carregador %d com %d formas.\n", get_id_carregador(car), n);

    for (int i = 0; i < n; i ++) {
        Geometria F = remove_fila(chao);
        fprintf(arq_txt, "A geometria carregada é a de id %d, do tipo: %c, que estava na posição X: %.1f e Y: %.1f.\n", get_id_forma(F), get_tipo_forma(F), get_x_forma(F), get_y_forma(F));
        //printf("A geometria carregada é a de id %d, do tipo: %c, que estava na posição X: %.1f e Y: %.1f.\n", get_id_forma(F), get_tipo_forma(F), get_x_forma(F), get_y_forma(F));

        insere_carregador((carregador*)car, F);
    }
}

void insere_carregador(Carregador car, Geometria g) {
    insere_pilha (((carregador*)car)->p, g);
}

Geometria remove_carregador(Carregador car) {
    return remove_pilha(((carregador*)car)->p);
}

void set_id_carregador (Carregador car, int id) {
    ((carregador*)car)->id = id;
}

int get_id_carregador (Carregador car) {
    return (((carregador*)car)->id);
}
/*
void set_pilha_carregador (Carregador car, Pilha p) {
    ((carregador*)car)->p = p;
}

Pilha get_pilha_carregador (car){
    return (((carregador*)car)->p);
}
*/
void libera_memoria_carregador (Carregador car) {
    carregador* lmc = (carregador*) car;
    Pilha lmp = lmc->p;
    free (lmp);
    free (lmc);
}

bool esta_vazio (Carregador car) {
    Geometria F = get_conteudo_pilha (((carregador*)car)->p);
    if (F != NULL) return false;
    return true;
}

size_t size_of_carregador (Carregador car) {
    return sizeof(carregador);
}