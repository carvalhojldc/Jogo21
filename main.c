
#include <stdio.h>
#include <stdlib.h>

#include "cartas21.h"

void inicia(struct jogo *Jogo) {
    
    Jogo->jHumano.pontos = 0;
    Jogo->jHumano.qntCartas = 0;

    Jogo->jMaquina.pontos = 0;
    Jogo->jMaquina.qntCartas = 0;
}

int main() {

    int i;
    bool jogada;

    struct jogo Jogo;
    struct carta *Carta;
    struct carta *CartaJogador;
    struct carta *CartaMaquina;
    
    /* Alocando memória */
    Carta = (struct carta*)malloc(52 * sizeof(struct carta)); 
    CartaJogador = (struct carta*)malloc(12 * sizeof(struct carta));
    CartaMaquina = (struct carta*)malloc(12 * sizeof(struct carta));
    
    geraBaralho(Carta, &Jogo);

    do {
        
        inicia(&Jogo);

        do {

            salvaJogadaJ(&Jogo, CartaJogador);
            salvaJogadaM(&Jogo, CartaMaquina);

            statusJogo(&Jogo);
            

            if(Jogo.jHumano.pontos >= 21 || Jogo.jMaquina.pontos >= 21) {
                 break;
            }

            jogada=novaJogada(1);

        } while(jogada); /* Faz o controle se ele quer uma nova carta */

        if(jogada == false) {
            salvaJogadaM(&Jogo, CartaMaquina);
        }

        statusJogo(&Jogo);
        divulgarResultado(&Jogo);
        
    } while(novaJogada(2));

    printf("\n\n Fim do jogo...");    
  
    /* Liberando alocação de memória */
    free(Carta);
    free(CartaJogador);
    free(CartaMaquina);

    return 0;
}
