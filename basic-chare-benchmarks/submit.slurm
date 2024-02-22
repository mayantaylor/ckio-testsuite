#!/bin/bash
#SBATCH --nodes=8
#SBATCH --ntasks-per-node=32
#SBATCH --output=run.out
#SBATCH --time=00:20:00      # hh:mm:ss for the job
#SBATCH --mem=20g


size=1024

module load openmpi
for test in 0;
do
    chares=2048
    ./charmrun ./reader $((chares)) $((size)) /ocean/projects/asc050015p/mtaylor5/testFile$((test)) +p$((8 * 32)) > 8nodes-2048readers/$((chares))chares.out 
done







