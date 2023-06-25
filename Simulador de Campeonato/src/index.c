#include <stdio.h>
#include <stdlib.h>
#include "../include/dados.h"
#include "../include/terminal.h"
#include "../include/chave.h"
#include "../include/tabela.h"


int main(void){
    /* CRIA a Estrutura de Dados */
    ListaLDE l;

    char nomeCampeonato[20];
    int times; //quantidade de times que participarão do campeonato

    /* Menu Inicial */
    blue();
    printf("\t\t\t\tSIMULADOR DE CAMPEONATOS\n\n");
    yellow();
    printf("\t\t/*\n\t\t*  Simulador de Campeonatos de até 8 Times\n\t\t*/\n\n");
    reset();

    /* Leitura de Dados */
    printf("-\nNome do Campeonato\t-> ");
    scanf("%19[^\n]s", nomeCampeonato);
    getchar();
    printf("\n-\n");
    do{ //laço até que input seja válido
        printf("Numero de Times\t\t-> ");
        scanf("%d", &times);
        getchar();
        if( (times>1 && times<9) && (times!=5 && times!=6 && times!=7) ) break; //input válido, encerra o laço
        printf("!numero invalido...\n\n");
    }while(1);


    switch(times){
        /*Confrontos por Chaveamento*/
        case 2:
        case 4:
        case 8:
                setChave(l, times, nomeCampeonato);
                break;
        /*Confrontos por Tabela*/
        case 3:
        //case 5:
        //case 6:
        //case 7:
                setTabela(l, times, nomeCampeonato);
                break;

        default:
                limpaTela();
                printf("ERRO: leitura de times\n"); //erro na validação do input, encerra o programa
                exit(1);
    }

    return 1;
}