#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CIRCULO.h"
#include "RETANGULO.h"
#include "LINHA.h"
#include "TEXTO.h"

#include "SVG.h"

void abre_svg (FILE **arq_svg, char* caminho) {
    *arq_svg = fopen (caminho, "w");
    if (arq_svg == NULL) {
        printf("O aquivo não exite. \n");
        exit(1);
    }
    fprintf(arq_svg,"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n");
    fprintf(arq_svg,"<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" width=\"1000\" height=\"1000\">\n");
    fprintf(arq_svg,"</g>\n");
}


void desenha_circulo_svg (FILE* arq_svg, Circulo c) {
    fprintf(arq_svg, "<circle id=\"%d\" style=\"fill:%s;fill-opacity:0.5;stroke:%s\" r=\"%lf\" cy=\"%lf\" cx=\"%lf\" />\n", get_id_circulo(c), get_corp_circulo(c), get_corb_circulo(c), get_r_circulo(c), get_y_circulo(c), get_x_circulo(c));
}

void desenha_retangulo_svg (FILE* arq_svg, Retangulo r) {
    fprintf(arq_svg, "<rect id=\"%d\" style=\"fill:%s;fill-opacity:0.5;stroke:%s\" height=\"%lf\" width=\"%lf\" y=\"%lf\" x=\"%lf\" stroke-width=\"%lf\" />\n", get_id_retangulo(r), get_corp_retangulo(r), get_corb_retangulo(r), get_h_retangulo(r), get_w_retangulo(r), get_y_retangulo(r), get_x_retangulo(r), get_sw_retangulo(r));
}

void desenha_linha_svg (FILE* arq_svg, Linha l) {
    fprintf(arq_svg, "<line id=\"%d\" x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-width=\"%lf\" />\n", get_id_linha(l), get_x1_linha(l), get_y1_linha(l), get_x2_linha(l), get_y2_linha(l), get_cor_linha(l));
}

void desenha_texto_svg (FILE* arq_svg, Texto t, Estilo ts) {
    char a = get_a_texto(t);
           if (a == 'i') {
        fprintf(arq_svg, "<text id=\"%d\" font-size=\"%s\" line-height=\"0\" text-anchor=\"start\" fill=\"%s\" stroke=\"%s\" font-family=\"%s\" y=\"%lf\" x=\"%lf\" stroke-width=\"%lf\" ><![CDATA[%s]]></text>\n", get_id_texto(t), get_size_estilo(ts), get_corp_texto(t), get_corb_texto(t), get_family_estilo(ts), get_y_texto(t), get_x_texto(t), 1.0, get_txt(t));
    } else if (a == 'm') {
        fprintf(arq_svg, "<text id=\"%d\" font-size=\"%s\" line-height=\"0\" text-anchor=\"middle\" fill=\"%s\" stroke=\"%s\" font-family=\"%s\" y=\"%lf\" x=\"%lf\" stroke-width=\"%lf\" ><![CDATA[%s]]></text>\n", get_id_texto(t), get_size_estilo(ts), get_corp_texto(t), get_corb_texto(t), get_family_estilo(ts), get_y_texto(t), get_x_texto(t), 1.0, get_txt(t));
    } else if (a == 'f') {
        fprintf(arq_svg, "<text id=\"%d\" font-size=\"%s\" line-height=\"0\" text-anchor=\"end\" fill=\"%s\" stroke=\"%s\" font-family=\"%s\" y=\"%lf\" x=\"%lf\" stroke-width=\"%lf\" ><![CDATA[%s]]></text>\n", get_id_texto(t), get_size_estilo(ts), get_corp_texto(t), get_corb_texto(t), get_family_estilo(ts), get_y_texto(t), get_x_texto(t), 1.0, get_txt(t));
    }
}

void fecharSVG(FILE* arq_svg) {
    fprintf(arq_svg, "</g>\n");
    fprintf(arq_svg,"</svg>\n");
    fclose(arq_svg);
}