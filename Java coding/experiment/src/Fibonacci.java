import java.util.Scanner;
public class Fibonacci {
    public static void main(String[] args) {
        Fibonacci f = new Fibonacci();
        Scanner s = new Scanner(System.in);
        System.out.println("Print the Fibonacci");
        System.out.print("Print the length you want：");
        int x = s.nextInt();
        for (int i = 1; i <= x; i++) {
            System.out.println("The No." + i + " number:" + f.fib(i));
        }
    }
    public int fib(int x) {
        if (x <= 2) {
            return 1;
        }
        else {
            return fib(x-2) + fib(x-1);
        }
    }
}
