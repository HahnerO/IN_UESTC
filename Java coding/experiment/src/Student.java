public class Student {
    private String name;
    private int age;
    private char sex;
    private int sID;

    public Student(String name, int age, char sex, int sID) {
        this.name = name;
        this.age = age;
        this.sex = sex;
        this.sID = sID;
    }

    public void printGrade(int grade) {
        System.out.println("\t"+this.sID+"\t"+this.name+"\t"+this.sex+"\t"+this.age+"\t"+grade);
    }
}
