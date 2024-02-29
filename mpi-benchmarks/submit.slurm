#!/bin/bash
#SBATCH --nodes=4
#SBATCH --ntasks-per-node=64
#SBATCH --output=run.out
#SBATCH --partition=cpu
#SBATCH --account=mzu-delta-cpu
#SBATCH --job-name=chare-bench
#SBATCH --time=00:20:00      # hh:mm:ss for the job
#SBATCH --constraint="scratch"
#SBATCH --mem=16g

tasks=64
size=1024
srun --nodes=4 --ntasks-per-node=$((tasks)) ./main $((size)) /scratch/mzu/mtaylor2/testFile0












