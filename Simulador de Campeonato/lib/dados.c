#include <stdlib.h>
#include <string.h>
#include "../include/dados.h"


void inicializa(ListaLDE *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
}


int insere(ListaLDE *l, char nome[20]){
    No *aux = (No *) malloc(sizeof(No));
    if(aux == NULL)
        return 0;

    static int vez = 1;
    aux->dado.id = vez++; //ID definido automaticamente, em ordem numérica
    strcpy(aux->dado.nome, nome);
    l->tam++;

    /*Caso: primeiro Nó*/
    if(l->inicio == NULL){
        l->inicio = aux;
        l->fim = aux;
        aux->ant = NULL;
        aux->prox = NULL;
        return 1;
    }

    /*Caso: insere Nó no fim*/
    aux->ant = l->fim; 
    aux->prox = NULL; 
    l->fim->prox = aux; 
    l->fim = aux;
    return 1;
}


int retira(ListaLDE *l, int id){
    No *aux;

    if(l->inicio == NULL){
        //Lista Vazia
        return 0;
    }

    /*Caso: removendo único Nó*/
    if( (id == l->inicio->dado.id) && (l->inicio == l->fim) ){
        aux = l->inicio; 
        l->inicio = NULL; 
        l->fim = NULL;
        free(aux);
        l->tam--;
        return 1;
    }

    /*Caso: removendo primeiro Nó*/
    if(id == l->inicio->dado.id){
        aux = l->inicio; 
        l->inicio = aux->prox; 
        l->inicio->ant = NULL; 
        l->fim->prox = NULL; 
        free(aux); 
        l->tam--;
        return 1;
    }

    /*Caso: removendo último Nó*/
    if(id == l->fim->dado.id) {
        aux = l->fim; 
        l->fim = aux->ant;
        l->fim->prox = NULL;
        free(aux);
        l->tam--;
        return 1;
    }

    /*Caso: removendo um Nó no meio*/
    aux = l->inicio->prox;

    while( (id != aux->dado.id) && (aux != l->fim) )
        aux = aux->prox;

    if(aux == l->fim){
        //O Elemento nao esta na Lista
        return 0;
    }

    aux->prox->ant = aux->ant; 
    aux->ant->prox = aux->prox;
    free(aux);
    l->tam--;
    return 1;
}





int estaVazia(ListaLDE *l){
    if(l->inicio == NULL) return 1;
    return 0;
}
int getInicio(ListaLDE *l){
    return l->inicio->dado.id;
}