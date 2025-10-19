#include "CARREGADOR.h"
#include "PILHA.h"
#include "FILA.h"
#include <stdio.h>

typedef struct carregador {
    int id;
} carregador;

Carregador cria_carregador (int id) {
    carregador *car = (carregador*) malloc (sizeof(carregador));
    car->id = id;

    return ((carregador*)car);
}   

void load_carregador (Carregador car, int n, Fila chao) {
    for (int i = 0; i < n; i ++) {
        Forma F = get_conteudo_fila (chao);
        insere_pilha (car, F);
        remove_fila (chao);
    }
}