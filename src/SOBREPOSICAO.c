#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "SOBREPOSICAO.h"
#include "FORMA.h"
#include "CIRCULO.h"
#include "RETANGULO.h"
#include "LINHA.h"
#include "TEXTO.h"
#include "GEO.h"

typedef struct bounding_box {
    double x_min, x_max, y_min, y_max;
} bb;

bb get_limite (Forma F1) {
    bb limite;
    char tipo = get_tipo_forma(F1);

    if (tipo == 'c') {
        Circulo c = get_info_forma (F1);

        limite.x_min = get_x_circulo(c) - get_r_circulo(c);
        limite.x_max = get_x_circulo(c) + get_r_circulo(c);
        limite.y_min = get_y_circulo(c) - get_r_circulo(c);
        limite.y_max = get_y_circulo(c) + get_r_circulo(c);
    }
    else if (tipo == 'r') {
        Retangulo r = get_info_forma (F1);

        limite.x_min = get_x_retangulo (r);
        limite.x_max = get_x_retangulo(r) + get_w_retangulo(r);
        limite.y_min = get_y_retangulo(r) - get_h_retangulo(r);
        limite.y_max = get_h_retangulo(r);
    }
    else if (tipo == 'l') {
        Linha l = get_info_forma (F1);

        limite.x_min = get_x1_linha (l);
        limite.x_max = get_x2_linha (l);
        limite.y_min = get_y1_linha (l);
        limite.y_max = get_x2_linha (l);
    }
    else if (tipo == 't') {
        Texto t = get_info_forma (F1);

        limite.x_min = 
        limite.x_max = 
        limite.y_min = 
        limite.y_max = 
    }
    return limite;
}

bool bb_esta_sobreposta (bb l1, bb l2) {
    return (l1.x_max >= l2.x_min && l1.x_min <= l2.x_max && l1.y_max >= l2.y_min && l1.y_min <= l2.y_max);
}

bool houve_colisao (F1, F2){
    bb b1 = get_limite (F1);
    bb b2 = get_limite (F2);

    if (!bb_esta_sobreposta) return false;

    char t1 = get_tipo_forma (F1);
    char t2 = get_tipo_forma (F2);

    if (t1 == 'c' && t2 == 'c'){
        Circulo c = get_info_forma (F1);

        double dx = get_x_circulo(c) - get_x_circulo(c);
        double dy = get_y_circulo(c) - get_y_circulo(c);
        double d_centro_circulos = sqrt (pow(dx,2) + pow(dy,2));

        if (d_centro_circulos <= (getRCirculo(F1) + getRCirculo(F2))) return true;
    }
    else if ((t1 == 'c' && t2 == 'l') || (t2 == 'l') && (t2 == 'c')) {}
    else if ((t1 == 'c' && t2 == 't') || (t2 == 't') && (t2 == 'c')) {}
    else if (t1 == 'r' || t2 == 'r') return true;
    else if (t1 == 'l' && t2 == 'l') {}
    else if ((t1 == 'l' && t2 == 't') || (t2 == 't') && (t2 == 'l')) {}
    else if (t1 == 't' && t2 == 't') {}
}







