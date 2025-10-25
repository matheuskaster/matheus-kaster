#ifndef SOBREPOSICAO.h
#define SOBREPOSICAO.h
#include "FORMA.h"
#include "CIRCULO.h"
#include "RETANGULO.h"
#include "LINHA.h"
#include "TEXTO.h"

/// @brief É uma função que recebe duas formas, calcula a área delas e verifica existe alguma intersecção das áreas.
/// @param F1 É um void pointer que aponta para a forma que já estava na arena.
/// @param F2 É um void pointer que aponta para a forma que acabou de ser lançada na arena.
/// @return Retorna um booleano que diz que é verdadeiro "true" caso haja sobreposição, ou diz que é falso "false" caso não haja.
bool houve_colisao (F1, F2);

#endif