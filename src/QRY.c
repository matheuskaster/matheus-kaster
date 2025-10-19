#include "QRY.h"
#include "GEO.h"
#include "FORMA.h"
#include "CARREGADOR.h"
#include "DISPARADOR.h"
#include "PILHA.h"
#include "FILA.h"

void qry (FILE* arq_qry, FILE* arq_txt, Fila arena, Disparador d) {
    if (arq_qry == NULL){
        printf("Erro ao ler o arquivo .qry");
        exit(1);
    }
    
    char linha[512];
    char comando[512];
    
    fopen(arq_txt, "r");
    
    while (fgets(linha, sizeof(linha), arq_qry) != NULL) {
        if(linha[0] == '\n' || linha[0] == '\r'){
            continue;
        }
        
        sscanf(linha, "%s", comando);
        
        if (strcmp(comando, "pd") == 0) {
            double x, y;
            sscanf(linha, "pd %lf %lf", &x, &y);
            pd(d, x, y);
        }
        else if (strcmp(comando, "lc") == 0) {
            Carregador car;
            int n;
            sscanf(linha, "lc %i %n", &car, &n);
            lc (car, n);
            
        }
        else if (strcmp(comando, "atch") == 0) {
            Carregador car_esq, car_dir;
            sscanf(linha,"atch %i %i %i", &d, &car_esq, &car_dir);
            atch(d, car_esq, car_dir);
        }
        else if (strcmp(comando, "shft") == 0) {
            char lado;
            int n;
            sscanf(linha, "shft %i %c %i", &d, &lado, &n);
            shft (d, lado, n);
        }
        else if (strcmp(comando, "dsp") == 0) {
            double dx, dy;
            sscanf(linha, "dsp %i %lf %lf", &d, &dx, &dy);
            void dsp (d, dx, dy, arena);
        }
        else if (strcmp(comando, "rjd") == 0) {
            char lado;
            double dx, dy;
            sscanf(linha, "dsp %i %c %lf %lf", &d, &lado, &dx, &dy);
            shft (d, lado, 1);
            dsp (d, dx+i*ix, dy+i*iy);
        }
        else if (strcmp(comando, "calc") == 0) {
        }
    }
    fclose (arq_qry);
}

void abrirTxt(FILE* arqTxt){
    fopen(arqTxt, "w");
}

void fecharTxt(FILE* arqTxt){
    if(arqTxt == NULL){
        printf("Erro ao acessar o arquivo .txt");
        exit(1);
    }
    fclose(arqTxt);
}