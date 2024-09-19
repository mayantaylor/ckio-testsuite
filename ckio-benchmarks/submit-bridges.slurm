#!/bin/bash
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --output=run.out
#SBATCH --time=00:05:00

module load gcc/13 openmpi/5
module load cuda/11

input_file=?
output_file=output.txt

nreaders=1
nbuf=1
filesize=1024
bgwork=0

# evict input file from cache
vmtouch -e $input_file

# read
./charmrun ./main $nreaders $nbuf $filesize $input_file $bgwork $output_file +p$SLURM_NTASKS

# check cache status post read
vmtouch $input_file
