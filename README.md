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

## Iniciando População

## Função de fitness

## Seleção natural(?)

## Crossover (Sexo)

## Mutação 

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

- **Teste 30 (30 pontos):**
MAX_GEN: 500000
POPULATION_SIZE: 1000000
Best fitness: 0.00136406
Distance: 733.105
Route: 26 24 25 23 16 17 30 5 6 2 14 8 21 10 20 7 11 1 18 3 4 12 13 22 9 19 15 27 29 28
Best Distance: 426.610
Best Route: 26 25 24 15 14 8 7 10 21 20 19 11 9 18 3 2 1 6 5 4 13 12 30 23 22 17 16 28 27 29

## Autores

<a href="https://github.com/AlbertWolf99">Alberto Neves (AlbertWolf99)</a> 

<a href="https://github.com/MarcusMedeiros99">Marcus Medeiros (MarcusMedeiros99)</a>

<a href="https://github.com/Math-O5">Mathias Fernandes (Math-O5)</a>

## Agradecimentos

<p>Ao professor <a href="https://github.com/simoesusp">Simões Eduardo</a> e aos escritores do artigo [2], disponivel na referencias.</p>

## Referencias
    
Simões E., aulas de algoritmos evolutivos, disponivel em <https://gitlab.com/simoesusp/disciplinas/-/tree/master/SSC0713-Sistemas-Evolutivos-Aplicados-a-Robotica>

Chunhua Fu, Solving TSP Problem with Improved Genetic Algorithm , disponivel em <https://aip.scitation.org/doi/pdf/10.1063/1.5039131>. 
