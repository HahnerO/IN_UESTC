public class TestMyDate {
    public static void main(String[] args) {
        MyDate my_date = new MyDate(1997, 8, 13);
        my_date.print();
        my_date.setDate(2018, 1, 5);
        my_date.print();
        my_date.setDay(20);
        my_date.print();
        my_date.setMonth(5);
        my_date.print();
        my_date.setYear(2018);
        my_date.print();
        System.out.println("Add 520 Days");
        my_date.add_Days(520);
        my_date.print();
    }
}

