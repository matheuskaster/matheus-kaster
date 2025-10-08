#include "stdio.h"
#include "stdlib.h"
#include "pilha.h"

typedef struct elemento {
    Conteudo chave;
    struct elemento* prox;
} elemento;  

typedef struct pilha {
    int tam;
    pilha* topo;
} pilha;

Pilha criar_pilha () {
    pilha* p = malloc(sizeof(pilha));
    p->topo = NULL;
    p->tam = 0;
    return ((pilha*)p);
}

void inserir_pilha (Pilha p) {

}