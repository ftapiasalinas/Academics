import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;

class LineDrawer extends MouseMotionAdapter {
    public void mouseDragged(MouseEvent event) {
      SimpleWhiteboard b = (SimpleWhiteboard) event.getSource();
      int x = event.getX();
      int y = event.getY();
      Graphics g = b.getGraphics();
      g.drawLine(b.lastX, b.lastY, x, y);
      b.record(x, y);
    }
  }
