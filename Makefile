# set default variables
procs?=3
size?=10

comp:
	# mpicc -o mpi_mat_mult mpi_mat_mult.c
	mpiCC -o mpi_mat_mult mpi_test.cpp

run:
	# mpiexec -np $(procs) ./mpi_mat_mult $(size)
	mpirun -np $(procs) ./mpi_mat_mult $(size)
	# mpirun -np $(procs) ./mpi_mat_mult

debug:
	# mpicc -g mpi_mat_mult.c
	mpiCC -g mpi_test.cpp

gdb:
	# mpiexec -n $(procs) gdb ./a.out $(size)
	mpiexec -n $(procs) gdb ./a.out

clean:
	rm mpi_mat_mult mat_mult_result.out

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
