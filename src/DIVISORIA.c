#include <stdio.h>
#include "DISPARADOR.h"
#include "CARREGADOR.h"
#include "DIVISORIA.h"

typedef struct {
    Elemento* elementos;
    int quantidade_elementos;
} divisoria;

Divisoria cria_div () {
    divisoria* div = (divisoria*)malloc(sizeof(divisoria));
    if (div == NULL) {
        printf("Erro na tentativa de alocar memória para a estrutura.\n");
        return;
    }
    div->elementos = (Elemento*)malloc(sizeof(Elemento));
    div->quantidade_elementos = 0;
    return div;
}

void insere_elem_div (Divisoria D, Elemento e) {
    divisoria* div = (divisoria*) D;

    int tam = div->quantidade_elementos;
    
    div->elementos = (Elemento*) realloc (div->elementos, sizeof(Elemento) * (tam)+1);

    div->elementos[tam] = e;
    div->quantidade_elementos++;
}

Elemento busca_elem_div (Divisoria D, int id, char tipo) {
    divisoria* div = (divisoria*) D;
    Elemento e;
    if (tipo == 'c') {
        for (int i = 0; i < div->quantidade_elementos; i++) {
            e = div->elementos[i];
            if (get_id_carregador(e) == id) return e;
        }
    } else if (tipo == 'd') {
        for (int i = 0 ; i < div->quantidade_elementos; i++) {
            e = div->elementos[i];
            if (get_id_disparador(e) == id) return e;
        }
    }
    return NULL;
}

void libera_div (Divisoria D, char tipo) {
    divisoria* div = (divisoria*) D;
    Elemento e;
    if (tipo == 'c') { 
        for (int i = 0 ; i < div->quantidade_elementos; i++) {
            e = div->elementos[i];
            libera_memoria_carregador(e);
        }
    }
    if (tipo == 'd') {
        for (int i = 0; i < div->quantidade_elementos; i++) {
            e = div->elementos[i];
            libera_memoria_disparador(e);
        }
    }
    free(D);
}