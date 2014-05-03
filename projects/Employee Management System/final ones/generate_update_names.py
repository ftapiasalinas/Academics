with open('D:\\users\\Pravin\\Desktop\\new se codes\\final ones\\allnames.txt','r') as f:
    content = f.readlines()
content = content[0].split()

wrt = open('D:\\users\\pravin\\Desktop\\new se codes\\final ones\\update_names_employees.sql','w')

for i, name in enumerate(content):
    query = 'update employees set name=\''+name+'\' where id='+str(i)+';'
    print query
    wrt.write(query+'\n')

wrt.close()

wrt = open('D:\\users\\pravin\\Desktop\\new se codes\\final ones\\update_names_employeescopypravin.sql','w')

for i, name in enumerate(content):
    query = 'update employeescopypravin set name=\''+name+'\' where id='+str(i)+';'
    print query
    wrt.write(query+'\n')

wrt.close()

wrt = open('D:\\users\\pravin\\Desktop\\new se codes\\final ones\\update_names_employeescopysurya.sql','w')

for i, name in enumerate(content):
    query = 'update employeescopysurya set name=\''+name+'\' where id='+str(i)+';'
    print query
    wrt.write(query+'\n')

wrt.close()

wrt = open('D:\\users\\pravin\\Desktop\\new se codes\\final ones\\update_names_employeescopyankur.sql','w')

for i, name in enumerate(content):
    query = 'update employeescopyankur set name=\''+name+'\' where id='+str(i)+';'
    print query
    wrt.write(query+'\n')

wrt.close()

wrt = open('D:\\users\\pravin\\Desktop\\new se codes\\final ones\\update_names_employeescopysahil.sql','w')

for i, name in enumerate(content):
    query = 'update employeescopysahil set name=\''+name+'\' where id='+str(i)+';'
    print query
    wrt.write(query+'\n')

wrt.close()
