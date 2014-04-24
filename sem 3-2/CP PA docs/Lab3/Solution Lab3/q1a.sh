#echo $1
#echo "now printing file"
cat $2
echo 
echo The count of $1 "in" $2 is
grep -wo $1 $2 | wc -w
