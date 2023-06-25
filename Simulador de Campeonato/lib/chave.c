#include <stdio.h>
#include <stdlib.h>
#include "../include/chave.h"
#include "../include/dados.h"
#include "../include/terminal.h"




void setChave(ListaLDE l, int total, char nomeCampeonato[20]){
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
    do{
        total = menuChave(l, total, nomeCampeonato); //menuChave realiza uma "etapa" e retorna a quantidade de times que avançaram para a próxima
    } while(total > 1); //encerra com apenas um time, o campeão
    
    /* Final do Programa - Liberando a Memória */
    while(!estaVazia(&l)){
        retira(&l, getInicio(&l));
    }
}


int menuChave(ListaLDE l, int confrontos, char nomeCampeonato[20]){
    confrontos = confrontos/2; //confrontos entre dois times, logo a quantidade de confrontos é igual a quantidade de equipes dividido por 2
    int erro; //variável auxiliar na verificação de erros no input

    int vencedor[confrontos]; //vetor com o resultado de cada confronto, armazenando o id do time
    for(int i=0; i<confrontos; i++){ //laço para zerar o vetor
        vencedor[i] = 0;
    }

    /*Menu Campeonato*/
    limpaTela();
    blue();
    printf("\t\t\t\tSIMULADOR DE CAMPEONATOS\n\n");
    yellow();
    printf("\t\t/*\n\t\t*  %s\n\t\t*/\n\n", nomeCampeonato);
    reset();

    chave(l, confrontos, vencedor); //primeira chamada, nenhum resultado definido
    /* Laço para o input do resultado de cada confronto */
    for(int i=0; i<confrontos; i++){
        if(confrontos==4) printf("Vencedor do JOGO %d -> ", i+1);
        else if(confrontos==2) printf("Vencedor da SEMI %d -> ", i+1);
        else printf("Vencedor da FINAL -> ");
        scanf("%d", &vencedor[i]);

        /* Atualização do Menu Campeonato */
        limpaTela();
        blue();
        printf("\t\t\t\tSIMULADOR DE CAMPEONATOS\n\n");
        yellow();
        printf("\t\t/*\n\t\t*  %s\n\t\t*/\n\n", nomeCampeonato);
        reset();
        erro = chave(l, confrontos, vencedor);
        if(erro) i--; //força repetir o laço com o valor atual 
    }
    /* "Etapa" Encerrada */
    blue();
    if(confrontos==1){
        printf("CAMPEONATO ENCERRADO!\n");
        reset();
        pausa(-10);
    } else {
        printf("CONFRONTOS DEFINIDOS!\n");
        reset();
        pausa(-11);
    }
    
    /* Remoção dos times eliminados da memória */
    No *aux;
    aux = l.inicio;
    do {
        for(int i=0; i<confrontos; i++){ //laço para percorrer o vetor vencedor
            if (aux->dado.id==vencedor[i]) break; //Nó atual é de um time vencedor, sai do laço

            if (i==confrontos-1) retira(&l, aux->dado.id); //Nó atual não é de um time vencedor, remoção do mesmo da memória
        }
        aux = aux->prox;
    }while(aux);

    return confrontos; //em cada confronto apenas um time avança, logo na proxima "rodada" o numero de equipes é igual ao numero de confrontos atual
}


int chave(ListaLDE l, int times, int vencedor[]){
    No *aux;
    aux = l.inicio;
    times = times*2; //confrontos entre dois times, logo a quantidade de times é igual a quantidade de confrontos multiplicado por 2
    int erro = 0; //inicializada com valor 0, indicando sem erros


    if(times==8) printf("------ JOGO 1 ------\n");
    else if(times==4) printf("------ SEMI 1 ------\n");
    else printf("------ FINAL  ------\n");

    /*CONFRONTO 1*/
    if(vencedor[0]==aux->dado.id) { //primeiro time do confronto venceu
        green();
        printf("%d. %s\n", aux->dado.id, aux->dado.nome); //vencedor em verde
        aux = aux->prox;
        red();
        printf("%d. %s\n", aux->dado.id, aux->dado.nome); //perdedor em vermelho
        aux = aux->prox;
        reset();
    } else if(vencedor[0]==aux->prox->dado.id) { //segundo time do confronto venceu
        red();
        printf("%d. %s\n", aux->dado.id, aux->dado.nome); //perdedor em vermelho
        aux = aux->prox;
        green();
        printf("%d. %s\n", aux->dado.id, aux->dado.nome); //vencedor em verde
        aux = aux->prox;
        reset();
    } else {
        /*Padrão, mostra times em cor branca*/
        printf("%d. %s\n", aux->dado.id, aux->dado.nome);
        aux = aux->prox;
        printf("%d. %s\n", aux->dado.id, aux->dado.nome);
        aux = aux->prox;

        /*Tratamento de erro*/
        if(vencedor[0] != 0) erro = 1; //sinaliza erro
    }


    printf("--------------------");
    if(times==2){ /*Campeonato Encerrado*/
        printf("\n\n");
        return erro;
    }
    

    if(times==4) printf("\t\t------ FINAL  ------\n\n\n------ SEMI 2 ------\t\t--------------------\n");
    else printf("\t\t------ SEMI 1 ------\n\n\n------ JOGO 2 ------\t\t--------------------\n");

    /*CONFRONTO 2*/
    if(vencedor[1]==aux->dado.id) { //primeiro time do confronto venceu
        green();
        printf("%d. %s\n", aux->dado.id, aux->dado.nome); //vencedor em verde
        aux = aux->prox;
        red();
        printf("%d. %s\n", aux->dado.id, aux->dado.nome); //perdedor em vermelho
        aux = aux->prox;
        reset();
    } else if(vencedor[1]==aux->prox->dado.id) { //segundo time do confronto venceu
        red();
        printf("%d. %s\n", aux->dado.id, aux->dado.nome); //perdedor em vermelho
        aux = aux->prox;
        green();
        printf("%d. %s\n", aux->dado.id, aux->dado.nome); //vencedor em verde
        aux = aux->prox;
        reset();
    } else {
        /*Padrão, mostra times em cor branca*/
        printf("%d. %s\n", aux->dado.id, aux->dado.nome);
        aux = aux->prox;
        printf("%d. %s\n", aux->dado.id, aux->dado.nome);
        aux = aux->prox;

        /*Tratamento de erro*/
        if(vencedor[1] != 0) erro = 1; //sinaliza erro
    }


    printf("--------------------");
    if(times==4){ /*Campeonato com 4 Times Encerrado*/
        printf("\n\n");
        return erro;
    }


    printf("\t\t\t\t\t\t\t\t\t------ FINAL  ------\n\n\n------ JOGO 3 ------\t\t\t\t\t\t\t\t\t--------------------\n");
    
    /*CONFRONTO 3*/
    if(vencedor[2]==aux->dado.id) { //primeiro time do confronto venceu
        green();
        printf("%d. %s\n", aux->dado.id, aux->dado.nome); //vencedor em verde
        aux = aux->prox;
        red();
        printf("%d. %s\n", aux->dado.id, aux->dado.nome); //perdedor em vermelho
        aux = aux->prox;
        reset();
    } else if(vencedor[2]==aux->prox->dado.id) { //segundo time do confronto venceu
        red();
        printf("%d. %s\n", aux->dado.id, aux->dado.nome); //perdedor em vermelho
        aux = aux->prox;
        green();
        printf("%d. %s\n", aux->dado.id, aux->dado.nome); //vencedor em verde
        aux = aux->prox;
        reset();
    } else {
        /*Padrão, mostra times em cor branca*/
        printf("%d. %s\n", aux->dado.id, aux->dado.nome);
        aux = aux->prox;
        printf("%d. %s\n", aux->dado.id, aux->dado.nome);
        aux = aux->prox;

        /*Tratamento de erro*/
        if(vencedor[2] != 0) erro = 1; //sinaliza erro
    }

    printf("--------------------\t\t------ SEMI 2 ------\n\n\n------ JOGO 4 ------\t\t--------------------\n");

    /*CONFRONTO 4*/
    if(vencedor[3]==aux->dado.id) { //primeiro time do confronto venceu
        green();
        printf("%d. %s\n", aux->dado.id, aux->dado.nome); //vencedor em verde
        aux = aux->prox;
        red();
        printf("%d. %s\n", aux->dado.id, aux->dado.nome); //perdedor em vermelho
        aux = aux->prox;
        reset();
    } else if(vencedor[3]==aux->prox->dado.id) { //segundo time do confronto venceu
        red();
        printf("%d. %s\n", aux->dado.id, aux->dado.nome); //perdedor em vermelho
        aux = aux->prox;
        green();
        printf("%d. %s\n", aux->dado.id, aux->dado.nome); //vencedor em verde
        aux = aux->prox;
        reset();
    } else {
        /*Padrão, mostra times em cor branca*/
        printf("%d. %s\n", aux->dado.id, aux->dado.nome);
        aux = aux->prox;
        printf("%d. %s\n", aux->dado.id, aux->dado.nome);
        aux = aux->prox;

        /*Tratamento de erro*/
        if(vencedor[3] != 0) erro = 1; //sinaliza erro
    }


    printf("--------------------\n\n");
    return erro; /*Campeonato com 8 Times Encerrado*/
}