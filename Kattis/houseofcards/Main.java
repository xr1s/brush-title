import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger h = sc.nextBigInteger();
        int more = h.mod(BigInteger.valueOf(8)).intValue();
        if (more == 0 || more == 5) System.out.println(h);
        else if (0 < more && more < 5)
            System.out.println(BigInteger.valueOf(5 - more).add(h));
        else if (5 < more && more < 8)
            System.out.println(BigInteger.valueOf(8 - more).add(h));
    }
}
