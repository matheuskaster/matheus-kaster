#ifndef DIVISORIA.h
#define DIVISORIA.h

typedef void* Divisoria;
typedef void* Elemento;

/*
TAD feito com o objetivo de armazenar os diferentes elementos criados, em arrays separados. Para deixar mais limpo e de fácil
acesso, ou seja, deixar o chão e a arena operando só com formas, enquanto os disparadores estão localizados em um vetor só com
disparadores, assim como os carregadores estarão localizados em um vetor só de carregadores.
*/


/// @brief Cria uma divisória feita para armazenar elementos do mesmo tipo em um único vetor, que contém esse tipo.
/// @return Retorna uma divisória 
Divisoria cria_div ();

/// @brief 
/// @param D 
/// @param e 
void insere_elem_div (Divisoria D, Elemento e);

/// @brief 
/// @param D 
/// @param id 
/// @param tipo 
/// @return 
Elemento busca_elem_div (Divisoria D, int id, char tipo);

/// @brief 
/// @param D 
/// @param tipo 
void libera_div (Divisoria D, char tipo);



#endif