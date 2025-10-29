#ifndef PILHA
#define PILHA
#include "FORMA.h"
#include <stdbool.h>

typedef void *Pilha;


// Arquivo .h revelando de uma forma abstrata o funcionamento de uma pilha, feita de forma genérica, pode ser utilizada em qualquer contexto que seja aplicável o conceito de LIFO. OU seja, será possível acessar somente o último elemento inserido na ED.


/// @brief Cria dinâmicamente uma pilha vazia, sem elementos.
/// @return Retorna um ponteiro para a pilha vazia.
Pilha cria_pilha();

/// @brief Verifica o tamanho da pilha, a quantidade de elementos que ela possui.
/// @param p É um ponteiro que aponta para a pilha p.
/// @return Retorna qual é o tamanho da pilha.
int tam_pilha(Pilha p);

/// @brief Insere um novo elemento no topo da pilha.
/// @param p É um ponteiro que aponta para a pilha p.
/// @param n O conteúdo que será inserido na pilha, podendo ser uma variável de qualquer tipo.
void insere_pilha(Pilha p, Geometria chave);

/// @brief Remove o elemento do topo da pilha
/// @param p É um ponteiro que aponta para a pilha p.
Geometria remove_pilha(Pilha p);

/// @brief Acessa o conteúdo do elemento no topo da pilha e informa o que ele é.
/// @param p É um ponteiro que aponta para a pilha p.
/// @return Retorna o conteúdo do topo.
Geometria get_conteudo_pilha(Pilha p);

/// @brief liberar memória da pilha.
/// @param p É um ponteiro para a pilha.
void libera_pilha(Pilha pilha);

#endif