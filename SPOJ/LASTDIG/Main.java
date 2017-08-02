import java.util.*;

public class Main {
    static int power(int base, int exponent, int module) {
        int result = 1;
        do {
            if (exponent % 2 == 1) result = result * base % module;
            if (exponent != 1) base = base * base % module;
            exponent >>= 1;
        } while (exponent != 0);
        return result;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int t = sc.nextInt(); t != 0; --t) {
            int a = sc.nextInt(), b = sc.nextInt();
            System.out.println(power(a, b, 10));
        }
    }
}
