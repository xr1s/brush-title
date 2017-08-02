import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int T = sc.nextInt(); T != 0; --T) {
            int N = sc.nextInt(), pow = 0;
            do pow += (N /= 5); while (N != 0);
            System.out.println(pow);
        }
    }
}
