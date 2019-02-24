# set default variables
procs?=1
size?=1000

comp:
	mpicc -o mpi_mat_mult mpi_mat_mult.c

run:
	mpirun -np $(procs) ./mpi_mat_mult $(size)

clean:
	rm mpi_mat_mult

hpc_1:
	hpcshell --nodes=1 --tasks-per-node=1 --time=12:00:00

hpc_2:
	hpcshell --nodes=1 --tasks-per-node=2 --time=06:00:00

hpc_4:
	hpcshell --nodes=2 --tasks-per-node=2 --time=04:00:00

hpc_8:
	hpcshell --nodes=2 --tasks-per-node=4 --time=02:00:00

hpc_16:
	hpcshell --nodes=2 --tasks-per-node=8 --time=01:00:00

hpc_28:
	hpcshell --nodes=2 --tasks-per-node=14 --time=00:30:00
