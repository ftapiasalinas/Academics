create user localuser identified by localuser;

--create session previlege
grant create session to localuser;
--read on main employees and copydata table
grant select on employees to localuser;
grant select on employeescopyankur to localuser;
grant select on employeescopysahil to localuser;
grant select on employeescopysurya to localuser;

--reads on metadata
grant select on copieswithme to localuser;
grant select on mytables_copy to localuser;

--reads / updates / truncates on output_employee table
grant select on output_employee to localuser;
grant update on output_employee to localuser;

--execute select_employee procedure - calling 3 levels + central one
grant execute on select_employee to localuser;
grant execute on select_emp_level1 to localuser;
grant execute on select_emp_level2 to localuser;
grant execute on select_emp_level3 to localuser;
grant execute on select_employee_central to localuser;

--execute on local select
grant execute on return_local_data to localuser;
grant execute on select_local_employees to localuser;

--granting select on permissions table to localuser
grant select on permissions to localuser;

grant create view to localuser;


