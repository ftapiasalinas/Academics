create or replace procedure r as
cursor empcur is select * from employees;
empval employees%rowtype;

bit int := 0;
begin
    for empval in empcur 
    loop
        if ((empval.skills like '%, c') or (empval.skills like 'c,%')) then
            if bit=0 then
                update employees set skills='java, c++, ruby' where id=empval.id;
            else 
                update employees set skills='ruby, python, java' where id=empval.id;
            end if;
              
        end if;
    end loop;
end;
