### Identificação

Disciplina: Programação Paralela  
Nome: Lana Rossato  

### Parte 1
O código para esta parte pode ser visto em [parte1.c](parte1.c).  
Os gráficos abaixo são para 500, 1000 e 2000 repetições e 2, 4, 8, 16, 32, 64 processos.

<img src = 500repet.png>
<img src = 1000repet.png>
<img src = 2000repet.png>

### Parte 2
Os testes foram executados com o número de processos igual a 16 e com as seguintes variações de largura de banda e latência: 100Mbps e 3us, 150Mbps e 5us, 200Mbps e 7us. O tamanho do vetor foi variado em 500, 1300 e 2000 posições. Foram feitas 100 execuções para cada configuração e após a média de cada uma.

<img src = 100Mbps3us.png>
<img src = 150Mbps5us.png>
<img src = 200Mbps7us.png>
<img src = comparações.png>

### Referências
- MPI_Wtime. https://mpi.deino.net/mpi_functions/MPI_Wtime.html
