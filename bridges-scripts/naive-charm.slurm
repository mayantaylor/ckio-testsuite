#!/bin/bash
# TODO: add sbatch specifications here... for example:

#SBATCH --job-name=reader
#SBATCH --output=reader.out
#SBATCH --error=reader.err
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1

# TODO: define the following variables
# TESTFILE: path to the file to be read
# SIZE: size of the file to be read
# OUTPUT: path to the output file
# PES: number of processing elements
# READERS: number of readers or clients
# BG: boolean indicating if background work should be run and timed

./charmrun ./reader $READERS $SIZE $TESTFILE $BG +p$PES +setcpuaffinity  > $OUTPUT;


