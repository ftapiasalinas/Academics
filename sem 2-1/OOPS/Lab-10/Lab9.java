
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class Lab9 extends JFrame
{
	private JButton a;
	private JButton b;
	private JButton c;
	private JButton d;
	private JTextField tf;
	private JLabel l;
	private int count;
	
	  
	
	public Lab9()
	{
		super("Title");
		setLayout(new FlowLayout());
		JPanel p = new JPanel();
		a = new JButton("A");
		b = new JButton("B");
		c = new JButton("C");
		d = new JButton("D");
		tf = new JTextField(20);
		l = new JLabel();
		setContentPane(p);
		
		p.add(a);
		p.add(b);
		p.add(c);
		p.add(d);
		p.add(tf);
		p.add(l);
		count = 0;
		
		a.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent event)
			{
					tf.setText(tf.getText()+"A");
					count+=1;
					l.setText(""+count);
			}
			
		};
		
		
		b.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent event)
			{
				tf.setText(tf.getText()+"B");
				count+=1;
				l.setText(""+count);
			}
			
		};
				
		
		c.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent event)
			{
				tf.setText(tf.getText()+"C");
				count+=1;
				l.setText(""+count);
			}
			
		};
		
		
		d.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent event)
			{
				tf.setText(tf.getText()+"D");
				count+=1;
				l.setText(""+count);
			}
			
		};
	}

}
