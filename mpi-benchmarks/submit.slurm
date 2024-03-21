#!/bin/bash
#SBATCH --nodes=4
#SBATCH --ntasks-per-node=32
#SBATCH --output=run-4nodes-128tasks.out
#SBATCH --time=00:20:00      # hh:mm:ss for the job
#SBATCH --mem=20g

tasks=128
size=1024
mpirun -np $((tasks)) ./main $((size)) /ocean/projects/asc050015p/mtaylor5/testFile0












