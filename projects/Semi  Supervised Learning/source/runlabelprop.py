from sklearn import semi_supervised

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
    return probabilities[:len(unlabeledrecords)]
