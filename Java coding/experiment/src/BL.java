import java.applet.*;
import java.awt.*;
public class BL extends Applet{
    public void init(){
        setLayout(new BorderLayout());
        add("North",new Button("North"));
        add("South",new Button("South"));
        add("West",new Button("West"));
        add("East",new Button("East"));
        add("Center",new Button("Center"));
    }
}