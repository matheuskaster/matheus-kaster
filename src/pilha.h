#ifndef pilha_h
#define pilha_h
#include <stdbool.h>

typedef void *Pilha;
typedef void *Conteudo;


// Arquivo .h revelando de uma forma abstrata o funcionamento de uma pilha, feita de forma genérica, pode ser utilizada em qualquer contexto que seja aplicável o conceito de LIFO. OU seja, será possível acessar somente o último elemento inserido na ED.


/// @brief Cria dinâmicamente uma pilha vazia, sem elementos.
/// @return Retorna um ponteiro para a pilha vazia.
Pilha criar_pilha();

/// @brief Verifica o tamanho da pilha, a quantidade de elementos que ela possui.
/// @param p É um ponteiro que aponta para a pilha p.
/// @return Retorna qual é o tamanho da pilha.
int tam_pilha(Pilha p);

/// @brief Insere um novo elemento no topo da pilha.
/// @param p É um ponteiro que aponta para a pilha p.
/// @param n O conteúdo que será inserido na pilha, podendo ser uma variável de qualquer tipo.
void inserir_pilha(Pilha p, Conteudo n);

/// @brief Remove o elemento do topo da pilha
/// @param p É um ponteiro que aponta para a pilha p.
void remover_topo_pilha(Pilha p);

/// @brief Acessa o conteúdo do elemento no topo da pilha e informa o que ele é.
/// @param p É um ponteiro que aponta para a pilha p.
/// @return Retorna o conteúdo do topo.
Conteudo get_conteudo_topo_pilha(Pilha p);

/// @brief Copia uma pilha fonte para outra 
/// @param copia Nova pilha copiada, com os mesmos elemento da anterior.
/// @param fonte Pilha original. 
void copiar_pilha (Pilha copia, Pilha fonte);

/// @brief liberar memória da pilha.
/// @param p É um ponteiro para a pilha.
void liberar_pilha(Pilha pilha);

#endif