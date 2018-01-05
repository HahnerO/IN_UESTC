public class MyDate {
    private static int[] day_In_each_Months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    private int year, month, day;
    private boolean leap = false;

    public MyDate(int year, int month, int day) {
        this.setYear(year);
        this.setMonth(month);
        this.setDay(day);
    }

    public void setDate(int year, int month, int day) {
        this.setYear(year);
        this.setMonth(month);
        this.setDay(day);
    }

    public int getYear() {
        return year;
    }
    public int getMonth() {
        return month;
    }
    public int getDay() {
        return day;
    }

    public void setYear(int year) {
        if (year > 0){
            this.year = year;
            if (year%4 == 0) {
                this.leap = true;
            }
            else {
                this.leap = false;
            }
        }
        else {
            System.out.println("Invalid input of year!");
            System.exit(1);
        }
    }
    public void setMonth(int month) {
        if (month >= 1 && month <= 12) {
            this.month = month;
        }
        else {
            System.out.println("Invalid input of month!");
            System.exit(1);
        }
    }
    public void setDay(int day) {
        switch (this.month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12: {
                if (day >= 1 && day <= 31) {
                    this.day = day;
                }
                else {
                    System.out.println("Invalid input of day!");
                    System.exit(1);
                }
            }
            break;
            case 2: {
                if (leap) {
                    if (day >= 1 && day <= 29) {
                        this.day = day;
                    }
                    else {
                        System.out.println("Invalid input of day!");
                        System.exit(1);
                    }
                }
                else {
                    if (day >= 1 && day <= 28) {
                        this.day = day;
                    }
                    else {
                        System.out.println("Invalid input of day!");
                        System.exit(1);
                    }
                }
            }
            break;
            case 4:
            case 6:
            case 9:
            case 11: {
                if (day >=1 && day <= 30) {
                    this.day = day;
                }
                else {
                    System.out.println("Invalid input of day!");
                    System.exit(1);
                }
            }
            break;
            default: {
                System.out.println("Invalid input of day!");
                System.exit(1);
            }
            break;
        }
    }




    private int init_Date() {
        int total_days = this.day;
        for (int i = 0; i < this.month-1; i++) {
            total_days += MyDate.day_In_each_Months[i];
        }
        if (this.leap && (this.month >= 3)) {
            total_days++;
        }
        this.setMonth(1);
        this.setDay(1);
        return total_days;
    }

    private int add_by_Year(int d) {
        while (true) {
            if (this.leap && d >= 366) {
                this.setYear(this.year+1);
                d -= 366;
            }
            else if (!this.leap && d >= 365) {
                this.setYear(this.year+1);
                d -= 365;
            }
            else {
                return d;
            }
        }
    }

    private int add_by_Month(int d) {
        while (true) {
            switch (this.month) {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12: {
                    if (d >= 31) {
                        this.month++;
                        d -= 31;
                    }
                    else {
                        return d;
                    }
                }
                break;
                case 2: {
                    if (this.leap) {
                        if (d >= 29) {
                            this.month++;
                            d -= 29;
                        }
                        else {
                            return d;
                        }
                    }
                    else {
                        if (d >= 28) {
                            this.month++;
                            d -= 28;
                        }
                        else {
                            return d;
                        }
                    }
                }
                break;
                case 4:
                case 6:
                case 9:
                case 11: {
                    if (d >= 30) {
                        this.month++;
                        d -= 30;
                    }
                    else {
                        return d;
                    }
                }
                break;
                default:
                    break;
            }
        }
    }

    private void add_by_Day(int d) {
        this.day += d;
    }

    public void add_Days(int d) {
        if (d >= 0) {
            int total = d + this.init_Date() - 1;
            this.add_by_Day(this.add_by_Month(this.add_by_Year(total)));
        }
        else {
            System.out.println("Invalid days!");
        }
    }

    public void print() {
        System.out.printf("The date is: %d/%d/%d\n", year, month, day);
    }
}
