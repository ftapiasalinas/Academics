#set -x
read -p "Enter a number between 1 and 1000 " number
if [ $number -gt 0 -a $number -lt 1000 ]
    then
        i=1
        while [ $i -le $number ]
        do
            temp=$i
            count=0
            rem=0
            while [ $temp -gt 0 ] 
            do
                rem=`expr $temp % 2`
                temp=`expr $temp / 2`
                if [ $rem -eq 1 ]
                then
                    count=`expr $count + 1`
                fi
            done
            if [ `expr $count % 2` -eq 0 ]
            then
                echo $i is a evil number
            else
                echo $i is not a evil number
            fi
            i=`expr $i + 1`    
        done
    else
        echo $number is not valid
fi
#set +x
