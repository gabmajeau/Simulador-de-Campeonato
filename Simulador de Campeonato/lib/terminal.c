#include <stdio.h>
#include "../include/terminal.h"


void limpaTela(void){
  printf("\033[H\033[J");
}

void pausa(int codigo){
  char c; //variável descartável da leitura

  switch(codigo){
    /* Codigos */
    case -10:
      printf("Aperte qualquer tecla para encerrar o campeonato...");
    case -11:
      printf("Aperte qualquer tecla para continuar o campeonato...");
  }

  getchar();
  scanf("%c", &c);
}


void red(void) {
printf(ANSI_RED);
  return;
}

void green(void) {
  printf(ANSI_GREEN);
  return;
}

void yellow(void) {
  printf(ANSI_YELLOW);
  return;
}

void blue(void) {
  printf(ANSI_BLUE);
  return;
}

void magenta(void) {
  printf(ANSI_MAGENTA);
  return;
}

void cyan(void) {
  printf(ANSI_CYAN);
  return;
}

void reset(void) {
  printf(ANSI_RESET);
  return;
}