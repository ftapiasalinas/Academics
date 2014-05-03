create or replace
procedure update_employee(setclause varchar2, whereclause varchar2) as
sqlstmt varchar(100);
cursor birthsitescur is select * from birthsites;
birthsitesval birthsites%rowtype;

cursor mytablecur is select * from mytables;
mytableval mytables%rowtype;

begin

for mytableval in mytablecur
loop
    dbms_output.put_line(mytableval.name);

    if mytableval.name='employees' then
        sqlstmt := 'update employees '||setclause||' '||whereclause;
        dbms_output.put_line(sqlstmt);
        execute immediate sqlstmt;
        --trigger does the rest
    end if;
end loop;
          dbms_output.put_line('i printed this hit');

for birthsitesval in birthsitescur
  loop
      if birthsitesval.tablename='employees' then
          sqlstmt := 'update employees'||birthsitesval.birthsitelink||' '||setclause||' '|| whereclause;
          dbms_output.put_line(sqlstmt);
          execute immediate sqlstmt;
      end if;
  end loop;
end;
