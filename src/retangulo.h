#ifndef retangulo.h
#define retangulo.h

typedef void* (Retangulo);


/// @brief Cria um retangulo com os parâmetros informados.
/// @param id Numero inteiro identificador para saber a qual retangulo ele está se referindo.
/// @param x É a coordenada no eixo x no qual a ancora do retangulo se encontra.
/// @param y É a coordenada no eixo y no qual a ancora do retangulo se encontra.
/// @param w É um numero real correspondente a largura do retangulo.
/// @param h É um numero real correspondente a altura do retangulo.
/// @param corb Indica a cor da borda do retangulo.
/// @param corp Indica a cor de preenchimento do retangulo.
/// @return Retorna um retangulo criado com os parâmetros.
Retangulo cria_retangulo (int id, double x, double y, double w, double h, char* corb, char* corp);

/// @brief O numero inteiro passado de parametro pela funçao se torna o identificador do retangulo.
/// @param c É um ponteiro que aponta para o retangulo.
/// @param id É o novo identificador do retangulo.
void set_id_retangulo (Retangulo r, int id);

/// @brief Informa qual é o id do retangulo.
/// @param c É um ponteiro que aponta para o retangulo.
/// @return Retorna o id do retangulo.
int get_id_retangulo (Retangulo r);

/// @brief O numero double passado de parametro pela funçao indica a coordenada no eixo x onde esta localizado a ancora do retangulo.
/// @param c É um ponteiro que aponta para o retangulo.
/// @param x É a coordenada no eixo x na qual a ancora do retangulo se encontra.
void set_x_retangulo (Retangulo c, double x);

/// @brief Informa qual é a coordenada no ponto x da ancora do retangulo.
/// @param c É um ponteiro que aponta para o retangulo.
/// @return Retorna qual é a coordenada no ponto da ancora do retangulo.
int get_x_retangulo (Retangulo r);

/// @brief O numero double passado de parametro pela funçao indica a coordenada no eixo y onde esta localizado a ancora do retangulo.
/// @param c É um ponteiro que aponta para o retangulo.
/// @param y É a coordenada no eixo y na qual a ancora do retangulo se encontra.
void set_y_retangulo (Retangulo r, double y);

/// @brief Informa qual é a coordenada no ponto y da ancora do retangulo.
/// @param c É um ponteiro que aponta para o retangulo.
/// @return Retorna qual é a coordenada no ponto y da ancora do retangulo.
int get_y_retangulo (Retangulo r);

/// @brief O numero passado por parametro na funçao, torna-se a largura do retangulo, tambem passado por parametro.
/// @param r É um ponteiro que aponta para o retangulo.
/// @param w É a largura que o retangulo possui.

void set_w_retangulo (Retangulo r, double w);

/// @brief Informa qual é a largura do retangulo.
/// @param r É um ponteiro que aponta para o retangulo.
/// @return Retorna qual é a largura do retangulo.
int get_w_retangulo (Retangulo r);

/// @brief O ponteiro para um char passado por parametro na funçao aponta para uma sequencia de letras determinam uma cor, e essa cor, por meio da funçao, passa a ser a nova cor de borda do retangulo, tambem passado por parametro.
/// @param r É um ponteiro que aponta para o retangulo.
/// @param corb É a nova cor do retangulo.
void set_corb_retangulo (Retangulo r, char* corb);

/// @brief Informa qual é a cor de borda do retangulo.
/// @param r É um ponteiro que aponta para o retangulo.
/// @return Retorna a cor de borda do retangulo.
char* get_corb_retangulo (Retangulo r);

/// @brief O ponteiro para um char passado por parametro na funçao aponta para uma sequencia de letras determinam uma cor, e essa cor, por meio da funçao, passa a ser a nova cor de preenchimento do retangulo, tambem passado por parametro.
/// @param r É um ponteiro que aponta para o retangulo.
/// @param corp É a nova cor do retangulo.
void set_corp_retangulo (Retangulo r, char* corp);

/// @brief Informa qual é a cor de preenchimento do retangulo.
/// @param r É um ponteiro que aponta para o retangulo.
/// @return Retorna a cor de preenchimento do retangulo.
char* get_corp_retangulo (Retangulo r);

/// @brief Calcula a area do retangulo.
/// @param r Um ponteiro que aponta para o retangulo.
/// @return Retorna um numero real float, correspondente ao tamanho dessa area.
int calcula_area_retangulo (Retangulo r);
#endif