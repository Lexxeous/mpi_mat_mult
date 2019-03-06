// include necessary libraries
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstdlib>

// declare namespace
using namespace std;

// prototype function(s)
double range_rand_double(double low, double high);

// start main
int main(int argc, char* argv[])
{
  double start_time = MPI_Wtime(); // wall time at the start of the program


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
	double double_lower_bound = 0;
	double double_upper_bound = 500000;


	srand(time(NULL)); // randomize seed based on current time

	// int A[10][10] = {0,0,0,0,0,0,0,0,0,0,
	// 								 1,1,1,1,1,1,1,1,1,1,
	// 								 2,2,2,2,2,2,2,2,2,2,
	// 								 3,3,3,3,3,3,3,3,3,3,
	// 								 4,4,4,4,4,4,4,4,4,4,
	// 								 5,5,5,5,5,5,5,5,5,5,
	// 								 6,6,6,6,6,6,6,6,6,6,
	// 								 7,7,7,7,7,7,7,7,7,7,
	// 								 8,8,8,8,8,8,8,8,8,8,
	// 								 9,9,9,9,9,9,9,9,9,9};

 //  int B[10][10] = {0,0,0,0,0,0,0,0,0,0,
	// 								 1,1,1,1,1,1,1,1,1,1,
	// 								 2,2,2,2,2,2,2,2,2,2,
	// 								 3,3,3,3,3,3,3,3,3,3,
	// 								 4,4,4,4,4,4,4,4,4,4,
	// 								 5,5,5,5,5,5,5,5,5,5,
	// 								 6,6,6,6,6,6,6,6,6,6,
	// 								 7,7,7,7,7,7,7,7,7,7,
	// 								 8,8,8,8,8,8,8,8,8,8,
	// 								 9,9,9,9,9,9,9,9,9,9};

  //  int C[10][10];

	cout << endl << "Creating square matricies of size " << mat_size << "..." << endl;
	double A[mat_size][mat_size];
	double B[mat_size][mat_size];
	double C[mat_size][mat_size];

	// // allocating the matrices
	// cout << endl << "Creating square matricies of size 10 with random double values..." << endl;
	// double** A, B, C;
	// A = calloc(10, sizeof(double*));
	// B = calloc(10, sizeof(double*));
	// C = calloc(10, sizeof(double*));
	// for (int i = 0; i < 10; i++)
	// {
	//   A[i] = calloc(10, sizeof(double));
	//   B[i] = calloc(10, sizeof(double));
	//   C[i] = calloc(10, sizeof(double));
	// }


	printf("\nInitializing random values...\n");
	for(int init_row = 0; init_row < mat_size; init_row++)
	{
		for(int init_col = 0; init_col < mat_size; init_row++)
		{
			A[init_row][init_col] = range_rand_double(double_lower_bound, double_upper_bound);
			B[init_row][init_col] = range_rand_double(double_lower_bound, double_upper_bound);
		}
	}

	// print matrix A								 
	for(int arow=0; arow<mat_size; arow++)
	{
		for(int acol=0; acol<mat_size; acol++)
		{
			printf("%lf\t", A[arow][acol]);
		}
		printf("\n");
	}
	printf("\n");


	// print matrix B							 
	for(int brow=0; brow<mat_size; brow++)
	{
		for(int bcol=0; bcol<mat_size; bcol++)
		{
			printf("%lf\t", B[brow][bcol]);
		}
		printf("\n");
	}
	printf("\n");


	double make_time = MPI_Wtime() - start_time; // seqential creation and initialization time


	//multiply square matricies
	for(int i=0; i<mat_size; i++)
	{
	  for(int j=0; j<mat_size; j++)
	  {
	    double curr_cell = 0; // initialize each new cell with 0
	    for(int k=0; k<mat_size; k++)
	    {
	      curr_cell += A[i][k]*B[k][j];
			}
	    C[i][j] = curr_cell;
	    printf("%lf\t", curr_cell);
		}
		printf("\n");
	}


  // for(int i = 0; i < world_size; i++)
  // {
  //   // compute start and end values for each process
  //   // split A into "partial_A[]" rows and send extra rows to worker processes
  // }

  //   // calculate height for each chunk ; width is all the same: <mat_size>


  double mult_time = MPI_Wtime() - make_time - start_time; // matrix mutiplication time


	double seq_time = make_time;
	double parallel_time = mult_time;

	printf("\nRandomized matrices (of type \"double\" & of square size %d) were sequentially created & initialized in %lf seconds.\n", mat_size, seq_time);
	printf("\nRandomized matrices (of type \"double\" & of square size %d) were multiplied in parallel in %lf seconds.\n", mat_size, parallel_time);

	MPI_Finalize();
}


double range_rand_double(double low, double high)
{
  double range = high - low; // get the range of values
  return (rand() / double (RAND_MAX) * (range - 1)) + low; // return a random double between high and low
}
