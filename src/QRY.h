#ifndef QRY
#define QRY
#include "GEO.h"
#include "PILHA.h"
#include "FILA.h"
#include "FORMA.h"
#include "DISPARADOR.h"

/*
/// @brief Monta um caminho para chegar no arquivo a partir de um diretório base e um nome de arquivo.
/// @param path_qry_completo Um vetor para armazenar o resultado.
/// @param entrada O diretório.
/// @param arq_qry O nome do arquivo.

void monta_path_completo(char* path_qry_completo, char* entrada, char* arq_qry);

/// @brief Removendo a extensão de um arquivo.
/// @param arq_qry O nome do arquivo com extensão.
/// @param nome_base_qry Um vetor de char para receber o resultado.
void extrai_nome_base(char* arq_qry, char* nome_base_qry);
*/
/// @brief É uma função feita para poder ler o arquivo de entrada qry e executar tudo o que é pedido para ser feito dentro dele.
/// @param chao É onde as formas ficam localizadas no início.
/// @param file_qry É o arquivo de entrada do tipo .qry.
/// @param file_svg É o arquivo de saída, com as ilustrações, depois de ter sido processado pelo qry.
/// @param file_txt É o arquivo de saída, com o relatório final, depois de ter sido processado pelo qry.
void qry (Fila chao, FILE* file_qry, FILE* file_svg_qry, FILE* file_txt);

#endif