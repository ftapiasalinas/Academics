package personal;
public class Student extends Person implements Comparable
	
{
	public String College,ID,University;
	public int compareTo (Object o)
	{
		Student stu = (Student)o;
		if (this.age > stu.age)
		return 1;
		if (this.age < stu.age)
		return -1;
		else return 0;

	}
	public  String getname()
	{
		return name;
	}	
	public  void setname(String name)
	{
	this.name = name;
	} 
	public  void setage(int age)
	{
	this.age= age;
	}
	public  int getage()
	{
		return age;
	}	
}	
