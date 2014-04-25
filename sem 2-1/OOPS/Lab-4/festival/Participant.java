package festival;
import festival.*;
import personal.*; 


public class Participant 
{
	public Event ev[] = new Event[5];
	public Event event = new Event();
	private String IDnumber,Name;
	public College col = new College();
	Address add = new Address();
	private double Mobileno;
	double Emergencyno;
	private	char Gender;
	private int Age;
	
	public Participant(String college,String university,String eventname)
	{
		col.setCollege(college);
		col.setUniversity(university);
		event.setEventname(eventname);
	}
	public Participant(String name,String idnumber,String college,String university,String eventname,double eventno,int position)
	{
		col.setCollege(college);
		col.setUniversity(university);
		event.setEventname(eventname);
		Name = name;
		IDnumber = idnumber;
		event.setEventname(eventname);
		event.setEventno(eventno);
		event.setposition(position);
	}
	public Participant(String name,String idnumber,String college,String university,String eventname,double eventno,
			int position,int age,char gender,double mobno,double emerno)
	{
		Age =age;
		Gender =gender;
		Mobileno = mobno;
		Emergencyno = emerno;
		col.setCollege(college);
		col.setUniversity(university);
		event.setEventname(eventname);
		Name = name;
		IDnumber = idnumber;
		event.setEventname(eventname);
		event.setEventno(eventno);
		event.setposition(position);
		
	}
		
	
	
}
