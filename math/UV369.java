import java.util.Scanner;
import java.util.Arrays;

public class Main {

    private static long[][] memo = new long[1000][1000];

    public static void main(String args[]) {

        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 1000; j++) {
                memo[i][j] = -1;
            }
        }

        int n, k;

        while (scanner.hasNext()) {
            n = scanner.nextInt();
            k = scanner.nextInt();
            if (n == 0 && k == 0) {
                break;
            }
            System.out.println(n + " things taken " + k + " at a time is " + binom(n, k) + " exactly.");
        }

    }

    public static long binom(int n, int k) {
        if (k == 0) {
            return 1;
        }

        if (k == n) {
            return 1;
        }

        if (memo[n][k] != -1) {
            return memo[n][k];
        }

        memo[n][k] = binom(n - 1, k - 1) + binom(n - 1, k);
        return memo[n][k];

    }
}
