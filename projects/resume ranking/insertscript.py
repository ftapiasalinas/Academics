import csv
import MySQLdb
db = MySQLdb.connect(host="localhost",user="root",passwd="root",db="test")
cur = db.cursor()

cur.execute('create table t12(journal_name varchar(100), weight_intra float, weight_overall float)')

with open('/home/sahil/Downloads/dataset-rr/journals/excel11.csv','rb') as csvfile:
	spamreader = csv.reader(csvfile, delimiter='$', quotechar='|')
	for row in spamreader:
		cur.execute("insert into t12 values("+"'"+row[1]+"' ,"+row[3]+","+row[4]+')')

db.commit()
