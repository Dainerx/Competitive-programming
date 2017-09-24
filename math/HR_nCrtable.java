import java.math.BigInteger;
import java.util.Scanner;
import java.util.HashMap;
import javafx.util.Pair;

public class Solution {

    private static HashMap<Pair<Integer, Integer>, BigInteger> memo = new HashMap<>(); //memo for dynamic programming

    public static void main(String args[]) {

        Scanner scanner = new Scanner(System.in);

        int T, N;
        T = scanner.nextInt();
        for (int i = 0; i < T; i++) {
            N = scanner.nextInt();
            BigInteger c = BigInteger.ONE;
            for (int j = 1; j < N + 2; j++) {
                System.out.print(c.mod(BigInteger.valueOf(1000000000)) + " ");
                c = c.multiply(BigInteger.valueOf(N + 1 - j));
                c = c.divide(BigInteger.valueOf(j));
            }
            System.out.println();
        }

    }
}
