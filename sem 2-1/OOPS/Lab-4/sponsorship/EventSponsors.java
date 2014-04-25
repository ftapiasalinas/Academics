package sponsorship;
import festival.Event;

abstract public class EventSponsors extends Sponsors implements Comparable{
	
	String event;
	Event var;
	
	public int compareTo (Object o)
	{
		EventSponsors es = (EventSponsors)o;
		if (this.money > es.money)
		return 1;
		if (this.money < es.money)
		return -1;
		else return 0;

	}
	abstract public void setName(String n);
	abstract public String getName();
	abstract public void setAddress(String a);
	abstract public String getAddress();
	abstract public void setEvent(String n);
	abstract public String getEvent();

}
