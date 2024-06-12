#!/bin/bash
#SBATCH --nodes=4
#SBATCH --ntasks-per-node=2
#SBATCH --output=run.out
#SBATCH --time=00:05:00      # hh:mm:ss for the job


nConfigs=0

dir=bridges/ucx-results
TESTFILE_DIR="/ocean/projects/asc050015p/mtaylor5/"
confFile=4nodes-varyreaders-variable

filesize=1024

pes=$((4 * 2))
buf=$pes



for conf in $(seq 5 9);
do
    bg=1
    for test in $(seq 0 9);
    do
        readers=$((2**$(($test + 3)))) # readers go from 8 to 2048
        echo "Running test $((test)) with $((buf)) buffer chares, $((filesize)) file size, $((readers)) readers, and $((pes)) processors"
        ./charmrun ./main $((buf)) $((filesize)) $((readers)) $TESTFILE_DIR/testfile_$((conf))_$((test)).txt $bg +p$((pes)) +setcpuaffinity > $dir/$((test)).out;
        sed -n '/-----SUMMARY DATA------/,/-----END SUMMARY------/p' $dir/$((test)).out | sed '1d;$d' >> $dir/$confFile.out;
    done
done




# buffer chares = number of mb
# for test in 0;
# do
#     filesize=$((2**$((test + 10))))
#     readers=2048
#     buf=$((filesize))
#     ./charmrun ./main $((buf)) $((filesize)) $((readers)) 10 /ocean/projects/asc050015p/mtaylor5/testFile$((test)) +p$((8 * 32)) > 8nodes-striperead/$((filesize))mb.out
# done

# buffer chares increase, everything else stays constant
#for test in 0 1 2 3 4 5 6 7 8 9 ;
#do
#    filesize=$((1024 * 4))
#    readers=$((2**$(($test + 5)))) # readers go from 32 to 2048
#    buf=$((2**9))
#    ./charmrun ./main $((buf)) $((filesize)) $((readers)) 10 /ocean/projects/asc050015p/mtaylor5/testFile$((test)) +p$((16 * 32))  > $dir/$((readers))readers.out;
#    sed -n '/-----SUMMARY DATA------/,/-----END SUMMARY------/p' $dir/$((readers))readers.out | sed '1d;$d' >> $dir/summary.out;
#done

