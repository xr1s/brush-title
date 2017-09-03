import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double c = sc.nextDouble();
        while (c != 0) {
            int cards = 0;
            double hang = 0;
            for (; hang < c; ++cards)
                hang += 1. / (cards + 2);
            System.out.println(cards + " card(s)");
            c = sc.nextDouble();
        }
    }
}
