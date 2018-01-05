import java.awt.*;
import java.awt.event.*;


public class SetColor {
    public static Frame f;
    public static Button b1,b2,b3;
    SetColor(){
        f=new Frame();
        f.setLayout(new BorderLayout());
        b1=new Button("set red");
        b2=new Button("set green");
        b3=new Button("set blue");
        f.add(b1,BorderLayout.EAST);
        f.add(b2,BorderLayout.WEST);
        f.add(b3,BorderLayout.CENTER);
        b1.addActionListener(new EventProcessor1());
        b2.addActionListener(new EventProcessor2());
        b3.addActionListener(new EventProcessor3());
        f.setSize(200, 100);
        f.setVisible(true);
    }
    public static void main(String args[]) {
        new SetColor();
    }
}
class EventProcessor1 implements ActionListener{

    @Override
    public void actionPerformed(ActionEvent e) {
        // TODO Auto-generated method stub
        SetColor.b1.setBackground(Color.RED);
        SetColor.b2.setBackground(Color.RED);
        SetColor.b3.setBackground(Color.RED);
    }

}
class EventProcessor2 implements ActionListener{

    @Override
    public void actionPerformed(ActionEvent e) {
        // TODO Auto-generated method stub
        SetColor.b1.setBackground(Color.GREEN);
        SetColor.b2.setBackground(Color.GREEN);
        SetColor.b3.setBackground(Color.GREEN);
    }

}
class EventProcessor3 implements ActionListener{

    @Override
    public void actionPerformed(ActionEvent e) {
        // TODO Auto-generated method stub
        SetColor.b1.setBackground(Color.BLUE);
        SetColor.b2.setBackground(Color.BLUE);
        SetColor.b3.setBackground(Color.BLUE);
    }

}
