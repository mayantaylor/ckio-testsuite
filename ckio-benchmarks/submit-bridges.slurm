#!/bin/bash
#SBATCH --nodes=16
#SBATCH --ntasks-per-node=32
#SBATCH --output=run.out
#SBATCH --time=00:05:00

module load gcc/13 openmpi/5
module load cuda/11

input_file="/ocean/projects/asc050015p/mtaylor5/16GB.bin"
output_file=32tpn-16GB.out

touch $output_file

nreaders=$SLURM_NTASKS
filesize=$((1024 * 16))
bgwork=0
nodes=$SLURM_NNODES

for bufperpe in 1 2 4; do
    nbuf=$((bufperpe * $SLURM_NTASKS))
    for iter in 1 2 3; do
        # evict input file from cache
        vmtouch -e $input_file
        # read
        ./charmrun ./main $nreaders $nbuf $filesize $input_file $bgwork $nodes $output_file  +p$SLURM_NTASKS
    done
done