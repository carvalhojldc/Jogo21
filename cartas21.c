
#include "cartas21.h"

long seed=0;

int aleatorio(int min,int max) {
    int r;

    if(!seed) {
        time(&seed);
        srand((unsigned)seed);
    }

    r=min+rand()%(max-min+1);
  
    return r;
}

void desenharPilha(struct carta * pilha[], int qnt) {
    
    int i;
    printf("\n");
    
    for(i=0; i<qnt; i++) {
        if(qnt-i==1 || qnt == 1) {
            printf("_________\n");
            printf("| %s     |\n", pilha[i]->simbolo);
            printf("|        |\n");
            printf("|        |\n");
            printf("|        |\n");
            printf("|_____%s_|\n", pilha[i]->simbolo);
        } else {
            printf("_________\n");
            printf("| %s     |\n", pilha[i]->simbolo);
        }
        
    }
    
}

void divulgarResultado(struct jogo * jogoAtual) {
    
    int maquina = jogoAtual->jMaquina.pontos;
    int humano = jogoAtual->jHumano.pontos;
    
    if(humano<= 21 &&  maquina>21) {
        printf("\nJOGADOR MAQUINA estourou! Vencedor: JOGADOR HUMANO");
    } 
    else if(maquina<= 21 &&  humano>21) {
        printf("\nJOGADOR HUMANO estourou! Vencedor: JOGADOR MAQUINA");
    } 
    else if(maquina > 21 && humano> 21) {
        if(maquina > humano) {
            printf("\nVencedor: JOGADOR HUMANO");
        } else {
            printf("\nVencedor: JOGADOR MAQUINA");
        }
    }
    else if(maquina == humano) {
        printf("Ocorreu empate");
    } 
    else if(maquina < humano) {
        printf("\nVencedor: JOGADOR HUMANO");
    } 
    else if(maquina > humano) {
        printf("\nVencedor: JOGADOR MAQUINA");
    }
    
}

void statusJogo(struct jogo * jogoAtual) {
    int i;
    
    system("clear");
    
    printf("############# 21 #############");
    printf("\n> Jogador Humano: %d pontos", jogoAtual->jHumano.pontos);
    desenharPilha(jogoAtual->jHumano.cartas, jogoAtual->jHumano.qntCartas);
    
    printf("\n> Jogador Máquina: %d pontos", jogoAtual->jMaquina.pontos);
    desenharPilha(jogoAtual->jMaquina.cartas, jogoAtual->jMaquina.qntCartas);    

}

bool novaJogada(int opc) {

    char jogar;
    bool ler= true; 

    do {
        if(opc == 1) {
            printf("\n- Deseja mais uma carta? (s/n) ");
        } else if(opc == 2) {
            printf("\n\n ** Deseja particidar de mais uma rodada? (s/n) ");
        }
        
        scanf("%c", &jogar);
        getchar(); /* Limpeza do buffer do teclado - momento do enter... */

        if(jogar != 's' && jogar != 'n') {
            printf("ERRO, opção inválida!");
          
            ler = true;
        } else { /* Ele digitou a entrada correta e finaliza o laço - atribuição false */
            ler = false; 
        }
    } while (ler);
    
    
    /*
        Se o jogador responder s, retorna true, ou seja, ele quer uma nova carta
        Caso contrário, retorna false, ele não quer uma nova carta
    */
    if(jogar == 's') {
        return true;
    } else {
        return false;
    }
}


int valorCarta(int carta) {
    
    /* 
        As cartas são geradas pelo intervelo [1,52]
       
        É realizado o tratamento para que o 
        valor real dela seja retornado [1,13]
     */
    
    if(carta >= 14 && carta <= 26) { /* Cartas Ouros */
        carta = carta - 13;
    } else if(carta >= 27 && carta <= 39) { /* Cartas Copas */
        carta = carta - 26;
    } else if(carta >= 40 && carta <= 52) { /* Cartas Espadas */ 
        carta = carta - 39;
    }    
    
    return carta; /* [1,13] */ 
}

void geraBaralho(struct carta *Carta, struct jogo *Jogo) {
    
    /*
        Gerando o baralho, cartas e repectivos naipes e simbolos
     
     */
    
    int i;
    int valor_carta;
    
    char simbolo[4] = "vN";
    char swap;
    
    for(i=0; i<52; i++) {
        Carta[i].valor = i+1;
        valor_carta = valorCarta(Carta[i].valor);
        
        strcpy(simbolo, "0"); /* ' array */
        
        if(valor_carta == 1) {
            swap = 'A';
        }
        else if(valor_carta < 10 ) {
            swap = (char )(valor_carta+48); /* Converte inteiro para char */
        } 
        else if(valor_carta == 11) {
            swap = 'J';
        } 
        else if(valor_carta == 12) {
            swap = 'Q';
        } 
        else if(valor_carta == 13) {
            swap = 'K';
        } 
        else if(valor_carta == 10) {
            strcpy(simbolo, "10");
        } 
        
        if(valor_carta != 10) {
            simbolo[0]=swap;
        }
                
        if(i < 13) { // Tipo Paus

            strcat(simbolo, "P");
            strcpy(Carta[i].simbolo, simbolo);
            
            Jogo->baralho[i] = &Carta[i];
        } 
        else if(i >= 13 && i < 26) { // Tipo Ouros
            
            strcat(simbolo, "O");
            strcpy(Carta[i].simbolo, simbolo);
            
            Jogo->baralho[i] = &Carta[i];		
        } 
        else if(i >= 26 && i < 39) { // Tipo Copas
            
            strcat(simbolo, "C");
            strcpy(Carta[i].simbolo, simbolo);
            
            Jogo->baralho[i] = &Carta[i];
        } 
        else if(i >= 39 && i < 52) { // Tipo Espadas

            strcat(simbolo, "E");
            strcpy(Carta[i].simbolo, simbolo);
            
            Jogo->baralho[i] = &Carta[i];
        }
    }
}

int geraCarta(struct jogo *Jogo) { 
    int valorCarta;
    int i;
    bool flag = true;
    
    valorCarta = aleatorio(MIN_C, MAX_C); /* Gera uma carta */
       
    while(1) {
        flag = true;
        for(i=0; i<Jogo->jHumano.qntCartas; i++) {
           if(valorCarta == Jogo->jHumano.cartas[i]->valor) {
               valorCarta = aleatorio(MIN_C, MAX_C);
               i = 0;
           }
        }
        
        for(i=0; i<Jogo->jMaquina.qntCartas; i++) {
           if(valorCarta == Jogo->jMaquina.cartas[i]->valor) {
               valorCarta = aleatorio(MIN_C, MAX_C);
               i = 0;
               flag = false;
           }
        }
        
        if(flag) {
            return valorCarta; /* Carta gerada */
        }
    }  
}

void salvaJogadaJ(struct jogo *Jogo, struct carta *CartaJogador) {
    
    int carta;
    int valor_carta;
    int i;
   
    i = Jogo->jHumano.qntCartas; 
    /* Para controle do indice do array */
    
    carta = geraCarta(Jogo);
    /* Gerando um valor entre o MIN e MAX */
    
    valor_carta = valorCarta(carta); 
    /* Buscando valor de carta referente ao valor sorteado */
    
    Jogo->jHumano.qntCartas += 1; 
    /* Para cada nova jogada, incrementa 1 */
    
    /* Controle de pontos */
    if(valor_carta <= 10) {
        Jogo->jHumano.pontos += valor_carta;
        /*
            Cada carta soma o valor nela numerado
            em pontos
            > O ás possui valor 1
        */
    } else {
        Jogo->jHumano.pontos += 10;
        /*
            Demais cartas (J, Q e K), possuem valor 10
        */
    }

    strcpy(CartaJogador[i].simbolo, Jogo->baralho[carta-1]->simbolo); 
    /* 
        Busca o simbolo/naipe da carta gerada pelo rand 
     
        [carta - 1] -> as cartas estão de [1,52], o array inicia 
        na possição 0
     
     */
    
    CartaJogador[i].valor = carta;
    /* Salva o valor real da carta gerada pelo rand */
    
    Jogo->jHumano.cartas[i] = &CartaJogador[i];
    /* Salvando os dados em jHumano*/
   
}

void salvaJogadaM(struct jogo *Jogo, struct carta *CartaMaquina) {
    
    int carta;
    int valor_carta;
    int i;
    
    i = Jogo->jMaquina.qntCartas; 
    /* Para controle do indice do array */
    
    carta = geraCarta(Jogo);
    /* Gerando um valor entre o MIN e MAX */
    
    valor_carta = valorCarta(carta); 
    /* Buscando valor de carta referente ao valor sorteado */
    
    Jogo->jMaquina.qntCartas += 1; 
    /* Para cada nova jogada, incrementa 1 */
    
    /* Controle de pontos */
    if(valor_carta <= 10) {
        Jogo->jMaquina.pontos += valor_carta;
        /*
            Cada carta soma o valor nela numerado
            em pontos
            > O ás possui valor 1
        */
    } else {
        Jogo->jMaquina.pontos += 10;
        /*
            Demais cartas (J, Q e K), possuem valor 10
        */
    }

    strcpy(CartaMaquina[i].simbolo, Jogo->baralho[carta-1]->simbolo); 
    /* 
        Busca o simbolo/naipe da carta gerada pelo rand 
     
        [carta - 1] -> as cartas estão de [1,52], o array inicia 
        na possição 0
     
     */
    
    CartaMaquina[i].valor = carta;
    /* Salva o valor real da carta gerada pelo rand */
    
    Jogo->jMaquina.cartas[i] = &CartaMaquina[i];
    /* Salvando os dados em jHumano*/
   
}
