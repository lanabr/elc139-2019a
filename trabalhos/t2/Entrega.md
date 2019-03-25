## Arquivo de entrega do trabalho 2

Nome: Lana Bertoldo Rossato  
Disciplina: Programação Paralela

### Pthreads

1. Explique como se encontram implementadas as 4 etapas de projeto: particionamento, comunicação, aglomeração, mapeamento (use trechos de código para ilustrar a explicação).
#### Particionamento 
#### Comunicação
#### Aglomeração
#### Mapeamento

2. Considerando o tempo (em microssegundos) mostrado na saída do programa, qual foi a aceleração (speedup) com o uso de threads?
```
$ ./pthreads_dotprod 1 1000000 2000
10000.000000
1 thread(s), 5497019 usec
$ ./pthreads_dotprod 2 500000 2000
10000.000000
2 thread(s), 2907005 usec
```
Gerando um speedup de 1.890956.

3. A aceleração se sustenta para outros tamanhos de vetores, números de threads e repetições? Para responder a essa questão, você terá que realizar diversas execuções, variando o tamanho do problema (tamanho dos vetores e número de repetições) e o número de threads (1, 2, 4, 8..., dependendo do número de núcleos). Cada caso deve ser executado várias vezes, para depois calcular-se um tempo de processamento médio para cada caso. Atenção aos fatores que podem interferir na confiabilidade da medição: uso compartilhado do computador, tempos muito pequenos, etc.

4. Elabore um gráfico/tabela de aceleração a partir dos dados obtidos no exercício anterior.

5. Explique as diferenças entre pthreads_dotprod.c e pthreads_dotprod2.c. Com as linhas removidas, o programa está correto?

### OpenMP

### Referências
Projeto de programas paralelos. https://github.com/AndreaInfUFSM/elc139-2019a/tree/master/slides
