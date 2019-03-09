1.
The root directory contains "Makefile" and "mpi_job.sh". You can run a particular MPI matrix multiplication job using either of these files.
The "mpi_mat_mult.cpp" program is set to print to the screen and output the results to a file called "mpi_mat_mult.out".


2.
Before the program will run, by either the "Makefile" method or the "mpi_job.sh" method, you must first run "make comp" to compile "mpi_mat_mult.cpp" into the appropriate executable "mpi_mat_mult".


3.1 Using "Makefile":
Allocate a proper quantity of nodes and define the number of tasks per node for MPI.
To do this, run "hpcshell --nodes=<num_nodes> --tasks-per-node=<TPN>".
When running on more than 2 processors, I used 2 nodes and the appropriate number of tasks per node to fulfill the resource requirements.
Adjust the default <procs> & <size> parameters at the top of the file to set the number of processes and matrix size for the program.
Call the "run" target by running "make run".
Obtain the output from the program either from the terminal window or the output file: "mpi_mat_mult.out".
NOTE: Lengthy processes may not finish in time before your connection to the HPC server times out. To avoid the potential loss of time and results, use the "mpi_job.sh" method instead.


3.2 Using "mpi_job.sh":
Set the estimated amount of time necessary to complete the job with "--time=<hh:mm:ss>".
Set the number of nodes necessary to complete the job with "--nodes=<num_nodes>".
Set the number of tasks per node necessary to complete the job with "--tasks-per-node=<tpn>".
Edit the <procs> & <size> parameters in-line with "mpirun -np <procs> ./mpi_mat_mult <size>".
Run "sbatch mpi_job.sh" to submit the batch job with the already hardcoded time requested, nodes, and tasks per node.
The HPC server will then assign a job ID to the submission (<job_id>). 
An output file with details about the job will be provided in the root directory as: "slurm-<job_id>.out"

4.
Run "make clean" to remove the executable and all other extraneous output files.
