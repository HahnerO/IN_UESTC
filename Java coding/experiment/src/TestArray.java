public class TestArray {
    public static void main(String[] args) {
        ArraySort array_sort = new ArraySort(new int[]{13, 8, 9, 1, 5, 7, 2, 17});

        int[] sim = array_sort.getSim();

        array_sort.setOrder();

        for (int i : sim) {
            System.out.println(i);
        }
    }
}