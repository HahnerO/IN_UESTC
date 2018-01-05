public class TestPoint {
    public static void main(String[] args) {
        Point point = new Point();

        System.out.println("The initial Point is ");
        int[] x_y = point.getPoint();
        System.out.println("( " + x_y[0] + " , " + x_y[1] + " )");

        point.setX(10);
        point.setY(20);
        System.out.println("Set Point in (10,20)");
        x_y = point.getPoint();
        System.out.println("( " + x_y[0] + " , " + x_y[1] + " )");

        point.movePoint(-10, -20);
        System.out.println("Back To initial with movePoint way");
        x_y = point.getPoint();
        System.out.println("( " + x_y[0] + " , " + x_y[1] + " )");
    }

}