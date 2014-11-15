from sklearn import preprocessing,metrics

from takeinput import takeinput      
from modifyclasslabels import modifyclasslabels
from shuffleandunlabel import shuffleandunlabel    
from runlabelprop import runlabelprop        
from runclassifier import runclassifier                    
from getscoreofLP import getscoreofLP    
import time

trainingtimestart = time.time()   
path = '/home/sahil/workspace/SSL/dataset/mfeat.csv'
data = []
target = []
records = [] 
shuffledbutlabeled = []

takeinput(path,data,target)

data  = preprocessing.scale(data)

modifyclasslabels(data,target,records)

print 'records length', len(records) 

separatedrecords = shuffleandunlabel(records,0.8,shuffledbutlabeled) # separatedrecords[0] - labeled records and else is unlabaled
trainingrecords = records[:(int)(0.7 * len(records))]
labeledrecords = separatedrecords[0]
unlabeledrecords = separatedrecords[1]

nooflabeledrecords = len(labeledrecords)

f1LP = getscoreofLP(labeledrecords,unlabeledrecords,shuffledbutlabeled,records)


initlabeledrecords = nooflabeledrecords
probabiltythreshold = 0.99
noofiterations = 0
perofrecordslabeledperiteration = []
classifier = 'SVM'

while nooflabeledrecords < len(trainingrecords):
    probabilities = runlabelprop(labeledrecords,unlabeledrecords)
    predictedclasses = runclassifier(labeledrecords,unlabeledrecords,classifier)
    newlyadded = 0
    foundTarget = False
    for i in range(len(probabilities)):
        if probabilities[i][predictedclasses[i]-1] >= probabiltythreshold: # predictedclasses[i]-1 if no 0 class label
            foundTarget = True
            unlabeledrecords[i-newlyadded][1] = predictedclasses[i]
            labeledrecords.append(unlabeledrecords.pop(i-newlyadded))
            newlyadded+=1
    
    if foundTarget == False:
        break
    
    perofrecordslabeledperiteration.append((float(newlyadded)/nooflabeledrecords) *100 )
    print 'newly labeled ' , newlyadded,
    nooflabeledrecords += newlyadded 
    print 'labeled ' ,nooflabeledrecords
    
    noofiterations += 1       


trainingtimeend = time.time()


totaltrainingtime = trainingtimeend-trainingtimestart
avgiterationtime = float(totaltrainingtime / noofiterations)
peroftotalnewrecordslabeled = float((nooflabeledrecords - initlabeledrecords)) /len(trainingrecords) * 100

testingtimestart = trainingtimeend

testrecords = shuffledbutlabeled[(int)(0.7 * len(records)):]
Y_true = []

for record in testrecords:
    Y_true.append(record[1])

predicted = runclassifier(labeledrecords, testrecords,False)
ourfmeasure = metrics.f1_score(y_true=Y_true, y_pred=predicted)
testingtimeend = time.time()
noofattributes = len(data[0])
totaltestingtime = testingtimeend - testingtimestart


print [totaltrainingtime , totaltestingtime , len(records) , noofattributes , probabiltythreshold , avgiterationtime , 
noofiterations , (peroftotalnewrecordslabeled) , perofrecordslabeledperiteration , ourfmeasure , classifier ,f1LP] 

print '\nho gaya bhai ho gaya..!!'