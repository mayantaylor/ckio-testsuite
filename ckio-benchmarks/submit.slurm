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
filesize=512
./charmrun ./main $((chares)) $((filesize)) +p$((chares)) > results-config1/$((chares)).out










