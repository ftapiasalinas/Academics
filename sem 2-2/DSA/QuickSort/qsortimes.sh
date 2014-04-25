#!/bin/bash

COUNTM=100
MINN=50
NSTEP=50
MAXN=10000
if [ $1 ]
then
	COUNTM=$1
	if [ $2 ]
	then
		MINN=$2
		if [ $3 ]
		then
			NSTEP=$3
			if [ $4 ]
			then
				MAXN=$4
			fi
		fi
	fi
fi

echo Compiling the quicksort program

gcc -D DEBUGQSORT=1 -o xtestqsort testqsort.c quicksort.c partition.c

echo Taking input sizes from $MINN to $MAXN with an increment of $NSTEP
echo Repeating $COUNTM times for each size
if (($MAXN>1000 || ($MAXN-$MINN)/$NSTEP>1000 || $COUNTM>1000)) ;
then
	echo The sizes or the repeat count are too large: will take a long time. Continue?
	read choice
	if [ $choice != "y" -a $choice != "Y" ]
	then
		echo You can redo the experiment by ./$0 10 10 10 100
		echo That will take sizes 10, 20, ..., 100 and repeat each 10 times
		echo You will get a quick result to see
		exit
	fi
fi

for ((n=$MINN ; n<=$MAXN ; n+=$NSTEP))
do
	for ((i=1; i<=$COUNTM; i++))
	do
		echo $n > temp.in
		for ((j=1; j<=n; j++))
		do
			echo $RANDOM
		done >> temp.in
		./xtestqsort < temp.in
	done
done > temp.out

rm temp.in

gcc -o xhist histogen.c

./xhist $MINN $NSTEP $MAXN < temp.out > octavescript.m

rm temp.out

octave octavescript.m

echo Do you want to examine the octave script generated and used?
read choice
if [ $choice != "n" -a $choice != "N" ]
then
	echo Ok, keeping octavescript.m
else
	rm octavescript.m
fi

echo Now examine the pdfs generated in this directory.
echo The histograms give the number of times various run-times were observed during the repetitions.
echo The runtime.pdf gives the actual growth of runtime with input size.
