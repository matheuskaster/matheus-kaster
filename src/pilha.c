#include "PILHA.h"
#include "stdio.h"
#include "stdlib.h"
#include "FORMA.h"

typedef struct elemento {
    Geometria chave;
    struct elemento *prox;
} elemento;

typedef elemento *pont;

typedef struct {
    int tam;
    pont topo;
} pilha;

Pilha cria_pilha () {
    pilha *p = (pilha*)malloc(sizeof(pilha));
    if (p == NULL) {
        printf("Erro ao tentar alocar memória para a criação da pilha. \n");
    }
    p->topo = NULL;
    p->tam = 0;
    return ((pilha*)p);
}

int tam_pilha (Pilha p) {
    return ((pilha*)p)->tam;
}

void insere_pilha (Pilha p, Geometria chave) {
    elemento *novo = (elemento *)malloc(sizeof(elemento));
    if (novo == NULL) return;
    novo->chave = chave;
    novo->prox = ((pilha*)p)->topo;
    ((pilha*)p)->topo = novo;
    ((pilha*)p)->tam++;
}

Geometria remove_pilha (Pilha p) {
    if (p == NULL || ((pilha*)p)->topo == NULL) {
        printf("Tentando remover de pilha vazia!\n");
        return NULL;
    }
    pont apagar = ((pilha*)p)->topo;
    Geometria ret = apagar->chave;
    ((pilha*)p)->topo = ((pilha*)p)->topo->prox;
    free(apagar);
    ((pilha*)p)->tam--;
    return ret;
}

Geometria get_conteudo_pilha (Pilha p) {
    if (p == NULL || ((pilha*)p)->topo == NULL) {
        return NULL;
    }
    elemento* e = (elemento*) ((pilha*)p)->topo;
    Geometria g = (Geometria) e->chave;
    printf("%d", get_id_forma(g));
    return ((pont)((pilha*)p)->topo)->chave;
} 

void libera_pilha (Pilha p) {
    if (p == NULL) return;
    pilha* _p = ((pilha*)p);
    pont atual = _p->topo;
    while (atual != NULL) {
        pont proximo = ((pont)atual)->prox;
        free(atual);
        atual = proximo;
    }
    free (_p);
}