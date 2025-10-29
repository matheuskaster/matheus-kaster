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
Geometria remove_fila(Fila f);

/// @brief 
/// @param f 
/// @return 
Fila clona_fila(Fila f);

/// @brief Libera a memória alocada para a fila.
/// @param f É um ponteiro para a fila.
void libera_fila(Fila fila);

#endif

