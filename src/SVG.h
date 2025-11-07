#ifndef SVG
#define SVG
#include <stdio.h>
#include "CIRCULO.h"
#include "RETANGULO.h"
#include "LINHA.h"
#include "TEXTO.h"
#include "FORMA.h"
#include "GEO.h"


/// @brief Escreve o cabeçalho do arquivo .svg, ou seja, é a declaração <?xml ...?> e a tag <svg ...> com seus atributos que 
/// definem o espaço e as regras para o desenho.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo, já inicializado.
void abre_svg (FILE* arq_svg);

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

/// @brief Passa as caracteísticas da forma para o svg poder escrever.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo, já inicializado.
/// @param f É a forma genérica que será desenhada no svg.
void desenha_forma_svg (FILE* arq_svg, Geometria f);

/// @brief É uma função que recebe um disparador, para acessar sua coordenada, a coordenada final da forma disparada, x e y, e utiliza do svg para 
// ilustrar o deslocamento no eixo vertical e horizontal da forma, ocorrido no disparo.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo, já inicializado.
/// @param d É um ponteiro que aponta para o disparador.
/// @param dx É o deslocamento da forma no eixo x.
/// @param dy É o deslocametno da forma no eixo y.
void desenha_dimensoes_de_disparo(FILE *arq_svg, void* d, double dx, double dy);

/// @brief É uma função que marca um asterisco na posição onde uma forma foi esmagada.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo, já inicializado.
/// @param x É a posição no eixo x onde o asterisco que será desenhado se encontrará.
/// @param y É a posição no eixo y onde o asterisco que será desenhado se encontrará.
void desenha_asterisco(FILE *arq_svg, double x, double y);

/// @brief Escreve o rodapé do arquivo .svg, ou seja, é a tag </svg> que fecha o arquivo svg, indicando a realização com sucesso.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo, já inicializado.
void fecha_svg (FILE* arq_svg);

/// @brief É uma função que desenha todas as formas do chão.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo, já inicializado.
/// @param chao É o local onde as formas recém criadas se encontram e onde elas retornarão ao fim do jogo.
void svg (FILE* arq_svg, Fila chao);


#endif

