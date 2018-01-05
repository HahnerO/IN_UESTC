public class Grade {
    private int gradeID;
    private Course crs;
    private int[] grd;

    public Grade(int gradeID, Course crs, int[] grd) {
        this.gradeID = gradeID;
        this.crs = crs;
        this.grd = grd;
    }

    public void print() {
        System.out.println("GradeID:" + this.gradeID + "\tCourse:" + this.crs.getName() + "\tCourseNumber:" + this.crs.getcrsID());
        System.out.println("Teacher:");
        this.crs.getTcr().print();
        System.out.println("Student's Grade is ");
        for (int i = 0; i < crs.getStus().length; i++) {
            crs.getStus()[i].printGrade(grd[i]);
        }
    }
}
