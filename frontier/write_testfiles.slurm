#!/bin/sh

#SBATCH -A bip249
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=10
#SBATCH --output=run.out
#SBATCH --time=00:00:30      # hh:mm:ss for the job

echo "writing to dir: " $TESTFILE_DIR
srun -N1 -n10 python writer.py $TESTFILE_DIR 4096 10
