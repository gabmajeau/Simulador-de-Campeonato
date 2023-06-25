#ifndef TERMINAL_H_INCLUDED
#define TERMINAL_H_INCLUDED

#define ANSI_RED     "\x1b[31m"
#define ANSI_GREEN   "\x1b[32m"
#define ANSI_YELLOW  "\x1b[33m"
#define ANSI_BLUE    "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN    "\x1b[36m"
#define ANSI_RESET   "\x1b[0m"

/*
*  Limpa a tela do terminal
*/
void limpaTela(void);

/*
*  Trava o programa até que o usuário pressione qualquer tecla
*  Recebe como parâmetro um código referente a mensagem a ser exibida
*/
void pausa(int codigo);

/*
*  Altera a cor do texto no terminal
*/
void red(void);
void green(void);
void yellow(void);
void blue(void);
void magenta(void);
void cyan(void);
void reset(void);

#endif //TERMINAL_H_INCLUDED