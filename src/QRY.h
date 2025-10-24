#ifndef QRY.h
#define QRY.h
#include "GEO.h"
#include "PILHA.h"
#include "FILA.h"
#include "FORMA.h"
#include "DISPARADOR.h"

/// @brief É uma função feita para poder ler o arquivo de entrada qry e executar tudo o que é pedido para ser feito dentro dele.
/// @param chao É onde as formas ficam localizadas no início.
/// @param arq_qry É o arquivo de entrada do tipo .qry.
/// @param path_svg_final É o caminho feito para chegar no arquivo de saída svg, ou seja, localizar em quais pastas está o arquivo para poder acessá-lo.
/// @param path_txt_final É o caminho feito para chegar no arquivo de saída txt, ou seja, localizar em quais pastas está o arquivo para poder acessá-lo.
void qry (Fila chao, FILE* arq_qry, char* path_svg_final, char* path_txt_final);

#endif