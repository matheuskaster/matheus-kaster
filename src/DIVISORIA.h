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

/// @brief 
/// @param D 
/// @param e 
void insere_elem_div_car (Divisoria D, Carregador c);

/// @brief 
/// @param D 
/// @param e 
void insere_elem_div_dis (Divisoria D, Disparador d);

/// @brief 
/// @param D 
/// @param id 
/// @param tipo 
/// @return 
Carregador busca_elem_div_car (Divisoria D, int id);

/// @brief 
/// @param D 
/// @param id 
/// @param tipo 
/// @return 
Disparador busca_elem_div_dis (Divisoria D, int id);
/// @brief 
/// @param D 
/// @param tipo 

void libera_div_car (Divisoria D);

void libera_div_dis (Divisoria D);



#endif