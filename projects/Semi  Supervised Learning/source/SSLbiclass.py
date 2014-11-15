import csv,random
from sklearn import semi_supervised, preprocessing,svm
from sklearn import metrics
import copy
def writetofile(path,content):
    with open(path, 'w') as f:
        for row in content:
            f.write("%.2f " % row[0])
            f.write("%.2f" % (float)(1- row[0]))
            f.write('\n')    
            
def takeinput(filename,data,target):
    records  = []
    inp = open(filename,'rb')
    read = csv.reader(inp)
    for row in read:
        if row[7] == 'QSO': #make it only for 2 classes  
            continue
        for i in range(7):
            row[i] = float(row[i])  # implementation requirement
        data.append([row[0],row[1],row[2],row[3],row[4],row[5],row[6]])
        target.append(row[7])
    
    return records
       
def modifyclasslabels(data,target,records):
    count = 0
    for val in target:
        if val == 'STAR':
            records.append([data[count],0])
        elif val == 'GALAXY':
            records.append([data[count],1])
        count+=1

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
                    
def runlabelprop(labeledrecords,unlabeledrecords):
   
    Xtrain = []
    Ytrain = []
    for record in unlabeledrecords:
        Xtrain.append(record[0])
        Ytrain.append(record[1])
    
    for record in labeledrecords:
        Xtrain.append(record[0])
        Ytrain.append(record[1])
    
    
    label_prop = semi_supervised.LabelPropagation()
    label_prop.fit(Xtrain,Ytrain)
    probabilities = label_prop.predict_proba(Xtrain)
#     print len(probabilities)
    return probabilities[:len(unlabeledrecords)]
    
def runSVM(labeledrecords,unlabeledrecords):
    Xtrain = []
    Ytrain = []

    for record in labeledrecords:
        Xtrain.append(record[0])
        Ytrain.append(record[1])
    
    classifier = svm.SVC()
    classifier.fit(Xtrain, Ytrain)
        
    predictedclasses = []    
    for record in unlabeledrecords:
        predictedclasses.append(classifier.predict(record[0]).tolist()[0])
    return predictedclasses
    
path = '/home/sahil/workspace/SSL/10000 records.csv'
data = []
target = []
records = [] 
shuffledbutlabeled = []
takeinput(path,data,target)

data  = preprocessing.scale(data)

modifyclasslabels(data,target,records)

print 'records left after removing extra class labels', len(records) 

separatedrecords = shuffleandunlabel(records,0.75,shuffledbutlabeled) # separatedrecords[0] - labeled records and else is unlabaled
trainingrecords = records[:(int)(0.7 * len(records))]
labeledrecords = separatedrecords[0]
unlabeledrecords = separatedrecords[1]
    
nooflabaledrecords = len(labeledrecords)

while nooflabaledrecords < len(trainingrecords):
    probabilities = runlabelprop(labeledrecords,unlabeledrecords)
    predictedclasses = runSVM(labeledrecords,unlabeledrecords)
    newlyadded = 0 
    foundTarget = False
    for i in range(len(predictedclasses)):
        if probabilities[i][predictedclasses[i]] >0.98:
            foundTarget = True
            unlabeledrecords[i-newlyadded][1] = predictedclasses[i]
            labeledrecords.append(unlabeledrecords.pop(i-newlyadded))
            nooflabaledrecords +=1
            newlyadded+=1
    
    if foundTarget==False:
        break
    
    print 'labeled ' ,nooflabaledrecords        

with open('/home/sahil/workspace/SSL/labeledRecords', 'w') as f:
    for record in labeledrecords:
        for num in record[0]:
            f.write(str(num) + ' ')
        f.write(str(record[1]) + '\n')

testrecords = records[(int)(0.7 * len(records)):]
Y_true = []

for record in testrecords:
    Y_true.append(record[1])
    
predicted = runSVM(labeledrecords, testrecords)
print metrics.f1_score(y_true=Y_true, y_pred=predicted)
print 'done :)'