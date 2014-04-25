
public class C2
{
	class C1
	{
		public int i;
		public int j;
		
	}
	C1 c1 = new C1();
	public void tell()
	{
		System.out.println(c1.i + " " + c1.j );//gives compile error
		//c1.tell();
	}
	
	public static void main(String []args)
	{
		C2 c2 = new C2();
		c2.tell();
	}
}
