## Trabalho Prático 1 -  Introdução a Inteligência Artificial
#### Professor Luiz Chaimowicz, UFMG 2022/2

## Sobre
Este projeto explora 5 maneiras diferentes de buscar por um vértice específico em um grafo. BFS, IDS, UCS, Greedy e AStar.

## Como Executar
### Terminal Linux
Para executar um programa em C++, precisamos primeiro compilar seu código fonte.
Para tal, execute o seguinte comando na pasta src:

``` g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp ```

Com isso, será gerado um executável *main*.

Para executar o programa, são necessários 6 parâmetros:
- caminho para o mapa de teste <MAP_PATH>
- o algoritmo escolhido <SEARCH_ALG>
    - BFS, IDS, UCS, Greedy, Astar são os valores válidos;
    - qualquer outro valor é considerado inválido, encerrando a execução
- quatro inteiros separados por espaço, simbolizando (linha, coluna):
    - posição inicial linha <INITIAL_LINE>
    - posição inicial coluna <INITIAL_COLUMN>
    - posição final linha <FINAL_LINE>
    - posição final coluna <FINAL_COLUMN>

Sintaxe: 
``` ./main <MAP_PATH> <SEARCH_ALG> <INITIAL_LINE> <INITIAL_COLUMN> <FINAL_LINE> <FINAL_COLUMN> ```

Exemplo: 
``` ./main ../maps/mapa_teste.map UCS 1 2 2 3 ```

### CMD Windows
Compilar: ``` g++ -o main.exe main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp ```

Executar: ``` ./main.exe ../maps/mapa_teste.map UCS 1 2 2 3 ```

### Makefile
Pode-se usar comandos do Makefile a partir da root do projeto para compilar e executar o programa:
- *make compile*, compila o programa
- *make run*, roda um mapa teste para UCS
- compilam e rodam um teste para cada algoritmo no mapa 'mapa_teste'
    - *make bfsTest* 
    - *make idsTest* 
    - *make ucsTest* 
    - *make greedyTest* 
    - *make astarTest*
- Pode-se rodar os testes de saída para floresta e cidade com os comandos, substituindo x por números entre 1-4:
    - Floresta:
        - *bfsForestx*
        - *idsForestx*
        - *ucsForestx*
        - *greedyForestx*
        - *astarForestx*
    - Cidade:
        - *bfsCityx*
        - *idsCityx*
        - *ucsCityx*
        - *greedyCityx*
        - *astarCityx*

## Saída
A saída do programa é dada da seguinte forma:

``` <PATH_WEIGHT> <NODES_START_TO_GOAL>```

Exemplo: ``` 2 (1,2) (1,3) (2,3) ```