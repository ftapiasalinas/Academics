package sponsorship;

public class SilverSponsors extends FestivalSponsors implements Comparable {
	
	public int compareTo (Object o)
	{
		SilverSponsors ss = (SilverSponsors)o;
		if (this.money > ss.money)
		return 1;
		if (this.money < ss.money)
		return -1;
		else return 0;

	}
	
	public void setName(String n){
		name =n;
	}
	
	public void setAddress(String a){
		address=a;
	}
	
	public String getName(){
		return name;
	}
	
	public String getAddress(){
		return address;
	}


}
