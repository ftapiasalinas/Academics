#set -x
count=0
inputs[0]=
i=0
while [ true ]
    do
        echo 'enter 1 for getting value of sine'
        echo 'enter 2 for getting value of cosine'
        echo 'enter any other value to break the loop'
        read input
        if [ $input -eq 1 -o $input -eq 2 ]
        then
            echo 'enter the value of theta in degrees'
            read theta
            radian=$(echo "a($theta)" | bc -l)
            if [ $input -eq 1 ]
            then
                sine=$(echo "scale=10; s($radian)" | bc -l)
                values[$count]=$sine
                inputs[$count]=$input
                #echo 'sine '$theta is $sine
            else
                cosine=$(echo "scale=10; c($radian)" | bc -l)
                values[$count]=$cosine
                inputs[$count]=$input
                #echo 'cosine '$theta is $cosine
            fi
        else
            echo 'Thank You !!'
            break
        fi
        count=`expr $count + 1 `
    done
while [ $i -lt $count ]
    do
        if [ ${inputs[$i]} -eq 1 ]
        then
            echo 'sine '${values[$i]}
        else
            echo 'cosine '${values[$i]}            
        fi
        i=`expr $i + 1`
    done
#set +x
