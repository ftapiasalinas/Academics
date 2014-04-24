import java.util.*;
import java.io.IOException;
import java.util.StringTokenizer;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapred.MapReduceBase;
import org.apache.hadoop.mapred.Mapper;
import org.apache.hadoop.mapred.OutputCollector;
import org.apache.hadoop.mapred.Reporter;
import org.apache.hadoop.mapreduce.JobID;
import org.apache.hadoop.mapred.JobConf;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.mapreduce.JobContext;
import org.apache.hadoop.mapreduce.Mapper.Context;

public class MapClass extends MapReduceBase
implements Mapper<LongWritable, Text, Text, IntWritable> {
public Split split=null;
private final static IntWritable one = new IntWritable(1);
private Text attValue = new Text();
private Text cLabel = new Text();
private int i;
private String token;
public static int no_Attr;
private int flag=0;
String passedindexlist,passedvalue;
int passedindex;

public void configure(JobConf conf)
{
	
	passedvalue = conf.get("pv");
	passedindexlist = conf.get("pil");

	passedindex=Integer.parseInt(conf.get("pi"));


	int count=0;
	String d = (String)passedvalue.subSequence(1, passedvalue.length()-1);
	List<String> vlist = new ArrayList<String>();

	StringTokenizer vals  = new StringTokenizer(d,",");
	

	while(vals.hasMoreTokens())
	{
		if(count==0)
			vlist.add(vals.nextToken());
		else
			vlist.add(vals.nextToken().substring(1));
		
		count++;
	}


	String e = (String)passedindexlist.subSequence(1, passedindexlist.length()-1);
	
	List<Integer> indlist = new ArrayList<Integer>();
	StringTokenizer tokens  = new StringTokenizer(e,",");
	
	count =0;
	while(tokens.hasMoreTokens())
	{
		if(count==0)
		indlist.add(Integer.valueOf(tokens.nextToken()));
		else
		{
			indlist.add(Integer.valueOf(tokens.nextToken().substring(1)));
		}
		count++;
	}


	split  = new Split(indlist,vlist);
	
	System.out.println(passedindex + " passed vale is " + passedvalue + "passed list ins " + passedindexlist );	
	System.out.println(" \n\n\n\n");		
}



public void map(LongWritable key, Text value,OutputCollector<Text, IntWritable> output,Reporter reporter) throws IOException {

  C45 id=new C45();//we need to access the static field like currentsplit so we need an object
  
  int size_split=0;
  
  String line = value.toString();      //changing input instance value to string
  
  //get all the attributes of the current row except the class label 
  StringTokenizer itr = new StringTokenizer(line);
  int index=0;
  String attr_value=null;
  no_Attr=itr.countTokens()-1;
  String attr[]=new String[no_Attr];
  boolean match=true;
  for(i =0;i<no_Attr;i++)
  {
	  attr[i]=itr.nextToken();		//Finding the values of different attributes
	 // System.out.println("dsfsd " + attr[i]);
  }
  
  
  String classLabel=itr.nextToken();//class label is assigned here by extracting it from the row
  size_split = split.attr_index.size();//get the number of attributes that have already been used for
  
	System.out.println("Current index : "+ passedindex);

  for(int count=0;count<size_split;count++)
  {
	  index=(Integer)split.attr_index.get(count);
	  attr_value=(String)split.attr_value.get(count);
	 if(attr[index].equals(attr_value))   //may also use attr[index][z][1].contentEquals(attr_value)
	 {
		 System.out.println("EQUALS IN MAP  nodes  "+attr[index]+"   inline  "+attr_value);
	 }
	 else
	 {
	 	//the moment it finds that some condition is not being satisfied it marks as false
		 System.out.println("NOT EQUAL IN MAP  nodes  "+attr[index]+"   inline  "+attr_value);
		 match=false;
		 break;
	 }
	  
  }
  
  
//if your instance has reached at some level of tree then we need to get the attributes to be considered for splitting further ..
//that is what is outputted as token = l+" "+attr[l]+" "+classLabel;


  if(match)
  {
	for(int l=0;l<no_Attr;l++)
	{  
		if(split.attr_index.contains(l))
		{

		}
		else
		{
			token=l+" "+attr[l]+" "+classLabel;
			//token = index of attribute,value of attribute,classlabel
			attValue.set(token);
			output.collect(attValue, one);//the combination(token) is sent as the key to reducer
			//System.out.println(token);
		}

	}
	if(size_split==no_Attr)//terminating condition
	{
		token=no_Attr+" "+"null"+" "+classLabel;
		attValue.set(token);
		output.collect(attValue, one);
	}
   }
 }//for method
  
}//for class
  
