def modifyclasslabels(data,target,records):
    count = 0
    for val in target:
        if val == 'STAR':
            records.append([data[count],0])
        elif val == 'GALAXY':
            records.append([data[count],1])
        elif val == 'QSO':
            records.append([data[count],2])
        else:
            records.append([data[count],int(val)])
        count+=1