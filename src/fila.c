#include "stdio.h"
#include "stdlib.h"
#include "CIRCULO.h"
#include "RETANGULO.h"
#include "LINHA.h"
#include "TEXTO.h"
#include "FORMA.h"
#include "FILA.h"

typedef struct elemento {
    Forma chave;
    struct elemento *prox;
} elemento;

typedef struct {
    int tam;
    pont inicio;
    pont fim;
} fila;

Fila cria_fila () {
    fila *f = (fila*)malloc(sizeof(fila));
    if (f == NULL) {
        printf("Erro ao tentar alocar memória para a criação da fila. \n");
    }
    f->inicio = NULL;
    f->fim = NULL;
    f->tam = 0;
    return ((fila*)f);
}

int tam_fila (Fila f) {
    return ((fila*)f)->tam;
}

void insere_fila (Fila f, Forma chave) {
    pont novo = (pont)malloc(sizeof(elemento));
    if (novo == NULL) return;
    novo->chave = chave;
    novo->prox = NULL;
    if (((fila*)f)->inicio == NULL) {
        ((fila*)f)->inicio = novo;
    } else {
    ((fila*)f)->fim->prox = novo;
    }

    ((fila*)f)->fim = novo;
    ((fila*)f)->tam++;
}

void remove_fila (Fila f) {
    if (f == NULL || ((fila*)f)->inicio == NULL) return;
    pont apagar = ((fila*)f)->inicio;
    ((fila*)f)->inicio = ((fila*)f)->inicio->prox;
    if (((fila*)f)->inicio == NULL) {
        ((fila*)f)->fim == NULL;
    }
    free(apagar);
    ((fila*)f)->tam--;
}

pont get_conteudo_fila (Fila f) {
    if (f == NULL || ((fila*)f)->inicio == NULL) {
        return;
    }
    return ((fila*)f)->inicio;
}

pont anda_fila (pont atual, Fila f) {
    return atual->prox;
}

void libera_fila (Fila f) {
    if (f == NULL) return;
    pont atual = ((fila*)f)->inicio;
    while (atual != NULL) {
        pont proximo = ((pont)atual)->prox;
        free(atual);
        atual = proximo;
    }
    free (f);
}