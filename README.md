# Genetic-Travelling-Saleman-Problem
GTSP improved

## O problema: TSP (O Caixeiro Viajante)
Este problema consiste em encontrar a menor rota(tour) que visite todas cidades uma vez a partir de uma cidade inicial e termine nessa mesma cidade. Essa rota descreve também um ciclo halmiltoniano simples. 

## Execução

Compile com: ```g++ src/environment.cpp src/main.cpp -o gtsp``` e execute com ```./gtsp```

## Solução
A solução proposta aqui é a implementação de um algoritmo evolutivo, baseado na teoria da evolução, em que indivíduos mais adaptados possuem maior probabilidade de sobrevivência. Esse algoritmo gerará uma heuristica que buscará a resposta certa usando dos individuos que mais se aproximarem de um caminho curto, sem sub-ciclos, descartando os piores e gerando novos.  

## Descrição formal
Cada cidade pode ser representada por um vértice V(i), e o custo de viajar entre duas cidades pela aresta D(V(i), V(j)). Temos n cidades e uma rota é descrita como P(X) = {V(1), V(2), ..., V(n)} e X = {1, 2, ..., n}. 

## Função objetivo
A rota deve apresentar a menor soma de todas arestas, em outras palavras, a  soma das arestas adjancetes.

Portanto, queremos minimizar: 

<a href="https://www.codecogs.com/eqnedit.php?latex=T_d&space;=&space;\sum_{i=1}^n&space;D(V_i,&space;V_{(i&plus;1)%n})" target="_blank"><img src="https://latex.codecogs.com/gif.latex?T_d&space;=&space;\sum_{i=1}^n&space;D(V_i,&space;V_{(i&plus;1)%n})" title="T_d = \sum_{i=1}^n D(V_i, V_{(i+1)%n})" /></a>

Note que o ultimo index (i + 1) % n corresponde ao caso de quando (i + 1) = (n + 1), então (n + 1) % n = 1. Além disso, em um caso real não sabemos se atingimos a solução ótima

## Inicializando População

A população é inicializada com a geração de indivíduos aleatórios, onde cada indivíduo possui um vetor de genes que representam as cidades na ordem em que são visitadas. Assim, um indivíduo é uma permutação das cidades existentes no problema. É fácil notar que o tamanho de um indivíduo é igual à quantidade de cidades. O tamanho da população é a quantidade de indivíduos gerada e é um parâmetro definido, que deve ser escolhido. De maneira geral, quanto maior o tamanho do problema, maior deve ser o tamanho da população.

## Cálculo do fitness

A cada geração, os indivíduos devem ser avaliados e possuir um fitness: um valor que representa o quão bom é um indivíduo. No caso, quanto menor a função objetivo quando aplicada em um indivíduo maior será o fitness. A função utilizada para avaliar os indivíduos é simplesmente o inverso da função objetivo.
	
	<a href="https://www.codecogs.com/eqnedit.php?latex=F_d&space;=&space;1/T_d" target="_blank"><img src="https://latex.codecogs.com/gif.latex?F_d&space;=&space;1/T_d" title="F_d = 1/T_d" /></a>

## Seleção

A seleção é feita de acordo com o fitness dos indivíduos. Uma parcela da população é selecionada como sua elite. Esses indivíduos são os que possuem os maiores fitness da sua geração e são mantidos na próxima geração. Os demais indivíduos gerados no crossover entre indivíduos de dentro com indivíduos de fora da elite.

## Crossover

O crossover é a maneira que novos indivíduos são gerados a partir da geração anterior. No caso, o crossover é realizado sempre entre dois indivíduos. Dois pontos são selecionados aleatoriamente do primeiro indivíduo. O trecho entre esses dois pontos é inserido no filho. O restante dos genes do novo indivíduo vem do segundo indivíduo, desde que não estejam no trecho inserido anteriormente.

## Mutação 

A mutação é uma técnica utilizada para manter a diversidade numa população. O seu objetivo é evitar que o algoritmo fique preso num máximo local. A mutação no problema abordado é feita trocando aleatoriamente duas cidades de posição na rota. A probabilidade de um gene ser trocado em um dado indivíduo é dada pela equação abaixo.

<a href="https://www.codecogs.com/eqnedit.php?latex=p&space;=&space;P_{MAX}&space;*&space;(P_{MAX}&space;-&space;P_{MIN})&space;*&space;(fitness&space;-&space;fitness_{avg})&space;/&space;(fitness_{max}&space;-&space;fitness_avg);" target="_blank"><img src="https://latex.codecogs.com/gif.latex?p&space;=&space;P_{MAX}&space;*&space;(P_{MAX}&space;-&space;P_{MIN})&space;*&space;(fitness&space;-&space;fitness_{avg})&space;/&space;(fitness_{max}&space;-&space;fitness_avg);" title="p = P_{MAX} * (P_{MAX} - P_{MIN}) * (fitness - fitness_{avg}) / (fitness_{max} - fitness_avg);" /></a>

Onde Pmax e Pmin são parâmetros definidos.

## Parâmetros e escolhas

- MAX_GEN: Quantidade máxima de gerações.
- POPULATION_SIZE: Tamanho da população utilizada.
- ELITE_SIZE: Tamanho da população de Elite.
- PERFECT_SCORE:
- ENABLE_OUTPUT: Assume 1, caso queira a impressão dos resultados de cada geração
- GENERATE_ROUTE:
- P_MAX:
- P_MIN:

## Resultados 

- **Libra (6 pontos):**

MAX_GEN: 100

POPULATION_SIZE: 10

Best fitness: 0.000801282

Distance: 1248

Route: 2 3 4 5 6 1

Best Distance: 1248

Best Route: 1 2 3 4 5 6

Best Solution Found: **YES** (Generation 6)


- **Orion (15 pontos):**

MAX_GEN: 100

POPULATION_SIZE: 100

Best fitness: 0.000538793

Distance: 1856

Route: 2 3 5 13 4 14 15 11 12 10 9 8 6 7 1

Best Distance: 1856

Best Route: 1 2 3 5 13 4 14 15 11 12 10 9 8 6 7

Best Solution Found: **YES** (Generation 72)

- **Teste 30 (30 pontos):**

MAX_GEN: 500000

POPULATION_SIZE: 1000000

Best fitness: 0.00136406

Distance: 733.105

Route: 26 24 25 23 16 17 30 5 6 2 14 8 21 10 20 7 11 1 18 3 4 12 13 22 9 19 15 27 29 28

Best Distance: 426.610

Best Route: 26 25 24 15 14 8 7 10 21 20 19 11 9 18 3 2 1 6 5 4 13 12 30 23 22 17 16 28 27 29

Best Distance Found: **NO**

## Autores

<a href="https://github.com/AlbertWolf99">Alberto Neves (AlbertWolf99)</a> 

<a href="https://github.com/MarcusMedeiros99">Marcus Medeiros (MarcusMedeiros99)</a>

<a href="https://github.com/Math-O5">Mathias Fernandes (Math-O5)</a>

## Agradecimentos

<p>Ao professor <a href="https://github.com/simoesusp">Simões Eduardo</a> e aos escritores do artigo [2], disponivel na referencias.</p>

## Referencias
    
Simões E., aulas de algoritmos evolutivos, disponivel em <https://gitlab.com/simoesusp/disciplinas/-/tree/master/SSC0713-Sistemas-Evolutivos-Aplicados-a-Robotica>

Chunhua Fu, Solving TSP Problem with Improved Genetic Algorithm , disponivel em <https://aip.scitation.org/doi/pdf/10.1063/1.5039131>. 
