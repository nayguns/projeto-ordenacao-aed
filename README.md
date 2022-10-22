# Projeto com métodos de Ordenação
Repositorio  com programa de metodos de ordenacao  em linguagem C para AVN1 - AED


# Escopo
Este é um trabalho de pesquisa e deve ser elaborado em grupos de dois ou três alunos.

O trabalho deverá ser apresentado pelos grupos de forma remota utilizando o MS-Teams durante a aula
do dia 21/10/2021.

A opção (2) do menu do programa é obrigatória e deve estar presente nos trabalhos de todos os
grupos de alunos.

- O menu do programa abaixo possui as opções 3 até 8.
- Cada grupo de trabalho deve apresentar apenas uma dessas opções, não todas, e o grupo deverá ser capaz de explicar o método de ordenação durante a aula remota para o professor e para todos os alunos presentes na aula.
- O método de ordenação escolhido pelo grupo de trabalho não pode ser o método Bubble Sort.
- Qualquer método de ordenação poderá ser utilizado, não somente aqueles listados nas opções 3 até 8 do menu do programa abaixo, com exceção do método já estudado Bubble Sort.
- Cada grupo deverá encontrar algum vídeo na Internet que explique o método de ordenação escolhido.
- Se não encontrar um vídeo na Internet o grupo deverá criar um vídeo explicando o método.


# Task
A seguir, detalhes do programa a ser implementado pelo grupo de trabalho.

- **1. Codificação com menu e métodos de busca**
    - [x]  O programa deve permitir ao usuário escolher as opções do menu várias vezes sem que o programa seja encerrado.
    - [x]  Cada operação do menu deve mostrar o tempo antes e depois do processamento para que o usuário possa saber o tempo que cada operação demora para ser executada.
    - [x]  Você deve compilar seu programa com um tamanho de array grande o suficiente para que o tempo gasto em cada operação seja de alguns segundos, de forma que seja possível avaliar o tempo de cada operação.
    - [x]  A impressão do array deve ser feita da seguinte forma: imprima somente os 100 primeiros elementos seguidos de reticências e, em seguida, imprima os 100 elementos do final da estrutura.
    
    ```
     (1) Preencher o array com números aleatórios
     (2) Ordenar o array pelo método Bubble Sort
     (3) Ordenar o array pelo método Insertion Sort
     (4) Ordenar o array pelo método Selection Sort
     (5) Ordenar o array pelo método Heap Sort
     (6) Ordenar o array pelo método Quick Sort
     (7) Ordenar o array pelo método Merge Sort
     (8) Ordenar o array pelo método Shell Sort
     (9) Imprimir o array
     Opcao: _
    ```
    
    **Observação: o programa deve ser modularizado e não deve conter variáveis com escopo global.** Você deve pesquisar em livros ou na Internet e encontrar os algoritmos de cada método de ordenação.
    
- **2. Relatórios para apresentação**
    - [x]  Execute o programa da questão anterior e anote em uma tabela o tempo gasto em cada uma das operações.
    - [x]  Anote também detalhes sobre o seu computador, como memória primária, processador, cache etc.
    - [x]  Esta tabela deverá ser mostrada durante a apresentação do trabalho.
- **3. Bugs que surgiram no desenvolvimento 🦟**
    - [x]  **Após ordenação no método Insertion o array está imprimindo com um caractere ‘3’ antes do array. Método de impressão do array é o mesmo para todos. (Ideal revisar o código do trecho).**
    - [x]  Compilador gerando warning com funções do tipo “void”;
    - [ ]  Alterar tipo do array para unsigned long int, afim de conseguir pegar todo o tamanho do limite do Rand;
    - [ ]  Tentar implementar no array static para tentar usar o vetor com mais posições;


# Updates
 - Atualização de impressão com informação de tamanho do Array;
 - Deploy com método de validação para checagem se Array está previamente preenchido antes de entrada nas outras opções do **Menu**;
 - Formatação nas mensagens que serão impressas em tela mediante opções;


# @Notion
Link de acesso com anotações e referências para desenvolvimento do programa.

[Pagina com anotações Notion](https://www.notion.so/Algoritmo-de-Ordena-o-6579e183124e4f23a94872a81ec69b48)
