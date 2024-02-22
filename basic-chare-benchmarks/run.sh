#!/bin/sh

echo "Running tests."

for i in 0 1 2 3 4 5 6 7 8 9;
do
    echo "Writing to file"
    python3 ./writer.py /ocean/projects/asc050015p/mtaylor5/testFile$((i)) 1024
done

sbatch submit.slurm

