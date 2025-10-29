#include <stdio.h>
#include <stdlib.h>
#include "DISPARADOR.h"
#include "CARREGADOR.h"
#include "DIVISORIA.h"
#include "PILHA.h"

typedef struct {
    Carregador* carregadores;
    int quantidade_carregadores;
} divisoria_car;

typedef struct {
    Disparador* disparadores;
    int quantidade_disparadores;
} divisoria_dis;

Divisoria cria_div_car () {
    divisoria_car* dc = (divisoria_car*)malloc(sizeof(divisoria_car));
    if (dc == NULL) {
        printf("Erro na tentativa de alocar memória para a estrutura.\n");
        return;
    }
    dc->carregadores = (Carregador*)malloc(sizeof(Carregador)*100);
    dc->quantidade_carregadores = 0;
    return dc;
}
Divisoria cria_div_dis () {
    divisoria_dis* dd = (divisoria_dis*)malloc(sizeof(divisoria_dis));
    if (dd == NULL) {
        printf("Erro na tentativa de alocar memória para a estrutura.\n");
        return;
    }
    dd->disparadores = (Disparador*)malloc(sizeof(Disparador)*100);
    dd->quantidade_disparadores = 0;
    return dd;
}


void insere_elem_div_car (Divisoria D, Carregador c) {
    divisoria_car* dc = (divisoria_car*) D;

    int tam = dc->quantidade_carregadores;
    
    //dc->carregadores = (Carregador*) realloc (dc->carregadores, sizeof(Carregador) * (tam)+1);

    ((Carregador*)dc->carregadores)[tam] = c;
    dc->quantidade_carregadores++;
}
void insere_elem_div_dis (Divisoria D, Disparador d) {
    divisoria_dis* dd = (divisoria_dis*) D;

    int tam = dd->quantidade_disparadores;
    
    //dd->disparadores = (Disparador*) realloc (dd->disparadores, sizeof(Disparador) * (tam)+1);

    ((Disparador*)dd->disparadores)[tam] = d;
    dd->quantidade_disparadores++;
} 

Carregador busca_elem_div_car (Divisoria D, int id) {
    divisoria_car* div = (divisoria_car*) D;
    Carregador c;
    for (int i = 0; i < div->quantidade_carregadores; i++) {
        c = div->carregadores[i];
        if (get_id_carregador(c) == id) return c;
    }
    c = cria_carregador(id);
    insere_elem_div_car(div, c);
    return c;
}
Disparador busca_elem_div_dis (Divisoria D, int id) {
    divisoria_dis* div = (divisoria_dis*) D;
    Disparador d;
    for (int i = 0 ; i < div->quantidade_disparadores; i++) {
        d = div->disparadores[i];
        if (get_id_disparador(d) == id) return d;
    }
    int x = 1.0, y = 1.0;
    d = cria_disparador(id, x, y);
    insere_elem_div_dis(div, d);
    return d;
    
}

void libera_div_car (Divisoria D) {
    if (D == NULL) return;
    divisoria_car* div = (divisoria_car*) D;
    Carregador c; 
    for (int i = 0 ; i < div->quantidade_carregadores; i++) {
        c = div->carregadores[i];
        libera_memoria_carregador(c);
    }
    free(div->carregadores);
    free(D);
}

void libera_div_dis (Divisoria D) {
    if (D == NULL) return;
    divisoria_dis* div = (divisoria_dis*) D;
    Disparador d;
    for (int i = 0; i < div->quantidade_disparadores; i++) {
        d = div->disparadores[i];
        libera_memoria_disparador(d);
    }
    free(div->disparadores);
    free(D);
}