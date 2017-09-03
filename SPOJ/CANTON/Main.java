import java.util.*;
import static java.lang.Math.*;

public class Main {
    private static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        for (int t = sc.nextInt(); t != 0; --t) {
            int n = sc.nextInt();
            int k = (int)ceil(sqrt(n << 3 | 1) / 2 + .5);
            int r = k * (k - 1) / 2 - n + 1;
            System.out.print("TERM " + n + " IS ");
            if (k % 2 == 0) {
                System.out.println(r + "/" + (k - r));
            } else {
                System.out.println((k - r) + "/" + r);
            }
        }
    }
}
