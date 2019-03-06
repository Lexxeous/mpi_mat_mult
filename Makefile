# set default variables
procs?=1
size?=10

comp:
	# mpicc -o mpi_mat_mult mpi_mat_mult.c
	mpiCC -o mpi_mat_mult mpi_test.cpp

run:
	mpirun -np $(procs) ./mpi_mat_mult $(size)
	# mpirun -np $(procs) ./mpi_mat_mult

debug:
	# mpicc -g mpi_mat_mult.c
	mpicc -g mpi_test.cpp

gdb:
	mpiexec -n $(procs) gdb ./a.out

clean:
	rm mpi_mat_mult

hpc1:
	hpcshell --nodes=1 --tasks-per-node=1

hpc2:
	hpcshell --nodes=1 --tasks-per-node=2

hpc4:
	hpcshell --nodes=2 --tasks-per-node=2

hpc8:
	hpcshell --nodes=2 --tasks-per-node=4

hpc16:
	hpcshell --nodes=2 --tasks-per-node=8

hpc28:
	hpcshell --nodes=2 --tasks-per-node=14
