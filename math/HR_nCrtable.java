import java.math.BigInteger;
import java.util.Scanner;
import java.util.HashMap;
import javafx.util.Pair;

public class Solution {

    public static void main(String args[]) {

        Scanner scanner = new Scanner(System.in);

        int T, N;
        T = scanner.nextInt();
        for (int i = 0; i < T; i++) {
            N = scanner.nextInt();
            //Opting for BigInteger class in Java is justified here since numbers grow exponentially 
            BigInteger c = BigInteger.ONE; // starting always with one
            //Complexity O(n)
            for (int j = 1; j < N + 2; j++) {
                System.out.print(c.mod(BigInteger.valueOf(1000000000)) + " "); // mod 10^9 for huge numbers
                c = c.multiply(BigInteger.valueOf(N + 1 - j));
                c = c.divide(BigInteger.valueOf(j));
            }
            System.out.println(); // go back to line
        }

    }
}
