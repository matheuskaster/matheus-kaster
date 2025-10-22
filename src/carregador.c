#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include "PILHA.h"
#include "FILA.h"
#include "CARREGADOR.h"

typedef struct carregador {
    int id;
    Pilha p;
} carregador;

Carregador cria_carregador (int id, Pilha p) {
    carregador *car = (carregador*) malloc (sizeof(carregador));
    if (car == NULL) {
        printf ("Erro ao alocar memoria para o carregador");
        exit (1);
    }
    car->id = id;
    car->p = p;

    return ((carregador*)car);
}

void load_carregador (Carregador car, int n, Fila chao) {
    for (int i = 0; i < n; i ++) {
        Forma F = get_conteudo_fila (chao);
        insere_pilha (((carregador*)car)->p, F);
        remove_fila (chao);
    }
}

void set_id_carregador (Carregador car, int id) {
    ((carregador*)car)->id = id;
}

int get_id_carregador (Carregador car) {
    return (((carregador*)car)->id);
}

void set_pilha_carregador (Carregador car, Pilha p) {
    ((carregador*)car)->p = p;
}

Pilha get_pilha_carregador (car){
    return (((carregador*)car)->p);
}

void libera_memoria_carregador (Carregador car) {
    carregador* lmc = (carregador*) car;
    Pilha lmp = lmc->p;
    free (lmp);
    free (lmc);
}

bool esta_vazio (Carregador car) {
    Forma F = get_conteudo_pilha (car);
    if (F != NULL) return false;
    else return true;
}

size_t size_of_carregador (Carregador car) {
    return sizeof(carregador);
}