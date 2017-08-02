import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int total = 0;
        for (int i = 1; i * i <= N; ++i) ++total;
        for (int i = 1; i <= N; ++i) {
            total += N / i;
        }
        System.out.println(total >> 1);
    }
}
