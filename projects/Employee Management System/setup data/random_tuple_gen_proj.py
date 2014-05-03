import string, random

def id_generator(size=6):
	return ''.join(random.choice(string.ascii_lowercase) for x in range(size))


f = open('D:\\Users\\Pravin\\Desktop\\new se codes\\setup data\\insertprojects_pravin.sql','w')

for i in range(1,41):
    query = 'insert into projects values('
    projname = '\''+ id_generator(7)+'\''
    projid = random.randint(1,5)
    loc = '\''+ id_generator(6) +'\''
    query += str(i) + ', ' + str(projid) + ', ' + projname + ', '+ loc  +');'
    f.write(query + '\n')

f.close()

    
    


    
    