create or replace procedure copytopravin as
    cursor cur is select * from employees@ankur_link where id>=1 and id<=300;
    
    begin
        for curval in cur1 
        loop
            insert into backup_employees@ankur_link values(curval.id, curval.name, curval.payscale, curval.joindate, curval.enddate, curval.skills, curval.salary);
        end loop;
    end;
    