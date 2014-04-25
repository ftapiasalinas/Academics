import java.awt.*;

public class Whiteboard extends SimpleWhiteboard {
  protected FontMetrics fm;
private Image picture;
  public void init() {
    super.init();
    Font font = new Font("Serif", Font.BOLD, 26);
    setFont(font);
    fm = getFontMetrics(font);
    addKeyListener(new CharDrawer());
    setSize(1500,1000);
  }
  public void paint(Graphics g)
  {	  
	  String filename = "bits.jpg"; // Downloaded from google map
	  if (filename != null) 
	  {
	   this.picture = this.getImage(this.getDocumentBase(), filename);
	  }
	  if (this.picture != null) 
	  {
	   g.drawImage(this.picture, 0, 0, this);
	  }
	  
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
}