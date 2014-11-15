import random
def shuffleandunlabel(records,percentage,shuffledbutlabeled):
    
    random.shuffle(records)
    
    for record in records: # copy.deepcopy(records) won't work ..
        shuffledbutlabeled.append(record)
   
    #70 percent is separation of training and test data and percentage variable has the amount of unlabeled data
    sizeoftrainingdata =  (int)(0.70 * len(records))
    recordstounlabel = (int)(percentage * sizeoftrainingdata) 
     
    for i in range(recordstounlabel):
        records[i][1] = -1
        
    unlabeledrecords = records[:recordstounlabel]    
    labeledrecords = records[recordstounlabel:sizeoftrainingdata]    
        
    print 'records unlabeled are ', recordstounlabel
    print 'records labeled are ' , (int)(0.7 * len(records)) - recordstounlabel

    return [labeledrecords,unlabeledrecords]
