# Genetic-Travelling-Saleman-Problem
GTSP improved

## O problema: TSP (O Caixeiro Viajante)
Este problema consiste em encontrar a menor rota(tour) que visite todas cidades uma vez a partir de uma cidade inicial e termine nessa mesma cidade. Essa rota é descreve também um ciclo halmiltoniano simples. 

## Execução

Compile com: ```g++ g++ src/environment.cpp src/main.cpp -o gtsp``` e execute com ```./gtsp```

## Soluçãp
A solução proposta aqui é a implementação de um algoritmo evolutivo, baseiado na teoria da evolução, em que individuos mais adaptados possuem mais probabilidade para sobreviverem. Esse algoritmo gerará uma heuristica que buscará a resposta certa usando dos individuos que mais se aproximarem de um caminho curto, sem sub-ciclos, descartando os piores e gerando novos.  

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

## Resultados 

## Autores

<a href="https://github.com/Math-O5">Mathias Fernandes (Math-O5)</a> 

<a href="https://github.com/AlbertWolf99">Alberto Wolf (Alberto99)</a> 

## Agradecimentos

<p>Ao professor <a href="https://github.com/simoesusp">Simões Eduardo</a> e aos escritores do artigo [2], disponivel na referencias.</p>

## Referencias
    
Simões E., aulas de algoritmos evolutivos, disponivel em <https://gitlab.com/simoesusp/disciplinas/-/tree/master/SSC0713-Sistemas-Evolutivos-Aplicados-a-Robotica>

Chunhua Fu, Solving TSP Problem with Improved Genetic Algorithm , disponivel em <https://aip.scitation.org/doi/pdf/10.1063/1.5039131>. 
