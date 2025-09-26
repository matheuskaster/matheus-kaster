#ifndef circulo.h
#define circulo.h
 
typedef void* (Circulo);

/// @brief Cria um circulo com os parâmetros informados.
/// @param id Numero inteiro identificador para saber a qual circulo ele está se referindo.
/// @param x É a coordenada no eixo x no qual o centro do circulo se encontra;
/// @param y É a coordenada no eixo y no qual o centro do circulo se encontra;
/// @param r Indica o tamanho do raio do ciculo.
/// @param corb Indica a cor da borda do ciculo.
/// @param corp Indica a cor de preenchimento do circulo.
/// @return Retorna um circulo criado com os parâmetros.
Circulo cria_circulo (int id, double x, double y, double r, char* corb, char* corp);


/// @brief O numero inteiro passado de parametro pela funçao se torna o identificador do circulo.
/// @param c É um ponteiro que aponta para o circulo.
/// @param id É o novo identificador do circulo.
void set_id_circulo (Circulo c, int id);


/// @brief Informa qual é o id do circulo.
/// @param c É um ponteiro que aponta para o circulo.
/// @return Retorna o id do circulo.
int get_id_circulo (Circulo c);

/// @brief O numero double passado de parametro pela funçao indica a coordenada no eixo x onde esta localizado o centro do circulo.
/// @param c É um ponteiro que aponta para o circulo.
/// @param x É a coordenada no eixo x na qual o centro do circulo se encontra.
void set_x_circulo (Circulo c, double x);

/// @brief Informa qual é a coordenada no ponto x do centro do circulo.
/// @param c É um ponteiro que aponta para o circulo.
/// @return Retorna qual é a coordenada no ponto x do centro do circulo.
int get_x_circulo (Circulo c);

/// @brief O numero double passado de parametro pela funçao indica a coordenada no eixo y onde esta localizado o centro do circulo.
/// @param c É um ponteiro que aponta para o circulo.
/// @param y É a coordenada no eixo y na qual o centro do circulo se encontra.
void set_y_circulo (Circulo c, double y);

/// @brief Informa qual é a coordenada no ponto y do centro do circulo.
/// @param c É um ponteiro que aponta para o circulo.
/// @return Retorna qual é a coordenada no ponto y do centro do circulo.
int get_y_circulo (Circulo c);

/// @brief O numero double passado de parametro pela funçao, torna-se o raio do circulo.
/// @param c É um ponteiro que aponta para o circulo.
/// @param r É o novo raio do circulo.
void set_r_circulo (Circulo c, double r);

/// @brief Informa qual é o tamanho do raio do circulo.
/// @param c É um ponteiro que aponta para o circulo.
/// @return Retorna o tamanho do raio do circulo.
int get_r_circulo (Circulo c);

/// @brief O ponteiro para um char passado por parametro na funçao aponta para uma sequencia de letras determinam uma cor, e essa cor, por meio da funçao, passa a ser a nova cor de borda do circulo, tambem passado por parametro.
/// @param c É um ponteiro que aponta para o circulo.
/// @param corb É a nova cor do circulo.
void set_corb_circulo (Circulo c, char* corb);

/// @brief Informa qual é a cor de borda do circulo.
/// @param c É um ponteiro que aponta para o circulo.
/// @return Retorna a cor de borda do circulo.
char* get_corb_circulo (Circulo c);

/// @brief O ponteiro para um char passado por parametro na funçao aponta para uma sequencia de letras determinam uma cor, e essa cor, por meio da funçao, passa a ser a nova cor de preenchimento do circulo, tambem passado por parametro.
/// @param c É um ponteiro que aponta para o circulo.
/// @param corp É a nova cor do circulo.
void set_corp_circulo (Circulo c, char* corp);

/// @brief Informa qual é a cor de preenchimento do circulo.
/// @param c É um ponteiro que aponta para o circulo.
/// @return Retorna a cor de preenchimento do circulo.
char* get_corp_circulo (Circulo c);

/// @brief Calcula a area do circulo.
/// @param c É um ponteiro que aponta para o circulo.
/// @return Retorna um numero real float, correspondente ao tamanho dessa area.
double calcula_area_circulo (Circulo c);
#endif