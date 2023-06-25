#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

typedef struct {
    int id;
    char nome[20];
} Time;

typedef struct no {
    Time dado;
    struct no *ant;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tam;
} ListaLDE;


/*
*  Seta os valores iniciais da ListaLDE para NULL
*/
void inicializa(ListaLDE *l);

/*
*  Insere mais um Nó na Estrutura de Dados
*  Recebe o nome do Time a ser inserido
*  Retorna Sucesso ou Falha na alocação
*/
int insere(ListaLDE *l, char nome[20]);

/*
*  Retira um Nó da Estrutura de Dados
*  Recebe o 'id' a ser retirado
*  Retorna Sucesso ou Falha na remoção
*/
int retira(ListaLDE *l, int id);


/*Funções Auxiliares*/
int estaVazia(ListaLDE *l); // Retorna 1 se a Estrutura de Dados está vazia e 0 caso contrário
int getInicio(ListaLDE *l); // Retorna o 'id' do primeiro Nó da Estrutura de Dados

#endif //DADOS_H_INCLUDED