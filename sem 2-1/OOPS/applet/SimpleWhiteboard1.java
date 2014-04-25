import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

public class SimpleWhiteboard1 extends Applet {
  /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	protected int lastX=0, lastY=0;
	public void init() {
    setBackground(Color.white);
    setForeground(Color.blue);
    addMouseListener(new PositionRecorder());
    addMouseMotionListener(new LineDrawer());
  }
	
  protected void record(int x, int y) 
  {
    lastX = x; lastY = y;
  }
  private class PositionRecorder extends MouseAdapter {
	    public void mouseEntered(MouseEvent event) {
	      requestFocus(); // Plan ahead for typing
	      
	      record(event.getX(), event.getY());
	    }

	    public void mousePressed(MouseEvent event) {
	    	
	  			 /*g.setColor(Color.white);
	  			  g.fillRect(400, 50, 200, 150);
	  			  g.setColor(Color.blue);
	  			  g.drawRect(400, 50, 200, 150);*/
	  			 record(event.getX(), event.getY());
	  	  
	    }
	  }
  
  private class LineDrawer extends MouseMotionAdapter {
    public void mouseDragged(MouseEvent event) {
      int x = event.getX();
      int y = event.getY();
      Graphics g = getGraphics();
      g.drawLine(lastX, lastY, x, y);
      record(x, y);
    }
  }
}