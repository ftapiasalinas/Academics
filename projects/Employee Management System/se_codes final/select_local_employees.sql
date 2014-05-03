create or replace PROCEDURE SELECT_LOCAL_EMPLOYEES(whereclause varchar2, site varchar2) AS
BEGIN
    case
       when site='ankur' then
            return_local_data@ankur_link(whereclause);
            declare
                cursor cur is select * from output_employee@ankur_link;
                curval employees%rowtype;
            begin    
                for curval in cur
                loop
                    insert into output_employee values(curval.id, curval.name, curval.payscale, curval.joindate, curval.enddate, curval.skills, curval.salary);
                end loop;
            end;
            
        when site='pravin' then
            return_local_data@pravin_link(whereclause);
            declare
                cursor cur is select * from output_employee@sahil_link;
                curval employees%rowtype;
            begin    
                for curval in cur
                loop
                    insert into output_employee values(curval.id, curval.name, curval.payscale, curval.joindate, curval.enddate, curval.skills, curval.salary);
                end loop;
            end;
            
        when site='surya' then
            return_local_data@surya_link(whereclause);
            declare
                cursor cur is select * from output_employee@surya_link;
                curval employees%rowtype;
            begin    
                for curval in cur
                loop
                    insert into output_employee values(curval.id, curval.name, curval.payscale, curval.joindate, curval.enddate, curval.skills, curval.salary);
                end loop;
            end;
            
        when site='sahil' then
            return_local_data(whereclause);
        end case;
         
        return;  
        
        
        exception
            when others then
                dbms_output.put_line('Not able to connect to remote link');
END;
