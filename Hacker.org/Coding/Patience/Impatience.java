import java.math.*;
import java.util.*;

public class Impatience {
    public static void main(String[] args) {
        Random rand = new Random(0xb483fL);
        long l, t;
        do {
            do t = l = rand.nextLong(); while (l < 0);
            for (int i = 0; i != 20000; ++i)
                t = t % 1000000000 << 1 | 1;
        } while (t % 1000000000 != 843997183);
        System.out.println(l);
    }
}
