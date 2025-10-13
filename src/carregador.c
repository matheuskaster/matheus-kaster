#include "carregador.h"
#include <stdio.h>

typedef struct carregador {
    int id;
} carregador;

Carregador cria_carregador (int id) {
    carregador *car = (carregador*) malloc (sizeof(carregador));
    car->id = id;

    return ((carregador*)car);
}

void load_carregador (Carregador car, int n) {
    for (int i = 0; i < n; i ++) {
        Conteudo forma = get_conteudo_fila (chao);
        Conteudo
        remove_fila (chao);
        insere_pilha (car, forma);
    }
}