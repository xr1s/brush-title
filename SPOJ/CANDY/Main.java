import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int N = sc.nextInt();
        while (N != -1) {
            int sum = 0;
            int[] candy = new int[N];
            for (int i = 0; i != N; ++i)
                sum += candy[i] = sc.nextInt();
            if (sum % N == 0) {
                int move = 0;
                for (int i = 0; i != N; ++i)
                    move += Math.abs(candy[i] - sum / N);
                System.out.println(move >> 1);
            } else System.out.println(-1);
            N = sc.nextInt();
        }
    }
}
