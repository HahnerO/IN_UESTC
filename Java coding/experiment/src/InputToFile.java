import java.io.*;


public class InputToFile {
    public static void main(String[] args) throws IOException{
        BufferedReader buf1 = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter buf2 = new BufferedWriter(new FileWriter("InputTest.txt"));
        System.out.println("Please input:");
        String str = buf1.readLine();
        while(!str.equals("Y")){
            buf2.write(str);
            buf2.newLine();
            System.out.println("Input Y to exit");
            str = buf1.readLine();
        buf1.close();
        buf2.close();
        }
    }
}
