package sponsorship;

public class PrizeSponsors extends EventSponsors implements Comparable{
	

	public int compareTo (Object o)
	{
		PrizeSponsors ps = (PrizeSponsors)o;
		if (this.money > ps.money)
		return 1;
		if (this.money < ps.money)
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
	
	public void setPrize(String e){
		event=e;
	}
	
	public String getEvent(){
		return event;
	}
	@Override
	public void setEvent(String n) {
		// TODO Auto-generated method stub
		
	}

}
