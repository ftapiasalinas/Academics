package sponsorship;

abstract public class FestivalSponsors extends Sponsors	implements Comparable{
	
	
	public int compareTo (Object o)
	{
		FestivalSponsors fs = (FestivalSponsors)o;
		if (this.money > fs.money)
		return 1;
		if (this.money < fs.money)
		return -1;
		else return 0;

	}
	abstract public void setName(String n);
	abstract public void setAddress(String a);
	abstract public String getName();
	abstract public String getAddress();

}
