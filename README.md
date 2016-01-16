# Jogo21

# 21 e Nada Mais
Encontrado em vários cassinos do mundo sob as mais diversas alcunhas e com uma grande quantidade de variações, o 21 é um clássico jogo de cartas onde um ou mais jogadores se enfrentam. Embora existam estratégias que possam ser usadas para se atingir a vitória, principalmente quando vários jogadores estão participando, este jogo depende muito do quanto a deusa da sorte está sorrindo para o jogador durante a partida.

Nesta versão, cada jogador inicia a partida com 0 pontos e recebe uma carta. O valor da carta escolhida é então adicionado aos seus pontos. Este valor segue a seguinte regra: cada ás possui valor 1; as cartas numéricas possuem seus valores nominais; e as
cartas com figura (J, Q e K) valem 10. Os pontos de cada carta escolhida são computados para os jogadores, os quais deverão decidir se desejam mais uma carta. Diante dessa escolha, o jogador pode solicitar mais uma carta ou parar o seu jogo por aí. O segundo jogador segue com seu turno realizando as mesmas escolhas. Este cenário se repete até que:
* Um dos jogadores atinja exatos 21 pontos (Figura 1), sendo considerado o vencedor;
* Um dos jogadores exceda os 21 pontos, sendo o outro considerado vencedor;
* Ambos os jogadores parem suas jogadas antes de completarem ou excederem os 21 pontos, sendo considerado o vencedor aquele que possuir uma maior pontuação; e
* Ambos os jogadores atinjam os 21 pontos com suas cartas ou excedam os 21 pontos, situação na qual se configura um empate.

# Mecânica do Jogo
Descrição Geral

Teremos dois jogadores: o jogador humano e o jogador máquina. Como a seleção de cartas é aleatória, caberá ao jogador humano escolher se deseja uma outra carta ou se deseja encerrar a partida. Após isso, cederá a vez para o jogador máquina. 

No turno do jogador máquina, uma nova carta será selecionada aleatoriamente e adicionada à sua pilha de cartas. Vale salientar que o jogador máquina sempre pegará uma nova carta, independentemente da escolha do jogador humano. Isso influi diretamente no resultado, pois o jogador humano pode utilizar isso em seu benefício para ganhar o jogo, indicando que não deseja mais cartas quando o jogador máquina possui uma quantidade de pontos muito elevada.

Caso o jogador humano escolha encerrar a partida, ela será encerrada logo após o jogador máquina selecionar sua última carta, ou seja, o jogador máquina irá selecionar apenas mais uma carta após o jogador humano decretar o fim da rodada.

A partida também poderá ser encerrada automaticamente caso algum dos jogadores exceda os 21 pontos ou atinja essa marca. Após isso, o jogo procederá para a divulgação do resultado da partida. Com os resultados dispostos, o jogador humano é questionado se deseja uma nova partida. Em caso afirmativo, uma nova terá início. Caso contrário, o programa será encerrado.
