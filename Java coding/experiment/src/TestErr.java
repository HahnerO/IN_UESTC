public class TestErr {
    public static void main(String[] args) {
        TestErr err = new TestErr();
        err.fuc1();
        err.fuc2();
        err.fuc3();
    }

    public void fuc1() throws ArithmeticException{
        try {
            int num = 5/0;
        } catch (ArithmeticException e) {
            e.printStackTrace();//打印错误
        }
    }

    public void fuc2() throws IndexOutOfBoundsException{
        try {
            int[] array = new int[2];
            array[4] = 3;
        } catch (IndexOutOfBoundsException e) {
            e.printStackTrace();
        }
    }

    public void fuc3() throws NullPointerException {
        try {
            int[] array = null;
            int l = array.length;
            System.out.println(l);
        } catch (NullPointerException e) {
            e.printStackTrace();
        }
    }
}
