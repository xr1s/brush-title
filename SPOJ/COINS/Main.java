import java.util.*;

public class Main {
    static long[] dp = new long[50000000];
    static long earn(int n) {
        if (n == 0) return 0;
        if (n >= 50000000)
            return Math.max(n, earn(n / 2) + earn(n / 3) + earn(n / 4));
        if (dp[n] == 0)
            dp[n] = Math.max(n, earn(n / 2) + earn(n / 3) + earn(n / 4));
        return dp[n];
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt()) {
            int n = sc.nextInt();
            System.out.println(earn(n));
        }
    }
}
