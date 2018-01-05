public class Teacher {
    private String name;
    private int age;
    private char sex;
    private int tID;

    public Teacher(String name, int age, char sex, int tID) {
        this.name = name;
        this.age = age;
        this.sex = sex;
        this.tID = tID;
    }

    public void print() {
        System.out.println("\t"+this.tID+"\t"+this.name+"\t"+this.sex+"\t"+this.age);
    }
}
