#ifndef CHAVE_H_INCLUDED
#define CHAVE_H_INCLUDED
#include "dados.h"

/*
*  Inicializa a Estrutura de Dados. Insere os Nós na mesma
*  Recebe como parâmetro a struct referencial da Estrutura de Dados, o numero de times participantes e o nome do campeonato
*/
void setChave(ListaLDE l, int total, char nomeCampeonato[20]);

/*
*  Gerencia os Confrontos. Trata dos Inputs durante o campeonato
*  Remove Nós, correspondente aos eliminados do campeonato, da Estrutura de Dados
*  Recebe como parâmetro a struct referencial da Estrutura de Dados, o numero de times participantes e o nome do campeonato
*  Retorna o numero de equipes vencedoras e que avançaram para a próxima "etapa"
*/
int menuChave(ListaLDE l, int confrontos, char nomeCampeonato[20]);

/*
*  Navega na Estrutura de Dados
*  Exibe, de forma organizada, o chaveamento de confrontos e os resultados
*  Recebe como parâmetro a struct referencial da Estrutura de Dados, o numero de confrontos e um vetor com os ids dos vencedores de cada confronto
*/
int chave(ListaLDE l, int times, int vencedor[]);

#endif //CHAVE_H_INCLUDED