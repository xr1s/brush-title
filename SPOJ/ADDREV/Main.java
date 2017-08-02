import java.lang.*;
import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int N = sc.nextInt(); N != 0; --N) {
            StringBuilder A = new StringBuilder(sc.next());
            StringBuilder B = new StringBuilder(sc.next());
            BigInteger a = new BigInteger(A.reverse().toString());
            BigInteger b = new BigInteger(B.reverse().toString());
            StringBuilder sum = new StringBuilder(a.add(b).toString());
            System.out.println(new BigInteger(sum.reverse().toString()));
        }
    }
}
