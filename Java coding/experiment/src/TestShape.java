public class TestShape {
    public static void main(String[] args) {
        Shape sha = new Shape();
        Triangle tri = new Triangle(new float[] {3, 4, 5});
        Rectangle rec = new Rectangle(new float[] {2, 3});
        Pillor pil = new Pillor(new float[] {1, 2});
        sha.print();
        tri.print();
        rec.print();
        pil.print();
    }
}
