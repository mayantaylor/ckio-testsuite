#!/bin/bash
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --output=run.out
#SBATCH --time=00:20:00      # hh:mm:ss for the job


TESTFILE_DIR="/ocean/projects/asc050015p/mtaylor5/"


module load openmpi
module load python
echo "writing to dir: " $TESTFILE_DIR
srun -N1 python writer-nompi.py $TESTFILE_DIR 4096 10
