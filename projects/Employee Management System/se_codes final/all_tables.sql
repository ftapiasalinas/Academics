CREATE TABLE employees
(
  ID INTEGER NOT NULL,
  NAME VARCHAR2(40) NOT NULL,
  PAYSCALE VARCHAR2(20) NOT NULL,
  JOINDATE DATE NOT NULL,
  ENDDATE DATE,
  SKILLS VARCHAR2(200) NOT NULL
  ,salary INTEGER
, CONSTRAINT TABLE1_PK PRIMARY KEY
  (
    ID
  )
,CONSTRAINT PAYRANGE CHECK
(payscale IN ('8000-15000','15000-25000','25000-40000','40000-100000'))
)
;

create table birthsites(tablename varchar2(30), birthsitelink varchar2(30), storedonpk int, minval int, maxval int); 
--birthsite link to be stored starting with @ ex employees	@ankur_link	1	301	400

create table copieswithme(tablename varchar2(30), attr varchar2(30), minval int, maxval int); 
--ex employeescopyankur	id	300	350

create table mytables(name varchar2(30), storedonpk int,  minval int, maxval int);

create table mytables_copy(tablename varchar2(30), remotelink varchar2(30)); 
--employees	ankur_link ***note there is no @ before ankur_link

CREATE TABLE output_employee
(
  ID INTEGER,
  NAME VARCHAR2(40) ,
  PAYSCALE VARCHAR2(20),
  JOINDATE DATE ,
  ENDDATE DATE,
  SKILLS VARCHAR2(200) 
  ,salary INTEGER);
  
  

/*

CREATE TABLE employeescopypravin
(
  ID INTEGER NOT NULL,
  NAME VARCHAR2(40) NOT NULL,
  PAYSCALE VARCHAR2(20) NOT NULL,
  JOINDATE DATE NOT NULL,
  ENDDATE DATE,
  SKILLS VARCHAR2(200) NOT NULL
  ,salary INTEGER
, CONSTRAINT copy1_PK PRIMARY KEY
  (
    ID
  )
,CONSTRAINT PAYRANGE1 CHECK
(payscale IN ('8000-15000','15000-25000','25000-40000','40000-100000'))
)
;


CREATE TABLE employeescopysurya
(
  ID INTEGER NOT NULL,
  NAME VARCHAR2(40) NOT NULL,
  PAYSCALE VARCHAR2(20) NOT NULL,
  JOINDATE DATE NOT NULL,
  ENDDATE DATE,
  SKILLS VARCHAR2(200) NOT NULL
  ,salary INTEGER
, CONSTRAINT copy2_PK PRIMARY KEY
  (
    ID
  )
,CONSTRAINT PAYRANGE2 CHECK
(payscale IN ('8000-15000','15000-25000','25000-40000','40000-100000'))
)
;


CREATE TABLE employeescopyankur
(
  ID INTEGER NOT NULL,
  NAME VARCHAR2(40) NOT NULL,
  PAYSCALE VARCHAR2(20) NOT NULL,
  JOINDATE DATE NOT NULL,
  ENDDATE DATE,
  SKILLS VARCHAR2(200) NOT NULL
  ,salary INTEGER
, CONSTRAINT copy3_PK PRIMARY KEY
  (
    ID
  )
,CONSTRAINT PAYRANGE3 CHECK
(payscale IN ('8000-15000','15000-25000','25000-40000','40000-100000'))
)
;


CREATE TABLE employeescopysahil
(
  ID INTEGER NOT NULL,
  NAME VARCHAR2(40) NOT NULL,
  PAYSCALE VARCHAR2(20) NOT NULL,
  JOINDATE DATE NOT NULL,
  ENDDATE DATE,
  SKILLS VARCHAR2(200) NOT NULL
  ,salary INTEGER
, CONSTRAINT copy4_PK PRIMARY KEY
  (
    ID
  )
,CONSTRAINT PAYRANGE4 CHECK
(payscale IN ('8000-15000','15000-25000','25000-40000','40000-100000'))
)
;



*/
