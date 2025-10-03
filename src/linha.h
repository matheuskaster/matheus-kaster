#ifndef linha.h
#define linha.h
 
typedef void* (Linha);

/// @brief Cria um linha com os parâmetros informados.
/// @param id Número inteiro identificador para saber a qual linha ele está se referindo.
/// @param x1 É o menor valor onde uma das extremidades da linha se encontra no eixo x (referente ao vértice inferior esquerdo), indicando a sua posição no plano.
/// @param y1 É o menor valor onde uma das extremidades da linha se encontra no eixo y (referente ao vértice inferior esquerdo), indicando a sua posição no plano.
/// @param x2 É o maior valor onde uma das extremidades da linha se encontra no eixo x (referente ao vértice superior direito), indicando a sua posição no plano.
/// @param y2 É o maior valor onde uma das extremidades da linha se encontra no eixo y (referente ao vértice superior direito), indicando a sua posição no plano.
/// @param cor Indica a cor da linha.
/// @return Retorna uma linha criada com os parâmetros.
Linha cria_linha (int id, double x1, double y1, double x2, double y2, double r, char* corb, char* corp);

/// @brief O número inteiro passado de parâmetro na função se torna o novo identificador da linha.
/// @param c É um ponteiro que aponta para a linha.
/// @param id É o novo identificador da linha.
void set_id_linha (Linha l, int id);

/// @brief Informa qual é o id da linha.
/// @param l É um ponteiro que aponta para a linha.
/// @return Retorna o id da linha.
int get_id_linha (Linha l);

/// @brief O número double passado por parâmetro pela função, torna-se o novo x1 da linha, que é o que indica onde esta localizado o x1 no eixo x.
/// @param l É um ponteiro que aponta para a linha.
/// @param x1 É o novo x1 da linha.
void set_x1_linha (Linha l, double x1);

/// @brief Informa qual é a menor das coordenadas no eixo x, que indica uma das extremidades da linha.
/// @param l É um ponteiro que aponta para a linha.
/// @return Retorna qual é menor coordenada do eixo x da linha.
double get_x1_linha (Linha l);

/// @brief O número double passado por parâmetro na função, torna-se o novo y1 da linha, que é o que indica onde esta localizado y1 no eixo y.
/// @param l É um ponteiro que aponta para a linha.
/// @param y1 É o novo y1 da linha.
void set_y1_linha (Linha l, double y1);

/// @brief Informa qual é a menor das coordenadas no eixo y, que indica uma das extremidades da linha.
/// @param l É um ponteiro que aponta para a linha.
/// @return Retorna qual é menor coordenada no eixo y da linha.
double get_y1_linha (Linha l);

/// @brief O número double passado por parâmetro na função, torna-se o novo x2 da linha, que é o que indica onde esta localizado o x2 no eixo x.
/// @param l É um ponteiro que aponta para a linha.
/// @param x2 É o novo x2 da linha.
void set_x2_linha (Linha l, double x2);

/// @brief Informa qual é a maior das coordenadas no eixo x, que indica uma das extremidades da linha.
/// @param l É um ponteiro que aponta para a linha.
/// @return Retorna o tamanho do raio da linha.
double get_x2_linha (Linha l);

/// @brief O número double passado por parâmetro na função, torna-se o novo y2 da linha, que é o que indica onde esta localizado o canto y2 no eixo y.
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

/// @brief Calcula a área da linha considerando a espessura dela como 10 u e vendo a distância entre as estremidades.
/// @param r Um ponteiro que aponta para a linha.
/// @return Retorna um numero real, double, correspondente ao tamanho dessa área.
double calcula_area_linha (Linha l);
#endif