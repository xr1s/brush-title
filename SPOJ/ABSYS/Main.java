import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int T = sc.nextInt(); T != 0; --T) {
            String lhs = sc.next();
            sc.next();
            String rhs = sc.next();
            sc.next();
            String rst = sc.next();
            int lv = 0, rv = 0, v = 0;
            if (lhs.contains("machula")) {
                v = Integer.parseInt(rst);
                rv = Integer.parseInt(rhs);
                lv = v - rv;
            }
            if (rhs.contains("machula")) {
                v = Integer.parseInt(rst);
                lv = Integer.parseInt(lhs);
                rv = v - lv;
            }
            if (rst.contains("machula")) {
                lv = Integer.parseInt(lhs);
                rv = Integer.parseInt(rhs);
                v = lv + rv;
            }
            System.out.printf("%d + %d = %d\n", lv, rv, v);
        }
    }
}
