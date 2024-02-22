#!/bin/bash
#SBATCH --nodes=8
#SBATCH --ntasks-per-node=32
#SBATCH --output=run.out
#SBATCH --time=00:20:00      # hh:mm:ss for the job
#SBATCH --mem=20g

filesize=1024

module load openmpi

for test in 0 1 2 3 4 5 6 7 8 9;
do
    buf=$((2**$((test + 1))))
    readers=2048
    ./charmrun ./main $((buf)) $((filesize)) $((readers)) 10 +p$((8 * 32)) /ocean/projects/asc050015p/mtaylor5/testFile$((test))  > 8nodes-2048readers-yeild25/$((buf))buf.out 
done









