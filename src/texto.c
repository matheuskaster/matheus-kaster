#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"
#include <string.h>
#include "stdbool.h"

typedef struct estilo {
    char *family;
    char *weight;
    char *size;
} estilo;

typedef struct texto {
    int id;
    double x, y;
    char* corb
    char* corp;
    char a;
    char* texto;
    double sw;  
    int n;
    Estilo ts;
} texto;

Estilo cria_estilo (char* family, char* weight, char* size) {
    Estilo* ts = (estilo*) malloc (sizeof(estilo));
    ts->family = (char*) malloc (sizeof(family)+1);
    if (ts->family == NULL) {
        printf ("Erro na alocação de memória ao criar a família");
        exit(1);
    }
    strcpy (ts->family, family);

    ts->weight = (char*) malloc (sizeof(weight)+1);
    if (ts->weight == NULL) {
        printf ("Erro na alocação de memória ao criar a expessura");
        exit(1);
    }
    strcpy (ts->weight, weight);

    ts->size = (char*) malloc (sizeof(size)+1);
    if (ts->size == NULL) {
        printf ("Erro na alocação de memória ao criar a tamanho");
        exit(1);
    }
    strcpy (ts->size, size);
    return ((estilo*)ts);
}

void set_family_estilo (Estilo ts, char *family) {
    strcpy (((estilo*)ts)->family, family);
}

char* get_family_estilo (Estilo ts) {
    return ((estilo*)ts)->family;
}

void set_weight_estilo (Estilo ts, char *weight) {
    strcpy (((estilo*)ts)->weight, weight);
}

char* get_weight(Estilo ts) {
    return ((estilo*)ts)->weight;
}

void set_size(Estilo ts, char *size) {
    strcpy (((estilo*)ts)->size, size);
}

char* get_size(Estilo ts) {
    return ((estilo*)ts)->size;
}


Texto cria_texto (int id, double x, double y, char* corb, char* corp, char a, char* texto, double sw, int n, Estilo ts) {
    Texto* t = (texto*) malloc (sizeof(texto));
    t->id = id;
    t->x = x;
    t->y = y;
    t->corb = (char*) malloc (strlen(corb)+1);
    if (t->corb == NULL) {
        printf("Erro na alocação de memória ao criar a cor de borda");
        exit(1);
    }
    strcpy(t->corb, corb);

    t->corp = (char*) malloc (strlen(corp)+1);
    if (t->corp == NULL) {
        printf("Erro na alocação de memória ao criar a cor de preenchimento");
        exit(1);
    }
    strcpy(t->corp, corp);

    t->a = a;
    
    t->texto = (char*) malloc (strlen(texto)+1);
    if (t->texto == NULL) {
        printf("Erro na alocação de memória ao criar o texto");
        exit(1);
    }
    strcpy(t->texto, texto);
    t->ts = ts;
    return ((texto*)t);

    void set_id_texto (Texto t, int id) {
        ((estilo*)ts)->id = id;
    }

    int get_id_texto (Texto t) {
        return ((estilo*)ts)->id;
    }

    void set_x_texto (Texto t, double x) {
        ((estilo*)ts)->x = x;
    }

    int get_x_texto (Texto t) {
        return ((estilo*)ts)->x;
    }

    void set_y_texto (Texto t, double y) {
        ((estilo*)ts)->y = y;
    }

    int get_y_texto (Texto t) {
        return ((estilo*)ts)->y = y;
    }

    void set_corb_texto (Texto t, char* corb) {
        strcpy (((estilo*)ts)->corb, corb);
    }

    char* get_corb_texto (Texto t) {
        return ((estilo*)ts)->corb;
    }

    void set_corp_texto (Texto t, char* corp) {
        strcpy (((estilo*)ts)->corp, corp);
    }

    char* get_corp_texto (Texto t) {
        return (((estilo*)ts)->corp, corp);
    }

    char* get_a_texto (Texto t) {
        return ((estilo*)ts)->a;
    }
}