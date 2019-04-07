### Identificação

Disciplina: Programação Paralela  
Nome: Lana Rossato  

O programa com OpenMP pode ser visto em [OpenMPDemoABC.cpp](OpenMPDemoABC.cpp)

### Casos de teste
```
Case 1: Schedule static, com especificacao do chunk
BBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAABBBCCCCCCCCCCCCCCCCCCCC
A=20
B=20
C=20

Case 2: Schedule static, sem especificacao do chunk
BBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAACCCCCCCCCCCCCCCCCCCC
A=20
B=20
C=20

Case 3: Schedule dynamic, com especificacao do chunk
CCCCCCCCCCAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACCCCCCCCCCBBBBBBBBBB
A=30
B=10
C=20

Case 4: Schedule dynamic, sem especificacao do chunk
BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBCCCCCCCCCCCCCCCCCAB
A=1
B=42
C=17

Case 5: Schedule guided, com especificacao do chunk
CCCCCCCCCCCCCCCBBBBBAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBCCCCC
A=26
B=14
C=20

Case 6: Schedule guided, sem especificacao do chunk
BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBCCCCCCCCCCCCCCAAAAAAAAA
A=9
B=37
C=14

Case 7: Schedule runtime
BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBAC
A=1
B=58
C=1

Case 8: Schedule auto
BBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAACCCCCCCCCCCCCCCCCCCC
A=20
B=20
C=20

Case 9: Sem exclusao mutua, mas com schedule auto
ABCACBABCABCABCABCABCABCABCABACBACBACBACBACBACBACBACBACBAC--
A=20
B=19
C=19

Case 9: Sem exclusao mutua e sem schedule definido
ACBACBACBACBACABCABCABCABACBACBACBACBACBACBACBACBACBACBACB--
A=20
B=19
C=19
```
Para os schedules static, dynamic e guided foram feitos teste com e sem a especificação do chunk. Para os demais, runtime e auto, foram feitos testes somente sem chunk.   
Os chunks são agrupamentos distribuídos entre as threads. Se o schedule for dynamic, os chunks são distribuídos pelas threads, quando termina, a thread recebe dinamicamente outro.  
Foram executados também dois casos sem exclusão mútua e com ou sem definição de schedule.

### Referências
- OpenMP: For & Scheduling. http://jakascorner.com/blog/2016/06/omp-for-scheduling.html
- Loop Scheduling in OpenMP. https://www.openmp.org/wp-content/uploads/SC17-Kale-LoopSchedforOMP_BoothTalk.pdf
