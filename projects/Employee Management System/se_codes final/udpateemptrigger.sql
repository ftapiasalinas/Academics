create or replace
trigger updateemptrigger
 after update on employees for each row
 declare
    cursor mytablescopycur is select * from Mytables_copy;
    mytablescopyval varchar2(200);
    --mytablescopyval mytablescopycur%rowtype;
    sqlstmt varchar2(200);
 begin
    for mytablescopyval in mytablescopycur
    loop
        if mytablescopyval.tablename='employees' then
            if mytablescopyval.remotelink='pravin_link' then
                update employeescopypravin@pravin_link set name=:new.name, enddate=:new.enddate, joindate=:new.joindate, payscale=:new.payscale, skills=:new.skills where id=:old.id;
            end if;
            
            /*if mytablescopyval.remotelink='sahil_link' then
                update employeescopypravin@ankur_link set name=:new.name, enddate=:new.enddate, joindate=:new.joindate, payscale=:new.payscale, skills=:new.skills where id=:old.id;
            end if;
            */
            /*if mytablescopyval.remotelink='surya_link' then
                update employeescopypravin@ankur_link set name=:new.name, enddate=:new.enddate, joindate=:new.joindate, payscale=:new.payscale, skills=:new.skills where id=:old.id;
            end if;
            */
            dbms_output.put_line(sqlstmt);
            --execute immediate sqlstmt;
        end if;
    end loop;
 end;
/