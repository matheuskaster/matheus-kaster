
#include "GEO.h"
#include "FORMA.h"
#include "PILHA.h"
#include "FILA.h"
#include "CARREGADOR.h"
#include "DISPARADOR.h"
#include "DIVISORIA.h"
#include "SOBREPOSICAO.h"
#include "QRY.h"
#include "SVG.h"
#include "stdio.h"
#include "string.h"
#include <stdlib.h>
/*
void monta_path_completo(char* path_qry_completo, char* entrada, char* arq_qry) {
    if (path_qry_completo == NULL || entrada == NULL || arq_qry == NULL) {
        printf("Erro ao tentar acessar os parâmetros. \n");
        return;
    }
    int len_ent = strlen(entrada);

    if (len_ent == 0 || entrada[len_ent - 1] == '/') {
        sprintf(path_qry_completo, "%s%s", entrada, arq_qry);
    } 
    else if (strcmp(entrada, ".") == 0) {
        strcpy(path_qry_completo, arq_qry);
    }
    else {
        sprintf(path_qry_completo, "%s/%s", entrada, arq_qry);
    }
}


void extrai_nome_base(char* arq_qry, char* nome_base_qry) {
    if (arq_qry == NULL || nome_base_qry == NULL) {
        printf("Erro ao tentar acessar os parâmetros. \n");
        return;
    }
    char* ultimo_ponto = strrchr(arq_qry, '.');
    if (ultimo_ponto == NULL || ultimo_ponto == arq_qry) {
        strcpy(nome_base_qry, arq_qry);
    } 
    else {
        int len_ent = ultimo_ponto - arq_qry;
        strncpy(nome_base_qry, arq_qry, len_ent);
        nome_base_qry[len_ent] = '\0';
    }
}
*/

void qry (Fila chao, FILE* arq_qry, char* path_svg_final, char* path_txt_final) {
    
    FILE* arq_txt = fopen(path_txt_final, "w");
    if (arq_txt == NULL) {
        printf("Erro na tentativa de abrir o arquivo .geo.\n");
        exit (1);
    }

    Fila arena = cria_fila();
    Divisoria vet_carregadores = cria_div();
    Divisoria vet_disparadores = cria_div();

    double pontuacao = 0.0;

    FILE* arq_svg = fopen(path_svg_final, "w");
    if (arq_svg == NULL) {
        printf("Erro na tentativa de abrir o arquivo .geo.\n");
        exit (1);
    }


    abre_svg(arq_svg);

    char linha[512];
    char comando[512];
    
    double potuacao = 0.0;
    int num_clones = 0, num_esmagadas = 0;
    int* num_disparos;

    while (fgets(linha, sizeof(linha), arq_qry) != NULL) {
        if(linha[0] == '\n' || linha[0] == '\r'){
            continue;
        }
        
        sscanf(linha, "%s", comando);
        
        if (strcmp(comando, "pd") == 0) {
            int id;
            double x, y;
            sscanf(linha, "pd %i %lf %lf", &id, &x, &y);
            pd(id, x, y, vet_disparadores);
        }
        else if (strcmp(comando, "lc") == 0) {
            int id, n;
            sscanf(linha, "lc %i %i", &id, &n);
            load_carregador (id, n, chao, vet_carregadores, arq_txt);
        }
        else if (strcmp(comando, "atch") == 0) {
            int id, car_esq, car_dir;
            sscanf(linha,"atch %i %i %i", &id, &car_esq, &car_dir);
            atch(id, car_esq, car_dir, vet_disparadores);
        }
        else if (strcmp(comando, "shft") == 0) {
            char lado;
            int id, n;
            sscanf(linha, "shft %i %c %i", &id, &lado, &n);
            shft (id, lado, n, vet_disparadores, arq_txt);
        }
        else if (strcmp(comando, "dsp") == 0) {
            int id;
            double dx, dy;
            char* v;
            sscanf(linha, "dsp %i %lf %lf %c", &id, &dx, &dy, &v);
            dsp (id, dx, dy, v, arena, vet_disparadores, arq_txt, num_disparos);
        }
        else if (strcmp(comando, "rjd") == 0) {
            char lado;
            int id;
            double dx, dy, ix, iy;
            sscanf(linha, "dsp %i %c %lf %lf %lf %lf", &id, &lado, &dx, &dy, &ix, &iy);

        }
        else if (strcmp(comando, "calc") == 0) {
            while (tam_fila(arena) >= 2) {
                
                Geometria I = get_conteudo_fila(arena);
                Geometria J = get_conteudo_fila(arena);
                if (houve_colisao(I, J)) {
                    double area_I = get_area_forma(I);
                    double area_J = get_area_forma(J);
                    if (area_I < area_J) {
                        pontuacao += area_I;
                        num_esmagadas++;
                        libera_forma(I);
                        insere_fila(chao, J);
                    } else {
                        char* cor_preenchimento_I = get_corp_forma(I);
                        set_corb_forma(J, cor_preenchimento_I);
                        Geometria clone_I = clona_forma(I);
                        num_clones++;
                        inverte_cores_forma(clone_I);
                        insere_fila(chao, I);
                        insere_fila(chao, J);
                        insere_fila(chao, clone_I);
                    }
                } else {
                    insere_fila(chao, I);
                    insere_fila(chao, J);
                }
            } 
            if (tam_fila(arena) == 1) {
                Geometria sobrou = get_conteudo_fila(arena);
                remove_fila(arena);
                insere_fila(chao, sobrou);
            }
        }
    }
    svg (arq_svg);
    fprintf(arq_txt, "RELATÓRIO:\n");
    fprintf(arq_txt, "pontuação total: %.2f\n", pontuacao);
    fprintf(arq_txt, "quantidade de disparos: %d\n", (*num_disparos));
    fprintf(arq_txt, "quantidade de formas clonadas: %d\n", num_clones);
    fprintf(arq_txt, "quantidade de formas esmagadas: %d\n", num_esmagadas);
    fecha_svg (arq_svg);
    fclose(arq_svg);
    fclose(arq_txt);

    //libera_fila_e_formas(arena);
    //libera_div(vet_carregadores, 'c');
    //libera_div(vet_disparadores, 'd');

    fclose (arq_qry);
}