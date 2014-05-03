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

--$$$$$take care about granting previleges on remote procedures/tables
---#######now creating localmanager#######---
---#######now creating localmanager#######---
---#######now creating localmanager#######---

/*create user localmanager identified by localmanager;

--create session previlege
grant create session to localmanager;

--read on main employees & copydata table
grant select on employees to localmanager;
grant update on employees to localmanager;
grant select on employeescopyankur to localmanager;
grant select on employeescopysahil to localmanager;
grant select on employeescopysurya to localmanager;

--reads on metadata
grant select on copieswithme to localmanager;
grant select on mytables_copy to localmanager;

--reads / updates / truncates on output_employee table
grant select on output_employee to localmanager;
grant update on output_employee to localmanager;

--execute select_employee procedure - calling 3 levels + central one
grant execute on select_employee to localmanager;
grant execute on select_emp_level1 to localmanager;
grant execute on select_emp_level2 to localmanager;
grant execute on select_emp_level3 to localmanager;
grant execute on select_employee_central to localmanager;

--execute on local select
grant execute on return_local_data to localmanager;
grant execute on select_local_employees to localmanager;

--grant execute on update_employee
grant execute on update_employee to localmanager;
grant execute on update_employee_level1 to localmanager;
grant execute on update_triggerargs to localmanager;
--auxilary tables used in update procedure and trigger
grant update on trigger_args to localmanager;
grant insert on trigger_args to localmanager;
*/
