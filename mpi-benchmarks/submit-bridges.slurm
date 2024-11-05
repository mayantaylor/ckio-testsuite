#!/bin/bash
#SBATCH --nodes=16
#SBATCH --ntasks-per-node=32
#SBATCH --output=run.out
#SBATCH --time=00:20:00      # hh:mm:ss for the job


module load gcc/13 openmpi/5
module load cuda/11
size=$((1024 * 16))

input_file="/ocean/projects/asc050015p/mtaylor5/16GB.bin"
output_file=mpi-16GB-32tpn.txt

touch $output_file

for iter in 1 2 3; do
    vmtouch -e $input_file
    mpirun -np $SLURM_NTASKS ./main $((size)) $input_file $output_file
done










