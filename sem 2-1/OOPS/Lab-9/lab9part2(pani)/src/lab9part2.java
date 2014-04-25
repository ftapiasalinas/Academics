import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.TitledBorder;
public class lab9part2 extends JFrame {
	
	public lab9part2(String title1)
	{
		super(title1);
		
		JPanel p = new JPanel(new GridLayout(2, 1, 1, 1));
		
		TitledBorder title;
		title = BorderFactory.createTitledBorder("lab9 part2");
		p.setBorder(title);
		
		JPanel p12 = new JPanel(new GridLayout(2, 2, 1, 1));
		p.add(p12);
		
		
		p12.setBorder(BorderFactory.createTitledBorder("sad"));
		p12.add(new JLabel("First Name"));
		p12.add(new TextField("name"));
		p12.add(new JLabel("Last Name"));
		p12.add(new TextField("name"));
		p12.add(new JLabel("Title"));
		p12.add(new TextField("name"));
		p12.add(new JLabel("Nick Name"));
		p12.add(new TextField("name"));
		
		JPanel p11 = new JPanel(new GridLayout(1, 2, 1, 1));
		p.add(p11);
		
		String[] dropdwn = { "Item 1", "Item 2", "Item 3", "Item 4",};
		JComboBox list = new JComboBox(dropdwn);
		list.setSelectedIndex(3);

		p11.add(new JLabel("Format"));
		p11.add(list);
	

		
		
		
		
		//second panel from here
		JPanel p1 = new JPanel(new GridLayout(2, 2, 1,2));
		TitledBorder title2;
		title2 = BorderFactory.createTitledBorder("la part2");
		p1.setBorder(title2);
		
		p1.add(new JLabel("Email"));//,BorderLayout.SOUTH);
		p1.add(new TextField("e-mail"));//,BorderLayout.NORTH);	
		
		JPanel p13 = new JPanel(new BorderLayout());
		p1.add(p13);
		JPanel p14 = new JPanel(new GridLayout(4,2,1,1));
		p1.add(p14);
		JButton b1 = new JButton("Add");
		p14.add(b1);
		JButton b2 = new JButton("Edit");
		p14.add(b2);
		JButton b3 = new JButton("Remove");
		p14.add(b3);
		JButton b4 = new JButton("As Default");
		p14.add(b4); 
		
		
			
		String[] list33 = { "Item 1", "Item 2", "Item 3", "Item 4","Item 5","Item 6","Item 7","Item 8"};
		JList list3 = new JList( list33 );
		list3.setVisibleRowCount(5);
		//p1.add(list3,BorderLayout.AFTER_LINE_ENDS);
		
		JScrollPane sp = new JScrollPane(list3);
		p1.add(sp );//,BorderLayout.AFTER_LINE_ENDS );
		
		ButtonGroup group = new ButtonGroup();
		
		
		JRadioButton bb1 = new JRadioButton("HTML",true);
		p1.add(bb1);
		
		JRadioButton bb2= new JRadioButton("PLAIN TEXT",false);
		p1.add(bb2);
		
		JRadioButton bb3 = new JRadioButton("CUSTOM",false);
		p1.add(bb3);
		
		group.add(bb1);
		group.add(bb2);
		group.add(bb3);
/*
		JPanel p13 = new JPanel(new BorderLayout());
		p1.add(p13);
		JPanel p14 = new JPanel(new GridLayout(4, 2, 1, 1));
		p1.add(p14,BorderLayout.EAST);
		JButton b1 = new JButton("Add");
		p14.add(b1,BorderLayout.EAST);
		JButton b2 = new JButton("Edit");
		p14.add(b2,BorderLayout.EAST);
		JButton b3 = new JButton("Remove");
		p14.add(b3,BorderLayout.EAST);
		JButton b4 = new JButton("As Default");
		p14.add(b4,BorderLayout.EAST); 
	*/	
		//p1.add(new JLabel("Email"),BorderLayout.NORTH);
		//p1.add(new TextField("e-mail"),BorderLayout.NORTH);	
		
		
		
		
		
		add(p,BorderLayout.CENTER);		
		add(p1,BorderLayout.SOUTH);
	
	}
		public static void main(String [] args){
			
			
			
		
		
		
		JFrame frame = new lab9part2("LAB -9 part2 ");
		frame.setSize(600,650);
		frame.setLocation(200,200);
		frame.setDefaultCloseOperation(EXIT_ON_CLOSE);
		frame.setVisible(true);
		frame.pack();
		
		}
		
		
		
		
		
		
		
		/*
		
		super(title);
		text = new JTextField();
		this.getContentPane().add(text,BorderLayout.NORTH);
		panel = new JPanel(new GridLayout(2,2,1,1));
		a = new JButton("A");
		b = new JButton("B");
		c = new JButton("C");
		d = new JButton("D");
		panel.add(a);
		panel.add(b);
		panel.add(c);
		panel.add(d);
		this.getContentPane().add(panel,BorderLayout.CENTER);
		label = new JLabel("No. of Clicks : " + numClicks);
		this.getContentPane().add(label,BorderLayout.SOUTH);
		
	}
	public static void main(String [] args)
	{
		JFrame frame = new Lab9("LAB -9 part2 ");
		frame.setSize(200,150);
		frame.setLocation(200,200);
		frame.setDefaultCloseOperation(EXIT_ON_CLOSE);
		frame.setVisible(true);
	}

	
	*/
	
}