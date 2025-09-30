#ifndef texto.h
#define texto.h
 
typedef void* (Texto);
typedef void* (Estilo);

/// @brief Cria um texto com as informaçoes relacionadas a cada um dos parametros.
/// @param id É o identificador, para saber como se referir a esse texto em especifico.
/// @param x É a posicao no eixo x, na qual esta localizada a ancora do texto.
/// @param y É a posicao no eixo y, na qual esta localizada a ancora do texto.
/// @param corb É a cor da borda de cada um dos caracteres do texto.
/// @param corp É a cor de preenchimento de cada um dos caracteres do texto.
/// @param a É um char, feito para poder identificar sobre qual parte do texto ele se refere (começo, meio, ou fim).
/// @param txto É o parametro que associa a forma do texto.
/// @return Retorna um texto criado com os parametros informados.
Texto cria_texto (int id, double x, double y, char* corb, char* corp, double a, char* txto);

/// @brief O numero inteiro passado por parametro pela funçao, torna-se o identificador para saber a qual texto ele se refere.
/// @param c É um ponteiro que aponta para o texto.l
/// @param id É o novo identificador do texto.
void set_id_texto (Texto t, int id);

/// @brief Acessa o texto informado atraves do parametro e mostra qual é o numero identificador dele.
/// @param t É um ponteiro que aponta para o texto.
/// @return Retorna um numero inteiro que é o identificador do texto especificado.
int get_id_texto (Texto t);

/// @brief O double passado por parametro pela funçao, torna-se a posiçao referente a qual coordenada ele se encontra no eixo x.
/// @param t É um ponteiro que aponta para o texto.
/// @param x É a nova coordenada no eixo x, onde esta localizado esse texto.
void set_x_texto (Texto t, double x);

/// @brief Acessa o texto informado pelo parametro e mostra qual é a coordenada no eixo x, na qual esta localizada o texto.
/// @param t É um ponteiro que aponta para o texto.
/// @return Retorna um doble representando a coordenada do eixo x que esta localizada o texto.
int get_x_texto (Texto t);

/// @brief O double passado por parametro pela funçao, torna-se a posiçao referente a qual coordenada ele se encontra no eixo y.
/// @param t É um ponteiro que aponta para o texto.
/// @param x É a nova coordenada no eixo y, onde esta localizado esse texto.
void set_y_texto (Texto t, double y);

/// @brief Acessa o texto informado pelo parametro e mostra qual é a coordenada no eixo y, na qual esta localizada o texto.
/// @param t É um ponteiro que aponta para o texto.
/// @return Retorna um doble representando a coordenada do eixo y que esta localizada o texto.
int get_y_texto (Texto t);

/// @brief O ponteiro para um char passado por parametro na funçao aponta para uma sequencia de letras determinam uma cor, e essa cor, por meio da funçao, passa a ser a nova cor de borda do texto, tambem passado por parametro.
/// @param r É um ponteiro que aponta para o texto.
/// @param corb É a nova cor do texto.
void set_corb_texto (Texto t, char* corb);

/// @brief Informa qual é a cor de borda do texto.
/// @param t É um ponteiro que aponta para o texto.
/// @return Retorna a cor de borda do texto.
char* get_corb_texto (Texto t);

/// @brief O ponteiro para um char passado por parametro na funçao aponta para uma sequencia de letras determinam uma cor, e essa cor, por meio da funçao, passa a ser a nova cor de preenchimento do texto, tambem passado por parametro.
/// @param t É um ponteiro que aponta para o texto.
/// @param corp É a nova cor do texto.
void set_corp_texto (Texto t, char* corp);

/// @brief Informa qual é a cor de preenchimento do texto.
/// @param t É um ponteiro que aponta para o texto.
/// @return Retorna a cor de preenchimento do texto.
char* get_corp_texto (Texto t);

/// @brief Informa qual é a posição relativa do texto, podendo ser i, no inicio; m, no meio, ou f, quando é o fim do texto.
/// @param t É um ponteiro que aponta para o texto.
/// @return Retorna qual é a posição relativa do texto.
char* get_a_texto (Texto t);

// TADSs relacionados ao estilo do texto:

/// @brief Cria um estilo que sera atribuido a um texto.
/// @param family familia da fonte, podendo ser, como opção, alguma das seguintes: (sans/sans-serif, serif, cursive).
/// @param weight expessura da fonte, podendo ser, como opção, alguma das seguintes: ( n: normal, b: bold, b+: bolder,l: | lighter).
/// @param size tamanho da fonte.
/// @return Retorna o estilo criado com os parâmetros informados.
Estilo cria_estilo(char* family, char* weight, char* size);

/// @brief O char ponteiro passado por parâmetro na função, torna-se a familia da fonte.
/// @param ts É um ponteiro para o estilo do texto.
/// @param family É a nova familia da fonte.
void setFamily(Estilo ts, char *family); 

/// @brief Informam qual é a familia da fonte do texto.
/// @param ts É um ponteiro para o estilo do texto.
/// @return Retorna a familia da fonte.
char* getFamily(Estilo ts);

/// @brief O char ponteiro passado por parâmetro na função, torna-se a expessura da fonte.
/// @param ts É um ponteiro para o estilo do texto.
/// @param weight É a nova expessura da fonte.
void setWeight(Estilo ts, char *weight);

/// @brief Informam qual é a expessura da fonte do texto.
/// @param ts É um ponteiro para o estilo do texto.
/// @return Retorna a expessura da fonte.
char* getWeight(Estilo ts);

/// @brief O char ponteiro passado por parâmetro na função, torna-se o tamanho da fonte.
/// @param ts É um ponteiro para o estilo do texto.
/// @param size É o novo tamanho da fonte
void setSize(Estilo ts, char *size);

/// @brief Informam qual é o tamanho da fonte do texto.
/// @param ts É um ponteiro para o estilo do texto.
/// @return Retorna o tamanho da fonte.
char* getSize(Estilo ts);

#endif