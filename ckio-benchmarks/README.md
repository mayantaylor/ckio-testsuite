## Running

`main.cpp` takes in the following arguments:
- number of readers
- number of buffer chares
- file size (in MB)
- file name (full path)
- background work boolean (denotes if background work should be run and timed)
- output file

The output file given will record a row of data for each run, with the following columns:
- number of readers
- number of buffer chares
- number of PEs (in non-smp, this is equivalent to the number of tasks)
- number of nodes
- file size (in MB)
- background work timed
- total time 