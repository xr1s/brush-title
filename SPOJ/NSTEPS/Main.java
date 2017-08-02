import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int T = sc.nextInt(); T != 0; --T) {
            int x = sc.nextInt(), y = sc.nextInt();
            if (x != y && x != y + 2) System.out.println("No Number");
            else System.out.println((0xffffffe & x)  + y);
        }
    }
}
