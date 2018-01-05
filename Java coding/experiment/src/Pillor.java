public class Pillor extends Shape {

    public Pillor(float[] edges) {
        this.edges = edges;
        this.Area();
        this.Volume();
    }

    public void Area() {
        this.area = (this.edges[0] + this.edges[1]) * 2 * this.edges[0] * Math.PI;
    }

    public void Volume() {
        this.volume = 2 * Math.PI * Math.pow(this.edges[0], 2) * this.edges[1];
    }

    public void print() {
        System.out.println("This is a Pillor with the r and height:"+this.edges[0]+','+this.edges[1]);
        System.out.println("The Area is "+this.area);
        System.out.println("The Volume is "+this.volume);
    }
}
