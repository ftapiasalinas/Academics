echo "enter file 1"
read filename1

echo "enter file 2"
read filename2

size_file1=`expr $(cat $filename1 | wc -c)`
#echo "size 1 $size_file1"

size_file2=`expr $(cat $filename2 | wc -c)`
#echo "size 2 $size_file2"

if test $size_file1 -gt $size_file2
then
	echo "$filename1 has more content: $size_file1"
elif test $size_file2 -gt $size_file1
then
	echo "$filename2 has more content: $size_file2"
else
	echo "No of lines are same: $size_file1"
fi

