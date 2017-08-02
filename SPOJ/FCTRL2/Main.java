import java.util.*;
import java.math.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        BigInteger[] factorial = new BigInteger[101];
        factorial[0] = BigInteger.valueOf(1);
        for (int i = 1; i <= 100; ++i)
            factorial[i] = BigInteger.valueOf(i).multiply(factorial[i - 1]);
        for (int t = sc.nextInt(); t != 0; --t)
            System.out.println(factorial[sc.nextInt()]);
    }
}
