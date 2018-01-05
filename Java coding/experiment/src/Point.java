public class Point {
    private int x;
    private int y;
    public Point() {//无参构造设为原点
        x = 0;
        y = 0;
    }
    public void setX(int x) {
        this.x = x;
    }
    public void setY(int y) {
        this.y = y;
    }
    public void movePoint(int i, int j) {
        setX(x+i);
        setY(y+j);
    }
    public int[] getPoint() {
        return new int[] {x, y};
    }
}
