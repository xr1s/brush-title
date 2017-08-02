import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int col = sc.nextInt();
        while (col != 0) {
            String enc = sc.next();
            int len = enc.length();
            int row = len / col;
            char[][] grid = new char[row][col];
            int r = 0, c = 0;
            for (int i = 0; i != len; ++i) {
                grid[r][c] = enc.charAt(i);
                if ((r & 1) == 0) {
                    if (++c == col) {
                        c = col - 1; ++r;
                    }
                } else if ((r & 1) == 1) {
                    if (--c == -1) {
                        c = 0; ++r;
                    }
                }
            }
            for (c = 0; c != col; ++c)
                for (r = 0; r != row; ++r)
                    System.out.print(grid[r][c]);
            System.out.print('\n');
            col = sc.nextInt();
        }
    }
}
