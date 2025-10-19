#ifndef SVG.h
#define SVG.h
#include <stdio.h>
#include "FORMA.h"
#include "GEO.h"


/// @brief Abre o arquivo svg e verifica se ele exite, permitindo o uso dele para ilustrar o jogo.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo.
/// @param caminho É um ponteiro para char, para poder guardar qual que é o caminho para acessar aquele caminho em específico.
void abre_svg (FILE **arq_svg, char *caminho);

/// @brief Passa as características do círculo para o svg poder o desenhar.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo.
/// @param c É um ponteiro que aponta para o círculo.
void desenha_circulo_svg (FILE* arq_svg, Circulo c);

/// @brief Passa as características do retângulo para o svg poder o desenhar.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo.
/// @param r É um ponteiro que aponta para o retângulo.
void desenha_retangulo_svg (FILE* arq_svg, Retangulo r);

/// @brief Passa as características da linha para o svg poder a desenhar.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo.
/// @param l É um ponteiro que aponta para a linha.
void desenha_linha_svg (FILE* arq_svg, Linha l);

/// @brief Passa as características do texto para o svg poder o escrever.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo.
/// @param t É um ponteiro que aponta para o texto.
void desenha_texto_svg (FILE* arq_svg, Texto t, Estilo ts);

/// @brief Fecha o arquivo svg, inferindo que foi tudo realizado com sucesso.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo.
void fecha_svg (FILE* arq_svg);


#endif