public class TestGrade {
    public static void main(String[] args) {
        Student st1 = new Student("Hahn", 20, 'M', 24);
        Student st2 = new Student("Hong", 18, 'F', 19);
        Student st3 = new Student("jing", 19, 'M', 22);
        Teacher tcr = new Teacher("Jiang", 20, 'M', 33);
        Student[] stus = new Student[] {st1, st2, st3};
        Course crs = new Course(1010120, "Java", tcr, stus);
        Grade grd = new Grade(001, crs, new int[] {100, 90, 95});
        grd.print();
    }
}
