import copy
from runlabelprop import runlabelprop
import math
import random
from sklearn import metrics

def getscoreofLP(labeledrecords,unlabeledrecords,shuffledbutlabeled,records):

    Y_actualLP = []
    
    for i in range(len(unlabeledrecords)):
        Y_actualLP.append(shuffledbutlabeled[i][1])
    
    for i in range((int)(0.7 * len(records)), len(records)): # test data included in LP
        Y_actualLP.append(shuffledbutlabeled[i][1])
    
    unlabeledrecordsLP = copy.deepcopy(unlabeledrecords)
        
    temp = copy.deepcopy(records[(int)(0.7 * len(records)):])
    for record in temp:
        unlabeledrecordsLP.append(record)
    
    for record in unlabeledrecordsLP:
        record[1] = -1
    
    
    probabilities = runlabelprop(labeledrecords, unlabeledrecordsLP)
    predictedLP = []
    count = 0
    for p in probabilities:
        maxprob = max(p)
        if(math.isnan(maxprob)):
#             print 'yes'
            predictedLP.append(random.randint(1,len(p)))
        else:
            index = p.tolist().index(maxprob)
            predictedLP.append(index)
        count +=1
    
    print 'done with LP, moving ahead'
    return metrics.f1_score(y_true=Y_actualLP, y_pred=predictedLP)
