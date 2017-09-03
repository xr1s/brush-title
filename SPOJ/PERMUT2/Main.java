import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int[] p = new int[100000];
    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        while (n != 0) {
            for (int i = 0; i != n; ++i)
                p[i] = sc.nextInt() - 1;
            boolean ambiguous = true;
            for (int i = 0; i != n; ++i)
                ambiguous &= p[p[i]] == i;
            if (!ambiguous) System.out.print("not ");
            System.out.println("ambiguous");
            n = sc.nextInt();
        }
    }
}
