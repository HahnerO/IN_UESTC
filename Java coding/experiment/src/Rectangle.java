public class Rectangle extends Shape {

    public Rectangle(float[] edges) {
        this.edges = edges;
        this.Area();
    }

    public void Area() {
        this.area = this.edges[0] * this.edges[1];
    }

    public void print() {
        System.out.println("This is a Rectangle with 2 edages: "+this.edges[0]+','+this.edges[1]);
        System.out.println("The Area is "+this.area);
    }
}
