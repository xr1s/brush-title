import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int N = sc.nextInt();
        do System.out.println(N * (N + 1) * (N << 1 | 1) / 6);
        while ((N = sc.nextInt()) != 0);
    }
}
