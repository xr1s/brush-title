import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int t = sc.nextInt(); t != 0; --t) {
            long N = sc.nextLong(), remain = 0;
            for (long i = 0; i != N; ++i) {
                remain += sc.nextLong() % N;
                remain = remain % N;
            }
            System.out.println(remain == 0 ? "YES" : "NO");
        }
    }
}
