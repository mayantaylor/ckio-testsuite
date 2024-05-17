import sys
import argparse

from mpi4py import MPI

comm = MPI.COMM_WORLD
rank = comm.Get_rank()
size = comm.Get_size()

GB = 1024*1024*1024
MB = 1024 * 1024 

base_filename = sys.argv[1] + "/testfile"
filesize = int(float(sys.argv[2]) * MB)
count = int(sys.argv[3])

for i in range(0, count):
    amode = MPI.MODE_WRONLY|MPI.MODE_CREATE
    filename = base_filename + "_" + str(rank) + "_" + str(i) + ".txt"

    # Create 4KB of data
    data = b"a" * 2048

    with open(filename, 'wb') as f:
        for _ in range(filesize // len(data)):
            f.write(data)


