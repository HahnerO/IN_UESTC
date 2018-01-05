/**
 * Created by hahn on 2017/9/11.
 */
class TestArray{
    public static void main(String args[]){
        int[] sim = {1,34,64,733,12,42,51,4,0};
        int temp, i, j;
        for (i = 0; i < (sim.length - 1); i++){
            for (j = i + 1; j < sim.length; j++){
                if (sim[i] > sim[j]){
                    temp = sim[i];
                    sim[i] = sim[j];
                    sim[j] = temp;
                }
            }
        }
        for (i = 0; i < sim.length; i++){
            System.out.println("sim[" + i + "] = " + sim[i]);
        }
    }
}
