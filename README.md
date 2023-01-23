# HARDWORD - JOGO DE ADIVINHAÇÃO

Esse projeto propõe a criação de um jogo de advinhar palavras, com o objetivo de aplicar, na prática, os conhecimentos adquiridos acerca de estruturas de dados. A estrutura escolhida foi uma Lista Cadastral Circular, implementada com alocação encadeada e dinâmica de memória e com Nó Header.

## A Aplicação:

Hardword é um jogo de adivinhação inspirado no mundialmente conhecido jogo, Wordle, criado por Josh Wardle e lançado em outubro de 2021, com foco e visual inspirados no universo da computação. A função do jogador é adivinhar a palavra sorteada, a qual será relacionada a área da computação e tecnologias. O usuário deverá dar palpites de palavras e o jogo mostrará, por meio de cores diversas, quais letras da palavra palpitada estão presentes na palavra sorteada e na posição correta, estão presentes na palavra sorteada, mas na posição errada ou não estão presentes na palavra sorteada. Sendo que a cor verde representa “presente e na posição correta”, a cor amarela representa “presente, mas na posição errada” e a cor cinza representa “não presente”. A partida termina quando o jogador chega a palavra sorteada ou faz uso das seis tentativas sem acerto.
<br/>
A principal diferença entre o jogo original e este é que Hardword é focado no universo da computação, sendo, dessa forma, uma atividade bastante divertidade e produtiva para aqueles que se interessam por essa fascinante área.


![image](https://user-images.githubusercontent.com/100099053/213937924-a7abad8f-2a19-44fd-8b00-3c8b83459769.png)
Tela inicial do Jogo

![image](https://user-images.githubusercontent.com/100099053/213938062-209bae52-5356-4971-b324-5ff4eb641f38.png)
Tela de informações

![image](https://user-images.githubusercontent.com/100099053/213938182-8a70879f-af3b-4737-8927-548630fd5847.png)
Tela em partida


## O Desenvolvimento:

A estrutura de dados Lista Cadastral Circular é utilizada na implementação da lista de palavras “chutadas” e cada letra armazenada na lista é comparada com sua correspondente na palavra sorteada para verificar seu estado, quando o jogador aciona o botão Check ou pressiona a tecla Enter.
<br/>
O projeto foi desenvolvido na linguagem de programação C++, com o auxílio da biblioteca gráfica SFML, para a implementação da interface. A implementação foi dividida em diversas classes com diferentes funções. Há classes que iniciam o loop do jogo, checam eventos para diferentes interfaces, iniciam interfaces para cada situação dentro do jogo, são componentes das interfaces, entre outras.


![estruturaLC](https://user-images.githubusercontent.com/100099053/214032700-ca177873-1676-432f-90cd-83d5f4766e8a.png)
Desenho criado para representar a estrutura de dados Lista Cadastral Circular

### Classes e Organização:
A classe Jogo inicia o loop do jogo, criando e abrindo uma janela e chamando métodos da classe OperacoesDoJogo caso ocorra algum evento.
<br/>OperacoesDoJogo lida com eventos, como movimento do mouse e pressionamento do mouse ou do teclado, para cada interface (InterfaceInicial, InterfaceInformacoes, InterfacePrincipal, InterfacePosJogo), sendo que as interfaces são representadas por ponteiros da classe abstrata (InterfacePadrao).
<br/>As classes InterfaceInicial, InterfaceInformacoes, InterfacePrincipal e InterfacePosJogo herdam a classe abstrata InterfacePadrao e possuem elementos visuais e funcionalidades específicas para cada situação de jogo, como Botao, Teclado, LetrasDoChute, GradeDeChutes.
<br/>A classe GradeDeChutes, possui um vector de objetos da classe Chutes (Lista cadastral), a qual representa os palpites do jogador, por meio do
encadeamento de objetos da classe Node, que, por sua vez, armazena cada letra chutada (LetrasDoChute) e aponta para a próxima e para a anterior.
<br/>A classe BancoDePalavras armazena, em um vetor, palavras relacionadas a computação e sorteia uma em cada início de partida.

## Participantes:
Leonardo Minguini Sanga
Victor Gabriel Bonometo

