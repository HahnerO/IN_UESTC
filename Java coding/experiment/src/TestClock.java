public class TestClock {
    public static void main(String[] args) {
        new Thread(new Clock("GMT+8", 100, 200)).start();//start to runnable
        new Thread(new Clock("GMT+10", 500, 200)).start();
        new Thread(new Clock("GMT+12", 900, 200)).start();
    }
}
