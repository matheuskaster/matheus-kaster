#ifndef DISPARADOR.h
#define DISPARADOR.h

typedef void *Disparador;
typedef void *Carregador;

/// @brief Cria um disparador.
/// @param id É um numero inteiro positivo que indentifica a qual disparador ele se refere.
/// @param x Número real que indica a coordenada no eixo x no qual o disparador se encontra.
/// @param y Número real que indica a coordenada no eixo y no qual o disparador se encontra.
/// @return Retorna um poonteiro para o disparador com os parâmetros informados.
Disparador cria_disparador (int id, double x, double y);

/// @brief Reposiciona o disparador passado por parâmetro para a nova coordanada x e y, também passados por parâmetro.
/// @param d É um ponteiro que aponta para o disparador d.
/// @param x O número double passado por parâmetro na função passa a ser a nova coordenada no eixo x onde está localizado o disparador.
/// @param y O número double passado por parâmetro na função passa a ser a nova coordenada no eixo x onde está localizado o disparador.
void pd (Disparador d, double x, double y);

/// @brief Os carregadores passador por parâmetro são anexados ao disparador escolhido.
/// @param d É um ponteiro que aponta para o disparador que será carregado.
/// @param car_esq É um ponteiro que aponta para qual carregador será colocado no lado esquerdo do Disparador.
/// @param car_dir É um ponteiro que aponta para qual carregador será colocado no lado direito do Disparador.
void atch (Disparador d, Carregador car_esq, Carregador car_dir);

/* 
/// @brief Será informado qual dos botões será apertado podendo ser 'e' para o esquerdo ou 
'd' para o direito, e a quantidade de vezes que isso será feito, ou seja, será retirada a 
última forma que foi colocada no carregador selecionado, e essa será postana posição de 
disparo. Caso já tenha alguma forma em posição de disparo, a forma que já estava naquela 
posição será inserida no outro carregador, liberando a posição de disparo.*/
/// @param d É um ponteiro que indicica qual disparador que está sendo operado.
/// @param lado É uma letra para escolher o lado da carga que será colocado em posição de disparo.
/// @param n É um número inteiro positivo que indica a quantidade de vezes que o botão 
void shft (Disparador d, char lado, int n);

/// @brief Dispara a forma que estava em posição na arena, a uma distância dx e dy da posição do disparador, e deixa sem nenhuma forma essa posição de disparo.
/// @param d É um ponteiro que indica qual disparador será disparado.
/// @return Retorna as informações armazenadas da forma.
void dsp (Disparador d, double dx, double dy, [v|i]);

void rjd (Disparador d, char lado, double dx, double dy, double ix, double iy);

/// @brief Informa um disparador, e espera a função mostrar qual é o falor no eixo x da coordenada que esse disparador se encontra.
/// @param d É um ponteiro que indica de qual disparador ele quer essa informação. 
/// @return Retorna o valor do x do disparador.
double get_x_disparador (Disparador d);

/// @brief Informa um disparador, e espera a função mostrar qual é o falor no eixo y da coordenada que esse disparador se encontra.
/// @param d É um ponteiro que indica de qual disparador ele quer essa informação. 
/// @return Retorna o valor do y do disparador.
double get_y_disparador (Disparador d);

/// @brief Libera a memória associada ao disparador.
/// @param d É um ponteiro que indica de qual disparador será liberada a memória.
void libera_memoria_disparador (Disparador d);

#endif