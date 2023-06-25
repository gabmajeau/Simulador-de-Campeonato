#ifndef TABELA_H_INCLUDED
#define TABELA_H_INCLUDED
#include "dados.h"

/*
*  Inicializa a Estrutura de Dados. Insere os Nós na mesma
*  Recebe como parâmetro a struct referencial da Estrutura de Dados, o numero de times participantes e o nome do campeonato
*/
void setTabela(ListaLDE l, int total, char nomeCampeonato[20]);

/*
*  Gerencia os Confrontos. Trata dos Inputs durante o campeonato
*  Recebe como parâmetro a struct referencial da Estrutura de Dados e o nome do campeonato
*  Retorna 1 quando ocorre o empate e 0 caso contrário
*/
int menuTabela(ListaLDE l, char nomeCampeonato[20]);

/*
*  Navega na Estrutura de Dados
*  Exibe, de forma organizada, o chaveamento de confrontos e os resultados
*  Recebe como parâmetro a struct referencial da Estrutura de Dados e um vetor com os ids dos vencedores de cada confronto
*/
void tabela(ListaLDE l, int vencedor[]);

#endif //TABELA_H_INCLUDED