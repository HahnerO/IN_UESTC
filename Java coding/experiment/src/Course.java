public class Course {
    private int cID;
    private String name;
    private Teacher tcr;
    private Student[] stus;

    public Course(int cID, String name, Teacher tcr, Student[] stus) {
        this.cID = cID;
        this.name = name;
        this.tcr = tcr;
        this.stus = stus;
    }
    public String getName() {
        return name;
    }
    public int getcrsID() {
        return cID;
    }
    public Teacher getTcr() {
        return this.tcr;
    }
    public Student[] getStus() {
        return this.stus;
    }
}
