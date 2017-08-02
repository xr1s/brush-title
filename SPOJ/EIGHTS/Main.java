import java.math.*;
import java.util.*;

public class Main {
    static BigInteger 二百五 = BigInteger.valueOf(250);
    static BigInteger 负五十八 = BigInteger.valueOf(-58);
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int t = sc.nextInt(); t != 0; --t)
            System.out.println(sc.nextBigInteger().multiply(二百五).add(负五十八));
    }
}
