create or replace procedure copytosahil as
    cursor cur1 is select * from employees@pravin_link where id>=40 and id<=50;
    cursor cur2 is select * from employees@pravin_link where id>=60 and id<=80;
    cursor cur3 is select * from employees@ankur_link where id>=390 and id<=400;
    curval employees%rowtype;
    begin
        for curval in cur1 
        loop
            insert into employeescopypravin values(curval.id, curval.name, curval.payscale, curval.joindate, curval.enddate, curval.skills, curval.salary);
        end loop;
        
        for curval in cur2 
        loop
            insert into employeescopypravin values(curval.id, curval.name, curval.payscale, curval.joindate, curval.enddate, curval.skills, curval.salary);
        end loop;
        
        for curval in cur3
        loop
            insert into employeescopyankur values(curval.id, curval.name, curval.payscale, curval.joindate, curval.enddate, curval.skills, curval.salary);
        end loop;
    end;
    