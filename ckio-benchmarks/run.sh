#!/bin/sh



for i in 0 1 2 3 4 5 6 7 8 9;
do
    python3 ./writer.py /scratch/mzu/mtaylor2/testFile$((i)) 512 
done

sbatch submit.slurm

