#!/bin/bash
#SBATCH -A bip249
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=10
#SBATCH --output=run.out
#SBATCH --time=00:20:00      # hh:mm:ss for the job



nConfigs=0
nTests=0
TESTFILE_DIR="/lustre/orion/bip249/scratch/mayat4/"

dir="frontier/results"

size=4096
confFile=odfr$((SLURM_JOB_NUM_NODES))nodes$((SLURM_NTASKS))tasks$((size))MB

for conf in $(seq 0 $nConfigs);
do
    nReaders=$((2 ** $(($conf + 3))))

    for test in $(seq 0 $nTests);
    do
        srun -N $SLURM_JOB_NUM_NODES --ntasks=$SLURM_NTASKS ./reader $((nReaders)) $((size)) $TESTFILE_DIR/testfile_$((conf))_$((test)).txt +traceroot proj > $dir/$((nReaders)).out;
        sed -n '/-----SUMMARY DATA------/,/-----END SUMMARY------/p' $dir/$((nReaders)).out | sed '1d;$d' >> \
$dir/$confFile.out;
        # $dir/$((nReaders)).out
    done
done
