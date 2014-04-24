echo the no of files that don\'t begin with the given characters and are text files are
echo enter a
read a
echo enter b
read b
echo enter c
read c
ls $1 | grep  ^[^a\|^b\|^c].*.txt
