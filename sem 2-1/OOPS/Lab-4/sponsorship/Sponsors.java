package sponsorship;

abstract class Sponsors implements NoOfYears,Comparable{
	String name;
	String address;
	public int years;
	public float money;
	public int compareTo (Object o)
	{
		Sponsors s = (Sponsors)o;
		if (this.money > s.money)
		return 1;
		if (this.money < s.money)
		return -1;
		else return 0;

	}
	public int getnoOfYears()
	{
		return years;	
	}
	abstract public void setName(String n);
	abstract public String getName();
	abstract public void setAddress(String a);
	abstract public String getAddress();

}
