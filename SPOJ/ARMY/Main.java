import java.io.*;
import static java.lang.Math.*;

public class Main {
    static InputStreamReader isr = new InputStreamReader(System.in);
    static BufferedReader br = new BufferedReader(isr);
    static String[] power;
    public static void main(String[] args) throws Exception {
        for (int T = Integer.parseInt(br.readLine()); T != 0; --T) {
            br.readLine();
            String[] NGNM = br.readLine().split(" ");
            int NG = Integer.parseInt(NGNM[0]);
            int NM = Integer.parseInt(NGNM[1]);
            int maxNG = 0, maxNM = 0;
            power = br.readLine().split(" ");
            while (NG-- != 0) maxNG = max(maxNG, Integer.parseInt(power[NG]));
            power = br.readLine().split(" ");
            while (NM-- != 0) maxNM = max(maxNM, Integer.parseInt(power[NM]));
            if (maxNM > maxNG) System.out.print("Mecha");
            System.out.println("Godzilla");
        }
    }
}
