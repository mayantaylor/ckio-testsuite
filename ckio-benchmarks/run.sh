#!/bin/sh



for i in 0 1 2 3 4 5 6 7 8 9;
	 
do
    for j in 0 1 2 3 4 5 6 7 8 9;
	     do
		 python3 ./writer.py /ocean/projects/asc050015p/mtaylor5/testFile$((i))$((j)) 1024
    done
done



