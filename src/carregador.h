#ifndef CARREGADOR
#define CARREGADOR

#include <stdbool.h>
#include "PILHA.h"
#include "FILA.h"

typedef void *Carregador;

/// @brief Cria um carregador com os parâmetros informados.
/// @param id Número inteiro positivo identificador, para saber a qual círculo ele está se referindo.
/// @param p É um ponteiro do tipo void, que aponta para uma pilha, possibilitando utilizá-la diretamente do carregador.
/// @return Retorna um círculo criado com os parâmetros.
Carregador cria_carregador (int id);

/// @brief Pega a quantidade desejada de formas, do chão, e as coloca dentro do carregador.
/// @param id É um numero inteiro positivo que indentifica a qual carregador ele se refere.
/// @param n Coloca as n primeiras formas que estão no chão.
/// @param chao É um ponteiro do tipo void, que aponta para uma fila, possibilitando retirar as formas do chão para carregar o carregador.
/// @param D 
/// @param arq_txt É o arquivo txt que realizará um relatório do que está acontecendo nesse comando.
//void load_carregador (int id, int n, Fila chao, Divisoria D, FILE* arq_txt);
void load_carregador (Carregador car, int n, Fila chao, FILE* arq_txt);

void insere_carregador(Carregador car, Geometria g);

Geometria remove_carregador(Carregador car);

/// @brief O número inteiro passado por parâmetro na função passa a ser o novo número identificador do carregador.
/// @param car É um ponteiro para o carregador que terá seu id alterado.
/// @param id É o novo número int que é responsável por identificar o carregador.
void set_id_carregador (Carregador car, int id);

/// @brief Informa qual é o identificador id, do carregador desejado.
/// @param car É um ponteiro que aponta para o carregador.
/// @return Retorna um número inteiro, que é o id do carregador.
int get_id_carregador (Carregador car);

/// @brief A pilha passada por parâmetro na função passa a nova pilha referente às formas contidas no carregador.
/// @param car É um ponteiro que aponta para o carregador que tera sua pilha alterada.
/// @param p É a nova pilha responsável por armazenar as formas.
//void set_pilha_carregador (Carregador car, Pilha p);

/// @brief Informa qual é a pilha p, do carregador desejado.
/// @param car É um ponteiro que aponta para o carregador.
/// @return Retorna um tipo Pilha, que é a pilha referente ao carregador.
//Pilha get_pillha_carregador (Carregador car);

/// @brief É uma função que libera para o computador utilizar a memória que tinha sido reservada para o carregador.
/// @param car É um ponteiro que aponta para o carregador que terá sua memória liberada.
void libera_memoria_carregador (Carregador car);

/// @brief Verifica se existe alguma forma dentro do carregador.
/// @param car É um ponteiro que aponta para o carregador para verificar se ele está vazio.
/// @return Retorna 'true', se de fato ele está vazio, ou 'false' se tem alguma forma dentro dele.a
bool esta_vazio (Carregador car);

#endif