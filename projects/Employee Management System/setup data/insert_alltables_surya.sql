
insert into birthsites values('employees', '@ankur_link',1,301,400); 
insert into birthsites values('employees', '@sahil_link',1,201,300);
insert into birthsites values('employees', '@pravin_link',1,1,100);



--birthsite link to be stored starting with @ ex employees	@ankur_link	1	301	400

insert into copieswithme values('employeescopypravin','id',40,50);
insert into copieswithme values('employeescopypravin','id',60,80);
insert into copieswithme values('employeescopyankur','id',390,400); 
--ex employeescopyankur	id	300	350

insert into mytables values('employees',1,101,200);

insert into mytables_copy values('employees','sahil_link');
insert into mytables_copy values('employees','pravin_link'); 
--employees	ankur_link ***note there is no @ before ankur_link