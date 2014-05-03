import string, random

def id_generator(size=6):
	return ''.join(random.choice(string.ascii_lowercase) for x in range(size))


payscales = ['8000-15000','15000-25000','25000-40000','40000-100000']
skills = ['java, c++, c','python, java, html','html, css, php', 'plsql, perl, lisp', 'c, python, java', 'octave, matlab, c#']
salaries = [28000, 8000, 15000,10000, 17000, 25000,3500, 40000,30000,100000]
f = open('D:\\Users\\Pravin\\Desktop\\new se codes\\setup data\\insert_queries_pravin.sql','w')
f.write('alter session set NLS_DATE_FORMAT = "MM/DD/YYYY";\n')
for i in range(401,500):
    query = 'insert into employeescopypravin@sahil_link values('
    name = '\''+ id_generator(7)+'\''
    payscale = '\''+ payscales[i%4] + '\''
    joindate = '\''+ str(format(random.randint(1, 12))) +'/'+ str(format(random.randint(1, 28), '02')) +'/'+ format(random.randint(1980, 2050), '02') + '\''
    #TO_DATE('12/12/1993','MM/DD/YYYY')
    enddate = '\''+ str(format(random.randint(1, 12))) +'/'+ str(format(random.randint(1, 28), '02')) +'/'+ format(random.randint(1980, 2050), '02') + '\''
   
    skill = '\''+skills[i%6]+'\''
    salary = salaries[i%10] 
    query += str(i) + ', ' + name + ', ' + payscale + ', ' + 'TO_DATE('  + joindate + ', \'MM/DD/YYYY\')' + ', ' + 'TO_DATE('  + enddate + ', \'MM/DD/YYYY\')' + ', ' + skill + ', ' + str(salary)+ ');'
    f.write(query + '\n')

f.close()

    
    


    
    