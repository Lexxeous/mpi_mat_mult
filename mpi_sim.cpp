// include necessary libraries
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <math.h>

// declare namespace
using namespace std;

// prototype function(s)
double range_rand_double(double low, double high);

// start main
int main(int argc, char* argv[])
{
	int mat_size = atoi(argv[1]); // user specified matrix size
	double C[mat_size][mat_size]; // create C as a "global" matrix?

	// initialize the MPI environment
  MPI_Init(NULL, NULL);
  int world_size, world_rank;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size); // get the number of processes
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank); // get the ranks for each individual process

  double start_time, make_time, mult_time;

  if(world_rank == 0)
  {
  	start_time = MPI_Wtime(); // wall time at the start of the program	
  }
 

  // command line arguments must be the executable & the matrix size: <mat_size>
  if (argc != 2 && world_rank == 0)
  {
    cout << "ERR:2:ARGC >> Wrong number of command line arguments.\nUse \"mpirun -np <world_size> ./<executable> <mat_size>\" as format.\n";
    MPI_Abort(MPI_COMM_WORLD, -2);
  }


  // defining necessary variables
	int chunk_size = floor(mat_size / world_size);
	int unique_rows = (mat_size % world_size) + chunk_size;
	double double_lower_bound = 0;
	double double_upper_bound = 500000;


	srand(time(NULL)); // randomize seed based on current time


	if(world_rank == 0)
  {
  	cout << "Results for: " << world_size << " processes, chunk sizes of " << chunk_size << ", and matrix sizes of " << mat_size << "...\n";
  	cout << "\nCreating square matricies of size " << mat_size << "...\n";
  }
  MPI_Barrier(MPI_COMM_WORLD);
	

	// // every process gets there own instance of matrices A & B
	// double A[10][10] = {0,0,0,0,0,0,0,0,0,0,
	// 								 1,1,1,1,1,1,1,1,1,1,
	// 								 2,2,2,2,2,2,2,2,2,2,
	// 								 3,3,3,3,3,3,3,3,3,3,
	// 								 4,4,4,4,4,4,4,4,4,4,
	// 								 5,5,5,5,5,5,5,5,5,5,
	// 								 6,6,6,6,6,6,6,6,6,6,
	// 								 7,7,7,7,7,7,7,7,7,7,
	// 								 8,8,8,8,8,8,8,8,8,8,
	// 								 9,9,9,9,9,9,9,9,9,9};

 //  double B[10][10] = {0,0,0,0,0,0,0,0,0,0,
	// 								 1,1,1,1,1,1,1,1,1,1,
	// 								 2,2,2,2,2,2,2,2,2,2,
	// 								 3,3,3,3,3,3,3,3,3,3,
	// 								 4,4,4,4,4,4,4,4,4,4,
	// 								 5,5,5,5,5,5,5,5,5,5,
	// 								 6,6,6,6,6,6,6,6,6,6,
	// 								 7,7,7,7,7,7,7,7,7,7,
	// 								 8,8,8,8,8,8,8,8,8,8,
	// 								 9,9,9,9,9,9,9,9,9,9};


	
	double A[mat_size][mat_size];
	double B[mat_size][mat_size];
	// double temp_C[mat_size][mat_size];

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
	//   temp_C[i] = calloc(10, sizeof(double));
	// }

	// double** A, B, C;
	// A = new double*[mat_size];
	// B = new double*[mat_size];
	// C = new double*[mat_size];
	// for(int i = 0; i < mat_size; ++i)
	// {
	//   A[i] = new double[mat_size];
	//   B[i] = new double[mat_size];
	//   temp_C[i] = new double[mat_size];
	// }

	// double** A = (double**) (malloc(sizeof(double*) * 10));
	// double** B = (double**) (malloc(sizeof(double*) * 10));
	// double** C = (double**) (malloc(sizeof(double*) * 10));
	// for (int i = 0; i < 10; i++)
	// {
	//   A[i] = (double*) malloc(sizeof(double) * 10);
	//   B[i] = (double*) malloc(sizeof(double) * 10);
	//   temp_C[i] = (double*) malloc(sizeof(double) * 10);
	// }


	if(world_rank == 0)
	{
		cout << "\nInitializing random values...\n";	
	}
	MPI_Barrier(MPI_COMM_WORLD);
	

	// every process gets there own instances of A & B
	for(int init_row = 0; init_row < mat_size; init_row++)
	{
		for(int init_col = 0; init_col < mat_size; init_col++)
		{
			A[init_row][init_col] = range_rand_double(double_lower_bound, double_upper_bound);
			B[init_row][init_col] = range_rand_double(double_lower_bound, double_upper_bound);
		}
	}

 //  // print the original matrices only once
 //  if(world_rank == 0)
 //  {
	// 	// print matrix A								 
	// 	for(int a_row = 0; a_row < mat_size; a_row++)
	// 	{
	// 		for(int a_col = 0; a_col < mat_size; a_col++)
	// 		{
	// 			cout << A[a_row][a_col] << "\t";
	// 		}
	// 		cout << "\n";
	// 	}
	// 	cout << "\n";


	// 	// print matrix B							 
	// 	for(int b_row = 0; b_row < mat_size; b_row++)
	// 	{
	// 		for(int b_col = 0; b_col < mat_size; b_col++)
	// 		{
	// 			cout << B[b_row][b_col] << "\t";
	// 		}
	// 		cout << "\n";
	// 	}
	// 	cout << "\n";

	if(world_rank == 0)
	{
		make_time = MPI_Wtime() - start_time; // seqential creation and initialization time
	}
	MPI_Barrier(MPI_COMM_WORLD);


	// calculate start and end values for row wise partitioning for every process
	int start = (chunk_size * world_rank);
  int end = (start + chunk_size - 1);
  if(world_rank == (world_size - 1))
  {
    end = mat_size - 1;
  }

  if(world_rank == 0)
	{
		cout << "\nGenerating matrix C by square matrix multiplication (C = A•B) with " 
				 << world_size << " processes and a chunk size of " << chunk_size << "...\n";
	}
	MPI_Barrier(MPI_COMM_WORLD);


  int curr_rank = 0;
	while(curr_rank < world_size)
	{
		if(world_rank == curr_rank)
		{
			cout << "\nProcess " << world_rank << " starts at row " << start << " and ends at row " << end << "...\n";
    }
   curr_rank++;
   MPI_Barrier(MPI_COMM_WORLD);
	}


	//multiply square matricies
	double curr_cell;
	for(int mult_row = start; mult_row <= end; mult_row++)
	{
	  for(int mult_col = 0; mult_col < mat_size; mult_col++)
	  {
	    curr_cell = 0; // initialize each new cell with 0
	    for(int itr = 0; itr < mat_size; itr++)
	    {
	      curr_cell += A[mult_row][itr]*B[itr][mult_col];
			}
			C[mult_row][mult_col] = curr_cell;
			// cout << C[mult_row][mult_col] << "\t"; // for printing each element
		}
		// cout << endl; // for ending each row
	}


	if(world_rank == 0)
	{
	  mult_time = MPI_Wtime() - make_time - start_time; // matrix mutiplication time

	  // output sequential and parallel execution times
	  cout << "\nRandomized matrices (of type \"double\" & of square size " << mat_size
				 << ") were sequentially created & initialized in " << make_time << " seconds.\n";

		cout << "\nRandomized matrices (of type \"double\" & of square size " << mat_size
				 << ") were multiplied in parallel in " << mult_time << " seconds.\n";
	}


	// // cleanup
	// for(int i = 0; i < 10; ++i)
	// {
	//   delete[] A[i];
	//   delete[] B[i];
	//   delete[] temp_C[i];
	// }
	// delete[] A;
	// delete[] B;
	// delete[] temp_C;

	MPI_Finalize();
}


double range_rand_double(double low, double high)
{
  double range = high - low; // get the range of values
  return (rand() / double (RAND_MAX) * (range - 1)) + low; // return a random double between high and low
}
