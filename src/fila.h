#ifndef fila_h
#define fila_h
#include <stdbool.h>

typedef void *Fila;
typedef void *Conteudo;


// Arquivo .h revelando de uma forma abstrata o funcionamento de uma fila, feita de forma genérica, pode ser utilizada em qualquer contexto que seja aplicável o conceito de FIFO. OU seja, será possível acessar somente o prifila elemento inserido na ED.


/// @brief Cria dinâmicamente uma fila vazia, sem elementos.
/// @return Retorna um ponteiro para a fila vazia.
Fila criar_fila();

/// @brief Insere um novo elemento no fim da fila.
/// @param f É um ponteiro que aponta para a fila f.
/// @param n O conteúdo que será inserido na fila, podendo ser uma variável de qualquer tipo.
void inserir_fila(Fila f, Conteudo n);

/// @brief Remove o elemento do início da fila
/// @param f É um ponteiro que aponta para a fila f.
void remover_inicio_fila(Fila f);

/// @brief Acessa o conteúdo do elemento no início da fila e informa o que ele é.
/// @param f É um ponteiro que aponta para a fila f.
/// @return Retorna o conteúdo do início.
Conteudo get_conteudo_inicio_fila(Fila f);

/// @brief Copia uma fila fonte para outra 
/// @param copia Nova fila copiada, com os mesmos elemento da anterior.
/// @param fonte Fila original, inalterada. 
void copiar_fila (Fila fopia, Fila fonte);

/// @brief Verifica o tamanho da fila, a quantidade de elementos que ela possui.
/// @param f É um ponteiro que aponta para a fila f.
/// @return Retorna qual é o tamanho da fila.
int tam_fila(Fila f);

/// @brief Libera a memória alocada para a fila.
/// @param f É um ponteiro para a fila.
void liberar_fila(Fila fila);

#endif