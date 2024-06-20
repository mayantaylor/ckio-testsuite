#!/bin/bash
# TODO: add sbatch specifications here... for example:

#SBATCH --job-name=ckio
#SBATCH --output=ckio.out
#SBATCH --error=ckio.err
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1

# TODO: define the following variables
# TESTFILE: path to the file to be read
# SIZE: size of the file to be read
# PES: number of processing elements
# READERS: number of readers or clients
# BG: boolean indicating if background work should be run and timed
# BUF: number of buffer chares being used

./charmrun ./main $BUF $SIZE $READERS $TESTFILE $BG +p$PES +setcpuaffinity


