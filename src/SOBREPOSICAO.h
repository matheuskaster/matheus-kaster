#ifndef SOBREPOSICAO.h
#define SOBREPOSICAO.h
#include "FORMA.h"
#include "CIRCULO.h"
#include "RETANGULO.h"
#include "LINHA.h"
#include "TEXTO.h"

/// @brief É uma função que recebe duas formas e verifica existe alguma intersecção entre o perímetro bounding box dessas duas formas.
/// @param F1 É um void pointer que aponta para a forma que já estava na arena. 
/// @param F2 É um void pointer que aponta para a forma que acabou de ser lançada na arena.
/// @return Retorna um booleano que diz que é verdadeiro "1" caso haja sobreposição, ou diz que é falso "0" caso não haja.
bool verifica_colisao (Forma F1, Forma F2);

#endif