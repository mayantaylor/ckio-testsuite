#!/bin/bash

# TODO: add sbatch specifications here... for example:

#SBATCH --job-name=mpi-benchmark
#SBATCH --output=mpi.out
#SBATCH --error=mpi.err
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1

# TODO: define the following variables
# TESTFILE: path to the file to be read
# SIZE: size of the file to be read
# PES: number of processing elements

mpirun -np $((SLURM_NTASKS)) ./main $SIZE $TESTFILE;










