import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        for (int t = sc.nextInt(); t != 0; --t) {
            int N = sc.nextInt();
            int[] men = new int[N], women = new int[N];
            for (int i = 0; i != N; ++i) men[i]   = sc.nextInt();
            for (int i = 0; i != N; ++i) women[i] = sc.nextInt();
            Arrays.sort(men); Arrays.sort(women);
            int hotness = 0;
            for (int i = 0; i != N; ++i)
                hotness += men[i] * women[i];
            System.out.println(hotness);
        }
    }
}
