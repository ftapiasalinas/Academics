create or replace procedure copytosahil as
    cursor cur1 is select * from employees where id>=70 and id<=90;
    --cursor cur2 is select * from employees@surya_link where id>=185 and id<=195;
    cursor cur3 is select * from employees@ankur_link where id>=310 and id<=325;
    curval employees%rowtype;
    begin
        for curval in cur1 
        loop
            insert into employeescopypravin@sahil_link values(curval.id, curval.name, curval.payscale, curval.joindate, curval.enddate, curval.skills, curval.salary);
        end loop;
        
        /*for curval in cur2 
        loop
            insert into employeescopysurya@sahil_link values(curval.id, curval.name, curval.payscale, curval.joindate, curval.enddate, curval.skills, curval.salary);
        end loop;
        */
        for curval in cur3
        loop
            insert into employeescopyankur@sahil_link values(curval.id, curval.name, curval.payscale, curval.joindate, curval.enddate, curval.skills, curval.salary);
        end loop;
    end;
    