#include "stdio.h"
#include "stdlib.h"
#include "pilha.h"

typedef struct elemento {
    Conteudo chave;
    struct elemento *prox;
} elemento;  

typedef elemento *pont;

typedef struct {
    int tam;
    pont *topo;
} pilha;

Pilha criar_pilha () {
    pilha* p = malloc(sizeof(pilha));
    p->topo = NULL;
    p->tam = 0;
    return ((pilha*)p);
}

int tam_pilha (Pilha p) {
    return ((pilha*)p)->tam;
}

void inserir_pilha (Pilha p, Conteudo chave) {
    pont novo = (pont)malloc(sizeof(elemento));
    if (novo == NULL) return;
    novo->chave = chave;
    novo->prox = ((pilha*)p)->topo;
    ((pilha*)p)->topo = novo;
}

void remover_pilha (Pilha p) {
    if (p == NULL || ((pilha*)p)->topo == NULL) return;
    pont apagar = ((pilha*)p)->topo;
    ((pilha*)p)->topo = ((pilha*)p)->topo->prox;
    free(apagar);
    ((piilha*)p)->tam--;
}

Conteudo get_conteudo_topo_pilha (Pilha p) {
    return ((pilha*)p)->topo->chave;
}

void liberar_pilha (Pilha p) {
    if (p == NULL) return;
    pont atual = ((pilha*)p)->topo;
    while (atual != NULL) {
        pont proximo = ((pont)atual)->prox;
        free(atual);
        atual = proximo;
    }
    free (p);
}

void copiar_pilha (Pilha copia, Pilha auxiliar, Pilha fonte) {
    pont aux = ((pilha*)fonte)->topo;
    while (aux != NULL) {
        inserir_pilha (auxiliar, ((pont)aux)->chave);
        aux = ((pont)aux)->prox;
    }
    aux = ((pilha*)auxiliar)->topo;
    while (aux != NULL) {
        inserir_pilha (copia, ((pont)aux)->chave);
        aux = ((pont)aux)->prox;
    }
    liberar_pilha (auxiliar);
}