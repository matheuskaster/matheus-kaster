#ifndef FORMA.h
#define FORMA.h
#include <stdio.h>

typedef void* Forma;
typedef forma* Pforma;
 
Forma cria_forma_circulo (char tipo, int id, double x, double y, double r, char *corb, char *corp);

Forma cria_forma_retangulo (char tipo, int id, double x, double y, double w, double h, char *corb, char *corp);

Forma cria_forma_linha (char tipo, int id, double x1, double y1, double x2, double y2, char *cor);

Forma cria_forma_texto (char tipo, int id, double x, double y, char *corb, char *corp, char a, char *txto);

char get_tipo_forma (Forma F);

double get_x_forma (Forma F);

double get_y_forma (Forma F);

Forma get_info_forma (Pforma F);

#endif