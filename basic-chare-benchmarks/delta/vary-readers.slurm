#!/bin/bash
#SBATCH --nodes=16
#SBATCH --ntasks-per-node=64
#SBATCH --output=run.out                                                                                                                 
#SBATCH --partition=cpu
#SBATCH --account=mzu-delta-cpu
#SBATCH --job-name=vary-readers
#SBATCH --time=00:20:00
#SBATCH --constraint="scratch"     

export FI_CXI_DEFAULT_CQ_SIZE=0

nConfigs=8
nTests=9
TESTFILE_DIR="/scratch/mzu/mtaylor2/"

dir="delta/results"
size=4096
confFile=vr$((SLURM_JOB_NUM_NODES))nodes$((SLURM_NTASKS))tasks$((size))MB

for conf in $(seq 0 $nConfigs);
do
    nReaders=$((2 ** $(($conf + 4))))

    for test in $(seq 0 $nTests);
    do
        ./charmrun ./reader $((nReaders)) $((size)) $TESTFILE_DIR/testfile_$((conf))_$((test)).txt +p$((SLURM_NTASKS)) > $dir/$((nReaders)).out;
        sed -n '/-----SUMMARY DATA------/,/-----END SUMMARY------/p' $dir/$((nReaders)).out | sed '1d;$d' >> $dir/$confFile.out;
        #rm $dir/$((nReaders)).out
    done
done
