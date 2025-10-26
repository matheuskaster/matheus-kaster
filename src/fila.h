#ifndef FILA
#define FILA
#include "FORMA.h"
#include <stdbool.h>

typedef void *Fila;
typedef struct elemento* pont;

// Arquivo .h revelando de uma forma abstrata o funcionamento de uma fila, feita de forma genérica, pode ser utilizada em qualquer contexto que seja aplicável o conceito de FIFO. OU seja, será possível acessar somente o prifila elemento inserido na ED.


/// @brief Cria dinâmicamente uma fila vazia, sem elementos.
/// @return Retorna um ponteiro para a fila vazia.
Fila cria_fila();

/// @brief Verifica o tamanho da fila, a quantidade de elementos que ela possui.
/// @param f É um ponteiro que aponta para a fila f.
/// @return Retorna qual é o tamanho da fila.
int tam_fila(Fila f);

/// @brief Insere um novo elemento no fim da fila.
/// @param f É um ponteiro que aponta para a fila f.
/// @param n O conteúdo que será inserido na fila, podendo ser uma variável de qualquer tipo.
void insere_fila(Fila f, Geometria n);

/// @brief Remove o elemento do início da fila
/// @param f É um ponteiro que aponta para a fila f.
void remove_fila(Fila f);

/// @brief Acessa o conteúdo do elemento no início da fila e informa o que ele é.
/// @param f É um ponteiro que aponta para a fila f.
/// @return Retorna o conteúdo do início.
pont get_conteudo_fila(Fila f);

/// @brief Pega um ponteiro de um elemento de uma fila e aponta para uma geometria.
/// @param p É um ponteiro que aponta para um elemento.
/// @return Retorna a chave, que é do tipo geometria.
Geometria pont_chave (pont p);

/// @brief Pega um ponteiro de um elemento de uma fila e aponta para o próximo elemento.
/// @param p É um ponteiro que aponta para um elemento.
/// @return Retorna o próximo, que é do tipo pont também.
pont pont_prox (pont p);

/// @brief Libera a memória alocada para a fila.
/// @param f É um ponteiro para a fila.
void libera_fila(Fila fila);

#endif