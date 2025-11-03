
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

void qry (Fila chao, FILE* file_qry, FILE* file_svg_qry, FILE* file_txt) {
    
    Fila arena = cria_fila();
    Divisoria vet_carregadores = cria_div_car();
    Divisoria vet_disparadores = cria_div_dis();

    double pontuacao = 0.0;

    abre_svg(file_svg_qry);

    char linha[512];
    char comando[512];
    
    double potuacao = 0.0;
    int num_clones = 0, num_esmagadas = 0;
    int num_disparos = 0;
    
    while (fgets(linha, sizeof(linha), file_qry) != NULL) {
        if(linha[0] == '\n' || linha[0] == '\r'){
            continue;
        }
        
        sscanf(linha, "%s", comando);
        
        if (strcmp(comando, "pd") == 0) {
            int id;
            double x, y;
            sscanf(linha, "pd %i %lf %lf", &id, &x, &y);
            Disparador d = busca_elem_div_dis(vet_disparadores, id);
            pd(d, x, y);
        }
        else if (strcmp(comando, "lc") == 0) {
            int id, n;
            sscanf(linha, "lc %i %i", &id, &n);
            Carregador car = busca_elem_div_car(vet_carregadores, id);
            load_carregador (car, n, chao, file_txt);
        }
        else if (strcmp(comando, "atch") == 0) {
            int id, car_esq_id, car_dir_id;
            sscanf(linha,"atch %i %i %i", &id, &car_esq_id, &car_dir_id);
            Carregador car_esq = busca_elem_div_car(vet_carregadores, car_esq_id);
            Carregador car_dir = busca_elem_div_car(vet_carregadores, car_dir_id);
            Disparador d = busca_elem_div_dis(vet_disparadores, id);
            atch(d, car_esq, car_dir);
        }
        else if (strcmp(comando, "shft") == 0) {
            char lado;
            int id, n;
            sscanf(linha, "shft %i %c %i", &id, &lado, &n);
            Disparador d = busca_elem_div_dis(vet_disparadores, id);
            shft (d, lado, n, file_txt);
        }
        else if (strcmp(comando, "dsp") == 0) {
            int id;
            double dx, dy;
            char eh_visivel;
            sscanf(linha, "dsp %i %lf %lf %c", &id, &dx, &dy, &eh_visivel);
            Disparador d = busca_elem_div_dis(vet_disparadores, id);
            dsp (d, dx, dy, eh_visivel, arena, file_txt, file_svg_qry, &num_disparos);
        }
        else if (strcmp(comando, "rjd") == 0) {
            char lado;
            int id;
            double dx, dy, ix, iy;
            sscanf(linha, "rjd %i %c %lf %lf %lf %lf", &id, &lado, &dx, &dy, &ix, &iy);
            Disparador d = busca_elem_div_dis(vet_disparadores, id);
            rjd (d, lado, dx, dy, ix, iy, arena, file_txt, file_svg_qry, &num_disparos);
        }
        else if (strcmp(comando, "calc") == 0) {
            while (tam_fila(arena) >= 2) {
                Geometria I = remove_fila(arena);
                Geometria J = remove_fila(arena);
                if (houve_colisao(I, J)) {
                    double area_I = get_area_forma(I);
                    double area_J = get_area_forma(J);
                    if (area_I < area_J) {
                        pontuacao += area_I;
                        num_esmagadas++;
                        double x = get_x_forma(I);
                        double y = get_y_forma(I);
                        desenha_asterisco (file_svg_qry, x, y);
                        libera_forma(I);
                        insere_fila(chao, J);
                    } else {
                        char* cor_preenchimento_I = get_corp_forma(I);
                        set_corb_forma(J, cor_preenchimento_I);
                        Geometria clone_I = clona_forma(I);
                        num_clones++;
                        //inverte_cores_forma(clone_I);
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
                Geometria sobrou = remove_fila(arena);
                insere_fila(chao, sobrou);
            }
        }
    }
    svg (file_svg_qry, chao);
    fecha_svg(file_svg_qry);
    fprintf(file_txt, "RELATÓRIO:\n");
    fprintf(file_txt, "pontuação total: %.2f\n", pontuacao);
    fprintf(file_txt, "quantidade de disparos: %d\n", num_disparos);
    fprintf(file_txt, "quantidade de formas clonadas: %d\n", num_clones);
    fprintf(file_txt, "quantidade de formas esmagadas: %d\n", num_esmagadas);

    libera_fila (arena);
    libera_div_car (vet_carregadores);
    libera_div_dis (vet_disparadores);
    //fecha_svg (file_svg_qry);
    //libera_fila_e_formas(arena);
    //libera_div(vet_carregadores, 'c');
    //libera_div(vet_disparadores, 'd');
}