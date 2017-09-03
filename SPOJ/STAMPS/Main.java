import java.util.*;

public class Main {
    private static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int scenarios = sc.nextInt();
        for (int scenario = 1; scenario <= scenarios; ++scenario) {
            int n = sc.nextInt(), m = sc.nextInt();
            int[] s = new int[m];
            for (int i = 0; i != m; ++i)
                s[i] = sc.nextInt();
            Arrays.sort(s);
            int friends, sum = 0;
            for (friends = 1; friends <= m; ++friends)
                if ((sum += s[m - friends]) >= n) break;
            System.out.println("Scenario #" + scenario + ':');
            if (sum >= n) System.out.println(friends);
            else System.out.println("impossible");
            if (scenario != scenarios) System.out.println();
        }
    }
}
