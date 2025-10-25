#include <stdio.h>
#include <string.h>
#include "FILA.h"
#include "DIVISORIA.h"
#include "GEO.h"
#include "QRY.h"
#include "SVG.h"



int main (int argc, char *argv[]) {
    char* entrada = NULL;
    char* arq_geo = NULL;
    char* saida = NULL;
    char* arq_qry = NULL;

    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0 && i + 1 < argc) {
            entrada = argv[++i];
        } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            arq_geo = argv[++i];
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            saida = argv[++i];
        } else if (strcmp(argv[i], "-q") == 0 && i + 1 < argc) {
            arq_qry = argv[++i];
        }
    }

    if (arq_geo == NULL || saida == NULL) {
        printf("Erro: Argumentos -f e -o sao obrigatórios.\n");
        printf("Uso: ./programa -f <arq.geo> -o <path_saida> [-e <path_entrada>] [-q <arq.qry>]\n");
        return 1;
    }

    char path_geo[1024];
    char base_geo[256];
    char path_svg_geo[1024];

    monta_path_completo(path_geo, entrada, arq_geo);
    extrai_nome_base(arq_geo, base_geo);
    sprintf(path_svg_geo, "%s/%s.svg", saida, base_geo);

    Fila chao = cria_fila();

    FILE* arq_geo = fopen(path_geo, "r");
    if (arq_geo == NULL) {
        printf("Erro na tentativa de abrir o arquivo .geo.\n");
        return 1;
    }

    FILE* arq_svg_geo = fopen(path_svg_geo, "w");
    if (arq_svg_geo == NULL) {
        printf("Erro na tentativa de criar o arquivo .svg \n");
        fclose(arq_geo);
        return 1;
    }
    
    geo (chao, arq_geo);
    svg (arq_svg_geo, chao);

    fclose (arq_geo);
    fclose (arq_svg_geo);

    if (arq_qry != NULL) {
        char path_qry_completo[1024];
        char nome_base_qry[256];
        char path_svg_final[1024];
        char path_txt_final[1024];

        
        montar_path_completo(path_qry_completo, entrada, arq_qry);
        extrair_nome_base(arq_qry, nome_base_qry);
        sprintf(path_svg_final, "%s/%s-%s.svg", saida, base_geo, nome_base_qry);
        sprintf(path_txt_final, "%s/%s-%s.txt", saida, base_geo, nome_base_qry);

        FILE* arq_qry = fopen(path_qry_completo, "r");
        if (arq_qry == NULL) {
            printf("Erro na tentativa de abrir o arquivo .qry.\n");
        } else {
            qry (chao, arq_qry, path_svg_final, path_txt_final);
            fclose(arq_qry);
        }
    }

    libera_fila_e_formas(chao);
    return 0;
}