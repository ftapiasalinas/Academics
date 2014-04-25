package sponsorship;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Output
{
	public static void main(String args[]) throws IOException
	{
		float total = 0;
		String largest = "null";
		String medium = "null";
		String smallest = "null";
		/*SilverSponsors ss[] = new SilverSponsors[3];
		ss[0] = new SilverSponsors();
		ss[0].money = 100000;
		ss[1] = new SilverSponsors();
		ss[1].money = 250000;	
		ss[2] = new SilverSponsors();
		ss[2].money = 500000;
		ss[0].years = 2;
		ss[1].years = 3;
		ss[2].years = 1;*/


	
		Sponsor[] sp = new Sponsor[3];		
		
		sp[0] = new GoldSponsor("Airtel",5000000,6,"Gurgaon","Waves");
		sp[1] = new PlatinumSponsor("Birla",405200,4,"Goa","Spree");
		sp[2] = new SilverSponsor("Google",5000000,4,"Bangalore","Quark");

		sp = Sponsor.bubble_sort(sp,3);
		System.out.println("Largest is : " + largest +"\nMedium is : " + medium + "\nSmallest is :" + smallest);  


		File file = new File("/home/user/Documents/2011C6ps520g/Lab-4/file.txt");
	
	
	FileWriter fw = new FileWriter(file);
	BufferedWriter bw = new BufferedWriter(fw);
	bw.write(largest);
	bw.write("\n");
	bw.write(medium);
	bw.write("\n");
	bw.write(smallest);
	
	bw.close();
	
	

	File file1 = new File("/home/user/Documents/2011C6ps520g/Lab-4/file1.txt");
	
	Scanner sc = null;
	int i=0;
	
		sc = new Scanner(file1);
		while(sc.hasNextLine())
		{
			String line = sc.nextLine();
	        System.out.println("ss[" + i +"]:" + line + "\n");
	         total = Float.parseFloat(line)+ total;
	         i++;
		}
		sc.close();
		System.out.println("total is " + total);
		
	
	

	
	
}
}

