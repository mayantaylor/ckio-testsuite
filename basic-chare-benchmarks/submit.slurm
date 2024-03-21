#!/bin/bash
#SBATCH --nodes=32
#SBATCH --ntasks-per-node=64
#SBATCH --output=run.out
#SBATCH --time=00:20:00      # hh:mm:ss for the job
#SBATCH --mem=20g

size=1024

module load openmpi
for test in 0;
do
    chares=2048
    ./charmrun ./reader $((chares)) $((size)) /ocean/projects/asc050015p/mtaylor5/testFile$((test)) +p$((32 * 64)) > 32nodes-64ppn.out

done
