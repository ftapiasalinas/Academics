
insert into birthsites values('employees', '@ankur_link',1,301,400); 
insert into birthsites values('employees', '@pravin_link',1,1,100);
insert into birthsites values('employees', '@surya_link',1,101,200);


--birthsite link to be stored starting with @ ex employees	@ankur_link	1	301	400

insert into copieswithme values('employeescopypravin','id',70,90);
insert into copieswithme values('employeescopysurya','id',185,195);
insert into copieswithme values('employeescopyankur','id',310,325); 
--ex employeescopyankur	id	300	350

insert into mytables values('employees',1,201,300);

insert into mytables_copy values('employees','sahil_link');
insert into mytables_copy values('employees','pravin_link'); 
insert into mytables_copy values('employees','ankur_link'); 
--employees	ankur_link ***note there is no @ before ankur_link