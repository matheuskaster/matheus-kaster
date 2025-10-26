#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include "FORMA.h"
#include "CIRCULO.h"
#include "RETANGULO.h"
#include "LINHA.h"
#include "TEXTO.h"
#include "SOBREPOSICAO.h"
#include "GEO.h"

typedef struct bounding_box {
    double x_min, x_max, y_min, y_max;
} bb;

double ponto_dist_segmento_quad(double px, double py, double x1, double y1, double x2, double y2) {
    double L2 = pow(x2 - x1, 2) + pow(y2 - y1, 2);
    if (L2 == 0) return pow(px - x1, 2) + pow(py - y1, 2); 

    double t = ((px - x1) * (x2 - x1) + (py - y1) * (y2 - y1)) / L2;
    t = fmax(0, fmin(1, t));

    double proj_x = x1 + t * (x2 - x1);
    double proj_y = y1 + t * (y2 - y1);
    
    return pow(px - proj_x, 2) + pow(py - proj_y, 2);
}

int orientation (double px, double py, double qx, double qy, double rx, double ry) {
    double val = (qy - py) * (rx - qx) - (qx - px) * (ry - qy);
    if (fabs(val) < 1e-9) return 0;
    return (val > 0) ? 1 : 2;
}

bool onSegment(double px, double py, double qx, double qy, double rx, double ry) {
    if (qx <= fmax(px, rx) && qx >= fmin(px, rx) &&
        qy <= fmax(py, ry) && qy >= fmin(py, ry))
       return true;
    return false;
}

bool segmento_intersecta(double p1x, double p1y, double q1x, double q1y, double p2x, double p2y, double q2x, double q2y) {
    int o1 = orientation(p1x, p1y, q1x, q1y, p2x, p2y);
    int o2 = orientation(p1x, p1y, q1x, q1y, q2x, q2y);
    int o3 = orientation(p2x, p2y, q2x, q2y, p1x, p1y);
    int o4 = orientation(p2x, p2y, q2x, q2y, q1x, q1y);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && onSegment(p1x, p1y, p2x, p2y, q1x, q1y)) return true;
    if (o2 == 0 && onSegment(p1x, p1y, q2x, q2y, q1x, q1y)) return true;
    if (o3 == 0 && onSegment(p2x, p2y, p1x, p1y, q2x, q2y)) return true;
    if (o4 == 0 && onSegment(p2x, p2y, q1x, q1y, q2x, q2y)) return true;

    return false;
}

bb get_limite (Geometria F1) {
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
        limite.y_min = get_y_retangulo(r);
        limite.y_max = get_y_retangulo(r) + get_h_retangulo(r);;
    }
    else if (tipo == 'l') {
        Linha l = get_info_forma (F1);

        double x1 = get_x1_linha (l);
        double y1 = get_y1_linha (l);
        double x2 = get_x2_linha (l);
        double y2 = get_y2_linha (l);

        limite.x_min = fmin(x1, x2);
        limite.x_max = fmax(x1, x2);
        limite.y_min = fmin(y1, y2);
        limite.y_max = fmax(y1, y2);
    }
    else if (tipo == 't') {
        Texto t = get_info_forma (F1);
        char a = get_a_texto(t);
        char* txto = get_txto(t);
        
        double comp = strlen(txto) * 10.0;
        
        double alt = 15.0; 
        double x = get_x_texto(t);
        double y = get_y_texto(t);

        limite.y_min = y;
        limite.y_max = y + alt;
        
        if (a == 'i') {
            limite.x_min = x;
            limite.x_max = x + comp;
        } else if (a == 'm') {
            limite.x_min = x - (comp / 2.0);
            limite.x_max = x + (comp / 2.0);
        } else if (a == 'f') {
            limite.x_min = x - comp;
            limite.x_max = x;
        }
    }
    return limite;
}

bool bb_esta_sobreposta (bb l1, bb l2) {
    return (l1.x_max >= l2.x_min && l1.x_min <= l2.x_max && l1.y_max >= l2.y_min && l1.y_min <= l2.y_max);
}

bool houve_colisao (F1, F2){
    bb b1 = get_limite (F1);
    bb b2 = get_limite (F2);

    if (!bb_esta_sobreposta(b1, b2)) return false;

    char t1 = get_tipo_forma (F1);
    char t2 = get_tipo_forma (F2);

    if (t1 == 'c' && t2 == 'c'){
        Circulo c1 = get_info_forma (F1);
        Circulo c2 = get_info_forma (F2);

        double dx = get_x_circulo(c1) - get_x_circulo(c2);
        double dy = get_y_circulo(c1) - get_y_circulo(c2);
        double d_centro_quad = pow(dx,2) + pow(dy,2);
        double d_raios_quad = pow(get_r_circulo(c1) + get_r_circulo(c2), 2);

        if (d_centro_quad <= d_raios_quad) return true;
    }
    else if ((t1 == 'c' && t2 == 'l') || (t2 == 'l') && (t2 == 'c')) {
        Circulo c = (t1 == 'c') ? get_info_forma(F1) : get_info_forma(F2);
        Linha l = (t1 == 'l') ? get_info_forma(F1) : get_info_forma(F2);
        
        double cx = get_x_circulo(c);
        double cy = get_y_circulo(c);
        double cr2 = pow(get_r_circulo(c), 2);
        
        double dist_quad = ponto_dist_segmento_quad(cx, cy, get_x1_linha(l), get_y1_linha(l), get_x2_linha(l), get_y2_linha(l));
        
        if (dist_quad <= cr2) return true;
    }
    else if ((t1 == 'c' && t2 == 't') || (t1 == 't' && t2 == 'c')) {
        Circulo c = (t1 == 'c') ? get_info_forma(F1) : get_info_forma(F2);
        Texto t = (t1 == 't') ? get_info_forma(F1) : get_info_forma(F2);

        double cx = get_x_circulo(c);
        double cy = get_y_circulo(c);
        double cr2 = pow(get_r_circulo(c), 2);
        
        double x1, y1, x2, y2;
        transforma_texto_em_linha(t, &x1, &y1, &x2, &y2);
        
        double dist_quad = ponto_dist_segmento_quad(cx, cy, x1, y1, x2, y2);
        
        if (dist_quad <= cr2) return true;
    }
    else if (t1 == 'r' || t2 == 'r') return true;
    else if (t1 == 'l' && t2 == 'l') {
        Linha l1 = get_info_forma (F1);
        Linha l2 = get_info_forma (F2);
        
        if (segmento_intersecta(get_x1_linha(l1), get_y1_linha(l1), get_x2_linha(l1), get_y2_linha(l1), get_x1_linha(l2), get_y1_linha(l2), get_x2_linha(l2), get_y2_linha(l2))) return true;
    }
    else if ((t1 == 'l' && t2 == 't') || (t1 == 't' && t2 == 'l')) {
        Linha l = (t1 == 'l') ? get_info_forma(F1) : get_info_forma(F2);
        Texto t = (t1 == 't') ? get_info_forma(F1) : get_info_forma(F2);

        double x1t, y1t, x2t, y2t;
        transforma_texto_em_linha (t, &x1t, &y1t, &x2t, &y2t);

        if (segmento_intersecta(get_x1_linha(l), get_y1_linha(l), get_x2_linha(l), get_y2_linha(l), x1t, y1t, x2t, y2t)) return true;
    }
    else if (t1 == 't' && t2 == 't') {
        Texto t1 = get_info_forma (F1);
        Texto t2 = get_info_forma (F2);

        double x1t1, y1t1, x2t1, y2t1;
        transforma_texto_em_linha (t1, &x1t1, &y1t1, &x2t1, &y2t1);
        
        double x1t2, y1t2, x2t2, y2t2;
        transforma_texto_em_linha (t2, &x1t2, &y1t2, &x2t2, &y2t2);

        if (segmento_intersecta(x1t1, y1t1, x2t1, y2t1, x1t2, y1t2, x2t2, y2t2)) return true;
    }
}