def writetofile(path,content):
    with open(path, 'w') as f:
        for row in content:
            for i in range(len(row)):
                f.write("%.2f " % row[i])
            f.write('\n')  