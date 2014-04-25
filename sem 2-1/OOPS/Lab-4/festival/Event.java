package festival;
import festival.*;
public class Event 
{
	private double Eventno;
	private int Position;
	private String Eventname;
	int i;
	
	public Event()
	{
		Eventno = 0;
		Position = 0;
		Eventname = "no event";
	}
	public void getposition()
	{
		System.out.println(Position);
	}
	public void setposition(int position)
	{
		Position = position;
	}
	public void setEventname(String evename)
	{
		Eventname = evename;
	}
	public void setEventno(double eveno)
	{
		Eventno = eveno;
	}
	
	
}	


