#!/bin/bash
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --output=run.out
#SBATCH --partition=cpu
#SBATCH --account=mzu-delta-cpu
#SBATCH --job-name=chare-bench
#SBATCH --time=00:20:00      # hh:mm:ss for the job
#SBATCH --constraint="scratch"
#SBATCH --mem=2g

chares=1
size=1024
./charmrun ./reader $((chares)) $((size)) /scratch/mzu/mtaylor2/testFile +p$((chares)) > results-1node-$((size))MB/$((chares))chare.out







