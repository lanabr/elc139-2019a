### Identificação

Disciplina: Programação Paralela  
Nome: Lana Rossato  
Usando Collaboratory  

### Parte 1
O código desenvolvido para estar parte está em [wavecuda1.cu](wavecuda1.cu). Ele paraleliza a criação de frames, fazendo com que cada thread calcule um frame.  
As configurações utilizadas foram: 1024 100, 1024 200, 256 50 e 256 100, sendo respectivamente o tamanho da imagem e o número de frames. 

Médias de tempo para o programa wave.c:  

|Configuração | tempo   |
|-------------|---------|
| 1024 100    | 13,7641 |
| 1024 200    | 27,1139 |
| 256 50      | 0,4239  |
| 256 100     | 0,8880  |

Médias de tempo para o programa wavecuda1.c:  

|Configuração | tempo   |
|-------------|---------|
| 1024 100    | 0,5110  |
| 1024 200    | 0,5353  |
| 256 50      | 0,0783  |
| 256 100     | 0,0791  |

Gráfico do speedup:  
<img src = speedup1.png>
