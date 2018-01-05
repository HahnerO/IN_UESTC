public class PrimeNumber {

    public int[] getPrimeNumber(int n) {
        if (n <= 1) {
            return new int[] {1, 1};
        }

        int[] PrimeArray = new int[n+1];
        PrimeArray[0] = PrimeArray[1] = 1;

        for (int i = 2; i < PrimeArray.length; i++) {
            if (!isPrimeNumber(i)) {
                PrimeArray[i] = 1;
            }
        }
        return PrimeArray;
    }

    public boolean isPrimeNumber(int n) {
        for (int i = 2; i < (int)(Math.sqrt(n)+1); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}
