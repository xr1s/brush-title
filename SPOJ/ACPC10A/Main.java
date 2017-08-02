import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int a1 = sc.nextInt(), a2 = sc.nextInt(), a3 = sc.nextInt();
        while (a1 != 0 || a2 != 0 || a3 != 0) {
            if (a1 + a3 == a2 << 1) System.out.println("AP " + (a3 + a2 - a1));
            if (a1 * a3 == a2 * a2) System.out.println("GP " + (a3 * a2 / a1));
            a1 = sc.nextInt(); a2 = sc.nextInt(); a3 = sc.nextInt();
        }
    }
}
