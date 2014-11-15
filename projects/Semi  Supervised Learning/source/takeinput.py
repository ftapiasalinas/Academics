import csv
def takeinput(filename,data,target):
    inp = open(filename,'rb')
    read = csv.reader(inp)
    for row in read:
        attributes = []
        for i in range(len(row) -1):
            if(row[i] == ''):
                row[i] = 0
            row[i] = float(row[i])
            attributes.append(row[i])
        data.append(attributes)
        target.append(row[len(row)-1])