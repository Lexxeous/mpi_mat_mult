#!/bin/bash
#SBATCH --nodes=1
#SBATCH --tasks-per-node=1
#SBATCH --time=00:10:00

mpirun -np 1 ./mpi_mat_mult 20