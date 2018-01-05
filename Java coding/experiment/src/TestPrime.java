public class TestPrime {

    public static void main(String[] args) {
        PrimeNumber p = new PrimeNumber();
        int[] PrimeArray = p.getPrimeNumber(6);
        for (int i = 1; i < PrimeArray.length; i++) {
            System.out.println(i+":"+PrimeArray[i]);
        }
    }

}
