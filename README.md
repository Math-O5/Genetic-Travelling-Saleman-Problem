# Genetic-Travelling-Saleman-Problem
GTSP improved

## TSP (O Caixeiro Viajante)
Este problema consiste em encontrar a menor rota(tour) que visite todas cidades uma vez a partir de uma cidade inicial e termine nessa mesma cidade.
A solução proposta aqui é a implementação de um algoritmo evolutivo, baseiado na teoria da evolução, em que individuos mais adaptados possuem mais probabilidade para sobreviverem. 

## Descrição formal
Cada cidade pode ser representada por um vértice V(i), e o custo de viajar entre duas cidades pela aresta D(V(i), V(j)). Temos n cidades e o conjunto de cidades é P(X) = {V(1), V(2), ..., V(n)} e X = {1, 2, ..., n}

## Função objetivo
A rota deve apresentar a menor soma de todas arestas, ou seja, a  soma das arestas adjancetes, portanto:

<a href="https://www.codecogs.com/eqnedit.php?latex=T_d&space;=&space;\sum_{i=1}^n&space;D(V_i,&space;V_{(i&plus;1)%n})" target="_blank"><img src="https://latex.codecogs.com/gif.latex?T_d&space;=&space;\sum_{i=1}^n&space;D(V_i,&space;V_{(i&plus;1)%n})" title="T_d = \sum_{i=1}^n D(V_i, V_{(i+1)%n})" /></a>

Note que o ultimo index (i + 1) % n corresponde ao caso de quando (i + 1) = (n + 1), então (n + 1) % n = 1.

## Iniciando População

## Função de fitness

## Seleção natural(?)

## Crossover (Sexo)

## Mutação 

## Parâmetros e escolhas

## Resultados 

## Autores

<a href="https://github.com/Math-O5">Simões Eduardo</a> 
<a href="https://github.com/AlbertWolf99">Simões Eduardo</a> 

## Agradecimentos

<p>Ao professor <a href="https://github.com/simoesusp">Simões Eduardo</a> e aos escritores do artigo [2], disponivel na referencias.</p>

## Referencias
    
Simões E., aulas de algoritmos evolutivos, disponivel em <https://gitlab.com/simoesusp/disciplinas/-/tree/master/SSC0713-Sistemas-Evolutivos-Aplicados-a-Robotica>

Chunhua Fu, Solving TSP Problem with Improved Genetic Algorithm , disponivel em <https://aip.scitation.org/doi/pdf/10.1063/1.5039131>. 