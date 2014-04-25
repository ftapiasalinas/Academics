
import personal.*;import java.util.StringTokenizer;


public class TestAddress 
{
	public static void main(String args[])
	{
	int i;	
	Address a[] = new Address[4]; 
	a[0] = new Address("21","2","122001","old delhi","market","dlf","gurgaon","haryana","INDIA");
	a[1] = new Address("22","3","403726","birla street","bogmalo beach","zuarinagar","vasco","goa","INDIA");
	a[2] = new Address("23","4","123456","downhill","museum","millenium","district1","xyz","ROME");
	a[3] = new Address("24","5","","uphill","zoo","abc","def","goa","INDIA");
	String temp[] = new String[7];
	
	StringTokenizer add = new StringTokenizer("#3A,1-164,Ist Line,Farmagudi,Ponda,Goa,403 405",",");
	for(i = 0;add.hasMoreTokens();i++)
	{
		temp[i]= add.nextToken();
		System.out.println(temp[i]);
		
		
		 
	}
	
	
	
	
		/*for(int i=0;i<4;i++)
		{
			a[i].printgoastate();
			System.out.println("\n\n");
		}*/
	
	for(int j=0;j<4;j++)
		a[j].checkpin();
	
	}
}
