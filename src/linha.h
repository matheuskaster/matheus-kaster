#ifndef linha.h
#define linha.h
 
typedef void* (Linha);

/// @brief Cria um linha com os parâmetros informados.
/// @param id Numero inteiro identificador para saber a qual linha ele está se referindo.
/// @param x1 É o menor valor onde uma das extremidades da linha se encontra no eixo x, indicando a sua posição no plano.
/// @param y1 É o menor valor onde uma das extremidades da linha se encontra no eixo y, indicando a sua posição no plano.
/// @param x2 É o maior valor onde uma das extremidades da linha se encontra no eixo x, indicando a sua posição no plano.
/// @param y2 É o maior valor onde uma das extremidades da linha se encontra no eixo y, indicando a sua posição no plano.
/// @param cor Indica a cor da linha.
/// @return Retorna uma linha criada com os parâmetros.
Linha cria_linha (int id, double x1, double y1, double x2, double y2, double r, char* corb, char* corp);

/// @brief O numero inteiro passado de parametro pela funçao se torna o identificador da linha.
/// @param c É um ponteiro que aponta para a linha.
/// @param id É o novo identificador da linha.
void set_id_linha (Linha l, int id);

/// @brief Informa qual é o id da linha.
/// @param l É um ponteiro que aponta para a linha.
/// @return Retorna o id da linha.
int get_id_linha (Linha l);

/// @brief O numero double passado por parametro pela funçao, torna-se o novo x1 da linha, que é o que indica onde esta localizado o canto inferior esquerdo da linha, no eixo x.
/// @param l É um ponteiro que aponta para a linha.
/// @param x1 É o novo x1 da linha.
void set_x1_linha (Linha l, double x1);

/// @brief Informa qual é a menor das coordenadas no eixo x, que indica uma das extremidades da linha.
/// @param l É um ponteiro que aponta para a linha.
/// @return Retorna qual é menor coordenada do eixo x da linha.
double get_x1_linha (Linha l);

/// @brief O numero double passado por parametro pela funçao, torna-se o novo y1 da linha, que é o que indica onde esta localizado o canto inferior esquerdo da linha, no eixo y.
/// @param l É um ponteiro que aponta para a linha.
/// @param y1 É o novo y1 da linha.
void set_y1_linha (Linha l, double y1);

/// @brief Informa qual é a menor das coordenadas no eixo y, que indica uma das extremidades da linha.
/// @param l É um ponteiro que aponta para a linha.
/// @return Retorna qual é menor coordenada no eixo y da linha.
double get_y1_linha (Linha l);

/// @brief O numero double passado por parametro pela funçao, torna-se o novo x2 da linha, que é o que indica onde esta localizado o canto superior direito da linha, no eixo x.
/// @param l É um ponteiro que aponta para a linha.
/// @param x2 É o novo x2 da linha.
void set_x2_linha (Linha l, double x2);

/// @brief Informa qual é a maior das coordenadas no eixo x, que indica uma das extremidades da linha.
/// @param l É um ponteiro que aponta para a linha.
/// @return Retorna o tamanho do raio da linha.
double get_x2_linha (Linha l);

/// @brief O numero double passado por parametro pela funçao, torna-se o novo y2 da linha, que é o que indica onde esta localizado o canto superior direito da linha, no eixo y.
/// @param l É um ponteiro que aponta para a linha.
/// @param y2 É o novo y2 da linha.
void set_y2_linha (Linha l, double y2);

/// @brief Informa qual é a maior das coordenadas no eixo y, que indica uma das extremidades da linha.
/// @param l É um ponteiro que aponta para a linha.
/// @return Retorna qual é a coordenada no ponto y do centro da linha.
double get_y2_linha (Linha l);


/// @brief Informa qual é a cor da linha.
/// @param l É um ponteiro que aponta para a linha.
/// @return Retorna a cor da linha.
char* get_cor (Linha l);

/// @brief Calcula a area da linha.
/// @param r Um ponteiro que aponta para a linha.
/// @return Retorna um numero real float, correspondente ao tamanho dessa area.
double calcula_area_linha (Linha l);
#endif