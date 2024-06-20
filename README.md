CkIO Testsuite to support reproducability of results for HIPC 2024 submission.

Results for this paper were generated on Bridges2 at PSC (https://www.psc.edu/resources/bridges-2/). 
Template slurm scripts can be found in bridges-scripts. These must be submitted from within the respective test suite directory. 
For example, to run the naive benchmarks:

`cd naive-charm`

`make`

`sbatch ../bridges-scripts/naive-charm.slurm`
