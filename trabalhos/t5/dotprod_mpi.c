#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mpi.h"

/*
 * Funcao executada pelos processos
 */
double dotprod_worker(double *a, double *b, int wsize, int repeat)
{
   int i, k;
   double mysum;

   for (k = 0; k < repeat; k++) {
      mysum = 0.0;
      for (i = 0; i < wsize; i++)  {
         mysum += (a[i] * b[i]);
      }
   }

   return mysum;
}

/*
 * Tempo (wallclock) em microssegundos
 */
long wtime()
{
   struct timeval t;
   gettimeofday(&t, NULL);
   return t.tv_sec*1000000 + t.tv_usec;
}

/*
 * Preenche vetor
 */
void fill(double *a, double *b, int size)
{
   int i;
   for (i = 0; i < size; i++) {
      a[i] = 0.01;
      b[i] = 1.0;
   }
}

/*
 * Funcao principal
 */
int main(int argc, char **argv)
{
   int i;
   int myrank, p, dest, tag = 0;
   double msg = 0.0;
   MPI_Status status;
   int wsize, repeat;
   long start_time, end_time;
   double sum = 0.0;
   int partes;

   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
   MPI_Comm_size(MPI_COMM_WORLD, &p);

   if ((argc != 3)) {
      printf("Uso: mpiexec -np <ntasks> %s <wsize> <repetitions>\n", argv[0]);
      MPI_Finalize();
      exit(EXIT_FAILURE);
   }

   wsize = atoi(argv[1]);
   repeat = atoi(argv[2]);

   partes = wsize / p;

   double *a = (double *) malloc(partes*sizeof(double));
   double *b = (double *) malloc(partes*sizeof(double));
   fill(a, b, partes);

   start_time = wtime();
   sum = dotprod_worker(a, b, partes, repeat);
   end_time = wtime();

   if(myrank == 0) {
      for(i = 0; i < p - 1; i++){
          MPI_Recv(&msg, 1, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
      }
      sum = sum + msg;
      printf("%f\n", sum);
      printf("%ld usec\n", end_time - start_time);
   }else{
      MPI_Send(&sum, 1, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);
   }

   MPI_Finalize();

   free(a);
   free(b);

   return EXIT_SUCCESS;
}
