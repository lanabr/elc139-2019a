## Arquivo de entrega do trabalho 2

Nome: Lana Bertoldo Rossato  
Disciplina: Programação Paralela

### Pthreads

1. Explique como se encontram implementadas as 4 etapas de projeto: particionamento, comunicação, aglomeração, mapeamento (use trechos de código para ilustrar a explicação).
#### Particionamento 
É a divisão do problema, identificando o máximo de oportunidades de paralelismo. No exemplo dado, vemos os vetores sendo alocados com a função **malloc** e preenchidos com a função **fill**.
```
dotdata.a = (double *) malloc(wsize*nthreads*sizeof(double));
fill(dotdata.a, wsize*nthreads, 0.01);
dotdata.b = (double *) malloc(wsize*nthreads*sizeof(double));
fill(dotdata.b, wsize*nthreads, 1.0);
```
Quando as threads são criadas, a função **dotprod_worker** é chamada, divindo o trabalho com as variáveis **start** e **end**, como mostrado abaixo.
```
int i, k;
long offset = (long) arg;
double *a = dotdata.a;
double *b = dotdata.b;     
int wsize = dotdata.wsize;
int start = offset*wsize;
int end = start + wsize;
double mysum;
```
#### Comunicação
É onde as threads se comunicam, e pode ser vista no código abaixo. O mutex garante a exclusividade da thread enquanto a soma que ela executou é incrementada na variável.
```
pthread_mutex_lock (&mutexsum);
dotdata.c += mysum;
pthread_mutex_unlock (&mutexsum);
```
#### Aglomeração
Tem como objetivo diminuir as comunicações. No código, é feita a soma das multiplicações afim de obter uma soma parcial.
```
for (k = 0; k < dotdata.repeat; k++) {
   mysum = 0.0;
   for (i = start; i < end ; i++)  {
      mysum += (a[i] * b[i]);
   }
}
```
#### Mapeamento
Onde o balanceamento é feito. No código, é de forma estática, feita pela função **doprod_threads** e ao criar, chama a função **dotprod_worker**.
```
for (i = 0; i < nthreads; i++) {
   pthread_create(&threads[i], &attr, dotprod_worker, (void *) i);
}
```

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

A tabela com a média, máximo e mínimo estão no arquivo [tabelaminmax.png](tabelaminmax.PNG). Sendo assim, as acelerações são as das tabelas abaixo.

Tamanho do vetor com 1 thread = 1 milhão, 2 threads = 500 mil, 4 threads = 250 mil. (3000 repet.)
Tamanho do vetor com 1 thread = 200 mil, 2 threads = 100 mil, 4 threads = 50 mil. (2000 repet.)
Tamanho do vetor com 1 thread = 2 milhões, 2 threads = 1 milhão, 4 threads = 500 mil. (1000 repet.)

Repetições | Aceleração média com 2 threads | Aceleração média com 4 threads
-----------|--------------------------------|-------------------------------
3000       |          1,933265138   	     |         3,500348138
2000       |          1,971370949	        |         3,763981041
1000       |          2,009120205	        |         3,093991444

Repetições | Aceleração mínima com 2 threads | Aceleração mínima com 4 threads
-----------|--------------------------------|-------------------------------
3000       |          1,846136289           |         3,48603812
2000       |          1,937154668	        |         3,706933068
1000       |          1,954168177           |      	3,193478635 

Repetições | Aceleração máxima com 2 threads | Aceleração máxima com 4 threads
-----------|--------------------------------|-------------------------------
3000       |          1,979646368           |      	3,470006153	
2000       |          1,839976737	        |         3,71261946
1000       |          1,959768949	        |         3,071331741

Na tabela com os valores médios, é possível ver um aumento da aceleração de 2 para 4 threads. Também, quanto maior é o vetor, maior é a aceleração para 2 threads, mas para 4 threads, o valor é maior quando o vetor é menor. 

4. Elabore um gráfico/tabela de aceleração a partir dos dados obtidos no exercício anterior.



5. Explique as diferenças entre pthreads_dotprod.c e pthreads_dotprod2.c. Com as linhas removidas, o programa está correto?

### OpenMP

### Referências
Projeto de programas paralelos. https://github.com/AndreaInfUFSM/elc139-2019a/tree/master/slides
