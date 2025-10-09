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
    pont topo;
} pilha;

Pilha criar_pilha () {
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

void inserir_pilha (Pilha p, Conteudo chave) {
    pont novo = (pont)malloc(sizeof(elemento));
    if (novo == NULL) return;
    novo->chave = chave;
    novo->prox = ((pilha*)p)->topo;
    ((pilha*)p)->topo = novo;
    ((pilha*)p)->tam++;
}

void remover_pilha (Pilha p) {
    if (p == NULL || ((pilha*)p)->topo == NULL) return;
    pont apagar = ((pilha*)p)->topo;
    ((pilha*)p)->topo = ((pilha*)p)->topo->prox;
    free(apagar);
    ((pilha*)p)->tam--;
}

Conteudo get_conteudo_topo_pilha (Pilha p) {
    if (p == NULL || ((pilha*)p)->topo == NULL) {
        return;
    }
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