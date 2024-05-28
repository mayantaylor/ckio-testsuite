#!/bin/bash
#SBATCH -A bip249
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --output=run.out
#SBATCH --time=00:00:30      # hh:mm:ss for the job

dir="frontier/results"
TESTFILE_DIR="/lustre/orion/bip249/scratch/mayat4/"
confFile="debug-1node-32pes-4GB-main"

nTests=4
buf=1
size=1024
bg=0

conf=4
readers=1;
for test in $(seq 0 $nTests);
do
    srun -N $SLURM_JOB_NUM_NODES --ntasks=$SLURM_NTASKS ./main $((buf)) $((size)) $((readers)) $TESTFILE_DIR/testfile_$((conf))_$((test)).txt $bg  > $dir/$((size))MB_$bg.out;
    sed -n '/-----SUMMARY DATA------/,/-----END SUMMARY------/p' $dir/$((size))MB_$bg.out | sed '1d;$d' >> $dir/$confFile.out;
done


