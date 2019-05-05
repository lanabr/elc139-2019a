#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mpi.h"

int main(int argc, char **argv)
{
   int myrank, numtasks, source, dest, msg, tag = 0;
   MPI_Status status;

   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
   MPI_Comm_size(MPI_COMM_WORLD, &numtasks);

   if(myrank == 0) {
      msg = 0;
      dest = 1;
      printf("Processo %d mandando mensagem %d\n", myrank, msg);
      MPI_Send(&msg, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
   }else if(myrank != numtasks - 1){
      source = myrank - 1;
      dest = myrank + 1;
      MPI_Recv(&msg, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
      printf("Processo %d recebendo mensagem %d\n", myrank, msg);
      msg = msg + 1;
      MPI_Send(&msg, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
      printf("Processo %d mandando mensagem %d\n    ", myrank, msg);
   }else{
      source = myrank - 1;
      MPI_Recv(&msg, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
      printf("Mensagem: %d\n", msg);
   }

   MPI_Finalize();

   return EXIT_SUCCESS;
}
