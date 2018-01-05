import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import javax.swing.JLabel;
import java.awt.Font;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.TimeZone;

public class Clock extends JFrame implements Runnable {
    private static final long serialVersionUID = 1L;
    private JLabel date;
    private JLabel time;
    private String timezone;

    public Clock(String timezone, int x, int y) {
        this.timezone = timezone;
        JPanel panel = new JPanel();//新建镶嵌页
        panel.setLayout(null);
        time = new JLabel();//新建时间表盘
        date = new JLabel();//新建日期
        getContentPane().add(panel, BorderLayout.CENTER);
        this.setVisible(true);
        this.setTitle("Clock in zone:" + this.timezone);
        this.setSize(400, 200);
        this.setLocation(x, y);
        this.setResizable(true);
        time.setBounds(100, 50, 200, 70);
        time.setFont(new Font("Arial", Font.PLAIN, 40));
        panel.add(time);//将时间插入镶嵌页
        date.setFont(new Font("Arial", Font.PLAIN, 17));
        date.setBounds(50, 20, 250, 20);
        panel.add(date);

        this.setDefaultCloseOperation(EXIT_ON_CLOSE);//同步关闭
    }

    public void run() {
        while(true) {
            try {
                SimpleDateFormat s1 = new SimpleDateFormat("yyyy / MM / dd  E");
                SimpleDateFormat s2 = new SimpleDateFormat("H:M:S");
                s1.setTimeZone(TimeZone.getTimeZone(this.timezone));//从时区读取时间
                s2.setTimeZone(TimeZone.getTimeZone(this.timezone));
                date.setText(s1.format(new Date()));
                time.setText(s2.format(new Date()));
            } catch(Throwable e) {
                e.printStackTrace();
            }
        }
    }
}
