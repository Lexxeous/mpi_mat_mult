#!/bin/bash
#SBATCH --nodes=2
#SBATCH --tasks-per-node=14
#SBATCH --time=00:10:00

mpirun -np 28 ./mpi_mat_mult 10000