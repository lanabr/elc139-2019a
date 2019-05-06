### Identificação

Disciplina: Programação Paralela  
Nome: Lana Rossato  

### Parte 1
Código em [dotprod_mpi.c](dotprod_mpi.c).

Os testes foram feitos com tamanhos de vetores de 2000000, 1000000 e 20000, e 3000, 2000, 1000 repetições. Foram utilizados também 1, 2 e 4 processos. Provavelmente alguma coisa deu errado, mas não sei o que é.

Vetor de tamanho 1000000:

Repetições | Aceleração com 2 threads | Aceleração com 4 threads
:---------:|:------------------------:|:------------------------:
 1000      |   	  4,023790749         |      15,71966061
 2000	     |      4,002921724         |    	 15,1099295
 3000      |     	4,005244693	        |      14,99162361

Vetor de tamanho 200000:

Repetições | Aceleração com 2 threads | Aceleração com 4 threads
:---------:|:------------------------:|:------------------------:
 1000      |    	4,203756047	        |     16,17701788
 2000	     |      4,149324345         |  	  16,21558861
 3000	     |      4,176966953         |  	  16,31057383

Vetor com tamanho 2000000:  

Repetições | Aceleração com 2 threads | Aceleração com 4 threads
:---------:|:------------------------:|:------------------------:
 1000	     |      3,922585275	        |     14,42951952
 2000	     |      3,973291394	        |     14,78932494
 3000	     |      3,959186746	        |     14,215379

### Parte 2
Código em [pipeline.c](pipeline.c).

### Parte 3
Para o programa [mpi_errado1.c](mpi_errado1.c), o programa corrigido é [mpi_errado1.c](mpi_corrigido1.c).  
Para o programa [mpi_errado2.c](mpi_errado2.c), o programa corrigido é [mpi_errado2.c](mpi_corrigido2.c).

### Referências

- MPI Broadcast and Collective Communication. http://mpitutorial.com/tutorials/mpi-broadcast-and-collective-communication/
