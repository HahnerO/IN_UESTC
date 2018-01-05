import java.awt.*;

import javax.swing.JTextArea;

public class NotePad {

    @SuppressWarnings("deprecation")
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Frame f=new Frame();

        f.setLayout(new BorderLayout());

        JTextArea textArea=new JTextArea();
        textArea.setLineWrap(true);

        f.add(textArea, BorderLayout.CENTER);

        Menu menu1=new Menu("File");
        Menu m1=new Menu("Open");
        MenuItem m5=new MenuItem("Recent files");
        MenuItem m2=new MenuItem("close");
        MenuItem m3=new MenuItem("Save");
        MenuItem m4=new MenuItem("Save as");
        m1.add(m5);
        menu1.add(m1);
        menu1.add(m2);
        menu1.add(m3);
        menu1.add(m4);


        Menu menu2=new Menu("Edit");
        MenuItem m6=new MenuItem("Back");
        MenuItem m7=new MenuItem("Stick");
        MenuItem m8=new MenuItem("Copy");
        MenuItem m9=new MenuItem("Paste");
        MenuItem m10=new MenuItem("Delete");
        menu2.add(m6);
        menu2.add(m7);
        menu2.add(m8);
        menu2.add(m9);
        menu2.add(m10);

        Menu menu3=new Menu("Format");
        MenuItem m11=new MenuItem("Return");
        MenuItem m12=new MenuItem("Fonts");
        menu3.add(m11);
        menu3.add(m12);

        Menu menu4=new Menu("About");
        MenuItem m13=new MenuItem("Update");
        menu4.add(m13);

        MenuBar mBar=new MenuBar();
        mBar.add(menu1);
        mBar.add(menu2);
        mBar.add(menu3);
        mBar.add(menu4);
        f.setMenuBar(mBar);
        f.setSize(300,200);
        f.show();
    }

}
