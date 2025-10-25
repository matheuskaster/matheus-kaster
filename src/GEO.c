#include "GEO.h"
#include "CIRCULO.h"
#include "TEXTO.h"
#include "LINHA.h"
#include "RETANGULO.h"
#include "FORMA.h"
#include <string.h>
#include <stdio.h>
#include "SVG.h"

void geo (Fila chao, FILE* arq_geo, FILE* arq_svg) {
    
    if(arq_geo == NULL){
        printf("Arquivo .geo não encontrado. \n");
        exit(1);
    }

    int ultimo_id = 0;

    char linha[256];
    char tipo;

    while (fgets(linha, sizeof(linha), arq_geo) != NULL){

        if (linha[0] == '\n' || linha[0] == '#'){
            continue;
        }

        sscanf(linha, "%c", &tipo);

        if (tipo == 'c') {
            int id;
            double x, y, r;
            char corb[8], corp[8];
            sscanf (linha, "c %d %lf %lf %lf %s %s", &id, &x, &y, &r, corb, corp);
            if (ultimo_id < id) {
                ultimo_id = id;
            }
            Forma F = cria_forma_circulo (tipo, id, x, y, r, corb, corp);
            insere_fila (chao, F);

        } else if (tipo == 'r') {
            int id;
            double x, y, w, h;
            char corb[8], corp[8];
            sscanf (linha, "r %d %lf %lf %lf %lf %s %s", &id, &x, &y, &w, &h, corb, corp);
            if (ultimo_id < id) {
                ultimo_id = id;
            }
            Forma F = cria_forma_retangulo (tipo, id, x, y, w, h, corb, corp);
            insere_fila (chao, F);

        } else if (tipo == 'l') {
            int id;
            double x1,y1,x2,y2;
            char cor[8];
            sscanf (linha, "l %d %d %d %d %s", &id, &x1, &y1, &x2, &y2, cor);
            if (ultimo_id < id) {
                ultimo_id = id;
            }
            Forma F = cria_forma_linha (tipo, id, x1, y1, x2, y2, cor);
            insere_fila (chao, F);

        } else if (tipo == 't') {
            int id;
            double x, y;
            char corb[8], corp[8], txto;
            char a;
            sscanf (linha, "t %d %d %d %s %s %c %s", &id, &x, &y, corb, corp, &a, txto);
            if (ultimo_id < id) {
                ultimo_id = id;
            }
            Forma F = cria_forma_texto (tipo, id, x, y, corb, corp, a, txto);
            insere_fila (chao, F);
        }
    }
    armazena_ultimo_id (ultimo_id);
}