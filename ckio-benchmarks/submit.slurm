#!/bin/bash
#SBATCH --nodes=4
#SBATCH --ntasks-per-node=32
#SBATCH --output=run.out
#SBATCH --time=00:20:00      # hh:mm:ss for the job
#SBATCH --mem=20g

module load openmpi
dir=results/4nodes/32cores/4GB/new

# buffer chares = number of cores
# for test in 0 1;
# do
#     filesize=$((2**$((test + 11))))
#     readers=2048
#     buf=256
#     ./charmrun ./main $((buf)) $((filesize)) $((readers)) 10 /ocean/projects/asc050015p/mtaylor5/testFile$((test)) +p$((8 * 32)) > 8nodes-256bc/$((filesize))mb.out
# done

# buffer chares = number of mb
# for test in 0;
# do
#     filesize=$((2**$((test + 10))))
#     readers=2048
#     buf=$((filesize))
#     ./charmrun ./main $((buf)) $((filesize)) $((readers)) 10 /ocean/projects/asc050015p/mtaylor5/testFile$((test)) +p$((8 * 32)) > 8nodes-striperead/$((filesize))mb.out
# done

# buffer chares increase, everything else stays constant
for test in 0 1 2 3 4 5 6 7 8 9;
do
    filesize=$((1024))
    readers=256
    # buf=$((2**$((test + 3))))  # buf chares go from 8 to 4096
    buf=$((2**$(($test + 5)))) # buf chares go from 32 to 512
    ./charmrun ./main $((buf)) $((filesize)) $((readers)) 10 /ocean/projects/asc050015p/mtaylor5/testFile$((test)) +p$((4 * 32))  > $dir/$((buf))buf.out;
    sed -n '/-----SUMMARY DATA------/,/-----END SUMMARY------/p' $dir/$((buf))buf.out | sed '1d;$d' >> $dir/summary.out;
done

