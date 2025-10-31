#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "FILA.h"
#include "DIVISORIA.h"
#include "GEO.h"
#include "QRY.h"
#include "SVG.h"


#define PATH_LEN 250
#define FILE_NAME_LEN 100
#define MSG_LEN 1000

void trataPath(char *path, int tamMax, char *arg)
{
    int argLen = strlen(arg);
    assert(argLen < tamMax);
    if (arg[argLen - 1] == '/')
    {
        arg[argLen - 1] = '\0';
    }
    strcpy(path, arg);
}

void trataNomeArquivo(char *path, int tamMax, char *arg)
{
    int argLen = strlen(arg);
    assert((argLen + 4) < tamMax);
    sprintf(path, "%s", arg);
}

void extrai_nome_base(char* arq_qry, char* nome_base_qry) {
    if (arq_qry == NULL || nome_base_qry == NULL) {
        printf("Erro ao tentar acessar os parâmetros. \n");
        return;
    }

    char nome_base_tmp[strlen(arq_qry)]; 
    char* ultimo_ponto = strrchr(arq_qry, '.');
    int len_ent;

    if (ultimo_ponto == NULL || ultimo_ponto == arq_qry) {
        strcpy(nome_base_tmp, arq_qry);
    } 
    else {
        len_ent = ultimo_ponto - arq_qry;
        strncpy(nome_base_tmp, arq_qry, len_ent);
        nome_base_tmp[len_ent] = '\0';
    }

    char* ultima_barra = strrchr(nome_base_tmp, '/');
    if (ultima_barra == NULL || ultima_barra == arq_qry) {
        strcpy(nome_base_qry, nome_base_tmp);
    } 
    else {
        //len_ent = ultima_barra - arq_qry;
        strcpy(nome_base_qry, ultima_barra + 1);
        //nome_base_qry[len_ent] = '\0';
    }
}

void main(int argc, char *argv[])
{
    char dir_entrada[PATH_LEN], dir_saida[PATH_LEN], arq_geo[FILE_NAME_LEN], arq_qry[FILE_NAME_LEN], msg[MSG_LEN];
    char *concat_caminho_arquivo;
    FILE *file_geo, *file_qry, *file_svg_geo, *file_svg_qry, *file_txt;
    /* MOSTRA OS PARAMETROS */
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    /* TRATA PARAMETROS */

    int i = 1;
    strcpy(msg, "");
    while (i < argc)
    {

        if (strcmp(argv[i], "-e") == 0) {
            i++;
            /* se i >= argc: ERRO-falta parametro */
            trataPath(dir_entrada, PATH_LEN, argv[i]);
        } else if (strcmp(argv[i], "-o") == 0)
        {
            i++;
            /* se i >= argc: ERRO-falta parametro */    
            trataPath(dir_saida, PATH_LEN, argv[i]);
        } else if (strcmp(argv[i], "-f") == 0)
        {
            i++;
            /* se i >= argc: ERRO-falta parametro */
            trataNomeArquivo(arq_geo, FILE_NAME_LEN, argv[i]);
        } else if (strcmp(argv[i], "-q") == 0)
        {
            i++;
            /* se i >= argc: ERRO-falta parametro */
            trataNomeArquivo(arq_qry, FILE_NAME_LEN, argv[i]);
        }
        else
        {
            strcat(msg, argv[i]);
            strcat(msg, " ");
        }
        i++;
    } // while
    /* GRAVA MENSAGEM NO ARQUIVO (DE ACORDO COM OS PARAMETROS) */
    int pLen = strlen(dir_entrada);
    int fLen = strlen(arq_geo);
    concat_caminho_arquivo = (char *)malloc((pLen + fLen + 2) * sizeof(char));
    sprintf(concat_caminho_arquivo, "%s/%s", dir_entrada, arq_geo);
    file_geo = fopen(concat_caminho_arquivo, "r");
    if (file_geo == NULL) {
        printf("Erro na tentativa de abrir o arquivo .geo.\n");
        return 1;
    }
    printf("%s\n", concat_caminho_arquivo);
    free(concat_caminho_arquivo);

    pLen = strlen(dir_entrada);
    fLen = strlen(arq_qry);
    concat_caminho_arquivo = (char *)malloc((pLen + fLen + 2) * sizeof(char));
    sprintf(concat_caminho_arquivo, "%s/%s", dir_entrada, arq_qry);
    file_qry = fopen(concat_caminho_arquivo, "r");
    if (file_qry == NULL) {
        printf("Erro na tentativa de abrir o arquivo .qry.\n");
        return 1;
    }
    printf("%s\n", concat_caminho_arquivo);
    free(concat_caminho_arquivo);

    pLen = strlen(dir_saida);
    fLen = strlen(arq_geo);
    char *nome_base = (char *)malloc((fLen - 3) * sizeof(char));
    extrai_nome_base(arq_geo, nome_base);
    char *arq_svg_geo = (char *)malloc((fLen + 1) * sizeof(char));
    sprintf(arq_svg_geo, "%s.%s", nome_base, "svg"); 

    concat_caminho_arquivo = (char *)malloc((pLen + fLen + 2) * sizeof(char));
    sprintf(concat_caminho_arquivo, "%s/%s", dir_saida, arq_svg_geo);
    file_svg_geo = fopen(concat_caminho_arquivo, "w");
    if (file_svg_geo == NULL) {
        printf("Erro na tentativa de abrir o arquivo geo .svg.\n");
        return 1;
    }
    printf("%s\n", concat_caminho_arquivo);
    free(nome_base);
    free(concat_caminho_arquivo);

    pLen = strlen(dir_saida);
    fLen = strlen(arq_qry);
    nome_base = (char *)malloc((fLen - 3) * sizeof(char));
    extrai_nome_base(arq_qry, nome_base);
    char *arq_svg_qry = (char *)malloc((fLen + 1) * sizeof(char));
    sprintf(arq_svg_qry, "%s.%s", nome_base, "svg"); 

    concat_caminho_arquivo = (char *)malloc((pLen + fLen + 2) * sizeof(char));
    sprintf(concat_caminho_arquivo, "%s/%s", dir_saida, arq_svg_qry);
    file_svg_qry = fopen(concat_caminho_arquivo, "w");
    if (file_svg_qry == NULL) {
        printf("Erro na tentativa de abrir o arquivo qry .svg.\n");
        return 1;
    }
    printf("%s\n", concat_caminho_arquivo);

    char *arq_txt = (char *)malloc((fLen + 1) * sizeof(char));
    sprintf(arq_svg_qry, "%s.%s", nome_base, "txt"); 
    sprintf(concat_caminho_arquivo, "%s/%s", dir_saida, arq_svg_qry);
    file_txt = fopen(concat_caminho_arquivo, "w");
    if (file_txt == NULL) {
        printf("Erro na tentativa de abrir o arquivo  .txt.\n");
        return 1;
    }
    printf("%s\n", concat_caminho_arquivo);
    free(nome_base);
    free(concat_caminho_arquivo);

    free(arq_svg_geo);
    free(arq_svg_qry);
    free(arq_txt);
    
    Fila chao = cria_fila();

    geo (chao, file_geo);
    abre_svg(file_svg_geo);
    svg (file_svg_geo, chao);
    fecha_svg(file_svg_geo);
    qry(chao, file_qry, file_svg_qry, file_txt);

    libera_fila (chao);
    fclose(file_geo);
    fclose(file_qry);
    fclose(file_svg_geo);
    fclose(file_svg_qry);
    fclose(file_txt);
    return 0;
}

/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FILA.h"
#include "DIVISORIA.h"
#include "GEO.h"
#include "QRY.h"
#include "SVG.h"



int main (int argc, char *argv[]) {
    char* entrada = NULL;
    char* arq_geo_file_name = NULL;
    char* saida = NULL;
    char* arq_qry = NULL;

    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0 && i + 1 < argc) {
            entrada = argv[++i];
        } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            arq_geo_file_name = argv[++i];
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            saida = argv[++i];
        } else if (strcmp(argv[i], "-q") == 0 && i + 1 < argc) {
            arq_qry = argv[++i];
        }
    }

    if (arq_geo_file_name == NULL || saida == NULL) {
        printf("Erro: Argumentos -f e -o sao obrigatórios.\n");
        printf("Uso: ./programa -f <arq.geo> -o <path_saida> [-e <path_entrada>] [-q <arq.qry>]\n");
        return 1;
    }

    char path_geo[1024];
    char base_geo[256];
    char path_svg_geo[1024];

    monta_path_completo(path_geo, entrada, arq_geo_file_name);
    extrai_nome_base(arq_geo_file_name, base_geo);
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


        monta_path_completo(path_qry_completo, entrada, arq_qry);
        extrai_nome_base(arq_qry, nome_base_qry);
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

    //libera_fila_e_formas(chao);
    return 0;
}
*/