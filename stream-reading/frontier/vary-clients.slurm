#!/bin/bash
#SBATCH -A bip249
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --output=run.out
#SBATCH --time=00:05:00      # hh:mm:ss for the job

nConfigs=2
nTests=0

dir="frontier/results"
TESTFILE_DIR="/lustre/orion/bip249/scratch/mayat4/"

confFile=filereader_bs$((SLURM_JOB_NUM_NODES))nodes$((SLURM_NTASKS))tasks

buf=1
size=1024
bg=0

conf=8;
for size in 512;
do
    readers=1
    for test in $(seq 0 $nTests);
    do
        srun  --network=single_node_vni -N $SLURM_JOB_NUM_NODES --ntasks=$SLURM_NTASKS ./main $((buf)) $((size)) $((readers)) $TESTFILE_DIR/testfile_$((conf))_$((test)).txt $bg +traceroot proj/small-debug > $dir/$((size))MB_$bg.out;
        sed -n '/-----SUMMARY DATA------/,/-----END SUMMARY------/p' $dir/$((size))MB_$bg.out | sed '1d;$d' >> $dir/$confFile.out;
    done
done

