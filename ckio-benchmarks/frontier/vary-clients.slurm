#!/bin/bash
#SBATCH -A bip249
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=2
#SBATCH --output=run.out
#SBATCH --time=00:05:00      # hh:mm:ss for the job

nConfigs=9
nTests=9
dir="frontier/results"
TESTFILE_DIR="/lustre/orion/bip249/scratch/mayat4/"
confFile=vary-clients-$((SLURM_JOB_NUM_NODES))nodes$((SLURM_NTASKS))tasks2^4bc_noyield

buf=$((2**4))
size=4096
bg=0

for conf in $(seq 0 $nConfigs);
do
    readers=$((2** $((conf + 3))))
    for test in $(seq 0 $nTests);
    do
        srun -N $SLURM_JOB_NUM_NODES --ntasks=$SLURM_NTASKS ./main $((buf)) $((size)) $((readers)) $TESTFILE_DIR/testfile_$((conf))_$((test)).txt $bg > $dir/$((size))MB_$bg.out;
        sed -n '/-----SUMMARY DATA------/,/-----END SUMMARY------/p' $dir/$((size))MB_$bg.out | sed '1d;$d' >> $dir/$confFile.out;
    done
done

