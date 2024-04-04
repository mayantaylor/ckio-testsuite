#!/bin/bash
#SBATCH --nodes=16
#SBATCH --ntasks-per-node=32
#SBATCH --output=run.out
#SBATCH --time=00:20:00      # hh:mm:ss for the job

size=$((1024 * 4))
dir=results/16nodes_32tasks_4GB

module load openmpi
for test in 0 1 2 3 4 5 6 7 8 9;
do
    chares=$((2 ** $((test + 4))))
    ./charmrun ./reader $((chares)) $((size)) /ocean/projects/asc050015p/mtaylor5/testFile$((test)) +p$((16 * 32)) > $dir/$((chares)).out;
    sed -n '/-----SUMMARY DATA------/,/-----END SUMMARY------/p' $dir/$((chares)).out | sed '1d;$d' >> $dir/summary.out;
done
