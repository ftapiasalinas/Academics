create or replace PROCEDURE return_local_data(whereclause varchar2) AS
    type empcurtype is ref cursor;
    empcv empcurtype;
    emprec employees%rowtype;
    sqlstmt varchar(200);
    
    cursor mytablecur is select * from MyTables;
    mytableval MyTables%rowtype; 
    
    cursor copieswithmecur is select * from copiesWithMe;
    copieswithmeval copiesWithMe%rowtype;
    tempval varchar2(30);
BEGIN
    execute immediate 'truncate table output_employee';
    for mytableval in mytablecur
    loop
        if mytableval.name='employees' then
            sqlstmt := 'select * from employees '||whereclause;
            open empcv for sqlstmt;
            loop 
                 fetch empcv into emprec;
                 exit when empcv%notfound;
                 insert into output_employee values(emprec.id, emprec.name, emprec.payscale, emprec.joindate, emprec.enddate, emprec.skills, emprec.salary);
            end loop;
            close empcv;  
        end if;
    end loop;
    
    for copieswithmeval in copieswithmecur 
    loop
        if copieswithmeval.tablename like 'employees%' then
            sqlstmt := 'select * from '||copieswithmeval.tablename||' ' || whereclause; 
            open empcv for sqlstmt;
            loop 
                 fetch empcv into emprec;
                 exit when empcv%notfound;
                 insert into output_employee values(emprec.id, emprec.name, emprec.payscale, emprec.joindate, emprec.enddate, emprec.skills, emprec.salary);
            end loop;
            close empcv;         
        end if;
    end loop;
    
    return;
END;
