#include <stdio.h>
#include <stdlib.h>
#include "../include/tabela.h"
#include "../include/dados.h"
#include "../include/terminal.h"




void setTabela(ListaLDE l, int total, char nomeCampeonato[20]){
    /* Menu Cadastro */
    limpaTela();
    blue();
    printf("\t\t\t\tSIMULADOR DE CAMPEONATOS\n\n");
    yellow();
    printf("\t\t/*\n\t\t*  %s\n\t\t*/\n\n", nomeCampeonato);
    reset();

    /* Leitura e Alocação dos Dados */
    inicializa(&l);
    char nomeTime[20]; //variável auxiliar para os inputs
    for (int i=0; i<total; i++) { //laço para leitura de todos os times
        printf("\n-\nTime %d -> ", i+1);
        scanf("%19[^\n]s", nomeTime);
        getchar();
        insere(&l, nomeTime);
    }

    /* Laço de chamada da função gerenciadora do Campeonato */
    int empate;
    do{
        empate = menuTabela(l, nomeCampeonato); //menuTabela realiza uma "etapa" e retorna se houve empate ou um time lider em pontos
    } while(empate); //encerra com um time lider de pontos, o campeão
    
    /* Final do Programa - Liberando a Memória */
    while(!estaVazia(&l)){
        retira(&l, getInicio(&l));
    }
}


int menuTabela(ListaLDE l, char nomeCampeonato[20]){
    int vencedor[3]; //vetor com o resultado de cada confronto, armazenando o id do time
    for(int i=0; i<3; i++){ //laço para zerar o vetor
        vencedor[i] = 0;
    }

    int jogos [3][2] = { //matriz contendo id de todos os confrontos da tabela
        {1,2},
        {2,3},
        {3,1}
    };

    /*Menu Campeonato*/
    limpaTela();
    blue();
    printf("\t\t\t\tSIMULADOR DE CAMPEONATOS\n\n");
    yellow();
    printf("\t\t/*\n\t\t*  %s\n\t\t*/\n\n", nomeCampeonato);
    reset();

    tabela(l, vencedor); //primeira chamada, nenhum resultado definido
    /* Laço para o input do resultado de cada confronto */
    for(int i=0; i<3; i++){
        for(;;){ //laço infinito para tratamento de erro do input
            printf("Vencedor do JOGO %d x %d -> ", jogos[i][0], jogos[i][1]);
            scanf("%d", &vencedor[i]);
            if(vencedor[i]==jogos[i][0] || vencedor[i]==jogos[i][1]) break; //input valido
            printf("\n\n");
        }
        /* Atualização do Menu Campeonato */
        limpaTela();
        blue();
        printf("\t\t\t\tSIMULADOR DE CAMPEONATOS\n\n");
        yellow();
        printf("\t\t/*\n\t\t*  %s\n\t\t*/\n\n", nomeCampeonato);
        reset();
        tabela(l, vencedor);
    }

    /* "Etapa" Encerrada */
    int empate = 0;
    /*estrutura equivalente/similar à matriz 'jogos'*/
    if((vencedor[0] != vencedor[1]) && (vencedor[1] != vencedor[2]) && (vencedor[2] != vencedor[0]) ) empate=1; //não-empate

    blue();
    if(!empate){
        printf("CAMPEONATO ENCERRADO!\n");
        reset();
        pausa(-10);
        return empate;
    } else {
        printf("ETAPA DEFINIDA!\n");
        reset();
        pausa(-11);
        return empate;
    }
}



void tabela(ListaLDE l, int vencedor[]){
    No *aux;
    aux = l.inicio;
    int vitorias[3]; //vetor para cada time, contendo quantidade de vitorias
    for(int i=0; i<3; i++){ //laço para zerar o vetor
        vitorias[i] = 0;
    }

    printf("------ TABELA ------\n");

    for(int i=0; i<3; i++){ //laço contador de vitorias
        if(aux->dado.id == vencedor[i]) vitorias[0]++;
    }
    if(vitorias[0] == 2){ //lider
        green();
        printf("[%d] %d. %s\n", vitorias[0], aux->dado.id, aux->dado.nome);
        reset();
    } else{
        printf("[%d] %d. %s\n", vitorias[0], aux->dado.id, aux->dado.nome);
    }
    
    aux = aux->prox;
    for(int i=0; i<3; i++){ //laço contador de vitorias
        if(aux->dado.id == vencedor[i]) vitorias[1]++;
    }
    if(vitorias[1] == 2){ //lider
        green();
        printf("[%d] %d. %s\n", vitorias[1], aux->dado.id, aux->dado.nome);
        reset();
    } else{
        printf("[%d] %d. %s\n", vitorias[1], aux->dado.id, aux->dado.nome);
    }

    aux = aux->prox;
    for(int i=0; i<3; i++){ //laço contador de vitorias
        if(aux->dado.id == vencedor[i]) vitorias[2]++;
    }
    if(vitorias[2] == 2){ //lider
        green();
        printf("[%d] %d. %s\n", vitorias[2], aux->dado.id, aux->dado.nome);
        reset();
    } else{
        printf("[%d] %d. %s\n", vitorias[2], aux->dado.id, aux->dado.nome);
    }

    printf("--------------------\n\n");
}