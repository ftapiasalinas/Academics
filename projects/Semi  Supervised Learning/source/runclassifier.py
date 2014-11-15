from sklearn import svm, linear_model

def runclassifier(labeledrecords,unlabeledrecords,SVMornot):
    Xtrain = []
    Ytrain = []

    for record in labeledrecords:
        Xtrain.append(record[0])
        Ytrain.append(record[1])
    if(SVMornot == 'SVM'):
        classifier = svm.SVC()
    else:
        classifier = linear_model.LogisticRegression()
    
    classifier.fit(Xtrain, Ytrain)
        
    predictedclasses = []    
    for record in unlabeledrecords:
        predictedclasses.append(classifier.predict(record[0]).tolist()[0])
    return predictedclasses
