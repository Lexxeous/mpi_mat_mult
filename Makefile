# set default variables
procs?=1
size?=1000

comp:
	# mpiCC -o mpi_mat_mult mpi_test.cpp
	mpiCC -o mpi_mat_mult mpi_mat_mult.cpp

run:
	mpirun -np $(procs) ./mpi_mat_mult $(size)
	# mpirun -np $(procs) ./mpi_mat_mult

debug:
	mpiCC -g mpi_test.cpp

gdb:
	mpiexec -d -np $(procs) ./mpi_mat_mult $(size)
	# mpiexec -n $(procs) gdb ./a.out

clean:
	rm mpi_mat_mult mpi_mat_mult.out a.out slurm*

hpc1: # 1 process
	hpcshell --nodes=1 --tasks-per-node=1

hpc2: # 2 processes
	hpcshell --nodes=1 --tasks-per-node=2

hpc4: # 4 processes
	hpcshell --nodes=2 --tasks-per-node=2

hpc8: # 8 processes
	hpcshell --nodes=2 --tasks-per-node=4

hpc16: # 16 processes
	hpcshell --nodes=2 --tasks-per-node=8

hpc28: # 28 processes
	hpcshell --nodes=2 --tasks-per-node=14
