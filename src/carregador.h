#ifndef CARREGADOR.h
#define CARREGADOR.h

typedef void *Carregador;

/// @brief Cria um carregador com os parâmetros informados.
/// @param id Número inteiro positivo identificador, para saber a qual círculo ele está se referindo.
/// @return Retorna um círculo criado com os parâmetros.
Carregador cria_carregador (int id);

/// @brief Pega a quantidade desejada de formas, do chão, e as coloca dentro do carregador.
/// @param c É um ponteiro para saber a qual carregador ele se refere.
/// @param n Coloca as n primeiras formas que estão no chão.
void lc (Carregador car, int n, Fila chao);

/// @brief Informa qual é o identificador id, do carregador desejado.
/// @param car É um ponteiro que aponta para um carregador.
/// @return Retorna um número inteiro, que é o id do carregador.
int get_id_carregador (Carregador car);
#endif