package sponsorship;

public class TitleSponsors extends EventSponsors implements Comparable {
	

	public int compareTo (Object o)
	{
		TitleSponsors ts = (TitleSponsors)o;
		if (this.money > ts.money)
		return 1;
		if (this.money < ts.money)
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
	
	public void setEvent(String e){
		event=e;
	}
	
	public String getEvent(){
		return event;
	}

}
