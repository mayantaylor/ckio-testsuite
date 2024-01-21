#!/bin/bash
#SBATCH --nodes=4
#SBATCH --ntasks-per-node=64
#SBATCH --output=run.out
#SBATCH --partition=cpu
#SBATCH --account=mzu-delta-cpu
#SBATCH --job-name=chare-bench
#SBATCH --time=00:20:00      # hh:mm:ss for the job
#SBATCH --constraint="scratch"

chares=256
size=64
./charmrun ./reader $((chares)) $((size)) /scratch/mzu/mtaylor2/testFile9 >> results-4nodes/$((chares))chares.txt +p$((chares))







