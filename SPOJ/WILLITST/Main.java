import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        System.out.println((n & n - 1) == 0 ? "TAK" : "NIE");
    }
}
