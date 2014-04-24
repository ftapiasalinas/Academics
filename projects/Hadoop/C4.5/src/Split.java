import java.util.ArrayList;
import java.util.List;

/*
This class stores info about the already built tree
attr_index is the list containing used indexes of the attributes in the tree till now
attr_value stores the split value of the corresponding attribute in the attr_index

*/
public class Split implements Cloneable{
	public List attr_index;
	public List attr_value;
	double entophy;
	String classLabel;
	Split()
	{
		 this.attr_index= new ArrayList<Integer>();
		 this.attr_value = new ArrayList<String>();
		
		
	}
	Split(List attr_index,List attr_value)
	{
		this.attr_index=attr_index;
		this.attr_value=attr_value;
		
	}
	
	void add(Split obj)
	{
		System.out.println("here in add");
		this.add(obj);
	}
	

}
