public class FourThread{
    static int count = 0;

    FourThread(){
        newThread t1 = new newThread(this,1);
        newThread t2 = new newThread(this,1);
        newThread t3 = new newThread(this,0);
        newThread t4 = new newThread(this,0);

        t1.start();
        t2.start();
        t3.start();
        t4.start();
    }

    synchronized void in_or_de(int code){
        if(code == 1){
            for(int i = 0; i <= 9; i++){
                count++;
                System.out.println("inc:" + count);
            }
        }else if(code == 0){
            for(int i = 0;i <= 9; i++){
                count--;
                System.out.println("dec:" + count);
            }
        }else{
            System.out.println("Invalid input");
        }
    }

    public static void main(String args[]){
        new FourThread();
    }
}

class newThread extends Thread{
    FourThread ft;
    int code;

    newThread(FourThread e,int c){
        ft = e;
        code = c;
    }

    public void run(){
        ft.in_or_de(code);
    }
}