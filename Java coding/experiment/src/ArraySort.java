import java.util.Arrays;

public class ArraySort {
    private int[] sim;
    public ArraySort(int[] array) {
        sim = array;
    }
    public int[] getSim() {
        return sim;
    }
    public void setOrder() {
        Arrays.sort(sim);//直接使用包自带的sort方法
    }
}