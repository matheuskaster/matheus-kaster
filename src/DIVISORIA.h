#ifndef DIVISORIA
#define DIVISORIA
#include "CARREGADOR.h"
#include "DISPARADOR.h"

typedef void* Divisoria;

/*
TAD feito com o objetivo de armazenar os diferentes elementos criados, em arrays separados. Para deixar mais limpo e de fácil
acesso, ou seja, deixar o chão e a arena operando só com formas, enquanto os disparadores estão localizados em um vetor só com
disparadores, assim como os carregadores estarão localizados em um vetor só de carregadores.
*/


/// @brief Cria uma divisória feita para armazenar todos os carregadores um único vetor, só com carregadores.
/// @return Retorna uma divisória de carregadores.
Divisoria cria_div_car ();


/// @brief Cria uma divisória feita para armazenar todos os disparadores em um único vetor, só com disparadores.
/// @return Retorna uma divisória de disparadores
Divisoria cria_div_dis ();

/// @brief Coloca um carregador dentro de uma divisória que armazena os carregadores.
/// @param D É o ponteiro para a divisória de carregadores.
/// @param c É um ponteiro que aponta para o carregador que será inserido na divisória.
void insere_elem_div_car (Divisoria D, Carregador c);

/// @brief Coloca um carregador dentro de uma divisória que armazena os disparadores.
/// @param D É o ponteiro para a divisória de disparadores.
/// @param d É um ponteiro que aponta para disparador que será inserido na divisória.
void insere_elem_div_dis (Divisoria D, Disparador d);

/// @brief Função que procura através do id único de cada carregador, o carregador desejado.
/// @param D É o ponteiro para a divisória de carregadores.
/// @param id É o id do carregador desejado.
/// @return Retorna o carregador desejado.
Carregador busca_elem_div_car (Divisoria D, int id);

/// @brief Função que procura através do id único de cada disparador, o disparador desejado.
/// @param D É o ponteiro para a divisória de disparadores.
/// @param id É o id do disparador desejado.
/// @return Retorna o disparador desejado.
Disparador busca_elem_div_dis (Divisoria D, int id);

/// @brief Libera toda a memória alocada pela divisória de carregadores novamente a disponibilizando para uso.
/// @param D É o ponteiro para saber qual divisória terá sua memória liberada.
void libera_div_car (Divisoria D);

/// @brief Libera toda a memória alocada pela divisória de disparadores novamente a disponibilizando para uso.
/// @param D É o ponteiro para saber qual divisória terá sua memória liberada.
void libera_div_dis (Divisoria D);

#endif