package personal;
public class College 
{
	 String Univer,Colname;
	 
	 public College()
	 {
		 Univer = "not set";
		 Colname = "not set";			
	 }
	public void getUniversityname()
	{
		System.out.println(Univer);
	}
	public void getCollege()
	{
		System.out.println(Colname);
	}
	public void setUniversity(String uniname)
	{
		Univer = uniname;		
	}
	public void setCollege(String col)
	{
		Colname = col;
	}
	
}
