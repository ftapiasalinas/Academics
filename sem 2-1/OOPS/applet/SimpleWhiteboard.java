
import java.applet.Applet;
import java.awt.*;

public class SimpleWhiteboard extends Applet {
  protected int lastX=0, lastY=0;
  
  
  
  public void init() {
    setBackground(Color.white);
    setForeground(Color.blue);
    addMouseListener(new PositionRecorder());
    addMouseMotionListener(new LineDrawer());

  }
  protected void record(int x, int y) {
    lastX = x; lastY = y;
  }
}
