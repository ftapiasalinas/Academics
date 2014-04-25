import java.awt.Graphics;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

class CharDrawer extends KeyAdapter {
    // When user types a printable character,
    // draw it and shift position rightwards.
    public void keyTyped(KeyEvent event) {
      Whiteboard b = (Whiteboard) event.getSource();
      Graphics g = b.getGraphics();
      String s = String.valueOf(event.getKeyChar());
      g.drawString(s,b.lastX,b.lastY);
      b.record(b.lastX + b.fm.stringWidth(s), b.lastY);
  }
}