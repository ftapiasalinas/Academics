echo the filename is $2
echo the permissions are 
permissions=`ls -l $2 | head --bytes=10 | grep -c x`
echo $permissions
if test $permissions -eq 0 
   then
        echo permission not there
        chmod -700 $2
    else
        echo `ls -l $2`
fi
