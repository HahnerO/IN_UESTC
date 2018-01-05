public class Triangle extends Shape {

    public Triangle(float[] edges) {
        this.edges = edges;
        this.Area();
    }

    public void Area() {
        double p = (this.edges[0] + this.edges[1] + this.edges[2]) / 2;
        this.area = Math.sqrt(p*(p-this.edges[0])*(p-this.edges[1])*(p-this.edges[2]));
    }

    public void print() {
        System.out.println("This is a Triangle with the 3 edges:"+this.edges[0]+','+this.edges[1]+','+this.edges[2]);
        System.out.println("The area is "+this.area);
    }
}