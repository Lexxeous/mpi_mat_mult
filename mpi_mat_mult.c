// include necessary libraries
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double rangeRandomDouble(double low, double high);

int main(int argc, char* argv[])
{
  double start_time = omp_get_wtime(); // wall time at the start of the program


  // initialize the MPI environment
  MPI_Init(NULL, NULL);
  int world_size, world_rank;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size); // get the number of processes
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank); // get the ranks


  // command line arguments must be the executable & the matrix size: <mat_size>
  if (argc != 2 && world_rank == 0)
  {
    printf("ERR:2:ARGC >> Wrong number of command line arguments.\nUse ./<executable> <mat_size> as format.\n");
    return -2;
  }


  // defining necessary variables
	int mat_size = atoi(argv[1]); // user specified matrix size
	int chunk_size = mat_size / world_size;
	double doubleLowerBound = 0;
	double doubleUpperBound = 500000;


	srand(time(NULL)); // randomize seed based on current time


	cout << endl << "Creating square matricies of size " << mat_size << "..." << endl;
	double A[mat_size][mat_size];
	double B[mat_size][mat_size];
	double C[mat_size][mat_size];


	cout << endl << "Initializing random values..." << endl;
	for(int i = 0; i < mat_size; i++)
	{
		for(int j = 0; j < mat_size; j++)
		{
			A[i][j] = rangeRandomDouble(doubleLowerBound, doubleUpperBound);
			B[i][j] = rangeRandomDouble(doubleLowerBound, doubleUpperBound);
		}
	}


	double make_time = omp_get_wtime() - start_time; // seqential creation and initialization time




  for(int i = 0; i < world_size; i++)
  {
    // compute start and end values for each process
    // split A into "partial_A[]" rows and send extra rows to worker processes
  }

    // calculate height for each chunk ; width is all the same: <mat_size>


  double mult_time = omp_get_wtime() - make_time - start_time; // matrix mutiplication time


	double seq_time = make_time;
	double parallel_time = mult_time;


	cout << endl << "Matrices of square size " << mat_size << " were sequentially created & initialized in "
			 << seq_time << " seconds." << endl;

	cout << endl << "Matrices of square size " << mat_size << " were multiplied in parallel in "
			 << parallel_time << " seconds." << endl;


	return 0;
}


double rangeRandomDouble(double low, double high)
{
  double range = high - low; // get the range of values
  return (rand() / double (RAND_MAX) * (range - 1)) + low; // return a random double between high and low
}
