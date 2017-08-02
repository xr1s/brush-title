import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int kase = 0; kase != 10; ++kase) {
            BigInteger total = sc.nextBigInteger();
            BigInteger more = sc.nextBigInteger();
            System.out.println(total.add(more).divide(BigInteger.valueOf(2)));
            System.out.println(total.subtract(more).divide(BigInteger.valueOf(2)));
        }
    }
}
