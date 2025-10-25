#ifndef GEO.h
#define GEO.h
#include <stdio.h>
#include "FORMA.h"
#include "FILA.h"

/// @brief É um TAD que utiliza funções de arquivo pra poder ler o .geo, criar as formas que estão no arquivo de entrada e inserir elas no chão.
/// @param chao É o chão do projeto, onde as formas ficam ao serem criadas.
/// @param arq_geo É o arquivo de entrada, do tipo .geo.
void geo (Fila chao, FILE* arq_geo);

#endif