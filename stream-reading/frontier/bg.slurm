#!/bin/bash
#SBATCH -A bip249
#SBATCH --nodes=16
#SBATCH --ntasks-per-node=32
#SBATCH --output=run.out
#SBATCH --time=00:20:00      # hh:mm:ss for the job

nConfigs=9
nTests=9
dir="frontier/results"
TESTFILE_DIR=/lustre/orion/bip249/scratch/mayat4/


# change file size
confFile=bgwork$((SLURM_JOB_NUM_NODES))nodes$((SLURM_NTASKS))tasks_injection
readers=2048

# bg work experiments
bg=1

size=4096
conf=0
buf=$((2**12))
for test in $(seq 0 $nTests);
do
    srun -N $SLURM_JOB_NUM_NODES --ntasks=$SLURM_NTASKS ./main $((buf)) $((size)) $((readers)) $TESTFILE_DIR/testfile_$((conf))_$((test)).txt $bg > $dir/$((size))MB_$bg.out;
    sed -n '/-----SUMMARY DATA------/,/-----END SUMMARY------/p' $dir/$((size))MB_$bg.out | sed '1d;$d' >> $dir/$confFile.out;
done

size=512
conf=1
buf=$((2**10))
for test in $(seq 0 $nTests);
do
    srun -N $SLURM_JOB_NUM_NODES --ntasks=$SLURM_NTASKS ./main $((buf)) $((size)) $((readers)) $TESTFILE_DIR/testfile_$((conf))_$((test)).txt $bg > $dir/$((size))MB_$bg.out;
    sed -n '/-----SUMMARY DATA------/,/-----END SUMMARY------/p' $dir/$((size))MB_$bg.out | sed '1d;$d' >> $dir/$confFile.out;
done


size=16
conf=2
buf=$((2**4))
for test in $(seq 0 $nTests);
do
    srun -N $SLURM_JOB_NUM_NODES --ntasks=$SLURM_NTASKS ./main $((buf)) $((size)) $((readers)) $TESTFILE_DIR/testfile_$((conf))_$((test)).txt $bg > $dir/$((size))MB_$bg.out;
    sed -n '/-----SUMMARY DATA------/,/-----END SUMMARY------/p' $dir/$((size))MB_$bg.out | sed '1d;$d' >> $dir/$confFile.out;
done

# no bg work
bg=0

size=4096
conf=3
buf=$((2**12))
for test in $(seq 0 $nTests);
do
    srun -N $SLURM_JOB_NUM_NODES --ntasks=$SLURM_NTASKS ./main $((buf)) $((size)) $((readers)) $TESTFILE_DIR/testfile_$((conf))_$((test)).txt $bg > $dir/$((size))MB_$bg.out;
    sed -n '/-----SUMMARY DATA------/,/-----END SUMMARY------/p' $dir/$((size))MB_$bg.out | sed '1d;$d' >> $dir/$confFile.out;
done

size=512
conf=4
buf=$((2**10))
for test in $(seq 0 $nTests);
do
    srun -N $SLURM_JOB_NUM_NODES --ntasks=$SLURM_NTASKS ./main $((buf)) $((size)) $((readers)) $TESTFILE_DIR/testfile_$((conf))_$((test)).txt $bg > $dir/$((size))MB_$bg.out;
    sed -n '/-----SUMMARY DATA------/,/-----END SUMMARY------/p' $dir/$((size))MB_$bg.out | sed '1d;$d' >> $dir/$confFile.out;
done


size=16
conf=5
buf=$((2**4))
for test in $(seq 0 $nTests);
do
    srun -N $SLURM_JOB_NUM_NODES --ntasks=$SLURM_NTASKS ./main $((buf)) $((size)) $((readers)) $TESTFILE_DIR/testfile_$((conf))_$((test)).txt $bg > $dir/$((size))MB_$bg.out;
    sed -n '/-----SUMMARY DATA------/,/-----END SUMMARY------/p' $dir/$((size))MB_$bg.out | sed '1d;$d' >> $dir/$confFile.out;
done