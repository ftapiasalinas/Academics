import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

public class Whiteboard1 extends SimpleWhiteboard1 {
  protected FontMetrics fm;
  public void init() {
    super.init();
    Font font = new Font("Serif", Font.BOLD, 20);
    setFont(font);
    fm = getFontMetrics(font);
    addKeyListener(new CharDrawer());
  }
  public void paint(Graphics g)
  {
  g.drawString("BITS Pilani - K.K. Birla Goa Campus", 350, 500);
  g.drawRect(400, 50, 200, 150);
  g.drawString("Main Building", 415,30);
  g.drawRect(100,100,200,150);
  g.drawString("A Wing", 150,80);
  g.drawRect(700, 100, 200, 150);
  g.drawString("C Wing", 750,80);
  g.drawRect(1000, 125, 200, 150);
  g.drawString("Library Lawns", 1015,110);
  }
  private class CharDrawer extends KeyAdapter {
    // When user types a printable character,
    // draw it and shift position rightwards.
    public void keyTyped(KeyEvent event) {
      String s = String.valueOf(event.getKeyChar());
      getGraphics().drawString(s, lastX, lastY);
      record(lastX + fm.stringWidth(s), lastY);
    }
  }
}