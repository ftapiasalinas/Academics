import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;


class PositionRecorder extends MouseAdapter{
	public void mouseEntered(MouseEvent event) 
	{
	SimpleWhiteboard b = (SimpleWhiteboard) event.getSource();
      //requestFocus(); // Plan ahead for typing
      b.record(event.getX(), event.getY());
    }

	public void mousePressed(MouseEvent event) {
	  SimpleWhiteboard b = (SimpleWhiteboard) event.getSource();
	  Graphics g = b.getGraphics();
	  if(event.getX() > 400 && event.getX() < 600 && event.getY() > 50 && event.getY() < 200 )
	  {
		  	
			 g.setColor(Color.white);
			  g.fillRect(400, 50, 200, 150);
			  g.setColor(Color.blue);
			  g.drawRect(400, 50, 200, 150);
			  b.record(event.getX(), event.getY());
	  }
	  else if(event.getX() > 100 && event.getX() < 300 && event.getY() > 100 && event.getY() < 250 )
	  {
		  g.setColor(Color.white);
		  g.fillRect(100,100,200,150);
		  g.setColor(Color.blue);
		  g.drawRect(100,100,200,150);
		  b.record(event.getX(), event.getY());
	  }
	  else if(event.getX() > 700 && event.getX() < 900 && event.getY() > 100 && event.getY() < 250 )
	  {
		  g.setColor(Color.white);
		  g.fillRect(700, 100, 200, 150);
		  g.setColor(Color.blue);
		  g.drawRect(700, 100, 200, 150);
		  b.record(event.getX(), event.getY());
	  }
	  else if(event.getX() > 1000 && event.getX() < 1200 && event.getY() > 125 && event.getY() < 275 )
	  {
		  g.setColor(Color.white);
		  g.fillRect(1000, 125, 200, 150);
		  g.setColor(Color.blue);
		  g.drawRect(1000, 125, 200, 150);
		  b.record(event.getX(), event.getY());
	  }
	  else
		  b.record(event.getX(), event.getY());
	  
	}
  }
