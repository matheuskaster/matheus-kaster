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
/// @param id É um numero inteiro positivo que indentifica a qual disparador ele se refere.
/// @param x O número double passado por parâmetro na função passa a ser a nova coordenada no eixo x onde está localizado o disparador.
/// @param y O número double passado por parâmetro na função passa a ser a nova coordenada no eixo x onde está localizado o disparador.
/// @param D 
void pd (int id, double x, double y, Divisoria D);

/// @brief Os carregadores passador por parâmetro são anexados ao disparador escolhido.
/// @param id É um numero inteiro positivo que indentifica a qual disparador ele se refere.
/// @param car_esq É um ponteiro que aponta para qual carregador será colocado no lado esquerdo do Disparador.
/// @param car_dir É um ponteiro que aponta para qual carregador será colocado no lado direito do Disparador.
/// @param D 
void atch (int id, int car_esq, int car_dir, Divisoria D);

/* 
/// @brief Será informado qual dos botões será apertado podendo ser 'e' para o esquerdo ou 
'd' para o direito, e a quantidade de vezes que isso será feito, ou seja, será retirada a 
última forma que foi colocada no carregador selecionado, e essa será postana posição de 
disparo. Caso já tenha alguma forma em posição de disparo, a forma que já estava naquela 
posição será inserida no outro carregador, liberando a posição de disparo.*/
/// @param id É um numero inteiro positivo que indentifica a qual disparador ele se refere.
/// @param lado É uma letra para escolher o lado da carga que será colocado em posição de disparo.
/// @param n É um número inteiro positivo que indica a quantidade de vezes que o botão.
/// @param D 
/// @param arq_txt É o arquivo txt que realizará um relatório do que está acontecendo nesse comando.
void shft (int id, char lado, int n, Disparador D, FILE* arq_txt);

/// @brief Dispara a forma que estava em posição na arena, a uma distância dx e dy da posição do disparador, e deixa sem nenhuma forma essa posição de disparo.
/// @param id É um numero inteiro positivo que indentifica a qual disparador ele se refere.
/// @param dx É a variação do deslocamento da coordenada inicial da forma na posição de disparo até a nova posição dela, ou seja,
/// sai da coordenada onde o disparador se encontra, e aumenta dx unidades no valor do eixo x.
/// @param dy É a variação do deslocamento da coordenada inicial da forma na posição de disparo até a nova posição dela, ou seja,
/// sai da coordenada onde o disparador se encontra, e aumenta dy unidades no valor do eixo y.
/// @param eh_visivel É um char que determina se será ilustrado as dimensões do disparo, recebe 'v', caso seja visível e 'i', se for invisível.
/// @param arena 
/// @param D
/// @param arq_txt É o arquivo txt que realizará um relatório do que está acontecendo nesse comando.
/// @param num_disparos Conta quantas vezes o disparados disparou alguma forma e depois escreve esse dado no txt.
void dsp (int id, double dx, double dy, char eh_visivel, Fila arena, Disparador D, FILE* arq_txt, int* num_disparos);

/// @brief O número inteiro passado por parâmetro na função passa a ser o novo número identificador do disparador.
/// @param d É um ponteiro para o disparador que terá seu id alterado.
/// @param id É o novo número int responsável por identificar o disparador. 
void set_id_disparador (Disparador d, int id);

/// @brief Informa qual é o identificador id, do disparador.
/// @param d É um ponteiro que indica de qual disparador ele quer essa informação.
/// @return Retorna o valor do id do disparador.
int get_id_disparador (Disparador d);

/// @brief O número double passado por parâmetro na função passa a ser o novo valor no eixo x da coordenada que esse disparador se encontra.
/// @param d É um ponteiro para o disparador que terá seu x alterado.
/// @param x É o novo número responsável por indicar onde está localizado o disparador no eixo x.
void set_x_disparador (Disparador d, double x);

/// @brief Informa um disparador, e espera a função mostrar qual é o valor no eixo x da coordenada que esse disparador se encontra.
/// @param d É um ponteiro que indica de qual disparador ele quer essa informação. 
/// @return Retorna o valor do x do disparador.
double get_x_disparador (Disparador d);

/// @brief O número double passado por parâmetro na função passa a ser o novo valor no eixo y da coordenada que esse disparador se encontra.
/// @param d É um ponteiro para o disparador que terá seu y alterado.
/// @param y É o novo número responsável por indicar onde está localizado o disparador no eixo y.
void set_y_disparador (Disparador d, double y);

/// @brief Informa um disparador, e espera a função mostrar qual é o valor no eixo y da coordenada que esse disparador se encontra.
/// @param d É um ponteiro que indica de qual disparador ele quer essa informação. 
/// @return Retorna o valor do y do disparador.
double get_y_disparador (Disparador d);

/// @brief Libera a memória associada ao disparador.
/// @param d É um ponteiro que indica de qual disparador será liberada a memória.
void libera_memoria_disparador (Disparador d);

#endif