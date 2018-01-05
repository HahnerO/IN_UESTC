import java.util.Scanner;

public class cmopute_in_speciffic {
    public static void main(String[] args) {
        cmopute_in_speciffic Add_number = new cmopute_in_speciffic();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Add each number in a number");
        System.out.print("Please input a number you want：");
        int num = scanner.nextInt();
        int result = Add_number.cmopute_in_speciffic(num);
        System.out.println("the result is :" + result);
    }

    public int cmopute_in_speciffic(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}
