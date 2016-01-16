
#ifndef CARTAS21_H
#define CARTAS21_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h>

#define MIN_C 1 /* Menor número possível de uma carta Ex=As-Paus (1*1) */
#define MAX_C 52 /* Maior número possível de uma carta Ex=Rei-Espadas (13*4)*/

typedef enum boolean { true = 1, false = 0 } bool;

// Struct referente à entidade "Carta"
struct carta {
    int valor; // Valor numérico da carta
    char simbolo[4]; // Representação em texto (para impressão e desenho)
};

// Struct referente à entidade "Jogador"
struct jogador {
    int pontos; // Quantidade de pontos obtidos até o momento
    int qntCartas; // Quantidade de cartas selecionadas
    struct carta * cartas[12]; // Vetor de cartas (armazena ponteiros para cartas)
};

// Struct referente à entidade "Jogo"
struct jogo {
    struct carta * baralho[52]; // Baralho de cartas a ser usado no jogo (armazena ponteiros para cartas)
    struct jogador jHumano;	// Dados referentes ao jogador humano
    struct jogador jMaquina; // Dados referentes jogador máquina
};

// Gera números aleatórios dentro do intervalo informado através dos parâmetros min e max.
// min: Valor mínimo do intervalo.
// max: Valor máximo do intervalo.
int aleatorio(int min, int max);

// Desenhar uma pilha de cartas. Esta função deverá ser implementada recursivamente.
// pilha: Pilha de cartas.
// qnt: Quantidade de cartas na pilha. 
void desenharPilha(struct carta * pilha[], int qnt);

// Divulgar resultado após término do jogo.
// jogoAtual: jogo que acabou de ser encerrado.
void divulgarResultado(struct jogo * jogoAtual);

// Imprime na tela o andamento do jogo
void statusJogo(struct jogo * jogoAtual);

// Controlar se quer realizar uma nova jogada ou não
bool novaJogada(int opc);

// Busca o valor real da carta
int valorCarta(int carta);

// Gera o baralho, cartas - valores e naipes 
void geraBaralho(struct carta *Carta, struct jogo *Jogo);

// Responsável por fazer o tratamento na geração
// de uma carta válida
int geraCarta(struct jogo *Jogo);

// Salva a jogada do Humano
void salvaJogadaJ(struct jogo *Jogo, struct carta *CartaJogador);

// Salva a jogada da Maquina
void salvaJogadaM(struct jogo *Jogo, struct carta *CartaMaquina);

#endif /* CARTAS21_H */

